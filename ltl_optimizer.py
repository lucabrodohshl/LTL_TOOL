"""
LTL Formula Optimization Library

This module provides a professional interface for optimizing LTL formula sets
using automata-based equivalence classes and containment analysis.
"""

import spot
import time
import json
import pandas as pd
import os
from collections import defaultdict
from dataclasses import dataclass, asdict
from typing import List, Dict, Set, Tuple, Optional, Any
from tqdm import tqdm
import networkx as nx
import matplotlib.pyplot as plt


@dataclass
class OptimizationMetrics:
    """Metrics for LTL formula optimization performance and results."""
    
    # Input characteristics
    total_formulas: int
    total_classes: int
    single_formula_classes: int
    multi_formula_classes: int
    
    # Performance metrics
    equivalence_class_time: float
    containment_analysis_time: float
    total_time: float
    
    # Optimization results
    original_formula_count: int
    optimized_formula_count: int
    reduction_percentage: float
    
    # Per-class details
    class_reductions: List[Dict[str, Any]]
    
    # Output folders
    ltl_output_folder: Optional[str] = None
    graph_output_folder: Optional[str] = None
    result_folder: Optional[str] = None
    
    def to_dict(self) -> Dict[str, Any]:
        """Convert metrics to dictionary for serialization."""
        return asdict(self)
    
    def save_to_csv(self, filepath: str) -> None:
        """Save metrics to CSV file using pandas."""
        # Use result_folder if specified, otherwise use filepath directory
        if self.result_folder:
            # Create benchmark_specific subfolder for individual benchmark results
            benchmark_specific_folder = os.path.join(self.result_folder, "benchmark_specific")
            os.makedirs(benchmark_specific_folder, exist_ok=True)
            filename = os.path.basename(filepath)
            base_path = os.path.join(benchmark_specific_folder, filename)
        else:
            base_path = filepath
            
        # Save main metrics (excluding class_reductions)
        metrics_dict = self.to_dict().copy()
        class_reductions = metrics_dict.pop('class_reductions')
        
        # Remove folder paths from the saved metrics to avoid clutter
        metrics_dict.pop('ltl_output_folder', None)
        metrics_dict.pop('graph_output_folder', None)
        metrics_dict.pop('result_folder', None)
        
        # Save main metrics as single-row CSV
        main_metrics_df = pd.DataFrame([metrics_dict])
        main_metrics_path = base_path.replace('.json', '_summary.csv') if base_path.endswith('.json') else base_path.replace('.csv', '_summary.csv')
        main_metrics_df.to_csv(main_metrics_path, index=False)
        
        # Save class reductions as separate CSV
        if class_reductions:
            class_reductions_df = pd.DataFrame(class_reductions)
            class_reductions_path = base_path.replace('.json', '_class_reductions.csv') if base_path.endswith('.json') else base_path.replace('.csv', '_class_reductions.csv')
            class_reductions_df.to_csv(class_reductions_path, index=False)


class DisjointSetUnion:
    """Efficient Union-Find data structure with path compression."""
    
    def __init__(self, n: int):
        self.parent = list(range(n))
    
    def find(self, x: int) -> int:
        """Find root with path compression."""
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x: int, y: int) -> None:
        """Union two sets."""
        self.parent[self.find(x)] = self.find(y)


class LTLOptimizer:
    """
    Professional LTL Formula Optimizer using automata-based equivalence classes.
    
    This class provides methods to:
    1. Group LTL formulas into equivalence classes based on atomic propositions
    2. Build containment graphs within each class
    3. Identify minimal representative formulas
    4. Measure optimization performance and results
    """
    
    def __init__(self, enable_visualization: bool = False, save_graphs: bool = False, verbose: bool = True):
        """
        Initialize the LTL Optimizer.
        
        Args:
            enable_visualization: Whether to generate NetworkX visualizations
            save_graphs: Whether to save graphs to files (requires graph_output_folder)
            verbose: Whether to show progress bars and detailed output
        """
        self.enable_visualization = enable_visualization
        self.save_graphs = save_graphs
        self.verbose = verbose
        self.metrics: Optional[OptimizationMetrics] = None
        

    
    def _construct_equivalence_classes(self, formulas: List[str]) -> Tuple[Dict[int, List[int]], List[Any]]:
        """
        Group formulas into equivalence classes based on atomic propositions.
        
        Args:
            formulas: List of LTL formula strings
            
        Returns:
            Tuple of (classes mapping representative to formula indices, automata list)
        """
        n = len(formulas)
        props_per_formula = []
        automata = []
        
        # Extract propositions and build automata in single pass
        for formula_str in formulas:
            try:
                formula = spot.formula(formula_str)
                props = spot.atomic_prop_collect(formula)
                props_per_formula.append(set(props))
                
                # Standardized automata construction using "BA"
                aut = spot.translate(formula, "BA")
                aut.merge_edges()
                aut = aut.postprocess()
                automata.append(aut)
            except Exception as e:
                if self.verbose:
                    print(f"Error processing formula '{formula_str}': {e}")
                props_per_formula.append(set())
                automata.append(None)
        
        # Build equivalence classes using Union-Find
        L = defaultdict(list)
        UF = DisjointSetUnion(n)
        
        for i, props in enumerate(props_per_formula):
            for literal in props:
                L[literal].append(i)
        
        for indices in L.values():
            for j in range(1, len(indices)):
                UF.union(indices[0], indices[j])
        
        # Group formula indices by representative
        classes = defaultdict(list)
        for i in range(n):
            rep = UF.find(i)
            classes[rep].append(i)
        
        return dict(classes), automata
    
    def _build_containment_graph(self, formula_indices: List[int], automata: List[Any]) -> Tuple[List[Set[int]], List[Set[int]]]:
        """
        Build containment graph for a set of automata with optimizations.
        
        Args:
            formula_indices: List of formula indices in the same equivalence class
            automata: Complete list of automata (indexed by original formula position)
            
        Returns:
            Tuple of (edges, reverse_edges) where edges[i] contains indices j such that automata[j] contains automata[i]
        """
        n = len(formula_indices)
        edges = [set() for _ in range(n)]
        reverse_edges = [set() for _ in range(n)]
        
        # Skip containment analysis for trivial cases
        if n <= 1:
            return edges, reverse_edges
        
        # Pre-filter valid automata
        valid_automata = []
        index_mapping = {}
        for i, idx in enumerate(formula_indices):
            if automata[idx] is not None:
                valid_automata.append((i, automata[idx]))
                index_mapping[i] = len(valid_automata) - 1
        
        # Skip if insufficient valid automata
        if len(valid_automata) <= 1:
            return edges, reverse_edges
        
        iterator = tqdm(range(len(valid_automata)), desc="Building containment graph", disable=not self.verbose)
        
        for i in iterator:
            local_i, aut_i = valid_automata[i]
            
            for j in range(len(valid_automata)):
                if i == j:
                    continue
                    
                local_j, aut_j = valid_automata[j]
                
                try:
                    # Optimization: Check if j is already known to contain i through transitivity
                    if local_j in edges[local_i]:
                        continue
                        
                    # Check containment: does aut_j contain aut_i?
                    if aut_j.contains(aut_i):
                        edges[local_i].add(local_j)
                        reverse_edges[local_j].add(local_i)
                        
                        # Early termination: if aut_i contains aut_j, they're equivalent
                        # Only check if we haven't already established the reverse relationship
                        if local_i not in edges[local_j] and aut_i.contains(aut_j):
                            edges[local_j].add(local_i)
                            reverse_edges[local_i].add(local_j)
                            
                except Exception as e:
                    if self.verbose:
                        print(f"Error checking containment between automata {local_i} and {local_j}: {e}")
        
        return edges, reverse_edges
    
    def _find_minimal_candidates(self, edges: List[Set[int]]) -> List[int]:
        """
        Find minimal candidates (non-dominated nodes) in the containment graph.
        
        Args:
            edges: Adjacency list representation of containment graph
            
        Returns:
            List of indices representing minimal candidates
        """
        dominated = set()
        for i in range(len(edges)):
            dominated.update(edges[i])
        
        return [i for i in range(len(edges)) if i not in dominated]
    
    def _save_minimal_formulas(self, formulas: List[str], minimal_indices: List[int], 
                              benchmark_name: str, ltl_output_folder: str) -> None:
        """
        Save minimal formulas to an LTL file.
        
        Args:
            formulas: Original list of formulas
            minimal_indices: Indices of minimal formulas to save
            benchmark_name: Name of the benchmark
            ltl_output_folder: Folder to save the LTL file
        """
        if not ltl_output_folder:
            return
            
        os.makedirs(ltl_output_folder, exist_ok=True)
        output_file = os.path.join(ltl_output_folder, f"{benchmark_name}_minimal.ltl")
        
        with open(output_file, 'w') as f:
            for idx in minimal_indices:
                f.write(f"{formulas[idx]}\n")
    
    def _save_containment_graph(self, edges: List[Set[int]], formulas: List[str], 
                               formula_indices: List[int], class_rep: int, 
                               graph_output_folder: str, benchmark_name: str) -> None:
        """
        Save NetworkX visualization of containment graph to file.
        
        Args:
            edges: Adjacency list representation of containment graph
            formulas: Original formula strings
            formula_indices: Indices of formulas in this class
            class_rep: Representative index for the class
            graph_output_folder: Folder to save graph files
            benchmark_name: Name of the benchmark
        """
        if not self.save_graphs or not graph_output_folder:
            return
        
        os.makedirs(graph_output_folder, exist_ok=True)
        
        G = nx.DiGraph()
        n = len(edges)
        
        # Add nodes and edges with actual formula strings
        formula_strings = [formulas[formula_indices[i]] for i in range(n)]
        
        for idx, formula in enumerate(formula_strings):
            G.add_node(f"F{idx}: {formula[:50]}{'...' if len(formula) > 50 else ''}")
        
        node_labels = list(G.nodes())
        for i in range(n):
            for j in edges[i]:
                G.add_edge(node_labels[i], node_labels[j])
        
        # Create and save visualization
        plt.figure(figsize=(15, 10))
        pos = nx.spring_layout(G, seed=42, k=3, iterations=50)
        nx.draw(G, pos, with_labels=True, node_size=2000, font_size=6, 
               arrows=True, node_color='lightblue', edge_color='gray')
        plt.title(f"Containment Graph for {benchmark_name} - Class {class_rep}")
        plt.tight_layout()
        
        # Save graph
        graph_file = os.path.join(graph_output_folder, f"{benchmark_name}_class_{class_rep}_graph.png")
        plt.savefig(graph_file, dpi=300, bbox_inches='tight')
        
        if self.enable_visualization:
            plt.show()
        else:
            plt.close()
    
    def optimize_formulas(self, formulas: List[str], benchmark_name: str = "unknown",
                         ltl_output_folder: Optional[str] = None,
                         graph_output_folder: Optional[str] = None,
                         result_folder: Optional[str] = None) -> OptimizationMetrics:
        """
        Optimize a set of LTL formulas by finding minimal representatives.
        
        Args:
            formulas: List of LTL formula strings to optimize
            benchmark_name: Name identifier for this benchmark
            ltl_output_folder: Optional folder to save minimal LTL formulas
            graph_output_folder: Optional folder to save containment graphs
            result_folder: Optional folder to save CSV results
            
        Returns:
            OptimizationMetrics object containing performance and result data
        """
        start_time = time.time()
        
        if self.verbose:
            print(f"Optimizing {len(formulas)} LTL formulas for benchmark: {benchmark_name}")
        
        # Phase 1: Construct equivalence classes
        equiv_start = time.time()
        equivalence_classes, automata = self._construct_equivalence_classes(formulas)
        equiv_time = time.time() - equiv_start
        
        # Phase 2: Analyze containment within each class
        
        
        single_formula_classes = 0
        class_reductions = []
        total_minimal_count = 0
        all_minimal_indices = []  # Track all minimal formula indices
        cached_graphs = {}  # Cache containment graphs for visualization
        
        iterator = tqdm(equivalence_classes.items(), desc="Processing classes", disable=not self.verbose)
        containment_start = time.time()
        for rep, automata_list in iterator:
            if len(automata_list) == 1:
                single_formula_classes += 1
                total_minimal_count += 1
                all_minimal_indices.extend(automata_list)  # Single formula is minimal
                continue
            
            # Build containment graph
            edges, reverse_edges = self._build_containment_graph(automata_list, automata)
            
            # Cache the graph ONLY if visualization or saving is needed
            if (self.enable_visualization or self.save_graphs):
                cached_graphs[rep] = (edges, automata_list)
            
            # Find minimal candidates
            minimal_candidates = self._find_minimal_candidates(edges)
            
            # Convert local indices to global indices
            global_minimal_indices = [automata_list[i] for i in minimal_candidates]
            all_minimal_indices.extend(global_minimal_indices)
            
            # Record class reduction metrics
            class_reduction = {
                "representative": rep,
                "original_count": len(automata_list),
                "minimal_count": len(minimal_candidates),
                "reduction_percentage": ((len(automata_list) - len(minimal_candidates)) / len(automata_list) * 100)
            }
            class_reductions.append(class_reduction)
            total_minimal_count += len(minimal_candidates)
        
        # Calculate timing metrics before any saving operations
        containment_time = time.time() - containment_start
        total_time = time.time() - start_time
        
        # Now handle saving/visualization using cached graphs (not included in timing)
        for rep, (edges, automata_list) in cached_graphs.items():
            self._save_containment_graph(edges, formulas, automata_list, rep, 
                                       graph_output_folder, benchmark_name)
        
        # Save minimal formulas if output folder specified
        if ltl_output_folder:
            self._save_minimal_formulas(formulas, sorted(all_minimal_indices), 
                                      benchmark_name, ltl_output_folder)
        
        # Calculate overall metrics
        original_count = len(formulas)
        optimized_count = total_minimal_count
        reduction_percentage = ((original_count - optimized_count) / original_count * 100) if original_count > 0 else 0
        
        # Create metrics object
        self.metrics = OptimizationMetrics(
            total_formulas=len(formulas),
            total_classes=len(equivalence_classes),
            single_formula_classes=single_formula_classes,
            multi_formula_classes=len(equivalence_classes) - single_formula_classes,
            equivalence_class_time=equiv_time,
            containment_analysis_time=containment_time,
            total_time=total_time,
            original_formula_count=original_count,
            optimized_formula_count=optimized_count,
            reduction_percentage=reduction_percentage,
            class_reductions=class_reductions,
            ltl_output_folder=ltl_output_folder,
            graph_output_folder=graph_output_folder,
            result_folder=result_folder
        )
        
        if self.verbose:
            self._print_summary()
        
        return self.metrics
    
    def _print_summary(self) -> None:
        """Print optimization summary to console."""
        if not self.metrics:
            return
        
        print("\n" + "=" * 60)
        print("OPTIMIZATION SUMMARY")
        print("=" * 60)
        print(f"Total formulas processed: {self.metrics.total_formulas}")
        print(f"Number of equivalence classes: {self.metrics.total_classes}")
        print(f"Classes with single formula: {self.metrics.single_formula_classes}")
        print(f"Classes with multiple formulas: {self.metrics.multi_formula_classes}")
        print(f"")
        print(f"Performance:")
        print(f"  Equivalence class construction: {self.metrics.equivalence_class_time:.3f}s")
        print(f"  Containment analysis: {self.metrics.containment_analysis_time:.3f}s")
        print(f"  Total time: {self.metrics.total_time:.3f}s")
        print(f"")
        print(f"Optimization Results:")
        print(f"  Original formulas: {self.metrics.original_formula_count}")
        print(f"  Optimized formulas: {self.metrics.optimized_formula_count}")
        print(f"  Reduction: {self.metrics.reduction_percentage:.1f}%")
        print("=" * 60)
    
    def process_benchmark_folder(self, benchmark_path: str, 
                                ltl_output_folder: Optional[str] = None,
                                graph_output_folder: Optional[str] = None,
                                result_folder: Optional[str] = None) -> OptimizationMetrics:
        """
        Process a single benchmark folder containing properties.ltl file.
        
        Args:
            benchmark_path: Path to benchmark folder
            ltl_output_folder: Optional folder to save minimal LTL formulas
            graph_output_folder: Optional folder to save containment graphs
            result_folder: Optional folder to save CSV results
            
        Returns:
            OptimizationMetrics for this benchmark
        """
        properties_file = os.path.join(benchmark_path, "properties.ltl")
        
        if not os.path.exists(properties_file):
            raise FileNotFoundError(f"Properties file not found: {properties_file}")
        
        with open(properties_file, 'r') as f:
            lines = f.readlines()
            formulas = [line.strip() for line in lines if line.strip()]
        
        benchmark_name = os.path.basename(benchmark_path)
        return self.optimize_formulas(formulas, benchmark_name, 
                                    ltl_output_folder, graph_output_folder, result_folder)
    
    def process_multiple_benchmarks(self, benchmark_folder: str, 
                                   ltl_output_folder: Optional[str] = None,
                                   graph_output_folder: Optional[str] = None,
                                   result_folder: Optional[str] = None) -> Dict[str, OptimizationMetrics]:
        """
        Process multiple benchmark folders and optionally save results.
        
        Args:
            benchmark_folder: Root folder containing multiple benchmark subfolders
            ltl_output_folder: Optional folder to save minimal LTL formulas
            graph_output_folder: Optional folder to save containment graphs
            result_folder: Optional folder to save CSV results
            
        Returns:
            Dictionary mapping benchmark name to OptimizationMetrics
        """
        results = {}
        
        # Create output directories if specified
        for folder in [ltl_output_folder, graph_output_folder, result_folder]:
            if folder and not os.path.exists(folder):
                os.makedirs(folder, exist_ok=True)
        
        benchmark_folders = sorted(os.listdir(benchmark_folder))
        
        for folder_name in tqdm(benchmark_folders, desc="Processing benchmarks"):
            folder_path = os.path.join(benchmark_folder, folder_name)
            
            if not os.path.isdir(folder_path):
                continue
            
            try:
                metrics = self.process_benchmark_folder(folder_path, ltl_output_folder, 
                                                      graph_output_folder, result_folder)
                results[folder_name] = metrics
                
                # Save individual results if result folder specified
                if result_folder:
                    output_file = os.path.join(result_folder, f"{folder_name}_metrics.csv")
                    metrics.save_to_csv(output_file)
                    
            except Exception as e:
                if self.verbose:
                    print(f"Error processing {folder_name}: {e}")
        
        return results
