"""
LTL Formula Optimization Library

This module provides a professional interface for optimizing LTL formula sets
using automata-based equivalence classes and containment analysis.
"""

import spot
import time
import json
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
    
    def to_dict(self) -> Dict[str, Any]:
        """Convert metrics to dictionary for serialization."""
        return asdict(self)
    
    def save_to_json(self, filepath: str) -> None:
        """Save metrics to JSON file."""
        with open(filepath, 'w') as f:
            json.dump(self.to_dict(), f, indent=2)


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
    
    def __init__(self, enable_visualization: bool = False, verbose: bool = True):
        """
        Initialize the LTL Optimizer.
        
        Args:
            enable_visualization: Whether to generate NetworkX visualizations
            verbose: Whether to show progress bars and detailed output
        """
        self.enable_visualization = enable_visualization
        self.verbose = verbose
        self.metrics: Optional[OptimizationMetrics] = None
        
    def _extract_atomic_propositions(self, formulas: List[str]) -> Tuple[Set[str], List[Any]]:
        """
        Extract atomic propositions and build automata for each formula.
        
        Args:
            formulas: List of LTL formula strings
            
        Returns:
            Tuple of (all_atomic_props, automata_list)
        """
        all_props = set()
        all_automata = []
        
        for formula_str in formulas:
            try:
                formula = spot.formula(formula_str)
                props = spot.atomic_prop_collect(formula)
                all_props.update(props)
                
                automaton = spot.translate(formula)
                automaton.merge_edges()
                automaton = automaton.postprocess()
                all_automata.append(automaton)
            except Exception as e:
                if self.verbose:
                    print(f"Error processing formula '{formula_str}': {e}")
                all_automata.append(None)
        
        return all_props, all_automata
    
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
        
        # Extract propositions and build automata
        for formula_str in formulas:
            try:
                formula = spot.formula(formula_str)
                props = spot.atomic_prop_collect(formula)
                props_per_formula.append(set(props))
                
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
        Build containment graph for a set of automata.
        
        Args:
            formula_indices: List of formula indices in the same equivalence class
            automata: Complete list of automata (indexed by original formula position)
            
        Returns:
            Tuple of (edges, reverse_edges) where edges[i] contains indices j such that automata[j] contains automata[i]
        """
        n = len(formula_indices)
        edges = [set() for _ in range(n)]
        reverse_edges = [set() for _ in range(n)]
        
        iterator = tqdm(range(n), desc="Building containment graph", disable=not self.verbose)
        for i in iterator:
            aut_i = automata[formula_indices[i]]
            if aut_i is None:
                continue
            for j in range(n):
                if i == j:
                    continue
                aut_j = automata[formula_indices[j]]
                if aut_j is None:
                    continue
                try:
                    if aut_j.contains(aut_i):
                        edges[i].add(j)
                        reverse_edges[j].add(i)
                except Exception as e:
                    if self.verbose:
                        print(f"Error checking containment: {e}")
        
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
    
    def _visualize_containment_graph(self, edges: List[Set[int]], formulas: List[str], class_rep: int) -> None:
        """
        Create NetworkX visualization of containment graph.
        
        Args:
            edges: Adjacency list representation of containment graph
            formulas: Formula strings for node labels
            class_rep: Representative index for the class
        """
        if not self.enable_visualization:
            return
        
        G = nx.DiGraph()
        n = len(edges)
        
        # Add nodes and edges
        for idx, formula in enumerate(formulas):
            G.add_node(formula)
        
        for i in range(n):
            for j in edges[i]:
                G.add_edge(formulas[i], formulas[j])
        
        # Create visualization
        plt.figure(figsize=(12, 8))
        pos = nx.spring_layout(G, seed=42)
        nx.draw(G, pos, with_labels=True, node_size=1500, font_size=8, arrows=True)
        plt.title(f"Containment Graph for Class {class_rep}")
        plt.show()
    
    def optimize_formulas(self, formulas: List[str], benchmark_name: str = "unknown") -> OptimizationMetrics:
        """
        Optimize a set of LTL formulas by finding minimal representatives.
        
        Args:
            formulas: List of LTL formula strings to optimize
            benchmark_name: Name identifier for this benchmark
            
        Returns:
            OptimizationMetrics object containing performance and result data
        """
        start_time = time.time()
        
        if self.verbose:
            print(f"Optimizing {len(formulas)} LTL formulas for benchmark: {benchmark_name}")
        
        # Phase 1: Construct equivalence classes
        equiv_start = time.time()
        equivalence_classes = self._construct_equivalence_classes(formulas)
        equiv_time = time.time() - equiv_start
        
        # Phase 2: Analyze containment within each class
        containment_start = time.time()
        
        single_formula_classes = 0
        class_reductions = []
        total_minimal_count = 0
        
        iterator = tqdm(equivalence_classes.items(), desc="Processing classes", disable=not self.verbose)
        
        for rep, automata_list in iterator:
            if len(automata_list) == 1:
                single_formula_classes += 1
                total_minimal_count += 1
                continue
            
            # Build containment graph
            edges, reverse_edges = self._build_containment_graph(automata_list)
            
            # Find minimal candidates
            minimal_candidates = self._find_minimal_candidates(edges)
            
            # Record class reduction metrics
            class_reduction = {
                "representative": rep,
                "original_count": len(automata_list),
                "minimal_count": len(minimal_candidates),
                "reduction_percentage": ((len(automata_list) - len(minimal_candidates)) / len(automata_list) * 100)
            }
            class_reductions.append(class_reduction)
            total_minimal_count += len(minimal_candidates)
            
            # Visualize if enabled
            if self.enable_visualization and len(automata_list) > 1:
                # Note: This requires mapping automata back to formula strings
                # For now, using placeholder strings
                formula_strings = [f"Formula_{i}" for i in range(len(automata_list))]
                self._visualize_containment_graph(edges, formula_strings, rep)
        
        containment_time = time.time() - containment_start
        total_time = time.time() - start_time
        
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
            class_reductions=class_reductions
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
    
    def process_benchmark_folder(self, benchmark_path: str) -> OptimizationMetrics:
        """
        Process a single benchmark folder containing properties.ltl file.
        
        Args:
            benchmark_path: Path to benchmark folder
            
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
        return self.optimize_formulas(formulas, benchmark_name)
    
    def process_multiple_benchmarks(self, benchmark_folder: str, output_dir: Optional[str] = None) -> Dict[str, OptimizationMetrics]:
        """
        Process multiple benchmark folders and optionally save results.
        
        Args:
            benchmark_folder: Root folder containing multiple benchmark subfolders
            output_dir: Optional directory to save individual results
            
        Returns:
            Dictionary mapping benchmark name to OptimizationMetrics
        """
        results = {}
        
        if output_dir and not os.path.exists(output_dir):
            os.makedirs(output_dir)
        
        benchmark_folders = sorted(os.listdir(benchmark_folder))
        
        for folder_name in tqdm(benchmark_folders, desc="Processing benchmarks"):
            folder_path = os.path.join(benchmark_folder, folder_name)
            
            if not os.path.isdir(folder_path):
                continue
            
            try:
                metrics = self.process_benchmark_folder(folder_path)
                results[folder_name] = metrics
                
                # Save individual results if output directory specified
                if output_dir:
                    output_file = os.path.join(output_dir, f"{folder_name}_metrics.json")
                    metrics.save_to_json(output_file)
                    
            except Exception as e:
                if self.verbose:
                    print(f"Error processing {folder_name}: {e}")
        
        return results
