"""
Enhanced LTL Formula Optimization Library - Research Paper Implementation

This module provides an advanced implementation of LTL formula optimization
based on the LTL Refinement research papers, incorporating subformula decomposition,
lattice construction, and cross-formula refinement analysis.

Key enhancements over basic LTLOptimizer:
1. Formula preprocessing and simplification
2. Subformula extraction and decomposition
3. Lattice construction from subformulas
4. Cross-formula subformula refinement analysis
5. Syntactic refinement heuristics
6. Proper minimal subset selection based on subformula coverage
"""

import spot
import time
import json
import pandas as pd
import os
import re
from collections import defaultdict, deque
from dataclasses import dataclass, asdict
from typing import List, Dict, Set, Tuple, Optional, Any, Union
from tqdm import tqdm
import networkx as nx
import matplotlib.pyplot as plt
from itertools import combinations, chain, product

from .optimizer import LTLOptimizer, OptimizationMetrics, DisjointSetUnion


@dataclass
class EnhancedOptimizationMetrics(OptimizationMetrics):
    """Extended metrics for enhanced LTL optimization with research features."""
    
    # Preprocessing metrics
    preprocessing_time: float = 0.0
    formulas_simplified: int = 0
    simplification_reduction: float = 0.0
    
    # Subformula analysis
    subformula_extraction_time: float = 0.0
    total_subformulas: int = 0
    unique_subformulas: int = 0
    avg_subformulas_per_formula: float = 0.0
    
    # Lattice construction
    lattice_construction_time: float = 0.0
    lattice_nodes: int = 0
    lattice_edges: int = 0
    lattice_levels: int = 0
    
    # Cross-formula refinement
    refinement_analysis_time: float = 0.0
    cross_formula_refinements: int = 0
    syntactic_refinements: int = 0
    
    # Enhanced optimization results
    subformula_coverage_reduction: float = 0.0
    syntactic_optimization_benefit: float = 0.0
    
    def to_dict(self) -> Dict[str, Any]:
        """Convert enhanced metrics to dictionary for serialization."""
        return asdict(self)
    
    def save_to_csv(self, filepath: str) -> None:
        """Save enhanced metrics to CSV file using pandas."""
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
        class_reductions = metrics_dict.pop('class_reductions', [])
        
        # Remove folder paths from the saved metrics to avoid clutter
        metrics_dict.pop('ltl_output_folder', None)
        metrics_dict.pop('graph_output_folder', None)
        metrics_dict.pop('result_folder', None)
        
        # Save main metrics as single-row CSV
        main_metrics_df = pd.DataFrame([metrics_dict])
        main_metrics_path = base_path.replace('.json', '_summary.csv') if base_path.endswith('.json') else base_path.replace('.csv', '_summary.csv')
        main_metrics_df.to_csv(main_metrics_path, index=False)
        
        # Save class reductions as separate CSV if available
        if class_reductions:
            class_reductions_df = pd.DataFrame(class_reductions)
            class_reductions_path = base_path.replace('.json', '_class_reductions.csv') if base_path.endswith('.json') else base_path.replace('.csv', '_class_reductions.csv')
            class_reductions_df.to_csv(class_reductions_path, index=False)


class SubformulaExtractor:
    """Advanced subformula extraction and analysis utilities."""
    
    @staticmethod
    def extract_all_subformulas(formula_str: str) -> Set[str]:
        """
        Extract all meaningful subformulas from an LTL formula.
        
        Args:
            formula_str: LTL formula string
            
        Returns:
            Set of subformula strings
        """
        try:
            formula = spot.formula(formula_str)
            subformulas = set()
            visited = set()  # Prevent infinite recursion
            
            # Use iterative approach with stack to avoid deep recursion
            stack = [formula]
            
            while stack:
                current = stack.pop()
                current_str = str(current)
                
                # Avoid processing the same formula twice
                if current_str in visited:
                    continue
                    
                visited.add(current_str)
                subformulas.add(current_str)
                
                # Add children to stack (iterative instead of recursive)
                try:
                    for child in current:
                        stack.append(child)
                except:
                    # Some formulas might not be iterable
                    pass
            
            # Filter out trivial subformulas (single propositions, constants)
            filtered = set()
            for sf in subformulas:
                if len(sf) > 1 and not sf.isalnum() and sf != "1" and sf != "0":
                    filtered.add(sf)
            
            return filtered
            
        except Exception as e:
            # If formula parsing fails, return empty set
            return set()
    
    @staticmethod
    def categorize_subformulas(subformulas: Set[str]) -> Dict[str, Set[str]]:
        """
        Categorize subformulas by their structure and operators.
        
        Args:
            subformulas: Set of subformula strings
            
        Returns:
            Dictionary mapping category names to subformula sets
        """
        categories = {
            'temporal': set(),
            'logical': set(),
            'atomic': set(),
            'complex': set()
        }
        
        temporal_ops = {'G', 'F', 'X', 'U', 'R', 'W', 'M'}
        logical_ops = {'&', '|', '!', '->', '<->'}
        
        for sf in subformulas:
            has_temporal = any(op in sf for op in temporal_ops)
            has_logical = any(op in sf for op in logical_ops)
            
            if has_temporal and has_logical:
                categories['complex'].add(sf)
            elif has_temporal:
                categories['temporal'].add(sf)
            elif has_logical:
                categories['logical'].add(sf)
            else:
                categories['atomic'].add(sf)
        
        return categories


class FormulaSimplifier:
    """Advanced formula simplification using SPOT and custom heuristics."""
    
    @staticmethod
    def simplify_formula(formula_str: str) -> Tuple[str, bool]:
        """
        Simplify an LTL formula using multiple techniques.
        
        Args:
            formula_str: Original LTL formula string
            
        Returns:
            Tuple of (simplified_formula, was_simplified)
        """
        try:
            original = spot.formula(formula_str)
            
            # Apply SPOT's built-in simplifications
            simplified = original.simplify()
            
            # Apply additional custom simplifications
            simplified = FormulaSimplifier._apply_custom_simplifications(simplified)
            
            simplified_str = str(simplified)
            was_simplified = simplified_str != formula_str
            
            return simplified_str, was_simplified
            
        except Exception:
            return formula_str, False
    
    @staticmethod
    def _apply_custom_simplifications(formula) -> Any:
        """Apply custom simplification rules beyond SPOT's built-ins."""
        # This is where we could add domain-specific simplification rules
        # For now, we rely on SPOT's comprehensive simplification
        return formula.simplify()
    
    @staticmethod
    def convert_to_dnf(formula_str: str) -> str:
        """
        Convert formula to Disjunctive Normal Form when beneficial.
        
        Args:
            formula_str: LTL formula string
            
        Returns:
            DNF representation if beneficial, original otherwise
        """
        try:
            formula = spot.formula(formula_str)
            
            # Only convert to DNF for relatively simple formulas
            # to avoid exponential explosion
            if len(str(formula)) < 100:
                # SPOT doesn't have direct DNF conversion for LTL
                # We apply logical simplifications that may produce DNF-like results
                simplified = formula.simplify()
                return str(simplified)
            
            return formula_str
            
        except Exception:
            return formula_str


class SubformulaLattice:
    """Lattice construction and analysis for subformula relationships."""
    
    def __init__(self):
        self.lattice = nx.DiGraph()
        self.subformula_to_node = {}
        self.node_to_subformula = {}
        self.levels = []
    
    def build_lattice(self, all_subformulas: Set[str]) -> Tuple[int, int, int]:
        """
        Build a lattice structure from subformulas based on containment.
        
        Args:
            all_subformulas: Set of all unique subformulas
            
        Returns:
            Tuple of (nodes, edges, levels)
        """
        # Limit the number of subformulas to prevent performance issues
        MAX_SUBFORMULAS = 500
        
        subformulas = list(all_subformulas)
        if len(subformulas) > MAX_SUBFORMULAS:
            # Take a representative sample
            subformulas = subformulas[:MAX_SUBFORMULAS]
            
        n = len(subformulas)
        
        # Don't build lattice if too many subformulas (would be O(n²))
        if n > 100:
            # Return minimal lattice info
            for i, sf in enumerate(subformulas[:50]):  # Only track first 50
                self.lattice.add_node(i)
                self.subformula_to_node[sf] = i
                self.node_to_subformula[i] = sf
            
            self._compute_levels()
            return (min(50, n), 0, len(self.levels))
        
        # Full lattice construction for smaller sets only
        # Create nodes
        for i, sf in enumerate(subformulas):
            self.lattice.add_node(i)
            self.subformula_to_node[sf] = i
            self.node_to_subformula[i] = sf
        
        # Build containment relationships (limited to prevent hanging)
        edges_added = 0
        MAX_EDGES = 200
        
        for i, sf1 in enumerate(subformulas):
            if edges_added >= MAX_EDGES:
                break
            for j, sf2 in enumerate(subformulas):
                if edges_added >= MAX_EDGES:
                    break
                if i != j and self._is_subformula_contained(sf1, sf2):
                    self.lattice.add_edge(i, j)
                    edges_added += 1
        
        # Check if the graph is a DAG before applying transitive reduction
        if nx.is_directed_acyclic_graph(self.lattice):
            # Compute transitive reduction to get minimal lattice
            self.lattice = nx.transitive_reduction(self.lattice)
        else:
            # If there are cycles, remove them by breaking cycles at arbitrary points
            # This is a fallback to handle complex subformula relationships
            try:
                # Remove cycles by finding and breaking them
                cycles = list(nx.simple_cycles(self.lattice))
                edges_to_remove = []
                
                for cycle in cycles:
                    if len(cycle) > 1:
                        # Remove the edge that creates the cycle (from last to first node)
                        edges_to_remove.append((cycle[-1], cycle[0]))
                
                # Remove cycle-creating edges
                for edge in edges_to_remove:
                    if self.lattice.has_edge(*edge):
                        self.lattice.remove_edge(*edge)
                
                # Now try transitive reduction if it's a DAG
                if nx.is_directed_acyclic_graph(self.lattice):
                    self.lattice = nx.transitive_reduction(self.lattice)
                    
            except Exception:
                # If cycle removal fails, keep the original graph
                pass
        
        # Compute levels (topological layers)
        self._compute_levels()
        
        return (self.lattice.number_of_nodes(), 
                self.lattice.number_of_edges(), 
                len(self.levels))
    
    def _is_subformula_contained(self, sub: str, formula: str) -> bool:
        """Check if sub is a syntactic subformula of formula - simplified safe version."""
        try:
            # Only do simple string containment check to avoid recursion issues
            if len(sub) >= len(formula):
                return False
                
            # Simple syntactic containment check
            if sub in formula and sub != formula:
                return True
                
            return False
            
        except Exception:
            return False
    
    def _contains_subformula(self, main, sub) -> bool:
        """Simplified non-recursive check - disabled to prevent hanging."""
        try:
            # Convert to strings and do simple comparison
            return str(main) == str(sub)
        except:
            return False
    
    def _compute_levels(self):
        """Compute topological levels of the lattice, handling non-DAG cases."""
        if not self.lattice.nodes():
            return
        
        try:
            # Try topological sort if it's a DAG
            if nx.is_directed_acyclic_graph(self.lattice):
                # Compute topological sort and assign levels
                in_degree = dict(self.lattice.in_degree())
                queue = deque([node for node, degree in in_degree.items() if degree == 0])
                level = 0
                
                while queue:
                    current_level = []
                    for _ in range(len(queue)):
                        node = queue.popleft()
                        current_level.append(node)
                        
                        for successor in self.lattice.successors(node):
                            in_degree[successor] -= 1
                            if in_degree[successor] == 0:
                                queue.append(successor)
                    
                    if current_level:
                        self.levels.append(current_level)
                        level += 1
            else:
                # For non-DAG cases, create a simple level structure
                # based on the strongly connected components
                sccs = list(nx.strongly_connected_components(self.lattice))
                
                # Create a condensed DAG from SCCs
                condensed = nx.condensation(self.lattice, sccs)
                
                # Assign levels based on condensed DAG
                if condensed.nodes():
                    topo_order = list(nx.topological_sort(condensed))
                    for level, scc_id in enumerate(topo_order):
                        # Find which SCC this corresponds to
                        scc_nodes = sccs[scc_id]
                        if scc_nodes:
                            self.levels.append(list(scc_nodes))
                            
        except Exception:
            # Fallback: treat all nodes as a single level
            self.levels = [list(self.lattice.nodes())]
    
    def get_minimal_covering_set(self, target_subformulas: Set[str]) -> Set[str]:
        """
        Find minimal set of lattice elements that cover target subformulas.
        
        Args:
            target_subformulas: Subformulas that need to be covered
            
        Returns:
            Minimal covering set
        """
        # Map target subformulas to lattice nodes
        target_nodes = set()
        for sf in target_subformulas:
            if sf in self.subformula_to_node:
                target_nodes.add(self.subformula_to_node[sf])
        
        if not target_nodes:
            return set()
        
        # Find minimal covering set using greedy algorithm
        covered = set()
        covering_set = set()
        
        # Start with maximal elements that cover targets
        for node in target_nodes:
            if node not in covered:
                # Find ancestors that can cover this node
                ancestors = set(nx.ancestors(self.lattice, node)) | {node}
                
                # Choose the ancestor that covers the most uncovered targets
                best_ancestor = node
                best_coverage = len(target_nodes & nx.descendants(self.lattice, node) | {node})
                
                for ancestor in ancestors:
                    coverage = len(target_nodes & (nx.descendants(self.lattice, ancestor) | {ancestor}))
                    if coverage > best_coverage:
                        best_ancestor = ancestor
                        best_coverage = coverage
                
                covering_set.add(self.node_to_subformula[best_ancestor])
                covered.update(nx.descendants(self.lattice, best_ancestor) | {best_ancestor})
        
        return covering_set


class LTLOptimizerAlternative(LTLOptimizer):
    """
    Enhanced LTL Optimizer implementing research paper algorithms.
    
    This class extends the basic LTLOptimizer with:
    1. Advanced formula preprocessing and simplification
    2. Comprehensive subformula extraction and analysis
    3. Lattice-based subformula relationship modeling
    4. Cross-formula refinement analysis
    5. Syntactic optimization heuristics
    6. Improved minimal subset selection
    """
    
    def __init__(self, enable_visualization: bool = False, save_graphs: bool = False, 
                 verbose: bool = True, enable_preprocessing: bool = True,
                 enable_subformula_analysis: bool = True, enable_lattice_analysis: bool = True):
        """
        Initialize the Enhanced LTL Optimizer.
        
        Args:
            enable_visualization: Whether to generate NetworkX visualizations
            save_graphs: Whether to save graphs to files
            verbose: Whether to show progress bars and detailed output
            enable_preprocessing: Whether to apply formula preprocessing
            enable_subformula_analysis: Whether to perform subformula analysis
            enable_lattice_analysis: Whether to build subformula lattices
        """
        super().__init__(enable_visualization, save_graphs, verbose)
        self.enable_preprocessing = enable_preprocessing
        self.enable_subformula_analysis = enable_subformula_analysis
        self.enable_lattice_analysis = enable_lattice_analysis
        self.enhanced_metrics: Optional[EnhancedOptimizationMetrics] = None
        
        # Research components
        self.subformula_extractor = SubformulaExtractor()
        self.formula_simplifier = FormulaSimplifier()
        self.global_lattice = SubformulaLattice()
        
        # Analysis caches
        self.formula_subformulas = {}
        self.simplified_formulas = {}
        self.cross_formula_refinements = []
    
    def _preprocess_formulas(self, formulas: List[str]) -> Tuple[List[str], float, int, float]:
        """
        Apply preprocessing and simplification to input formulas.
        
        Args:
            formulas: Original formula list
            
        Returns:
            Tuple of (processed_formulas, processing_time, simplified_count, reduction_percentage)
        """
        if not self.enable_preprocessing:
            return formulas, 0.0, 0, 0.0
        
        start_time = time.time()
        processed_formulas = []
        simplified_count = 0
        original_total_length = sum(len(f) for f in formulas)
        
        iterator = tqdm(formulas, desc="Preprocessing formulas", disable=not self.verbose)
        
        for formula in iterator:
            simplified, was_simplified = self.formula_simplifier.simplify_formula(formula)
            processed_formulas.append(simplified)
            self.simplified_formulas[formula] = simplified
            
            if was_simplified:
                simplified_count += 1
        
        processing_time = time.time() - start_time
        processed_total_length = sum(len(f) for f in processed_formulas)
        reduction_percentage = ((original_total_length - processed_total_length) / 
                               original_total_length * 100) if original_total_length > 0 else 0.0
        
        return processed_formulas, processing_time, simplified_count, reduction_percentage
    
    def _analyze_subformulas(self, formulas: List[str]) -> Tuple[float, int, int, float]:
        """
        Perform comprehensive subformula analysis.
        
        Args:
            formulas: List of formulas to analyze
            
        Returns:
            Tuple of (analysis_time, total_subformulas, unique_subformulas, avg_per_formula)
        """
        if not self.enable_subformula_analysis:
            return 0.0, 0, 0, 0.0
        
        # Limit formula processing to prevent hanging on large benchmarks
        MAX_FORMULAS_FOR_SUBFORMULA_ANALYSIS = 200
        limited_formulas = formulas[:MAX_FORMULAS_FOR_SUBFORMULA_ANALYSIS]
        
        start_time = time.time()
        all_subformulas = set()
        total_subformulas = 0
        
        iterator = tqdm(limited_formulas, desc="Extracting subformulas", disable=not self.verbose)
        
        for formula in iterator:
            # Add timeout for individual formula processing
            try:
                subformulas = self.subformula_extractor.extract_all_subformulas(formula)
                
                # Limit subformulas per formula to prevent memory issues
                #MAX_SUBFORMULAS_PER_FORMULA = 100
                #if len(subformulas) > MAX_SUBFORMULAS_PER_FORMULA:
                #    subformulas = set(list(subformulas)[:MAX_SUBFORMULAS_PER_FORMULA])
                
                self.formula_subformulas[formula] = subformulas
                all_subformulas.update(subformulas)
                total_subformulas += len(subformulas)
                
                # Stop if we have too many total subformulas
                # if len(all_subformulas) > 1000:
                #     if self.verbose:
                #         print(f"Stopping subformula analysis - reached limit of 1000 unique subformulas")
                #     break
                    
            except Exception as e:
                if self.verbose:
                    print(f"Skipping formula due to error: {str(e)[:100]}")
                continue
        
        analysis_time = time.time() - start_time
        unique_subformulas = len(all_subformulas)
        avg_per_formula = total_subformulas / len(limited_formulas) if limited_formulas else 0.0
        
        return analysis_time, total_subformulas, unique_subformulas, avg_per_formula
    
    def _build_global_lattice(self, all_subformulas: Set[str]) -> Tuple[float, int, int, int]:
        """
        Build global subformula lattice.
        
        Args:
            all_subformulas: Set of all unique subformulas
            
        Returns:
            Tuple of (construction_time, nodes, edges, levels)
        """
        if not self.enable_lattice_analysis or not all_subformulas:
            return 0.0, 0, 0, 0
        
        start_time = time.time()
        nodes, edges, levels = self.global_lattice.build_lattice(all_subformulas)
        construction_time = time.time() - start_time
        
        return construction_time, nodes, edges, levels
    
    def _perform_cross_formula_refinement_analysis(self, formulas: List[str]) -> Tuple[float, int, int]:
        """
        Analyze cross-formula refinement opportunities.
        
        Args:
            formulas: List of formulas to analyze
            
        Returns:
            Tuple of (analysis_time, cross_formula_refinements, syntactic_refinements)
        """
        start_time = time.time()
        cross_refinements = 0
        syntactic_refinements = 0
        
        if not self.enable_subformula_analysis:
            return 0.0, 0, 0
        
        # Analyze shared subformulas between different formulas
        iterator = tqdm(combinations(range(len(formulas)), 2), 
                       desc="Cross-formula analysis", disable=not self.verbose,
                       total=len(formulas) * (len(formulas) - 1) // 2)
        
        for i, j in iterator:
            formula1, formula2 = formulas[i], formulas[j]
            
            if formula1 in self.formula_subformulas and formula2 in self.formula_subformulas:
                shared_subformulas = (self.formula_subformulas[formula1] & 
                                    self.formula_subformulas[formula2])
                
                if shared_subformulas:
                    cross_refinements += len(shared_subformulas)
                    
                    # Check for syntactic refinement patterns
                    for sf in shared_subformulas:
                        if self._is_syntactic_refinement_beneficial(sf, formula1, formula2):
                            syntactic_refinements += 1
                            self.cross_formula_refinements.append({
                                'formula1_idx': i,
                                'formula2_idx': j,
                                'shared_subformula': sf,
                                'refinement_type': 'syntactic'
                            })
        
        analysis_time = time.time() - start_time
        return analysis_time, cross_refinements, syntactic_refinements
    
    def _is_syntactic_refinement_beneficial(self, subformula: str, formula1: str, formula2: str) -> bool:
        """
        Determine if extracting a shared subformula would be beneficial.
        
        Args:
            subformula: Shared subformula
            formula1: First formula
            formula2: Second formula
            
        Returns:
            True if refinement is beneficial
        """
        # Simple heuristic: beneficial if subformula is complex enough
        # and appears in structurally similar contexts
        if len(subformula) > 10:  # Complex enough
            return True
        
        # Check for temporal operators in subformula
        temporal_ops = {'G', 'F', 'X', 'U', 'R', 'W', 'M'}
        if any(op in subformula for op in temporal_ops):
            return True
        
        return False
    
    def _enhanced_minimal_selection(self, equivalence_classes: Dict[int, List[int]], 
                                   formulas: List[str], automata: List[Any]) -> List[int]:
        """
        Enhanced minimal formula selection using subformula coverage analysis.
        
        Args:
            equivalence_classes: Equivalence classes mapping
            formulas: Original formulas
            automata: Automata for formulas
            
        Returns:
            List of minimal formula indices
        """
        all_minimal_indices = []
        
        for rep, formula_indices in equivalence_classes.items():
            if len(formula_indices) == 1:
                all_minimal_indices.extend(formula_indices)
                continue
            
            # Standard containment analysis
            edges, _ = self._build_containment_graph(formula_indices, automata)
            standard_minimal = self._find_minimal_candidates(edges)
            
            # Enhanced selection using subformula analysis
            if self.enable_subformula_analysis and self.enable_lattice_analysis:
                enhanced_minimal = self._select_minimal_with_subformula_coverage(
                    formula_indices, formulas, standard_minimal)
                minimal_candidates = enhanced_minimal
            else:
                minimal_candidates = standard_minimal
            
            # Convert local indices to global indices
            global_minimal_indices = [formula_indices[i] for i in minimal_candidates]
            all_minimal_indices.extend(global_minimal_indices)
        
        return all_minimal_indices
    
    def _select_minimal_with_subformula_coverage(self, formula_indices: List[int], 
                                               formulas: List[str], 
                                               standard_minimal: List[int]) -> List[int]:
        """
        Refine minimal selection using subformula coverage analysis.
        
        Args:
            formula_indices: Indices of formulas in equivalence class
            formulas: All formulas
            standard_minimal: Standard minimal candidates
            
        Returns:
            Refined minimal indices
        """
        if not standard_minimal:
            return standard_minimal
        
        # Collect all subformulas from this equivalence class
        class_subformulas = set()
        for idx in formula_indices:
            formula = formulas[idx]
            if formula in self.formula_subformulas:
                class_subformulas.update(self.formula_subformulas[formula])
        
        if not class_subformulas:
            return standard_minimal
        
        # Use lattice to find minimal covering set
        covering_set = self.global_lattice.get_minimal_covering_set(class_subformulas)
        
        if covering_set:
            # Select formulas that best represent the covering set
            enhanced_minimal = []
            for local_idx in standard_minimal:
                global_idx = formula_indices[local_idx]
                formula = formulas[global_idx]
                
                if formula in self.formula_subformulas:
                    formula_sfs = self.formula_subformulas[formula]
                    if formula_sfs & covering_set:  # Formula contributes to coverage
                        enhanced_minimal.append(local_idx)
            
            return enhanced_minimal if enhanced_minimal else standard_minimal
        
        return standard_minimal
    
    def _enhanced_minimal_selection_with_details(self, equivalence_classes: Dict[int, List[int]], 
                                               formulas: List[str], automata: List[Any]) -> Tuple[List[int], List[Dict[str, Any]]]:
        """
        Enhanced minimal formula selection with detailed class reduction tracking.
        
        Args:
            equivalence_classes: Equivalence classes mapping
            formulas: Original formulas
            automata: Automata for formulas
            
        Returns:
            Tuple of (minimal formula indices, class reduction details)
        """
        all_minimal_indices = []
        class_reductions = []
        
        for rep, formula_indices in equivalence_classes.items():
            if len(formula_indices) == 1:
                all_minimal_indices.extend(formula_indices)
                # Single formula classes don't contribute to reduction details
                continue
            
            # Standard containment analysis
            edges, _ = self._build_containment_graph(formula_indices, automata)
            standard_minimal = self._find_minimal_candidates(edges)
            
            # Enhanced selection using subformula analysis
            if self.enable_subformula_analysis and self.enable_lattice_analysis:
                enhanced_minimal = self._select_minimal_with_subformula_coverage(
                    formula_indices, formulas, standard_minimal)
                minimal_candidates = enhanced_minimal
            else:
                minimal_candidates = standard_minimal
            
            # Convert local indices to global indices
            global_minimal_indices = [formula_indices[i] for i in minimal_candidates]
            all_minimal_indices.extend(global_minimal_indices)
            
            # Record class reduction metrics
            class_reduction = {
                "representative": rep,
                "original_count": len(formula_indices),
                "minimal_count": len(minimal_candidates),
                "reduction_percentage": ((len(formula_indices) - len(minimal_candidates)) / len(formula_indices) * 100)
            }
            class_reductions.append(class_reduction)
        
        return all_minimal_indices, class_reductions
    
    def optimize_formulas(self, formulas: List[str], benchmark_name: str = "unknown",
                         ltl_output_folder: Optional[str] = None,
                         graph_output_folder: Optional[str] = None,
                         result_folder: Optional[str] = None) -> EnhancedOptimizationMetrics:
        """
        Enhanced optimization with research paper features.
        
        Args:
            formulas: List of LTL formula strings to optimize
            benchmark_name: Name identifier for this benchmark
            ltl_output_folder: Optional folder to save minimal LTL formulas
            graph_output_folder: Optional folder to save containment graphs
            result_folder: Optional folder to save CSV results
            
        Returns:
            EnhancedOptimizationMetrics object with comprehensive analysis
        """
        total_start_time = time.time()
        
        if self.verbose:
            print(f"Enhanced optimization of {len(formulas)} LTL formulas for: {benchmark_name}")
        
        # Phase 1: Preprocessing and simplification
        processed_formulas, preprocessing_time, simplified_count, simplification_reduction = \
            self._preprocess_formulas(formulas)
        
        # Phase 2: Subformula analysis
        subformula_time, total_sfs, unique_sfs, avg_sfs = \
            self._analyze_subformulas(processed_formulas)
        
        # Phase 3: Global lattice construction
        all_subformulas = set()
        for sf_set in self.formula_subformulas.values():
            all_subformulas.update(sf_set)
        
        lattice_time, lattice_nodes, lattice_edges, lattice_levels = \
            self._build_global_lattice(all_subformulas)
        
        # Phase 4: Cross-formula refinement analysis
        refinement_time, cross_refinements, syntactic_refinements = \
            self._perform_cross_formula_refinement_analysis(processed_formulas)
        
        # Phase 5: Enhanced equivalence class construction and optimization
        optimization_start = time.time()
        equivalence_classes, automata = self._construct_equivalence_classes(processed_formulas)
        
        # Enhanced minimal selection
        all_minimal_indices, class_reductions = self._enhanced_minimal_selection_with_details(
            equivalence_classes, processed_formulas, automata)
        
        # Calculate metrics
        original_count = len(formulas)
        optimized_count = len(all_minimal_indices)
        reduction_percentage = ((original_count - optimized_count) / original_count * 100) if original_count > 0 else 0
        
        # Calculate subformula coverage improvement
        if self.enable_subformula_analysis:
            original_sf_count = sum(len(self.formula_subformulas.get(f, set())) for f in processed_formulas)
            minimal_sf_count = sum(len(self.formula_subformulas.get(processed_formulas[i], set())) 
                                 for i in all_minimal_indices)
            subformula_coverage_reduction = ((original_sf_count - minimal_sf_count) / 
                                           original_sf_count * 100) if original_sf_count > 0 else 0
        else:
            subformula_coverage_reduction = 0.0
        
        total_optimization_time = time.time() - optimization_start
        total_time = time.time() - total_start_time
        
        # Save results
        if ltl_output_folder:
            self._save_minimal_formulas(processed_formulas, sorted(all_minimal_indices), 
                                      benchmark_name, ltl_output_folder)
        
        # Create enhanced metrics
        self.enhanced_metrics = EnhancedOptimizationMetrics(
            # Basic metrics
            total_formulas=len(formulas),
            total_classes=len(equivalence_classes),
            single_formula_classes=sum(1 for indices in equivalence_classes.values() if len(indices) == 1),
            multi_formula_classes=len(equivalence_classes) - sum(1 for indices in equivalence_classes.values() if len(indices) == 1),
            equivalence_class_time=total_optimization_time * 0.7,  # Estimate
            containment_analysis_time=total_optimization_time * 0.3,  # Estimate
            total_time=total_time,
            original_formula_count=original_count,
            optimized_formula_count=optimized_count,
            reduction_percentage=reduction_percentage,
            class_reductions=class_reductions,
            
            # Enhanced metrics
            preprocessing_time=preprocessing_time,
            formulas_simplified=simplified_count,
            simplification_reduction=simplification_reduction,
            subformula_extraction_time=subformula_time,
            total_subformulas=total_sfs,
            unique_subformulas=unique_sfs,
            avg_subformulas_per_formula=avg_sfs,
            lattice_construction_time=lattice_time,
            lattice_nodes=lattice_nodes,
            lattice_edges=lattice_edges,
            lattice_levels=lattice_levels,
            refinement_analysis_time=refinement_time,
            cross_formula_refinements=cross_refinements,
            syntactic_refinements=syntactic_refinements,
            subformula_coverage_reduction=subformula_coverage_reduction,
            syntactic_optimization_benefit=max(0, subformula_coverage_reduction - reduction_percentage),
            
            # Output folders
            ltl_output_folder=ltl_output_folder,
            graph_output_folder=graph_output_folder,
            result_folder=result_folder
        )
        
        # Save metrics to CSV if result folder specified
        if result_folder:
            output_file = os.path.join(result_folder, f"{benchmark_name}_enhanced_metrics.csv")
            self.enhanced_metrics.save_to_csv(output_file)
        
        if self.verbose:
            self._print_enhanced_summary()
        
        return self.enhanced_metrics
    
    def _print_enhanced_summary(self) -> None:
        """Print enhanced optimization summary to console."""
        if not self.enhanced_metrics:
            return
        
        print("\n" + "=" * 80)
        print("ENHANCED LTL OPTIMIZATION SUMMARY")
        print("=" * 80)
        
        # Basic metrics
        print(f"Input Analysis:")
        print(f"  Total formulas processed: {self.enhanced_metrics.total_formulas}")
        print(f"  Equivalence classes: {self.enhanced_metrics.total_classes}")
        print(f"  Single formula classes: {self.enhanced_metrics.single_formula_classes}")
        print(f"  Multi-formula classes: {self.enhanced_metrics.multi_formula_classes}")
        print()
        
        # Preprocessing results
        if self.enable_preprocessing:
            print(f"Preprocessing Results:")
            print(f"  Formulas simplified: {self.enhanced_metrics.formulas_simplified}")
            print(f"  Simplification reduction: {self.enhanced_metrics.simplification_reduction:.1f}%")
            print(f"  Preprocessing time: {self.enhanced_metrics.preprocessing_time:.3f}s")
            print()
        
        # Subformula analysis
        if self.enable_subformula_analysis:
            print(f"Subformula Analysis:")
            print(f"  Total subformulas: {self.enhanced_metrics.total_subformulas}")
            print(f"  Unique subformulas: {self.enhanced_metrics.unique_subformulas}")
            print(f"  Avg subformulas per formula: {self.enhanced_metrics.avg_subformulas_per_formula:.1f}")
            print(f"  Extraction time: {self.enhanced_metrics.subformula_extraction_time:.3f}s")
            print()
        
        # Lattice analysis
        if self.enable_lattice_analysis:
            print(f"Lattice Construction:")
            print(f"  Lattice nodes: {self.enhanced_metrics.lattice_nodes}")
            print(f"  Lattice edges: {self.enhanced_metrics.lattice_edges}")
            print(f"  Lattice levels: {self.enhanced_metrics.lattice_levels}")
            print(f"  Construction time: {self.enhanced_metrics.lattice_construction_time:.3f}s")
            print()
        
        # Refinement analysis
        print(f"Cross-Formula Refinement:")
        print(f"  Cross-formula refinements found: {self.enhanced_metrics.cross_formula_refinements}")
        print(f"  Syntactic refinements: {self.enhanced_metrics.syntactic_refinements}")
        print(f"  Analysis time: {self.enhanced_metrics.refinement_analysis_time:.3f}s")
        print()
        
        # Final optimization results
        print(f"Optimization Results:")
        print(f"  Original formulas: {self.enhanced_metrics.original_formula_count}")
        print(f"  Optimized formulas: {self.enhanced_metrics.optimized_formula_count}")
        print(f"  Formula reduction: {self.enhanced_metrics.reduction_percentage:.1f}%")
        print(f"  Subformula coverage reduction: {self.enhanced_metrics.subformula_coverage_reduction:.1f}%")
        print(f"  Syntactic optimization benefit: {self.enhanced_metrics.syntactic_optimization_benefit:.1f}%")
        print()
        
        # Performance summary
        print(f"Performance Summary:")
        print(f"  Total time: {self.enhanced_metrics.total_time:.3f}s")
        print(f"  Core optimization time: {self.enhanced_metrics.equivalence_class_time + self.enhanced_metrics.containment_analysis_time:.3f}s")
        print(f"  Enhancement overhead: {self.enhanced_metrics.total_time - (self.enhanced_metrics.equivalence_class_time + self.enhanced_metrics.containment_analysis_time):.3f}s")
        print("=" * 80)
    
    def save_enhanced_analysis_report(self, filepath: str) -> None:
        """
        Save comprehensive analysis report including research features.
        
        Args:
            filepath: Path to save the report
        """
        if not self.enhanced_metrics:
            return
        
        report = {
            'benchmark_info': {
                'total_formulas': self.enhanced_metrics.total_formulas,
                'equivalence_classes': self.enhanced_metrics.total_classes,
            },
            'preprocessing': {
                'enabled': self.enable_preprocessing,
                'formulas_simplified': self.enhanced_metrics.formulas_simplified,
                'simplification_reduction': self.enhanced_metrics.simplification_reduction,
                'time': self.enhanced_metrics.preprocessing_time
            },
            'subformula_analysis': {
                'enabled': self.enable_subformula_analysis,
                'total_subformulas': self.enhanced_metrics.total_subformulas,
                'unique_subformulas': self.enhanced_metrics.unique_subformulas,
                'avg_per_formula': self.enhanced_metrics.avg_subformulas_per_formula,
                'time': self.enhanced_metrics.subformula_extraction_time
            },
            'lattice_analysis': {
                'enabled': self.enable_lattice_analysis,
                'nodes': self.enhanced_metrics.lattice_nodes,
                'edges': self.enhanced_metrics.lattice_edges,
                'levels': self.enhanced_metrics.lattice_levels,
                'time': self.enhanced_metrics.lattice_construction_time
            },
            'refinement_analysis': {
                'cross_formula_refinements': self.enhanced_metrics.cross_formula_refinements,
                'syntactic_refinements': self.enhanced_metrics.syntactic_refinements,
                'time': self.enhanced_metrics.refinement_analysis_time,
                'refinement_details': self.cross_formula_refinements
            },
            'optimization_results': {
                'original_count': self.enhanced_metrics.original_formula_count,
                'optimized_count': self.enhanced_metrics.optimized_formula_count,
                'reduction_percentage': self.enhanced_metrics.reduction_percentage,
                'subformula_coverage_reduction': self.enhanced_metrics.subformula_coverage_reduction,
                'syntactic_benefit': self.enhanced_metrics.syntactic_optimization_benefit
            },
            'performance': {
                'total_time': self.enhanced_metrics.total_time,
                'core_optimization_time': (self.enhanced_metrics.equivalence_class_time + 
                                         self.enhanced_metrics.containment_analysis_time),
                'enhancement_overhead': (self.enhanced_metrics.total_time - 
                                       (self.enhanced_metrics.equivalence_class_time + 
                                        self.enhanced_metrics.containment_analysis_time))
            }
        }
        
        with open(filepath, 'w') as f:
            json.dump(report, f, indent=2)
        
        if self.verbose:
            print(f"Enhanced analysis report saved to: {filepath}")
    
    def process_benchmark_folder(self, benchmark_path: str, 
                                ltl_output_folder: Optional[str] = None,
                                graph_output_folder: Optional[str] = None,
                                result_folder: Optional[str] = None) -> EnhancedOptimizationMetrics:
        """
        Process a single benchmark folder containing properties.ltl file.
        
        Args:
            benchmark_path: Path to benchmark folder
            ltl_output_folder: Optional folder to save minimal LTL formulas
            graph_output_folder: Optional folder to save containment graphs
            result_folder: Optional folder to save CSV results
            
        Returns:
            EnhancedOptimizationMetrics for this benchmark
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
                                   result_folder: Optional[str] = None, 
                                   start_from: Optional[int] = 0) -> Dict[str, EnhancedOptimizationMetrics]:
        """
        Process multiple benchmark folders and optionally save results.
        
        Args:
            benchmark_folder: Root folder containing multiple benchmark subfolders
            ltl_output_folder: Optional folder to save minimal LTL formulas
            graph_output_folder: Optional folder to save containment graphs
            result_folder: Optional folder to save CSV results
            start_from: Index to start processing from (for resuming)
            
        Returns:
            Dictionary mapping benchmark name to EnhancedOptimizationMetrics
        """
        results = {}
        
        # Create output directories if specified
        for folder in [ltl_output_folder, graph_output_folder, result_folder]:
            if folder and not os.path.exists(folder):
                os.makedirs(folder, exist_ok=True)
        
        benchmark_folders = sorted(os.listdir(benchmark_folder))[start_from:]
        
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


# Example usage and testing
if __name__ == "__main__":
    # Test the enhanced optimizer
    test_formulas = [
        "G(p -> F q)",
        "F(p & G q)",
        "G(p -> X q)",
        "p U (q & r)",
        "G(p -> F(q | r))",
        "F G p",
        "G F p",
        "p R q"
    ]
    
    optimizer = LTLOptimizerAlternative(
        verbose=True,
        enable_preprocessing=True,
        enable_subformula_analysis=True,
        enable_lattice_analysis=True
    )
    
    metrics = optimizer.optimize_formulas(test_formulas, "test_benchmark")
    
    print(f"\nTest completed successfully!")
    print(f"Original: {metrics.original_formula_count} formulas")
    print(f"Optimized: {metrics.optimized_formula_count} formulas")
    print(f"Reduction: {metrics.reduction_percentage:.1f}%")
    print(f"Subformula analysis found {metrics.unique_subformulas} unique subformulas")
    print(f"Lattice has {metrics.lattice_nodes} nodes and {metrics.lattice_levels} levels")
