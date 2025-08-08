"""
LTL Formula Reduction Performance Analysis Tool

This script provides comprehensive analysis and visualization of LTL formula
optimization results, including reduction metrics, performance characteristics,
and comparative analysis across benchmarks.
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os
from typing import Optional, Tuple, Dict, List
from pathlib import Path

# Try to import seaborn for enhanced visualizations
try:
    import seaborn as sns
    HAS_SEABORN = True
except ImportError:
    HAS_SEABORN = False


class LTLReductionAnalyzer:
    """
    Professional analyzer for LTL formula reduction performance with publication-quality visualizations.
    """
    
    def __init__(self, save_plots: bool = True, show_plots: bool = False, 
                 output_folder: str = "ltl_reduction_analysis"):
        """
        Initialize the LTL reduction analyzer.
        
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
        
        if HAS_SEABORN:
            sns.set_palette("husl")
    
    def load_optimization_data(self, results_folder: str = "optimized_results") -> Tuple[pd.DataFrame, pd.DataFrame]:
        """
        Load LTL optimization results from the results folder.
        
        Args:
            results_folder: Path to optimization results folder
            
        Returns:
            Tuple of (summary_df, class_reductions_df)
        """
        # Load main benchmark summary
        summary_path = os.path.join(results_folder, "benchmark_summary.csv")
        if not os.path.exists(summary_path):
            raise FileNotFoundError(f"Benchmark summary not found at: {summary_path}")
        
        summary_df = pd.read_csv(summary_path)
        
        # Load individual class reduction data
        benchmark_specific_folder = os.path.join(results_folder, "benchmark_specific")
        class_reductions_data = []
        
        if os.path.exists(benchmark_specific_folder):
            for file in os.listdir(benchmark_specific_folder):
                if file.endswith("_class_reductions.csv"):
                    benchmark_name = file.replace("_metrics_class_reductions.csv", "")
                    class_df = pd.read_csv(os.path.join(benchmark_specific_folder, file))
                    class_df['Benchmark'] = benchmark_name
                    class_reductions_data.append(class_df)
        
        if class_reductions_data:
            class_reductions_df = pd.concat(class_reductions_data, ignore_index=True)
        else:
            class_reductions_df = pd.DataFrame()
        
        # Sort by benchmark name for consistent ordering
        summary_df = summary_df.sort_values('Benchmark').reset_index(drop=True)
        
        return summary_df, class_reductions_df
    
    def create_reduction_overview(self, summary_df: pd.DataFrame) -> None:
        """
        Create comprehensive reduction overview with multiple metrics.
        
        Args:
            summary_df: DataFrame with benchmark summary data
        """
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        fig.suptitle('LTL Formula Reduction Analysis Overview', fontsize=16, fontweight='bold')
        
        benchmarks = summary_df['Benchmark']
        reductions = summary_df['Reduction_Percentage']
        original_counts = summary_df['Original_Count']
        optimized_counts = summary_df['Optimized_Count']
        
        # 1. Reduction Percentage by Benchmark
        bars1 = ax1.bar(range(len(benchmarks)), reductions, alpha=0.7, color='forestgreen')
        ax1.set_xlabel('Benchmark Index')
        ax1.set_ylabel('Reduction Percentage (%)')
        ax1.set_title('Formula Reduction by Benchmark')
        ax1.grid(True, alpha=0.3, axis='y')
        ax1.set_ylim(0, max(reductions) * 1.1)
        
        # Highlight exceptional reductions
        high_reduction_threshold = np.percentile(reductions, 75)
        for i, (bar, reduction) in enumerate(zip(bars1, reductions)):
            if reduction >= high_reduction_threshold:
                bar.set_color('darkgreen')
                bar.set_alpha(0.9)
        
        # Add average line
        avg_reduction = reductions.mean()
        ax1.axhline(y=avg_reduction, color='red', linestyle='--', linewidth=2, 
                   label=f'Average: {avg_reduction:.1f}%')
        ax1.legend()
        
        # 2. Original vs Optimized Formula Counts
        x_pos = np.arange(len(benchmarks))
        width = 0.35
        
        ax2.bar(x_pos - width/2, original_counts, width, label='Original', alpha=0.7, color='lightcoral')
        ax2.bar(x_pos + width/2, optimized_counts, width, label='Optimized', alpha=0.7, color='skyblue')
        ax2.set_xlabel('Benchmark Index')
        ax2.set_ylabel('Formula Count')
        ax2.set_title('Original vs Optimized Formula Counts')
        ax2.legend()
        ax2.grid(True, alpha=0.3, axis='y')
        
        # 3. Reduction Efficiency vs Original Size
        formula_savings = original_counts - optimized_counts
        ax3.scatter(original_counts, formula_savings, alpha=0.6, s=60, color='purple')
        ax3.set_xlabel('Original Formula Count')
        ax3.set_ylabel('Formulas Saved')
        ax3.set_title('Reduction Efficiency vs Problem Size')
        ax3.grid(True, alpha=0.3)
        
        # Add trend line
        z = np.polyfit(original_counts, formula_savings, 1)
        p = np.poly1d(z)
        ax3.plot(original_counts, p(original_counts), "r--", alpha=0.8, linewidth=2)
        
        # 4. Reduction Distribution
        ax4.hist(reductions, bins=15, alpha=0.7, color='orange', edgecolor='black')
        ax4.set_xlabel('Reduction Percentage (%)')
        ax4.set_ylabel('Frequency')
        ax4.set_title('Distribution of Reduction Percentages')
        ax4.grid(True, alpha=0.3, axis='y')
        ax4.axvline(avg_reduction, color='red', linestyle='--', linewidth=2, 
                   label=f'Mean: {avg_reduction:.1f}%')
        ax4.legend()
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'reduction_overview.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Reduction overview saved to: {os.path.join(self.output_folder, 'reduction_overview.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_performance_analysis(self, summary_df: pd.DataFrame) -> None:
        """
        Create detailed performance analysis charts.
        
        Args:
            summary_df: DataFrame with benchmark summary data
        """
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        fig.suptitle('LTL Optimization Performance Analysis', fontsize=16, fontweight='bold')
        
        # 1. Processing Time vs Problem Size
        ax1.scatter(summary_df['Total_Formulas'], summary_df['Total_Time'], 
                   alpha=0.6, s=60, color='steelblue')
        ax1.set_xlabel('Total Formulas')
        ax1.set_ylabel('Processing Time (seconds)')
        ax1.set_title('Processing Time vs Problem Size')
        ax1.set_yscale('log')
        ax1.grid(True, alpha=0.3)
        
        # Add trend line
        valid_mask = (summary_df['Total_Formulas'] > 0) & (summary_df['Total_Time'] > 0)
        if valid_mask.sum() > 1:
            log_formulas = np.log(summary_df['Total_Formulas'][valid_mask])
            log_times = np.log(summary_df['Total_Time'][valid_mask])
            z = np.polyfit(log_formulas, log_times, 1)
            p = np.poly1d(z)
            sorted_formulas = np.sort(summary_df['Total_Formulas'][valid_mask])
            ax1.plot(sorted_formulas, np.exp(p(np.log(sorted_formulas))), 
                    "r--", alpha=0.8, linewidth=2, label=f'Trend (slope: {z[0]:.2f})')
            ax1.legend()
        
        # 2. Time per Formula Analysis
        time_per_formula = summary_df['Time_Per_Formula']
        ax2.bar(range(len(summary_df)), time_per_formula, alpha=0.7, color='darkorange')
        ax2.set_xlabel('Benchmark Index')
        ax2.set_ylabel('Time per Formula (seconds)')
        ax2.set_title('Processing Efficiency by Benchmark')
        ax2.set_yscale('log')
        ax2.grid(True, alpha=0.3, axis='y')
        
        # 3. Equivalence Class Analysis
        ax3.scatter(summary_df['Total_Classes'], summary_df['Reduction_Percentage'], 
                   alpha=0.6, s=60, color='green')
        ax3.set_xlabel('Number of Equivalence Classes')
        ax3.set_ylabel('Reduction Percentage (%)')
        ax3.set_title('Reduction vs Equivalence Class Count')
        ax3.grid(True, alpha=0.3)
        
        # 4. Multi-Class vs Single-Class Analysis
        multi_class_ratio = summary_df['Multi_Formula_Classes'] / summary_df['Total_Classes'] * 100
        ax4.scatter(multi_class_ratio, summary_df['Reduction_Percentage'], 
                   alpha=0.6, s=60, color='purple')
        ax4.set_xlabel('Multi-Formula Classes (%)')
        ax4.set_ylabel('Reduction Percentage (%)')
        ax4.set_title('Reduction vs Multi-Class Ratio')
        ax4.grid(True, alpha=0.3)
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'performance_analysis.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Performance analysis saved to: {os.path.join(self.output_folder, 'performance_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_detailed_reduction_chart(self, summary_df: pd.DataFrame) -> None:
        """
        Create detailed benchmark-by-benchmark reduction chart.
        
        Args:
            summary_df: DataFrame with benchmark summary data
        """
        plt.figure(figsize=(20, 8))
        
        benchmarks = summary_df['Benchmark']
        reductions = summary_df['Reduction_Percentage']
        
        # Create color map based on reduction percentage
        colors = plt.cm.RdYlGn(reductions / 100)  # Normalize to 0-1 for colormap
        
        bars = plt.bar(range(len(benchmarks)), reductions, color=colors, alpha=0.8)
        
        plt.xlabel('Benchmark Name', fontsize=12)
        plt.ylabel('Reduction Percentage (%)', fontsize=12)
        plt.title('LTL Formula Reduction by Benchmark', fontsize=14, fontweight='bold')
        plt.xticks(range(len(benchmarks)), benchmarks, rotation=45, ha='right')
        plt.grid(True, alpha=0.3, axis='y')
        
        # Add value labels on bars
        for i, (bar, reduction) in enumerate(zip(bars, reductions)):
            if reduction > 5:  # Only label significant reductions
                plt.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 0.5, 
                        f'{reduction:.1f}%', ha='center', va='bottom', fontsize=8)
        
        # Add average and median lines
        avg_reduction = reductions.mean()
        median_reduction = reductions.median()
        plt.axhline(y=avg_reduction, color='red', linestyle='--', linewidth=2, 
                   label=f'Average: {avg_reduction:.1f}%')
        plt.axhline(y=median_reduction, color='blue', linestyle='-.', linewidth=2, 
                   label=f'Median: {median_reduction:.1f}%')
        
        plt.legend()
        plt.ylim(0, max(reductions) * 1.1)
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'detailed_reduction_chart.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Detailed reduction chart saved to: {os.path.join(self.output_folder, 'detailed_reduction_chart.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_class_reduction_analysis(self, class_reductions_df: pd.DataFrame) -> None:
        """
        Create analysis of per-class reduction patterns.
        
        Args:
            class_reductions_df: DataFrame with per-class reduction data
        """
        if class_reductions_df.empty:
            print("No class reduction data available for analysis.")
            return
        
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        fig.suptitle('Equivalence Class Reduction Analysis', fontsize=16, fontweight='bold')
        
        # 1. Class Size vs Reduction
        ax1.scatter(class_reductions_df['original_count'], 
                   class_reductions_df['reduction_percentage'], 
                   alpha=0.6, s=40, color='steelblue')
        ax1.set_xlabel('Original Class Size')
        ax1.set_ylabel('Class Reduction (%)')
        ax1.set_title('Reduction vs Original Class Size')
        ax1.grid(True, alpha=0.3)
        
        # 2. Distribution of Class Reductions
        ax2.hist(class_reductions_df['reduction_percentage'], bins=20, 
                alpha=0.7, color='green', edgecolor='black')
        ax2.set_xlabel('Class Reduction Percentage (%)')
        ax2.set_ylabel('Frequency')
        ax2.set_title('Distribution of Class Reductions')
        ax2.grid(True, alpha=0.3, axis='y')
        
        # 3. Class Size Distribution
        ax3.hist(class_reductions_df['original_count'], bins=15, 
                alpha=0.7, color='orange', edgecolor='black')
        ax3.set_xlabel('Original Class Size')
        ax3.set_ylabel('Frequency')
        ax3.set_title('Distribution of Class Sizes')
        ax3.grid(True, alpha=0.3, axis='y')
        
        # 4. Reduction Efficiency by Class Size
        class_sizes = class_reductions_df['original_count']
        size_bins = [2, 5, 10, 20, float('inf')]
        size_labels = ['2-4', '5-9', '10-19', '20+']
        
        binned_reductions = []
        for i in range(len(size_bins)-1):
            mask = (class_sizes >= size_bins[i]) & (class_sizes < size_bins[i+1])
            if mask.any():
                binned_reductions.append(class_reductions_df['reduction_percentage'][mask].mean())
            else:
                binned_reductions.append(0)
        
        ax4.bar(size_labels, binned_reductions, alpha=0.7, color='purple')
        ax4.set_xlabel('Class Size Range')
        ax4.set_ylabel('Average Reduction (%)')
        ax4.set_title('Average Reduction by Class Size')
        ax4.grid(True, alpha=0.3, axis='y')
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'class_reduction_analysis.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Class reduction analysis saved to: {os.path.join(self.output_folder, 'class_reduction_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def generate_comprehensive_report(self, summary_df: pd.DataFrame, 
                                    class_reductions_df: pd.DataFrame) -> Dict:
        """
        Generate comprehensive statistical report.
        
        Args:
            summary_df: DataFrame with benchmark summary data
            class_reductions_df: DataFrame with per-class reduction data
            
        Returns:
            Dictionary with comprehensive statistics
        """
        # Overall statistics
        total_original = summary_df['Original_Count'].sum()
        total_optimized = summary_df['Optimized_Count'].sum()
        overall_reduction = (total_original - total_optimized) / total_original * 100
        
        stats = {
            # Basic metrics
            'total_benchmarks': len(summary_df),
            'total_original_formulas': total_original,
            'total_optimized_formulas': total_optimized,
            'overall_reduction_percentage': overall_reduction,
            'formulas_eliminated': total_original - total_optimized,
            
            # Reduction statistics
            'avg_reduction_per_benchmark': summary_df['Reduction_Percentage'].mean(),
            'median_reduction_per_benchmark': summary_df['Reduction_Percentage'].median(),
            'max_reduction': summary_df['Reduction_Percentage'].max(),
            'min_reduction': summary_df['Reduction_Percentage'].min(),
            'std_reduction': summary_df['Reduction_Percentage'].std(),
            
            # Performance statistics
            'total_processing_time': summary_df['Total_Time'].sum(),
            'avg_processing_time': summary_df['Total_Time'].mean(),
            'avg_time_per_formula': summary_df['Time_Per_Formula'].mean(),
            'fastest_benchmark': summary_df.loc[summary_df['Time_Per_Formula'].idxmin(), 'Benchmark'],
            'slowest_benchmark': summary_df.loc[summary_df['Time_Per_Formula'].idxmax(), 'Benchmark'],
            
            # Equivalence class statistics
            'total_equivalence_classes': summary_df['Total_Classes'].sum(),
            'avg_classes_per_benchmark': summary_df['Total_Classes'].mean(),
            'total_multi_formula_classes': summary_df['Multi_Formula_Classes'].sum(),
            'multi_class_ratio': summary_df['Multi_Formula_Classes'].sum() / summary_df['Total_Classes'].sum() * 100,
            
            # Best/worst performers
            'best_reduction_benchmark': summary_df.loc[summary_df['Reduction_Percentage'].idxmax(), 'Benchmark'],
            'worst_reduction_benchmark': summary_df.loc[summary_df['Reduction_Percentage'].idxmin(), 'Benchmark'],
            'largest_benchmark': summary_df.loc[summary_df['Total_Formulas'].idxmax(), 'Benchmark'],
            'smallest_benchmark': summary_df.loc[summary_df['Total_Formulas'].idxmin(), 'Benchmark'],
        }
        
        # Class-level statistics if available
        if not class_reductions_df.empty:
            stats.update({
                'total_analyzed_classes': len(class_reductions_df),
                'avg_class_reduction': class_reductions_df['reduction_percentage'].mean(),
                'median_class_reduction': class_reductions_df['reduction_percentage'].median(),
                'avg_original_class_size': class_reductions_df['original_count'].mean(),
                'max_class_size': class_reductions_df['original_count'].max(),
                'classes_with_100_percent_reduction': (class_reductions_df['reduction_percentage'] == 100).sum(),
                'classes_with_no_reduction': (class_reductions_df['reduction_percentage'] == 0).sum(),
            })
        
        return stats
    
    def print_analysis_report(self, stats: Dict) -> None:
        """
        Print comprehensive analysis report to console.
        
        Args:
            stats: Statistics dictionary from generate_comprehensive_report
        """
        print("\n" + "=" * 80)
        print("LTL FORMULA REDUCTION ANALYSIS REPORT")
        print("=" * 80)
        
        print("\nOVERALL REDUCTION PERFORMANCE:")
        print(f"  Total benchmarks analyzed: {stats['total_benchmarks']}")
        print(f"  Original formulas: {stats['total_original_formulas']:,}")
        print(f"  Optimized formulas: {stats['total_optimized_formulas']:,}")
        print(f"  Formulas eliminated: {stats['formulas_eliminated']:,}")
        print(f"  Overall reduction: {stats['overall_reduction_percentage']:.2f}%")
        
        print("\nREDUCTION STATISTICS:")
        print(f"  Average reduction per benchmark: {stats['avg_reduction_per_benchmark']:.2f}%")
        print(f"  Median reduction per benchmark: {stats['median_reduction_per_benchmark']:.2f}%")
        print(f"  Best reduction: {stats['max_reduction']:.2f}%")
        print(f"  Worst reduction: {stats['min_reduction']:.2f}%")
        print(f"  Standard deviation: {stats['std_reduction']:.2f}%")
        
        print("\nPERFORMANCE CHARACTERISTICS:")
        print(f"  Total processing time: {stats['total_processing_time']:.2f} seconds")
        print(f"  Average time per benchmark: {stats['avg_processing_time']:.3f} seconds")
        print(f"  Average time per formula: {stats['avg_time_per_formula']:.6f} seconds")
        
        print("\nEQUIVALENCE CLASS ANALYSIS:")
        print(f"  Total equivalence classes: {stats['total_equivalence_classes']:,}")
        print(f"  Average classes per benchmark: {stats['avg_classes_per_benchmark']:.1f}")
        print(f"  Multi-formula classes: {stats['total_multi_formula_classes']:,}")
        print(f"  Multi-class ratio: {stats['multi_class_ratio']:.2f}%")
        
        print("\nBEST/WORST PERFORMERS:")
        print(f"  Best reduction: {stats['best_reduction_benchmark']} ({stats['max_reduction']:.1f}%)")
        print(f"  Worst reduction: {stats['worst_reduction_benchmark']} ({stats['min_reduction']:.1f}%)")
        print(f"  Fastest processing: {stats['fastest_benchmark']}")
        print(f"  Slowest processing: {stats['slowest_benchmark']}")
        print(f"  Largest benchmark: {stats['largest_benchmark']}")
        print(f"  Smallest benchmark: {stats['smallest_benchmark']}")
        
        if 'total_analyzed_classes' in stats:
            print("\nCLASS-LEVEL ANALYSIS:")
            print(f"  Classes analyzed: {stats['total_analyzed_classes']:,}")
            print(f"  Average class reduction: {stats['avg_class_reduction']:.2f}%")
            print(f"  Average original class size: {stats['avg_original_class_size']:.1f}")
            print(f"  Largest class size: {stats['max_class_size']}")
            print(f"  Classes with 100% reduction: {stats['classes_with_100_percent_reduction']}")
            print(f"  Classes with no reduction: {stats['classes_with_no_reduction']}")
        
        print("=" * 80)
    
    def save_analysis_results(self, stats: Dict, summary_df: pd.DataFrame) -> None:
        """
        Save analysis results to CSV files.
        
        Args:
            stats: Statistics dictionary
            summary_df: Summary DataFrame
        """
        if not self.save_plots:
            return
        
        # Save comprehensive statistics
        stats_df = pd.DataFrame(list(stats.items()), columns=['Metric', 'Value'])
        stats_path = os.path.join(self.output_folder, 'reduction_statistics.csv')
        stats_df.to_csv(stats_path, index=False)
        print(f"Statistics saved to: {stats_path}")
        
        # Save enhanced summary with additional calculated metrics
        enhanced_summary = summary_df.copy()
        enhanced_summary['Formula_Savings'] = enhanced_summary['Original_Count'] - enhanced_summary['Optimized_Count']
        enhanced_summary['Efficiency_Score'] = enhanced_summary['Reduction_Percentage'] / enhanced_summary['Time_Per_Formula']
        enhanced_summary['Class_Utilization'] = enhanced_summary['Multi_Formula_Classes'] / enhanced_summary['Total_Classes'] * 100
        
        enhanced_path = os.path.join(self.output_folder, 'enhanced_summary.csv')
        enhanced_summary.to_csv(enhanced_path, index=False)
        print(f"Enhanced summary saved to: {enhanced_path}")
    
    def analyze_ltl_reduction(self, results_folder: str = "optimized_results") -> Tuple[pd.DataFrame, Dict]:
        """
        Complete LTL reduction analysis with all visualizations and statistics.
        
        Args:
            results_folder: Path to optimization results folder
            
        Returns:
            Tuple of (summary_df, comprehensive_stats)
        """
        print(f"Loading LTL optimization results from: {results_folder}")
        summary_df, class_reductions_df = self.load_optimization_data(results_folder)
        
        print(f"Analyzing {len(summary_df)} benchmark optimization results...")
        
        # Generate all visualizations
        self.create_detailed_reduction_chart(summary_df)
        self.create_reduction_overview(summary_df)
        self.create_performance_analysis(summary_df)
        self.create_class_reduction_analysis(class_reductions_df)
        
        # Generate comprehensive statistics
        stats = self.generate_comprehensive_report(summary_df, class_reductions_df)
        
        # Print and save results
        self.print_analysis_report(stats)
        self.save_analysis_results(stats, summary_df)
        
        print(f"\nLTL reduction analysis complete! Results saved to: {self.output_folder}")
        return summary_df, stats


def main():
    """Main execution function."""
    
    # Configuration
    RESULTS_FOLDER = "optimized_results"
    SAVE_PLOTS = True
    SHOW_PLOTS = False  # Set to True to display plots interactively
    OUTPUT_FOLDER = "ltl_reduction_analysis"
    
    # Initialize analyzer
    analyzer = LTLReductionAnalyzer(
        save_plots=SAVE_PLOTS,
        show_plots=SHOW_PLOTS,
        output_folder=OUTPUT_FOLDER
    )
    
    # Run analysis
    if os.path.exists(RESULTS_FOLDER):
        summary_df, stats = analyzer.analyze_ltl_reduction(RESULTS_FOLDER)
        
        # Print key findings
        print(f"\nKEY FINDINGS:")
        print(f"  Overall formula reduction achieved: {stats['overall_reduction_percentage']:.1f}%")
        print(f"  Average processing time per formula: {stats['avg_time_per_formula']:.6f} seconds")
        print(f"  {stats['formulas_eliminated']:,} formulas eliminated across all benchmarks")
        
    else:
        print(f"Error: Results folder '{RESULTS_FOLDER}' not found.")
        print("Please run the LTL optimization process first to generate results.")


if __name__ == "__main__":
    main()
