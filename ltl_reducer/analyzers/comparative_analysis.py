"""
Comparative Analysis: Baseline vs Optimized LTL Model Checking

This script provides a comprehensive comparison between baseline model checking
and the optimized LTL approach, including timing analysis, speedup metrics,
and overhead analysis. Designed for publication-quality results (ICSE-style).
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os
import seaborn as sns
from typing import Tuple, Dict, Optional
from pathlib import Path
import warnings
warnings.filterwarnings('ignore')

# Set style for publication-quality plots
plt.style.use('default')
plt.rcParams.update({
    'font.size': 11,
    'axes.titlesize': 13,
    'axes.labelsize': 12,
    'xtick.labelsize': 10,
    'ytick.labelsize': 10,
    'legend.fontsize': 10,
    'figure.titlesize': 15,
    'lines.linewidth': 2,
    'lines.markersize': 6
})

# Try to import seaborn for enhanced visualizations
try:
    import seaborn as sns
    HAS_SEABORN = True
    sns.set_palette("Set2")
except ImportError:
    HAS_SEABORN = False


class ComparativeAnalyzer:
    """
    Professional analyzer for comparing baseline vs optimized LTL model checking performance.
    """
    
    def __init__(self, save_plots: bool = True, show_plots: bool = False, 
                 output_folder: str = "comparative_analysis"):
        """
        Initialize the comparative analyzer.
        
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
    
    def load_and_align_data(self, baseline_file: str, optimized_file: str) -> Tuple[pd.DataFrame, pd.DataFrame]:
        """
        Load and align baseline and optimized timing data.
        
        Args:
            baseline_file: Path to baseline timing summary CSV
            optimized_file: Path to optimized timing summary CSV
            
        Returns:
            Tuple of (baseline_df, optimized_df) with matching benchmarks
        """
        print("Loading timing data...")
        
        # Load baseline data
        baseline_df = pd.read_csv(baseline_file)
        if 'Unnamed: 0' in baseline_df.columns:
            baseline_df = baseline_df.drop('Unnamed: 0', axis=1)
        
        # Load optimized data
        optimized_df = pd.read_csv(optimized_file)
        if 'Unnamed: 0' in optimized_df.columns:
            optimized_df = optimized_df.drop('Unnamed: 0', axis=1)
        
        # Find common benchmarks
        baseline_benchmarks = set(baseline_df['Benchmark'])
        optimized_benchmarks = set(optimized_df['Benchmark'])
        common_benchmarks = baseline_benchmarks.intersection(optimized_benchmarks)
        
        print(f"Baseline benchmarks: {len(baseline_benchmarks)}")
        print(f"Optimized benchmarks: {len(optimized_benchmarks)}")
        print(f"Common benchmarks: {len(common_benchmarks)}")
        
        # Filter to common benchmarks and sort
        baseline_aligned = baseline_df[baseline_df['Benchmark'].isin(common_benchmarks)].copy()
        optimized_aligned = optimized_df[optimized_df['Benchmark'].isin(common_benchmarks)].copy()
        
        baseline_aligned = baseline_aligned.sort_values('Benchmark').reset_index(drop=True)
        optimized_aligned = optimized_aligned.sort_values('Benchmark').reset_index(drop=True)
        
        return baseline_aligned, optimized_aligned
    
    def load_optimization_overhead(self, benchmark_specific_folder: str, 
                                 common_benchmarks: list) -> pd.DataFrame:
        """
        Load optimization overhead data from benchmark-specific CSV files.
        
        Args:
            benchmark_specific_folder: Path to optimized_results/benchmark_specific
            common_benchmarks: List of benchmark names to process
            
        Returns:
            DataFrame with optimization overhead data
        """
        print("Loading optimization overhead data...")
        
        overhead_data = []
        
        for benchmark in common_benchmarks:
            csv_file = os.path.join(benchmark_specific_folder, f"{benchmark}_metrics_summary.csv")
            
            if os.path.exists(csv_file):
                try:
                    df = pd.read_csv(csv_file)
                    
                    # Extract timing information
                    total_time = df['total_time'].iloc[0] if 'total_time' in df.columns else 0
                    equivalence_time = df['equivalence_class_time'].iloc[0] if 'equivalence_class_time' in df.columns else 0
                    containment_time = df['containment_analysis_time'].iloc[0] if 'containment_analysis_time' in df.columns else 0
                    
                    overhead_data.append({
                        'Benchmark': benchmark,
                        'Optimization_Time': total_time,
                        'Equivalence_Class_Time': equivalence_time,
                        'Containment_Analysis_Time': containment_time
                    })
                    
                except Exception as e:
                    print(f"Warning: Could not load {csv_file}: {e}")
                    overhead_data.append({
                        'Benchmark': benchmark,
                        'Optimization_Time': 0,
                        'Equivalence_Class_Time': 0,
                        'Containment_Analysis_Time': 0
                    })
            else:
                print(f"Warning: {csv_file} not found")
                overhead_data.append({
                    'Benchmark': benchmark,
                    'Optimization_Time': 0,
                    'Equivalence_Class_Time': 0,
                    'Containment_Analysis_Time': 0
                })
        
        return pd.DataFrame(overhead_data)
    
    def create_timing_comparison(self, baseline_df: pd.DataFrame, optimized_df: pd.DataFrame,tolerance=0.2) -> None:
        """
        Create comprehensive timing comparison visualization.
        
        Args:
            baseline_df: Baseline timing data
            optimized_df: Optimized timing data
        """
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(20, 12))
        fig.suptitle('Model Checking Performance: Baseline vs Optimized LTL', 
                    fontsize=16, fontweight='bold')
        
        benchmarks = baseline_df['Benchmark']
        baseline_times = baseline_df['Total Elapsed Time (seconds)']
        optimized_times = optimized_df['Total Elapsed Time (seconds)']
        
        # 1. Side-by-side bar comparison
        x = np.arange(len(benchmarks))
        width = 0.35
        
        bars1 = ax1.bar(x - width/2, baseline_times, width, label='Baseline', 
                       alpha=0.8, color='lightcoral')
        bars2 = ax1.bar(x + width/2, optimized_times, width, label='Optimized', 
                       alpha=0.8, color='skyblue')
        
        ax1.set_xlabel('Benchmark Index')
        ax1.set_ylabel('Total Elapsed Time (seconds)')
        ax1.set_title('Total Elapsed Time: Baseline vs Optimized')
        ax1.legend()
        ax1.grid(True, alpha=0.3, axis='y')
        ax1.set_yscale('log')
        
        # 2. Speedup analysis
        speedup = baseline_times / optimized_times
        speedup = speedup.replace([np.inf, -np.inf], np.nan).fillna(1)
        
        colors = ['green' if s >= 1- tolerance else 'red' for s in speedup]
        bars = ax2.bar(range(len(benchmarks)), speedup, alpha=0.7, color=colors)
        ax2.axhline(y=1, color='black', linestyle='--', linewidth=2, label='No speedup')
        ax2.set_xlabel('Benchmark Index')
        ax2.set_ylabel('Speedup Factor')
        ax2.set_title('Speedup: Baseline Time / Optimized Time')
        ax2.grid(True, alpha=0.3, axis='y')
        ax2.legend()
        
        # Add speedup values on bars
        for i, (bar, speed) in enumerate(zip(bars, speedup)):
            if not np.isnan(speed) and speed != np.inf:
                height = bar.get_height()
                ax2.text(bar.get_x() + bar.get_width()/2., height + 0.1,
                        f'{speed:.1f}x', ha='center', va='bottom', fontsize=8)
        
        # 3. Scatter plot: baseline vs optimized
        ax3.scatter(baseline_times, optimized_times, alpha=0.6, s=60, color='purple')
        
        # Add diagonal line (y=x)
        max_time = max(baseline_times.max(), optimized_times.max())
        min_time = min(baseline_times.min(), optimized_times.min())
        ax3.plot([min_time, max_time], [min_time, max_time], 'r--', 
                linewidth=2, label='Equal performance')
        
        ax3.set_xlabel('Baseline Time (seconds)')
        ax3.set_ylabel('Optimized Time (seconds)')
        ax3.set_title('Baseline vs Optimized Performance Correlation')
        ax3.set_xscale('log')
        ax3.set_yscale('log')
        ax3.grid(True, alpha=0.3)
        ax3.legend()
        
        # 4. Average time per property comparison
        speedup = baseline_times / optimized_times
        speedup = speedup.replace([np.inf, -np.inf], np.nan).fillna(1)
        
        colors = ['green' if s >= 1- tolerance else 'red' for s in speedup]
        bars = ax4.bar(range(len(benchmarks)), speedup, alpha=0.7, color=colors)

        
        ax4.set_xlabel('Benchmark Index')
        ax4.set_ylabel('Speedup Factor')
        ax4.set_title('Speedup: Baseline Time / Optimized Time+refinement time')
        ax4.legend()
        ax4.grid(True, alpha=0.3, axis='y')
        ax4
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'timing_comparison.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Timing comparison saved to: {os.path.join(self.output_folder, 'timing_comparison.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_detailed_benchmark_chart(self, baseline_df: pd.DataFrame, 
                                      optimized_df: pd.DataFrame) -> None:
        """
        Create detailed benchmark-by-benchmark comparison chart.
        
        Args:
            baseline_df: Baseline timing data
            optimized_df: Optimized timing data
        """
        plt.figure(figsize=(24, 10))
        
        benchmarks = baseline_df['Benchmark']
        baseline_times = baseline_df['Total Elapsed Time (seconds)']
        optimized_times = optimized_df['Total Elapsed Time (seconds)']
        
        x = np.arange(len(benchmarks))
        width = 0.35
        
        bars1 = plt.bar(x - width/2, baseline_times, width, label='Baseline Model Checking', 
                       alpha=0.8, color='#FF6B6B', edgecolor='black', linewidth=0.5)
        bars2 = plt.bar(x + width/2, optimized_times, width, label='Optimized LTL Model Checking', 
                       alpha=0.8, color='#4ECDC4', edgecolor='black', linewidth=0.5)
        
        plt.xlabel('Benchmark', fontsize=14, fontweight='bold')
        plt.ylabel('Total Elapsed Time (seconds)', fontsize=14, fontweight='bold')
        plt.title('Model Checking Performance Comparison by Benchmark', 
                 fontsize=16, fontweight='bold', pad=20)
        
        plt.xticks(x, benchmarks, rotation=45, ha='right')
        plt.yscale('log')
        plt.grid(True, alpha=0.3, axis='y')
        plt.legend(fontsize=12, loc='upper left')
        
        # Add improvement indicators
        for i, (baseline, optimized) in enumerate(zip(baseline_times, optimized_times)):
            if optimized < baseline:
                improvement = ((baseline - optimized) / baseline) * 100
                plt.text(i, max(baseline, optimized) * 1.1, f'{improvement:.1f}% faster', 
                        ha='center', va='bottom', fontsize=8, fontweight='bold', color='green')
            elif optimized > baseline:
                slowdown = ((optimized - baseline) / baseline) * 100
                plt.text(i, max(baseline, optimized) * 1.1, f'{slowdown:.1f}% slower', 
                        ha='center', va='bottom', fontsize=8, fontweight='bold', color='red')
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'detailed_benchmark_comparison.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Detailed benchmark comparison saved to: {os.path.join(self.output_folder, 'detailed_benchmark_comparison.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_overhead_analysis(self, baseline_df: pd.DataFrame, optimized_df: pd.DataFrame,
                               overhead_df: pd.DataFrame, 
                               tolerance = 0.2) -> None:
        """
        Create analysis including optimization overhead.
        
        Args:
            baseline_df: Baseline timing data
            optimized_df: Optimized timing data
            overhead_df: Optimization overhead data
        """
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(20, 12))
        fig.suptitle('Complete Analysis: Model Checking + Optimization Overhead', 
                    fontsize=16, fontweight='bold')
        
        benchmarks = baseline_df['Benchmark']
        baseline_times = baseline_df['Total Elapsed Time (seconds)']
        optimized_times = optimized_df['Total Elapsed Time (seconds)']
        optimization_times = overhead_df['Optimization_Time']
        total_optimized_times = optimized_times + optimization_times
        
        # 1. Three-way comparison
        x = np.arange(len(benchmarks))
        width = 0.25
        
        bars1 = ax1.bar(x - width, baseline_times, width, label='Baseline', 
                       alpha=0.8, color='lightcoral')
        bars2 = ax1.bar(x, optimized_times, width, label='Optimized (MC only)', 
                       alpha=0.8, color='skyblue')
        bars3 = ax1.bar(x + width, total_optimized_times, width, label='Optimized (MC + Overhead)', 
                       alpha=0.8, color='lightgreen')
        
        ax1.set_xlabel('Benchmark Index')
        ax1.set_ylabel('Total Time (seconds)')
        ax1.set_title('Complete Time Analysis: Baseline vs Optimized (with overhead)')
        ax1.legend()
        ax1.grid(True, alpha=0.3, axis='y')
        ax1.set_yscale('log')
        
        # 2. Net speedup analysis (including overhead)
        net_speedup = baseline_times / total_optimized_times
        net_speedup = net_speedup.replace([np.inf, -np.inf], np.nan).fillna(1)
        
        colors = ['green' if s >=1-tolerance else 'red' for s in net_speedup]
        bars = ax2.bar(range(len(benchmarks)), net_speedup, alpha=0.7, color=colors)
        ax2.axhline(y=1, color='black', linestyle='--', linewidth=2, label='Break-even')
        ax2.set_xlabel('Benchmark Index')
        ax2.set_ylabel('Net Speedup Factor')
        ax2.set_title('Net Speedup (including optimization overhead)')
        ax2.grid(True, alpha=0.3, axis='y')
        ax2.legend()
        
        # 3. Optimization overhead breakdown
        ax3.bar(x, overhead_df['Equivalence_Class_Time'], width, label='Equivalence Classes', 
               alpha=0.8, color='orange')
        ax3.bar(x, overhead_df['Containment_Analysis_Time'], width, 
               bottom=overhead_df['Equivalence_Class_Time'], label='Containment Analysis', 
               alpha=0.8, color='purple')
        
        ax3.set_xlabel('Benchmark Index')
        ax3.set_ylabel('Optimization Time (seconds)')
        ax3.set_title('Optimization Overhead Breakdown')
        ax3.legend()
        ax3.grid(True, alpha=0.3, axis='y')
        
        # 4. Overhead vs benefit analysis
        model_checking_savings = baseline_times - optimized_times
        overhead_cost = optimization_times
        net_benefit = model_checking_savings - overhead_cost
        
        ax4.scatter(overhead_cost, model_checking_savings, alpha=0.6, s=80, color='blue')
        
        # Add diagonal line where overhead = savings
        max_val = max(overhead_cost.max(), model_checking_savings.max())
        ax4.plot([0, max_val], [0, max_val], 'r--', linewidth=2, label='Break-even line')
        
        ax4.set_xlabel('Optimization Overhead (seconds)')
        ax4.set_ylabel('Model Checking Time Savings (seconds)')
        ax4.set_title('Cost-Benefit Analysis: Overhead vs Savings')
        ax4.grid(True, alpha=0.3)
        ax4.legend()
        
        # Add quadrant labels
        ax4.text(0.05, 0.95, 'Net Loss\n(High overhead)', transform=ax4.transAxes, 
                fontsize=10, alpha=0.7, ha='left', va='top')
        ax4.text(0.95, 0.05, 'Net Gain\n(Low overhead)', transform=ax4.transAxes, 
                fontsize=10, alpha=0.7, ha='right', va='bottom')
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'overhead_analysis.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Overhead analysis saved to: {os.path.join(self.output_folder, 'overhead_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def generate_performance_statistics(self, baseline_df: pd.DataFrame, 
                                      optimized_df: pd.DataFrame,
                                      overhead_df: pd.DataFrame,
                                      tolerance = 0.2) -> Dict:
        """
        Generate comprehensive performance statistics.
        
        Args:
            baseline_df: Baseline timing data
            optimized_df: Optimized timing data
            overhead_df: Optimization overhead data
            
        Returns:
            Dictionary with performance statistics
        """
        baseline_times = baseline_df['Total Elapsed Time (seconds)']
        optimized_times = optimized_df['Total Elapsed Time (seconds)']
        optimization_times = overhead_df['Optimization_Time']
        total_optimized_times = optimized_times + optimization_times
        
        # Calculate speedups
        mc_only_speedup = baseline_times / optimized_times
        net_speedup = baseline_times / total_optimized_times
        
        # Calculate individual overhead percentages for each benchmark
        individual_overhead_percentages = (optimization_times / baseline_times) * 100
        individual_overhead_percentages = individual_overhead_percentages.replace([np.inf, -np.inf], np.nan)
        
        # Handle infinite values
        mc_only_speedup = mc_only_speedup.replace([np.inf, -np.inf], np.nan)
        net_speedup = net_speedup.replace([np.inf, -np.inf], np.nan)
        
        stats = {
            'total_benchmarks': len(baseline_df),
            'baseline_total_time': baseline_times.sum(),
            'optimized_mc_total_time': optimized_times.sum(),
            'optimization_total_time': optimization_times.sum(),
            'total_optimized_time': total_optimized_times.sum(),
            'baseline_avg_time': baseline_times.mean(),
            'optimized_mc_avg_time': optimized_times.mean(),
            'optimization_avg_time': optimization_times.mean(),
            'total_optimized_avg_time': total_optimized_times.mean(),
            'mc_only_geometric_mean_speedup': np.exp(np.log(mc_only_speedup.dropna()).mean()) if len(mc_only_speedup.dropna()) > 0 else 1,
            'net_geometric_mean_speedup': np.exp(np.log(net_speedup.dropna()).mean()) if len(net_speedup.dropna()) > 0 else 1,
            'mc_only_median_speedup': mc_only_speedup.median(),
            'net_median_speedup': net_speedup.median(),
            'best_mc_speedup': mc_only_speedup.max(),
            'best_net_speedup': net_speedup.max(),
            'worst_mc_speedup': mc_only_speedup.min(),
            'worst_net_speedup': net_speedup.min(),
            'benchmarks_with_net_improvement': (net_speedup >= 1- tolerance).sum(),
            'benchmarks_with_mc_improvement': (mc_only_speedup >= 1- tolerance).sum(),
            'total_time_saved_mc_only': (baseline_times - optimized_times).sum(),
            'total_time_saved_net': (baseline_times - total_optimized_times).sum(),
            'overhead_percentage': (optimization_times.sum() / baseline_times.sum()) * 100,
            'overhead_median_percentage': individual_overhead_percentages.median(),
            'overhead_mean_percentage': individual_overhead_percentages.mean(),
            'overhead_efficiency': ((baseline_times - total_optimized_times).sum() / optimization_times.sum()) * 100,  
            'break_even_factor': optimization_times.sum() / (baseline_times - optimized_times).sum(),  
            'net_benefit_percentage_gross': ((baseline_times - optimized_times).sum() / baseline_times.sum()) * 100,
            'net_benefit_percentage': ((baseline_times - total_optimized_times).sum() / baseline_times.sum()) * 100,
            #from the index, get the name of the least performing benchmark
            'least_performing_benchmark': baseline_df.iloc[(baseline_times - total_optimized_times).idxmin()]['Benchmark'] if len(baseline_df) > 0 else None,
        }
        
        return stats
    
    def print_performance_report(self, stats: Dict) -> None:
        """
        Print comprehensive performance report.
        
        Args:
            stats: Performance statistics dictionary
        """
        print("\n" + "=" * 80)
        print("COMPARATIVE PERFORMANCE ANALYSIS REPORT")
        print("=" * 80)
        
        print(f"\nDataset Overview:")
        print(f"  Total benchmarks analyzed: {stats['total_benchmarks']}")
        print(f"  Baseline total runtime: {stats['baseline_total_time']:.2f} seconds")
        print(f"  Optimized MC total runtime: {stats['optimized_mc_total_time']:.2f} seconds")
        print(f"  Optimization overhead: {stats['optimization_total_time']:.2f} seconds")
        print(f"  Complete optimized runtime: {stats['total_optimized_time']:.2f} seconds")
        
        print(f"\nModel Checking Only Performance:")
        print(f"  Geometric mean speedup: {stats['mc_only_geometric_mean_speedup']:.2f}x")
        print(f"  Median speedup: {stats['mc_only_median_speedup']:.2f}x")
        print(f"  Best speedup: {stats['best_mc_speedup']:.2f}x")
        print(f"  Worst speedup: {stats['worst_mc_speedup']:.2f}x")
        print(f"  Benchmarks improved: {stats['benchmarks_with_mc_improvement']}/{stats['total_benchmarks']}")
        print(f"  Total time saved: {stats['total_time_saved_mc_only']:.2f} seconds")
        
        print(f"\nNet Performance (including optimization overhead):")
        print(f"  Geometric mean speedup: {stats['net_geometric_mean_speedup']:.2f}x")
        print(f"  Median speedup: {stats['net_median_speedup']:.2f}x")
        print(f"  Best net speedup: {stats['best_net_speedup']:.2f}x")
        print(f"  Worst net speedup: {stats['worst_net_speedup']:.2f}x")
        print(f"  Benchmarks with net improvement: {stats['benchmarks_with_net_improvement']}/{stats['total_benchmarks']}")
        print(f"  Total net time saved: {stats['total_time_saved_net']:.2f} seconds")
        
        print(f"\nOverhead Analysis:")
        print(f"  Optimization overhead percentage: {stats['overhead_percentage']:.2f}%")
        print(f"  Average optimization time per benchmark: {stats['optimization_avg_time']:.2f} seconds")
        
        print("=" * 80)
    
    def save_statistics_report(self, stats: Dict) -> None:
        """
        Save statistics to CSV file.
        
        Args:
            stats: Performance statistics dictionary
        """
        if self.save_plots:
            stats_df = pd.DataFrame(list(stats.items()), columns=['Metric', 'Value'])
            stats_path = os.path.join(self.output_folder, 'performance_statistics.csv')
            stats_df.to_csv(stats_path, index=False)
            print(f"Performance statistics saved to: {stats_path}")
    
    def run_complete_analysis(self, baseline_file: str = "baseline_timing_summary.csv",
                            optimized_file: str = "ltlreduction_timing_summary.csv",
                            benchmark_specific_folder: str = "optimized_results/benchmark_specific", 
                            tolerance = 0.2) -> None:
        """
        Run complete comparative analysis.
        
        Args:
            baseline_file: Path to baseline timing summary
            optimized_file: Path to optimized timing summary
            benchmark_specific_folder: Path to optimization overhead data
        """
        print("Starting Comparative Analysis: Baseline vs Optimized LTL")
        print("=" * 60)
        
        # Load and align data
        baseline_df, optimized_df = self.load_and_align_data(baseline_file, optimized_file)
        
        # Load optimization overhead
        common_benchmarks = baseline_df['Benchmark'].tolist()
        overhead_df = self.load_optimization_overhead(benchmark_specific_folder, common_benchmarks)
        
        # Align overhead data
        overhead_df = overhead_df.sort_values('Benchmark').reset_index(drop=True)
        
        print("\nGenerating visualizations...")
        
        # Create visualizations
        self.create_timing_comparison(baseline_df, optimized_df, tolerance)
        self.create_detailed_benchmark_chart(baseline_df, optimized_df)
        self.create_overhead_analysis(baseline_df, optimized_df, overhead_df)
        
        # Generate and print statistics
        stats = self.generate_performance_statistics(baseline_df, optimized_df, overhead_df,tolerance)
        self.print_performance_report(stats)
        self.save_statistics_report(stats)
        
        print(f"\nAnalysis complete! Results saved to: {self.output_folder}")


def main():
    """Main execution function."""
    
    # Configuration
    BASELINE_FILE = "baseline_timing_summary.csv"
    OPTIMIZED_FILE = "ltlreduction_timing_summary.csv"
    BENCHMARK_SPECIFIC_FOLDER = "optimized_results/benchmark_specific"
    SAVE_PLOTS = True
    SHOW_PLOTS = False
    OUTPUT_FOLDER = "comparative_analysis"
    
    # Initialize analyzer
    analyzer = ComparativeAnalyzer(
        save_plots=SAVE_PLOTS,
        show_plots=SHOW_PLOTS,
        output_folder=OUTPUT_FOLDER
    )
    
    # Check if required files exist
    if not os.path.exists(BASELINE_FILE):
        print(f"Error: Baseline file '{BASELINE_FILE}' not found.")
        return
    
    if not os.path.exists(OPTIMIZED_FILE):
        print(f"Error: Optimized file '{OPTIMIZED_FILE}' not found.")
        return
    
    if not os.path.exists(BENCHMARK_SPECIFIC_FOLDER):
        print(f"Error: Benchmark specific folder '{BENCHMARK_SPECIFIC_FOLDER}' not found.")
        return
    
    # Run complete analysis
    analyzer.run_complete_analysis(
        baseline_file=BASELINE_FILE,
        optimized_file=OPTIMIZED_FILE,
        benchmark_specific_folder=BENCHMARK_SPECIFIC_FOLDER
    )


if __name__ == "__main__":
    main()
