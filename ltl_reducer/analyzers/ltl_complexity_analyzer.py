"""
LTL Formula Complexity Analysis Tool

This module provides comprehensive complexity metrics for LTL formulas
and analyzes the relationship between complexity and processing time.
"""

import spot
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os
import re
from typing import Dict, List, Tuple, Optional
from dataclasses import dataclass
from pathlib import Path


@dataclass
class FormulaComplexity:
    """Comprehensive complexity metrics for an LTL formula."""
    
    # Basic structural metrics
    length: int                    # Total character count
    operator_count: int           # Number of temporal and logical operators
    atomic_prop_count: int        # Number of unique atomic propositions
    nesting_depth: int           # Maximum nesting depth of operators
    
    # Temporal operator metrics
    temporal_operators: int       # Count of temporal operators (G, F, X, U, R)
    future_operators: int        # Count of F (Finally) operators
    global_operators: int        # Count of G (Globally) operators
    next_operators: int          # Count of X (Next) operators
    until_operators: int         # Count of U (Until) operators
    release_operators: int       # Count of R (Release) operators
    
    # Logical operator metrics
    logical_operators: int        # Count of logical operators (&, |, !, ->)
    conjunction_count: int        # Count of & operators
    disjunction_count: int        # Count of | operators
    negation_count: int          # Count of ! operators
    implication_count: int       # Count of -> operators
    
    # Automata-based complexity
    automaton_states: int        # Number of states in the automaton
    automaton_edges: int         # Number of edges in the automaton
    
    # Derived complexity metrics
    structural_complexity: float  # Weighted combination of structural features
    temporal_complexity: float   # Temporal operator complexity score
    automaton_complexity: float  # Automaton-based complexity score
    overall_complexity: float    # Combined complexity score


class LTLComplexityAnalyzer:
    """
    Analyzer for LTL formula complexity and its relationship with processing time.
    """
    
    def __init__(self, save_plots: bool = True, show_plots: bool = False, 
                 output_folder: str = "complexity_analysis"):
        """
        Initialize the complexity analyzer.
        
        Args:
            save_plots: Whether to save plots to files
            show_plots: Whether to display plots interactively
            output_folder: Folder to save analysis results
        """
        self.save_plots = save_plots
        self.show_plots = show_plots
        self.output_folder = output_folder
        
        if self.save_plots and not os.path.exists(self.output_folder):
            os.makedirs(self.output_folder)
        
        # Set style for publication-quality plots
        plt.style.use('default')
        plt.rcParams.update({
            'font.size': 10,
            'axes.titlesize': 12,
            'axes.labelsize': 11,
            'xtick.labelsize': 9,
            'ytick.labelsize': 9,
            'legend.fontsize': 9,
            'figure.titlesize': 14
        })
    
    def analyze_formula_complexity(self, formula_str: str) -> FormulaComplexity:
        """
        Analyze the complexity of a single LTL formula.
        
        Args:
            formula_str: LTL formula string
            
        Returns:
            FormulaComplexity object with all metrics
        """
        try:
            # Parse formula with Spot
            formula = spot.formula(formula_str)
            
            # Basic metrics
            length = len(formula_str)
            atomic_props = spot.atomic_prop_collect(formula)
            atomic_prop_count = len(atomic_props)
            
            # Operator counting using regex patterns
            temporal_patterns = {
                'G': r'\bG\b',
                'F': r'\bF\b', 
                'X': r'\bX\b',
                'U': r'\bU\b',
                'R': r'\bR\b'
            }
            
            logical_patterns = {
                '&': r'&',
                '|': r'\|',
                '!': r'!',
                '->': r'->'
            }
            
            # Count temporal operators
            temporal_counts = {}
            for op, pattern in temporal_patterns.items():
                temporal_counts[op] = len(re.findall(pattern, formula_str))
            
            temporal_operators = sum(temporal_counts.values())
            
            # Count logical operators
            logical_counts = {}
            for op, pattern in logical_patterns.items():
                logical_counts[op] = len(re.findall(pattern, formula_str))
            
            logical_operators = sum(logical_counts.values())
            operator_count = temporal_operators + logical_operators
            
            # Calculate nesting depth
            nesting_depth = self._calculate_nesting_depth(formula_str)
            
            # Automaton metrics
            try:
                automaton = spot.translate(formula, "BA")
                automaton.merge_edges()
                automaton = automaton.postprocess()
                
                automaton_states = automaton.num_states()
                automaton_edges = automaton.num_edges()
            except:
                automaton_states = 0
                automaton_edges = 0
            
            # Calculate derived complexity metrics
            structural_complexity = self._calculate_structural_complexity(
                length, operator_count, atomic_prop_count, nesting_depth
            )
            
            temporal_complexity = self._calculate_temporal_complexity(
                temporal_counts, nesting_depth
            )
            
            automaton_complexity = self._calculate_automaton_complexity(
                automaton_states, automaton_edges
            )
            
            overall_complexity = self._calculate_overall_complexity(
                structural_complexity, temporal_complexity, automaton_complexity
            )
            
            return FormulaComplexity(
                length=length,
                operator_count=operator_count,
                atomic_prop_count=atomic_prop_count,
                nesting_depth=nesting_depth,
                temporal_operators=temporal_operators,
                future_operators=temporal_counts.get('F', 0),
                global_operators=temporal_counts.get('G', 0),
                next_operators=temporal_counts.get('X', 0),
                until_operators=temporal_counts.get('U', 0),
                release_operators=temporal_counts.get('R', 0),
                logical_operators=logical_operators,
                conjunction_count=logical_counts.get('&', 0),
                disjunction_count=logical_counts.get('|', 0),
                negation_count=logical_counts.get('!', 0),
                implication_count=logical_counts.get('->', 0),
                automaton_states=automaton_states,
                automaton_edges=automaton_edges,
                structural_complexity=structural_complexity,
                temporal_complexity=temporal_complexity,
                automaton_complexity=automaton_complexity,
                overall_complexity=overall_complexity
            )
            
        except Exception as e:
            print(f"Error analyzing formula '{formula_str}': {e}")
            # Return default complexity for error cases
            return FormulaComplexity(
                length=len(formula_str), operator_count=0, atomic_prop_count=0,
                nesting_depth=0, temporal_operators=0, future_operators=0,
                global_operators=0, next_operators=0, until_operators=0,
                release_operators=0, logical_operators=0, conjunction_count=0,
                disjunction_count=0, negation_count=0, implication_count=0,
                automaton_states=0, automaton_edges=0, structural_complexity=0.0,
                temporal_complexity=0.0, automaton_complexity=0.0, overall_complexity=0.0
            )
    
    def _calculate_nesting_depth(self, formula_str: str) -> int:
        """Calculate the maximum nesting depth of parentheses."""
        max_depth = 0
        current_depth = 0
        
        for char in formula_str:
            if char == '(':
                current_depth += 1
                max_depth = max(max_depth, current_depth)
            elif char == ')':
                current_depth -= 1
        
        return max_depth
    
    def _calculate_structural_complexity(self, length: int, operator_count: int, 
                                       atomic_prop_count: int, nesting_depth: int) -> float:
        """Calculate structural complexity score."""
        # Weighted combination of structural features
        return (
            0.1 * length +
            2.0 * operator_count +
            1.0 * atomic_prop_count +
            3.0 * nesting_depth
        )
    
    def _calculate_temporal_complexity(self, temporal_counts: Dict[str, int], 
                                     nesting_depth: int) -> float:
        """Calculate temporal operator complexity score."""
        # Weight different temporal operators by their typical complexity
        weights = {'G': 3.0, 'F': 2.0, 'X': 1.0, 'U': 4.0, 'R': 4.0}
        
        weighted_sum = sum(weights.get(op, 1.0) * count 
                          for op, count in temporal_counts.items())
        
        return weighted_sum * (1.0 + 0.5 * nesting_depth)
    
    def _calculate_automaton_complexity(self, states: int, edges: int) -> float:
        """Calculate automaton-based complexity score."""
        if states == 0:
            return 0.0
        return states + 0.1 * edges
    
    def _calculate_overall_complexity(self, structural: float, temporal: float, 
                                    automaton: float) -> float:
        """Calculate overall complexity as weighted combination."""
        return 0.3 * structural + 0.4 * temporal + 0.3 * automaton
    
    def load_benchmark_formulas(self, benchmark_folder: str) -> Dict[str, List[str]]:
        """
        Load formulas from benchmark folders.
        
        Args:
            benchmark_folder: Root folder containing benchmark subfolders
            
        Returns:
            Dictionary mapping benchmark name to list of formulas
        """
        benchmark_formulas = {}
        
        if not os.path.exists(benchmark_folder):
            print(f"Benchmark folder not found: {benchmark_folder}")
            return benchmark_formulas
        
        for folder_name in sorted(os.listdir(benchmark_folder)):
            folder_path = os.path.join(benchmark_folder, folder_name)
            
            if not os.path.isdir(folder_path):
                continue
            
            properties_file = os.path.join(folder_path, "properties.ltl")
            
            if os.path.exists(properties_file):
                try:
                    with open(properties_file, 'r') as f:
                        formulas = [line.strip() for line in f.readlines() if line.strip()]
                    benchmark_formulas[folder_name] = formulas
                    print(f"Loaded {len(formulas)} formulas from {folder_name}")
                except Exception as e:
                    print(f"Error loading {folder_name}: {e}")
        
        return benchmark_formulas
    
    def analyze_benchmark_complexity(self, benchmark_folder: str, 
                                   timing_results_folder: str = "optimized_results") -> pd.DataFrame:
        """
        Analyze complexity of all benchmarks and correlate with timing data.
        
        Args:
            benchmark_folder: Folder containing benchmark subfolders
            timing_results_folder: Folder containing timing results
            
        Returns:
            DataFrame with complexity and timing analysis
        """
        print(f"Analyzing complexity for benchmarks in: {benchmark_folder}")
        
        # Load benchmark formulas
        benchmark_formulas = self.load_benchmark_formulas(benchmark_folder)
        
        if not benchmark_formulas:
            raise ValueError("No benchmark formulas found to analyze")
        
        # Load timing data if available
        timing_data = self._load_timing_data(timing_results_folder)
        
        analysis_results = []
        
        for benchmark_name, formulas in benchmark_formulas.items():
            print(f"Analyzing complexity for {benchmark_name} ({len(formulas)} formulas)...")
            
            # Analyze each formula
            formula_complexities = []
            for formula in formulas:
                complexity = self.analyze_formula_complexity(formula)
                formula_complexities.append(complexity)
            
            # Calculate aggregate metrics for this benchmark
            if formula_complexities:
                avg_complexity = self._calculate_average_complexity(formula_complexities)
                max_complexity = self._calculate_max_complexity(formula_complexities)
                
                # Get timing data for this benchmark if available
                timing_info = timing_data.get(benchmark_name, {})
                
                result = {
                    'benchmark': benchmark_name,
                    'formula_count': len(formulas),
                    'avg_length': np.mean([c.length for c in formula_complexities]),
                    'avg_operator_count': np.mean([c.operator_count for c in formula_complexities]),
                    'avg_atomic_props': np.mean([c.atomic_prop_count for c in formula_complexities]),
                    'avg_nesting_depth': np.mean([c.nesting_depth for c in formula_complexities]),
                    'avg_temporal_ops': np.mean([c.temporal_operators for c in formula_complexities]),
                    'avg_automaton_states': np.mean([c.automaton_states for c in formula_complexities]),
                    'avg_structural_complexity': avg_complexity.structural_complexity,
                    'avg_temporal_complexity': avg_complexity.temporal_complexity,
                    'avg_automaton_complexity': avg_complexity.automaton_complexity,
                    'avg_overall_complexity': avg_complexity.overall_complexity,
                    'max_overall_complexity': max_complexity.overall_complexity,
                    'complexity_variance': np.var([c.overall_complexity for c in formula_complexities]),
                    
                    # Timing information
                    'total_time': timing_info.get('total_time', 0.0),
                    'time_per_formula': timing_info.get('time_per_formula', 0.0),
                    'equivalence_class_time': timing_info.get('equivalence_class_time', 0.0),
                    'containment_analysis_time': timing_info.get('containment_analysis_time', 0.0),
                }
                
                analysis_results.append(result)
        
        df = pd.DataFrame(analysis_results)
        
        # Save detailed analysis
        if self.save_plots:
            output_file = os.path.join(self.output_folder, 'complexity_analysis.csv')
            df.to_csv(output_file, index=False)
            print(f"Complexity analysis saved to: {output_file}")
        
        return df
    
    def _load_timing_data(self, timing_results_folder: str) -> Dict[str, Dict]:
        """Load timing data from optimization results."""
        timing_data = {}
        
        # Try to load from benchmark summary first
        summary_path = os.path.join(timing_results_folder, "benchmark_summary.csv")
        if os.path.exists(summary_path):
            summary_df = pd.read_csv(summary_path)
            for _, row in summary_df.iterrows():
                timing_data[row['Benchmark']] = {
                    'total_time': row.get('Total_Time', 0.0),
                    'time_per_formula': row.get('Time_Per_Formula', 0.0),
                    'equivalence_class_time': row.get('Equivalence_Class_Time', 0.0),
                    'containment_analysis_time': row.get('Containment_Analysis_Time', 0.0),
                }
        
        return timing_data
    
    def _calculate_average_complexity(self, complexities: List[FormulaComplexity]) -> FormulaComplexity:
        """Calculate average complexity metrics."""
        if not complexities:
            return FormulaComplexity(
                length=0, operator_count=0, atomic_prop_count=0, nesting_depth=0,
                temporal_operators=0, future_operators=0, global_operators=0,
                next_operators=0, until_operators=0, release_operators=0,
                logical_operators=0, conjunction_count=0, disjunction_count=0,
                negation_count=0, implication_count=0, automaton_states=0,
                automaton_edges=0, structural_complexity=0.0, temporal_complexity=0.0,
                automaton_complexity=0.0, overall_complexity=0.0
            )
        
        return FormulaComplexity(
            length=int(np.mean([c.length for c in complexities])),
            operator_count=int(np.mean([c.operator_count for c in complexities])),
            atomic_prop_count=int(np.mean([c.atomic_prop_count for c in complexities])),
            nesting_depth=int(np.mean([c.nesting_depth for c in complexities])),
            temporal_operators=int(np.mean([c.temporal_operators for c in complexities])),
            future_operators=int(np.mean([c.future_operators for c in complexities])),
            global_operators=int(np.mean([c.global_operators for c in complexities])),
            next_operators=int(np.mean([c.next_operators for c in complexities])),
            until_operators=int(np.mean([c.until_operators for c in complexities])),
            release_operators=int(np.mean([c.release_operators for c in complexities])),
            logical_operators=int(np.mean([c.logical_operators for c in complexities])),
            conjunction_count=int(np.mean([c.conjunction_count for c in complexities])),
            disjunction_count=int(np.mean([c.disjunction_count for c in complexities])),
            negation_count=int(np.mean([c.negation_count for c in complexities])),
            implication_count=int(np.mean([c.implication_count for c in complexities])),
            automaton_states=int(np.mean([c.automaton_states for c in complexities])),
            automaton_edges=int(np.mean([c.automaton_edges for c in complexities])),
            structural_complexity=np.mean([c.structural_complexity for c in complexities]),
            temporal_complexity=np.mean([c.temporal_complexity for c in complexities]),
            automaton_complexity=np.mean([c.automaton_complexity for c in complexities]),
            overall_complexity=np.mean([c.overall_complexity for c in complexities])
        )
    
    def _calculate_max_complexity(self, complexities: List[FormulaComplexity]) -> FormulaComplexity:
        """Find the maximum complexity metrics."""
        if not complexities:
            return self._calculate_average_complexity([])
        
        max_idx = np.argmax([c.overall_complexity for c in complexities])
        return complexities[max_idx]
    
    def create_complexity_vs_time_analysis(self, df: pd.DataFrame) -> None:
        """
        Create visualizations showing relationship between complexity and processing time.
        
        Args:
            df: DataFrame with complexity and timing analysis
        """
        if df.empty:
            print("No data available for complexity vs time analysis.")
            return
        
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        fig.suptitle('Formula Complexity vs Processing Time Analysis', fontsize=16, fontweight='bold')
        
        # Filter out benchmarks with zero timing data
        valid_timing = df[df['time_per_formula'] > 0]
        
        if valid_timing.empty:
            print("No valid timing data available for analysis.")
            return
        
        # 1. Overall Complexity vs Time per Formula
        ax1.scatter(valid_timing['avg_overall_complexity'], valid_timing['time_per_formula'], 
                   alpha=0.6, s=60, color='steelblue')
        ax1.set_xlabel('Average Overall Complexity')
        ax1.set_ylabel('Time per Formula (seconds)')
        ax1.set_title('Overall Complexity vs Processing Time')
        ax1.set_yscale('log')
        ax1.grid(True, alpha=0.3)
        
        # Add correlation line
        if len(valid_timing) > 1:
            try:
                z = np.polyfit(valid_timing['avg_overall_complexity'], 
                              np.log(valid_timing['time_per_formula']), 1)
                p = np.poly1d(z)
                x_line = np.linspace(valid_timing['avg_overall_complexity'].min(),
                                   valid_timing['avg_overall_complexity'].max(), 100)
                ax1.plot(x_line, np.exp(p(x_line)), "r--", alpha=0.8, linewidth=2)
                
                # Calculate correlation
                corr = np.corrcoef(valid_timing['avg_overall_complexity'], 
                                 np.log(valid_timing['time_per_formula']))[0, 1]
                ax1.text(0.05, 0.95, f'Correlation: {corr:.3f}', transform=ax1.transAxes,
                        bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.8))
            except:
                pass
        
        # 2. Automaton Complexity vs Time
        ax2.scatter(valid_timing['avg_automaton_states'], valid_timing['time_per_formula'],
                   alpha=0.6, s=60, color='green')
        ax2.set_xlabel('Average Automaton States')
        ax2.set_ylabel('Time per Formula (seconds)')
        ax2.set_title('Automaton Complexity vs Processing Time')
        ax2.set_yscale('log')
        ax2.grid(True, alpha=0.3)
        
        # 3. Temporal Complexity vs Time
        ax3.scatter(valid_timing['avg_temporal_complexity'], valid_timing['time_per_formula'],
                   alpha=0.6, s=60, color='red')
        ax3.set_xlabel('Average Temporal Complexity')
        ax3.set_ylabel('Time per Formula (seconds)')
        ax3.set_title('Temporal Complexity vs Processing Time')
        ax3.set_yscale('log')
        ax3.grid(True, alpha=0.3)
        
        # 4. Complexity Distribution
        ax4.hist(df['avg_overall_complexity'], bins=15, alpha=0.7, color='orange', edgecolor='black')
        ax4.set_xlabel('Average Overall Complexity')
        ax4.set_ylabel('Frequency')
        ax4.set_title('Distribution of Complexity Scores')
        ax4.grid(True, alpha=0.3, axis='y')
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'complexity_vs_time_analysis.png'),
                       dpi=300, bbox_inches='tight')
            print(f"Complexity vs time analysis saved to: {os.path.join(self.output_folder, 'complexity_vs_time_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_complexity_breakdown_analysis(self, df: pd.DataFrame) -> None:
        """
        Create detailed breakdown of complexity components.
        
        Args:
            df: DataFrame with complexity analysis
        """
        if df.empty:
            return
        
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        fig.suptitle('LTL Formula Complexity Breakdown Analysis', fontsize=16, fontweight='bold')
        
        # 1. Complexity Components Comparison
        complexity_components = ['avg_structural_complexity', 'avg_temporal_complexity', 'avg_automaton_complexity']
        component_names = ['Structural', 'Temporal', 'Automaton']
        
        x_pos = np.arange(len(df))
        width = 0.25
        
        for i, (component, name) in enumerate(zip(complexity_components, component_names)):
            ax1.bar(x_pos + i * width, df[component], width, label=name, alpha=0.7)
        
        ax1.set_xlabel('Benchmark Index')
        ax1.set_ylabel('Complexity Score')
        ax1.set_title('Complexity Components by Benchmark')
        ax1.legend()
        ax1.grid(True, alpha=0.3, axis='y')
        
        # 2. Operator Count Distribution
        ax2.scatter(df['avg_operator_count'], df['avg_overall_complexity'], alpha=0.6, s=60, color='purple')
        ax2.set_xlabel('Average Operator Count')
        ax2.set_ylabel('Average Overall Complexity')
        ax2.set_title('Operator Count vs Overall Complexity')
        ax2.grid(True, alpha=0.3)
        
        # 3. Nesting Depth Analysis
        ax3.scatter(df['avg_nesting_depth'], df['avg_overall_complexity'], alpha=0.6, s=60, color='brown')
        ax3.set_xlabel('Average Nesting Depth')
        ax3.set_ylabel('Average Overall Complexity')
        ax3.set_title('Nesting Depth vs Overall Complexity')
        ax3.grid(True, alpha=0.3)
        
        # 4. Formula Length vs Complexity
        ax4.scatter(df['avg_length'], df['avg_overall_complexity'], alpha=0.6, s=60, color='navy')
        ax4.set_xlabel('Average Formula Length')
        ax4.set_ylabel('Average Overall Complexity')
        ax4.set_title('Formula Length vs Overall Complexity')
        ax4.grid(True, alpha=0.3)
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'complexity_breakdown_analysis.png'),
                       dpi=300, bbox_inches='tight')
            print(f"Complexity breakdown analysis saved to: {os.path.join(self.output_folder, 'complexity_breakdown_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def generate_complexity_report(self, df: pd.DataFrame) -> Dict:
        """
        Generate comprehensive complexity analysis report.
        
        Args:
            df: DataFrame with complexity analysis
            
        Returns:
            Dictionary with complexity statistics
        """
        if df.empty:
            return {}
        
        stats = {
            'total_benchmarks': len(df),
            'total_formulas': df['formula_count'].sum(),
            'avg_complexity_per_benchmark': df['avg_overall_complexity'].mean(),
            'max_complexity': df['avg_overall_complexity'].max(),
            'min_complexity': df['avg_overall_complexity'].min(),
            'complexity_std': df['avg_overall_complexity'].std(),
            
            'avg_formula_length': df['avg_length'].mean(),
            'avg_operator_count': df['avg_operator_count'].mean(),
            'avg_nesting_depth': df['avg_nesting_depth'].mean(),
            'avg_temporal_operators': df['avg_temporal_ops'].mean(),
            'avg_automaton_states': df['avg_automaton_states'].mean(),
            
            'most_complex_benchmark': df.loc[df['avg_overall_complexity'].idxmax(), 'benchmark'],
            'simplest_benchmark': df.loc[df['avg_overall_complexity'].idxmin(), 'benchmark'],
        }
        
        # Add timing correlations if available
        valid_timing = df[df['time_per_formula'] > 0]
        if len(valid_timing) > 1:
            correlations = {}
            complexity_measures = ['avg_overall_complexity', 'avg_structural_complexity', 
                                 'avg_temporal_complexity', 'avg_automaton_complexity']
            
            for measure in complexity_measures:
                try:
                    corr = np.corrcoef(valid_timing[measure], valid_timing['time_per_formula'])[0, 1]
                    correlations[f'{measure}_time_correlation'] = corr
                except:
                    correlations[f'{measure}_time_correlation'] = 0.0
            
            stats.update(correlations)
        
        return stats
    
    def print_complexity_report(self, stats: Dict) -> None:
        """Print complexity analysis report to console."""
        if not stats:
            print("No complexity statistics to report.")
            return
        
        print("\n" + "=" * 80)
        print("LTL FORMULA COMPLEXITY ANALYSIS REPORT")
        print("=" * 80)
        
        print("\nOVERALL COMPLEXITY METRICS:")
        print(f"  Total benchmarks analyzed: {stats['total_benchmarks']}")
        print(f"  Total formulas analyzed: {stats['total_formulas']:,}")
        print(f"  Average complexity per benchmark: {stats['avg_complexity_per_benchmark']:.3f}")
        print(f"  Maximum complexity: {stats['max_complexity']:.3f}")
        print(f"  Minimum complexity: {stats['min_complexity']:.3f}")
        print(f"  Complexity standard deviation: {stats['complexity_std']:.3f}")
        
        print("\nFORMULA CHARACTERISTICS:")
        print(f"  Average formula length: {stats['avg_formula_length']:.1f} characters")
        print(f"  Average operator count: {stats['avg_operator_count']:.1f}")
        print(f"  Average nesting depth: {stats['avg_nesting_depth']:.1f}")
        print(f"  Average temporal operators: {stats['avg_temporal_operators']:.1f}")
        print(f"  Average automaton states: {stats['avg_automaton_states']:.1f}")
        
        print("\nCOMPLEXITY EXTREMES:")
        print(f"  Most complex benchmark: {stats['most_complex_benchmark']}")
        print(f"  Simplest benchmark: {stats['simplest_benchmark']}")
        
        # Print correlations if available
        correlation_keys = [k for k in stats.keys() if 'correlation' in k]
        if correlation_keys:
            print("\nCOMPLEXITY-TIME CORRELATIONS:")
            for key in correlation_keys:
                measure_name = key.replace('_time_correlation', '').replace('avg_', '')
                print(f"  {measure_name.title()}: {stats[key]:.3f}")
        
        print("=" * 80)
    
    def analyze_complexity_and_performance(self, benchmark_folder: str = "benchmark_000",
                                         timing_results_folder: str = "optimized_results") -> Tuple[pd.DataFrame, Dict]:
        """
        Complete complexity analysis with performance correlation.
        
        Args:
            benchmark_folder: Folder containing benchmark subfolders
            timing_results_folder: Folder containing timing results
            
        Returns:
            Tuple of (analysis_df, complexity_stats)
        """
        print(f"Starting comprehensive complexity analysis...")
        
        # Analyze benchmark complexity
        df = self.analyze_benchmark_complexity(benchmark_folder, timing_results_folder)
        
        if df.empty:
            print("No data available for analysis.")
            return df, {}
        
        # Generate visualizations
        self.create_complexity_vs_time_analysis(df)
        self.create_complexity_breakdown_analysis(df)
        
        # Generate statistics
        stats = self.generate_complexity_report(df)
        
        # Print report
        self.print_complexity_report(stats)
        
        # Save statistics
        if self.save_plots:
            stats_df = pd.DataFrame(list(stats.items()), columns=['Metric', 'Value'])
            stats_path = os.path.join(self.output_folder, 'complexity_statistics.csv')
            stats_df.to_csv(stats_path, index=False)
            print(f"Complexity statistics saved to: {stats_path}")
        
        print(f"\nComplexity analysis complete! Results saved to: {self.output_folder}")
        return df, stats


def main():
    """Main execution function."""
    
    # Configuration
    BENCHMARK_FOLDER = "benchmark_000"
    TIMING_RESULTS_FOLDER = "optimized_results"
    SAVE_PLOTS = True
    SHOW_PLOTS = False
    OUTPUT_FOLDER = "complexity_analysis"
    
    # Initialize analyzer
    analyzer = LTLComplexityAnalyzer(
        save_plots=SAVE_PLOTS,
        show_plots=SHOW_PLOTS,
        output_folder=OUTPUT_FOLDER
    )
    
    # Run analysis
    try:
        df, stats = analyzer.analyze_complexity_and_performance(
            BENCHMARK_FOLDER, TIMING_RESULTS_FOLDER
        )
        
        if not df.empty and stats:
            print(f"\nKEY FINDINGS:")
            print(f"  Average complexity score: {stats['avg_complexity_per_benchmark']:.3f}")
            print(f"  Most complex benchmark: {stats['most_complex_benchmark']}")
            
            # Print strongest correlation if timing data available
            correlation_keys = [k for k in stats.keys() if 'correlation' in k]
            if correlation_keys:
                strongest_corr_key = max(correlation_keys, key=lambda k: abs(stats[k]))
                measure_name = strongest_corr_key.replace('_time_correlation', '').replace('avg_', '')
                print(f"  Strongest time correlation: {measure_name.title()} ({stats[strongest_corr_key]:.3f})")
        
    except Exception as e:
        print(f"Error during complexity analysis: {e}")
        print("Please ensure:")
        print("1. Benchmark folder exists and contains properties.ltl files")
        print("2. Timing results are available (optional)")


if __name__ == "__main__":
    main()
