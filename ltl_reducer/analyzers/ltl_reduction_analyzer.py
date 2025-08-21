"""
LTL Formula Reduction Performance Analysis Tool

This script provides comprehensive analysis and visualization of LTL formula
optimization results, including reduction metrics, performance characteristics,
comparative analysis across benchmarks, zero-reduction cases, and handling
of skewed formula count distributions.
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os
import seaborn as sns
from typing import Optional, Tuple, Dict, List
from pathlib import Path
from datetime import datetime
import warnings
from mpl_toolkits.axes_grid1.inset_locator import inset_axes
from matplotlib.patches import Rectangle
warnings.filterwarnings('ignore')

# Try to import seaborn for enhanced visualizations
try:
    import seaborn as sns
    HAS_SEABORN = True
except ImportError:
    HAS_SEABORN = False


class LTLReductionAnalyzer:
    """
    Comprehensive analyzer for LTL formula reduction performance with:
    - Standard reduction analysis and visualizations
    - Zero reduction cases analysis
    - Timing characteristics analysis  
    - Handling of skewed formula count distributions
    - Publication-quality visualizations
    """
    
    def __init__(self, save_plots: bool = True, show_plots: bool = False, 
                 output_folder: str = "ltl_reduction_analysis", 
                 results_file: str = "optimized_results/calculated_benchmark_summary.csv"):
        """
        Initialize the LTL reduction analyzer.
        
        Args:
            save_plots: Whether to save plots to files
            show_plots: Whether to display plots interactively
            output_folder: Folder to save analysis results
            results_file: Path to the calculated benchmark summary CSV
        """
        self.save_plots = save_plots
        self.show_plots = show_plots
        self.output_folder = output_folder
        self.results_file = results_file
        
        if self.save_plots and not os.path.exists(self.output_folder):
            os.makedirs(self.output_folder)
        
        # Set style for publication-quality plots
        plt.style.use('default')
        plt.rcParams.update({
            'font.size': 8,
            'axes.titlesize': 8,
            'axes.labelsize': 8,
            'xtick.labelsize': 8,
            'ytick.labelsize': 8,
            'legend.fontsize': 8,
            'figure.titlesize': 8, 
            'legend.fontsize': 8
           
        })
        
        if HAS_SEABORN:
            sns.set_palette("husl")
        
        # Color palette for comprehensive analysis
        self.colors = {
            'zero_reduction': '#E74C3C',     # Red for zero reduction
            'low_reduction': '#F39C12',      # Orange for low reduction
            'medium_reduction': '#F1C40F',   # Yellow for medium reduction
            'high_reduction': '#27AE60',     # Green for high reduction
            'primary': '#3498DB',            # Blue
            'secondary': '#9B59B6',          # Purple
            'neutral': '#95A5A6'             # Gray
        }
        
        if HAS_SEABORN:
            sns.set_palette("husl")
    
    def load_optimization_data(self, results_folder: str = "optimized_results") -> Tuple[pd.DataFrame, pd.DataFrame]:
        """
        Load LTL optimization results from the results folder.
        Handles cases where overall summary doesn't exist by building from individual files.
        
        Args:
            results_folder: Path to optimization results folder
            
        Returns:
            Tuple of (summary_df, class_reductions_df)
        """
        # Try to load main benchmark summary first
        summary_path = os.path.join(results_folder, "benchmark_summary.csv")
        summary_df = None
        
        if os.path.exists(summary_path):
            print(f"Loading existing benchmark summary from: {summary_path}")
            summary_df = pd.read_csv(summary_path)
        else:
            print(f"Benchmark summary not found at: {summary_path}")
            print("Building summary from individual benchmark files...")
            summary_df = self._build_summary_from_individual_files(results_folder)
        
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
        if summary_df is not None and not summary_df.empty:
            summary_df = summary_df.sort_values('Benchmark').reset_index(drop=True)
        
        return summary_df, class_reductions_df
    
    def _build_summary_from_individual_files(self, results_folder: str) -> pd.DataFrame:
        """
        Build comprehensive summary from individual benchmark files.
        
        Args:
            results_folder: Path to optimization results folder
            
        Returns:
            DataFrame with calculated summary statistics
        """
        benchmark_specific_folder = os.path.join(results_folder, "benchmark_specific")
        
        if not os.path.exists(benchmark_specific_folder):
            raise FileNotFoundError(f"Neither summary nor individual files found. Expected: {benchmark_specific_folder}")
        
        summary_data = []
        
        # Process each benchmark's individual files
        for file in sorted(os.listdir(benchmark_specific_folder)):
            if file.endswith("_summary.csv"):
                benchmark_name = file.replace("_metrics_summary.csv", "")
                
                # Load summary metrics
                summary_file_path = os.path.join(benchmark_specific_folder, file)
                benchmark_metrics = pd.read_csv(summary_file_path)
                
                if len(benchmark_metrics) > 0:
                    metrics_row = benchmark_metrics.iloc[0]  # Should be single row
                    
                    # Extract key metrics and calculate derived ones
                    summary_entry = {
                        'Benchmark': benchmark_name,
                        'Total_Formulas': metrics_row.get('total_formulas', 0),
                        'Total_Classes': metrics_row.get('total_classes', 0),
                        'Single_Formula_Classes': metrics_row.get('single_formula_classes', 0),
                        'Multi_Formula_Classes': metrics_row.get('multi_formula_classes', 0),
                        'Original_Count': metrics_row.get('original_formula_count', 0),
                        'Optimized_Count': metrics_row.get('optimized_formula_count', 0),
                        'Reduction_Percentage': metrics_row.get('reduction_percentage', 0.0),
                        'Equivalence_Class_Time': metrics_row.get('equivalence_class_time', 0.0),
                        'Containment_Analysis_Time': metrics_row.get('containment_analysis_time', 0.0),
                        'Total_Time': metrics_row.get('total_time', 0.0),
                    }
                    
                    # Calculate derived metrics
                    if summary_entry['Total_Formulas'] > 0:
                        summary_entry['Time_Per_Formula'] = summary_entry['Total_Time'] / summary_entry['Total_Formulas']
                    else:
                        summary_entry['Time_Per_Formula'] = 0.0
                    
                    summary_data.append(summary_entry)
                    print(f"  Processed: {benchmark_name}")
        
        if not summary_data:
            raise ValueError("No valid benchmark summary files found to build overview from")
        
        summary_df = pd.DataFrame(summary_data)
        
        # Save the calculated summary for future use
        calculated_summary_path = os.path.join(results_folder, "calculated_benchmark_summary.csv")
        summary_df.to_csv(calculated_summary_path, index=False)
        print(f"Calculated summary saved to: {calculated_summary_path}")
        
        return summary_df
    
    def create_reduction_overview(self, summary_df: pd.DataFrame) -> None:
        """
        Create comprehensive reduction overview with multiple metrics.
        
        Args:
            summary_df: DataFrame with benchmark summary data
        """
        if summary_df.empty:
            print("No data available for reduction overview.")
            return
        
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
        
        if len(reductions) > 0 and max(reductions) > 0:
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
        
        # Add trend line if we have enough data points
        if len(original_counts) > 1:
            try:
                z = np.polyfit(original_counts, formula_savings, 1)
                p = np.poly1d(z)
                ax3.plot(original_counts, p(original_counts), "r--", alpha=0.8, linewidth=2)
            except:
                pass  # Skip trend line if fitting fails
        
        # 4. Reduction Distribution
        if len(reductions) > 0:
            ax4.hist(reductions, bins=min(15, len(reductions)), alpha=0.7, color='orange', edgecolor='black')
            ax4.set_xlabel('Reduction Percentage (%)')
            ax4.set_ylabel('Frequency')
            ax4.set_title('Distribution of Reduction Percentages')
            ax4.grid(True, alpha=0.3, axis='y')
            
            avg_reduction = reductions.mean()
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
    

    def create_zero_vs_nonzero_scatter(self, df: pd.DataFrame) -> None:
        """
        Create a single scatter plot comparing zero reduction vs non-zero reduction cases.
        
        Args:
            df: DataFrame with benchmark data
        """
        zero_reduction = df[df['Reduction_Percentage'] == 0.0].copy()
        non_zero = df[df['Reduction_Percentage'] > 0.0].copy()
        
        plt.figure(figsize=(6, 4))
        
        # Plot zero reduction cases with larger, more prominent markers
        plt.scatter(zero_reduction['Total_Formulas'], zero_reduction['Total_Time'],
                s=80, alpha=0.8, color=self.colors['zero_reduction'], 
                edgecolors='white', linewidth=1, label=f'Zero Reduction (n={len(zero_reduction)})')
        
        # Plot non-zero reduction cases with smaller markers
        plt.scatter(non_zero['Total_Formulas'], non_zero['Total_Time'],
                s=40, alpha=0.6, color=self.colors['primary'], 
                label=f'Non-Zero Reduction (n={len(non_zero)})')
        
        # Add trend line analysis
        valid_mask = (df['Total_Formulas'] > 0) & (df['Total_Time'] > 0)
        if valid_mask.sum() > 1:
            log_formulas = np.log(df['Total_Formulas'][valid_mask])
            log_times = np.log(df['Total_Time'][valid_mask])
            z = np.polyfit(log_formulas, log_times, 1)
            p = np.poly1d(z)
            sorted_formulas = np.sort(df['Total_Formulas'][valid_mask])
            plt.plot(sorted_formulas, np.exp(p(np.log(sorted_formulas))), 
                    "r--", alpha=0.8, linewidth=2, label=f'Trend (slope: {z[0]:.2f})', color='darkorange')

        # Create inset for zoomed view
        
        plt.xlabel('Number of Formulas', fontsize=12)
        plt.ylabel('Total Processing Time (seconds)', fontsize=12)
        #plt.title('Processing Time vs Formula Count: Zero vs Non-Zero Reduction', 
                #fontsize=14, fontweight='bold')
        plt.legend(fontsize=11)
        plt.grid(False, alpha=0.3)
        #plt.yscale('log')  # Log scale due to wide range of processing times
        #plt.xscale('symlog', linthresh=10)
        plt.xscale('log')
        #plt.xlim(0, 15)
        # Add some statistics as text annotations



        if len(zero_reduction) > 0 and len(non_zero) > 0 and False:
            zero_avg_time = zero_reduction['Total_Time'].mean()
            nonzero_avg_time = non_zero['Total_Time'].mean()
            zero_avg_formulas = zero_reduction['Total_Formulas'].mean()
            nonzero_avg_formulas = non_zero['Total_Formulas'].mean()
            
            # Add trend line interpretation
            if valid_mask.sum() > 1:
                trend_interpretation = "Superlinear" if z[0] > 1 else "Sublinear" if z[0] < 1 else "Linear"
                stats_text = f"""Statistics:
    Zero Reduction: {zero_avg_formulas:.1f} avg formulas, {zero_avg_time:.4f}s avg time
    Non-Zero Reduction: {nonzero_avg_formulas:.1f} avg formulas, {nonzero_avg_time:.4f}s avg time
    Trend: {trend_interpretation} scaling (slope: {z[0]:.2f})"""
            else:
                stats_text = f"""Statistics:
    Zero Reduction: {zero_avg_formulas:.1f} avg formulas, {zero_avg_time:.4f}s avg time
    Non-Zero Reduction: {nonzero_avg_formulas:.1f} avg formulas, {nonzero_avg_time:.4f}s avg time"""
            
            plt.text(0.02, 0.98, stats_text, transform=plt.gca().transAxes, 
                    fontsize=10, verticalalignment='top', 
                    bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.8))
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'zero_vs_nonzero_scatter.pgf'), dpi=300, bbox_inches='tight')
            plt.savefig(os.path.join(self.output_folder, 'zero_vs_nonzero_scatter.png'), dpi=300, bbox_inches='tight')
            print(f"Zero vs Non-Zero scatter plot saved to: {os.path.join(self.output_folder, 'zero_vs_nonzero_scatter.png')}")
        
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
        
        # 3. Detailed Processing Time by Benchmark (similar to detailed_reduction_chart)
        ax3.remove()  # Remove the subplot to create a larger plot
        ax4.remove()  # Remove the subplot to create a larger plot
        
        # Create a single large subplot for the detailed timing chart
        ax_detailed = plt.subplot2grid((2, 2), (1, 0), colspan=2, fig=fig)
        
        benchmarks = summary_df['Benchmark']
        times = summary_df['Total_Time']
        
        # Create color map based on processing time (reversed so faster = green, slower = red)
        # Normalize times to 0-1 range for colormap
        time_normalized = (times - times.min()) / (times.max() - times.min() + 1e-8)
        colors = plt.cm.RdYlGn_r(time_normalized)  # Reversed colormap
        
        bars = ax_detailed.bar(range(len(benchmarks)), times, color=colors, alpha=0.8)
        
        ax_detailed.set_xlabel('Benchmark Name', fontsize=12)
        ax_detailed.set_ylabel('Processing Time (seconds)', fontsize=12)
        ax_detailed.set_title('LTL Processing Time by Benchmark', fontsize=14, fontweight='bold')
        ax_detailed.set_xticks(range(len(benchmarks)))
        ax_detailed.set_xticklabels(benchmarks, rotation=45, ha='right', fontsize=9)
        ax_detailed.grid(True, alpha=0.3, axis='y')
        
        # Add value labels on bars (for significant times)
        for i, (bar, time_val) in enumerate(zip(bars, times)):
            if time_val > times.max() * 0.1:  # Only label bars above 10% of max time
                if time_val < 1:
                    label = f'{time_val:.3f}s'
                elif time_val < 10:
                    label = f'{time_val:.2f}s'
                else:
                    label = f'{time_val:.1f}s'
                ax_detailed.text(bar.get_x() + bar.get_width()/2, bar.get_height() + times.max() * 0.01, 
                        label, ha='center', va='bottom', fontsize=8)
        
        # Add average and median lines
        avg_time = times.mean()
        median_time = times.median()
        ax_detailed.axhline(y=avg_time, color='red', linestyle='--', linewidth=2, 
                   label=f'Average: {avg_time:.3f}s')
        ax_detailed.axhline(y=median_time, color='blue', linestyle='-.', linewidth=2, 
                   label=f'Median: {median_time:.3f}s')
        
        ax_detailed.legend()
        ax_detailed.set_ylim(0, times.max() * 1.1)
        
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
    def create_detailed_reduction_chart_no_zeros(self, summary_df: pd.DataFrame) -> None:
        """
        Create detailed benchmark-by-benchmark reduction chart.
        
        Args:
            summary_df: DataFrame with benchmark summary data
        """
        plt.figure(figsize=(20, 8))
        temp = summary_df[summary_df['Reduction_Percentage'] > 0]
        benchmarks = temp['Benchmark']
        reductions = temp['Reduction_Percentage']
        
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
            plt.savefig(os.path.join(self.output_folder, 'detailed_reduction_chart_no_zeros.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Detailed reduction chart with no zeros saved to: {os.path.join(self.output_folder, 'detailed_reduction_chart_no_zeros.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
            
    def create_detailed_timing_chart(self, summary_df: pd.DataFrame) -> None:
        """
        Create detailed benchmark-by-benchmark timing chart (similar to detailed_reduction_chart).
        
        Args:
            summary_df: DataFrame with benchmark summary data
        """
        plt.figure(figsize=(20, 8))
        
        benchmarks = summary_df['Benchmark']
        times = summary_df['Total_Time']
        
        # Create color map based on processing time (reversed so faster = green, slower = red)
        # Normalize times to 0-1 range for colormap
        time_normalized = (times - times.min()) / (times.max() - times.min() + 1e-8)
        colors = plt.cm.RdYlGn_r(time_normalized)  # Reversed colormap
        
        bars = plt.bar(range(len(benchmarks)), times, color=colors, alpha=0.8)
        
        plt.xlabel('Benchmark Name', fontsize=12)
        plt.ylabel('Processing Time (seconds)', fontsize=12)
        plt.title('LTL Processing Time by Benchmark', fontsize=14, fontweight='bold')
        plt.xticks(range(len(benchmarks)), benchmarks, rotation=45, ha='right')
        plt.grid(True, alpha=0.3, axis='y')
        
        # Add value labels on bars (for significant times)
        for i, (bar, time_val) in enumerate(zip(bars, times)):
            if time_val > times.max() * 0.1:  # Only label bars above 10% of max time
                if time_val < 1:
                    label = f'{time_val:.3f}s'
                elif time_val < 10:
                    label = f'{time_val:.2f}s'
                else:
                    label = f'{time_val:.1f}s'
                plt.text(bar.get_x() + bar.get_width()/2, bar.get_height() + times.max() * 0.01, 
                        label, ha='center', va='bottom', fontsize=8)
        
        # Add average and median lines
        avg_time = times.mean()
        median_time = times.median()
        plt.axhline(y=avg_time, color='red', linestyle='--', linewidth=2, 
                   label=f'Average: {avg_time:.3f}s')
        plt.axhline(y=median_time, color='blue', linestyle='-.', linewidth=2, 
                   label=f'Median: {median_time:.3f}s')
        
        plt.legend()
        plt.ylim(0, times.max() * 1.1)
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'detailed_timing_chart.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Detailed timing chart saved to: {os.path.join(self.output_folder, 'detailed_timing_chart.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
            
    def create_performance_outliers_analysis(self, summary_df: pd.DataFrame) -> None:
        """
        Create comprehensive analysis of worst performing, most efficient, and slowest benchmarks.
        
        Args:
            summary_df: DataFrame with benchmark summary data
        """
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(20, 16))
        fig.suptitle('LTL Benchmark Performance Outliers Analysis', fontsize=18, fontweight='bold')
        
        # 1. Worst Performing Benchmarks (lowest reduction percentage)
        worst_performers = summary_df.nsmallest(15, 'Reduction_Percentage')
        
        colors_worst = plt.cm.Reds(np.linspace(0.3, 0.9, len(worst_performers)))
        bars1 = ax1.barh(range(len(worst_performers)), worst_performers['Reduction_Percentage'],
                        color=colors_worst, alpha=0.8)
        ax1.set_yticks(range(len(worst_performers)))
        ax1.set_yticklabels([name.replace('_000', '') for name in worst_performers['Benchmark']], 
                           fontsize=10)
        ax1.set_xlabel('Reduction Percentage (%)')
        ax1.set_title('15 Worst Performing Benchmarks\n(Lowest Reduction)', fontweight='bold')
        ax1.grid(True, alpha=0.3, axis='x')
        
        # Add value labels
        for i, (bar, reduction) in enumerate(zip(bars1, worst_performers['Reduction_Percentage'])):
            ax1.text(bar.get_width() + 0.5, bar.get_y() + bar.get_height()/2, 
                    f'{reduction:.1f}%', ha='left', va='center', fontsize=9)
        
        # 2. Slowest Benchmarks (highest processing time)
        slowest_benchmarks = summary_df.nlargest(15, 'Total_Time')
        
        colors_slow = plt.cm.Oranges(np.linspace(0.3, 0.9, len(slowest_benchmarks)))
        bars2 = ax2.barh(range(len(slowest_benchmarks)), slowest_benchmarks['Total_Time'],
                        color=colors_slow, alpha=0.8)
        ax2.set_yticks(range(len(slowest_benchmarks)))
        ax2.set_yticklabels([name.replace('_000', '') for name in slowest_benchmarks['Benchmark']], 
                           fontsize=10)
        ax2.set_xlabel('Processing Time (seconds)')
        ax2.set_title('15 Slowest Benchmarks\n(Highest Processing Time)', fontweight='bold')
        ax2.set_xscale('log')
        ax2.grid(True, alpha=0.3, axis='x')
        
        # Add value labels
        for i, (bar, time_val) in enumerate(zip(bars2, slowest_benchmarks['Total_Time'])):
            if time_val < 1:
                label = f'{time_val:.3f}s'
            elif time_val < 10:
                label = f'{time_val:.2f}s'
            elif time_val < 100:
                label = f'{time_val:.1f}s'
            else:
                label = f'{time_val:.0f}s'
            ax2.text(bar.get_width() * 1.1, bar.get_y() + bar.get_height()/2, 
                    label, ha='left', va='center', fontsize=9)
        
        # 3. Least Efficient Benchmarks (highest time per formula)
        summary_df['Time_Per_Formula_Safe'] = summary_df['Total_Time'] / summary_df['Total_Formulas']
        least_efficient = summary_df.nlargest(15, 'Time_Per_Formula_Safe')
        
        colors_inefficient = plt.cm.Purples(np.linspace(0.3, 0.9, len(least_efficient)))
        bars3 = ax3.barh(range(len(least_efficient)), least_efficient['Time_Per_Formula_Safe'],
                        color=colors_inefficient, alpha=0.8)
        ax3.set_yticks(range(len(least_efficient)))
        ax3.set_yticklabels([name.replace('_000', '') for name in least_efficient['Benchmark']], 
                           fontsize=10)
        ax3.set_xlabel('Time per Formula (seconds)')
        ax3.set_title('15 Least Efficient Benchmarks\n(Highest Time per Formula)', fontweight='bold')
        ax3.set_xscale('log')
        ax3.grid(True, alpha=0.3, axis='x')
        
        # Add value labels
        for i, (bar, efficiency) in enumerate(zip(bars3, least_efficient['Time_Per_Formula_Safe'])):
            if efficiency < 0.001:
                label = f'{efficiency:.6f}s'
            elif efficiency < 0.01:
                label = f'{efficiency:.5f}s'
            elif efficiency < 0.1:
                label = f'{efficiency:.4f}s'
            elif efficiency < 1:
                label = f'{efficiency:.3f}s'
            else:
                label = f'{efficiency:.2f}s'
            ax3.text(bar.get_width() * 1.1, bar.get_y() + bar.get_height()/2, 
                    label, ha='left', va='center', fontsize=9)
        
        # 4. Combined Analysis - Problem Benchmarks (combining all issues)
        # Create a composite score: normalize and combine worst aspects
        norm_worst_reduction = (summary_df['Reduction_Percentage'].max() - summary_df['Reduction_Percentage']) / (summary_df['Reduction_Percentage'].max() - summary_df['Reduction_Percentage'].min() + 1e-8)
        norm_slow_time = (summary_df['Total_Time'] - summary_df['Total_Time'].min()) / (summary_df['Total_Time'].max() - summary_df['Total_Time'].min() + 1e-8)
        norm_inefficient = (summary_df['Time_Per_Formula_Safe'] - summary_df['Time_Per_Formula_Safe'].min()) / (summary_df['Time_Per_Formula_Safe'].max() - summary_df['Time_Per_Formula_Safe'].min() + 1e-8)
        
        # Composite problematic score (higher = more problematic)
        summary_df['Problem_Score'] = (norm_worst_reduction * 0.4 + norm_slow_time * 0.3 + norm_inefficient * 0.3)
        most_problematic = summary_df.nlargest(15, 'Problem_Score')
        
        # Create scatter plot showing the relationship
        scatter = ax4.scatter(most_problematic['Total_Time'], most_problematic['Reduction_Percentage'],
                             s=most_problematic['Total_Formulas'] * 3, 
                             c=most_problematic['Problem_Score'], 
                             cmap='Reds', alpha=0.7, edgecolors='black', linewidth=1)
        
        ax4.set_xlabel('Processing Time (seconds)')
        ax4.set_ylabel('Reduction Percentage (%)')
        ax4.set_title('15 Most Problematic Benchmarks\n(Bubble size = Formula count, Color = Problem score)', 
                     fontweight='bold')
        ax4.set_xscale('log')
        ax4.grid(True, alpha=0.3)
        
        # Add colorbar
        cbar = plt.colorbar(scatter, ax=ax4)
        cbar.set_label('Problem Score (higher = more problematic)')
        
        # Annotate the most problematic points
        for i, row in most_problematic.head(5).iterrows():
            ax4.annotate(row['Benchmark'].replace('_000', ''), 
                        (row['Total_Time'], row['Reduction_Percentage']),
                        xytext=(5, 5), textcoords='offset points', 
                        fontsize=8, alpha=0.8)
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'performance_outliers_analysis.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Performance outliers analysis saved to: {os.path.join(self.output_folder, 'performance_outliers_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
        
        # Print summary statistics
        print(f"\n=== PERFORMANCE OUTLIERS SUMMARY ===")
        print(f"Worst performing benchmarks (lowest reduction):")
        for i, (_, row) in enumerate(worst_performers.head(5).iterrows()):
            print(f"  {i+1}. {row['Benchmark']}: {row['Reduction_Percentage']:.1f}% reduction")
        
        print(f"\nSlowest benchmarks (highest processing time):")
        for i, (_, row) in enumerate(slowest_benchmarks.head(5).iterrows()):
            print(f"  {i+1}. {row['Benchmark']}: {row['Total_Time']:.3f}s")
        
        print(f"\nLeast efficient benchmarks (highest time per formula):")
        for i, (_, row) in enumerate(least_efficient.head(5).iterrows()):
            print(f"  {i+1}. {row['Benchmark']}: {row['Time_Per_Formula_Safe']:.6f}s per formula")
        
        print(f"\nMost problematic benchmarks (composite score):")
        for i, (_, row) in enumerate(most_problematic.head(5).iterrows()):
            print(f"  {i+1}. {row['Benchmark']}: {row['Problem_Score']:.3f} problem score")
            print(f"      └─ {row['Reduction_Percentage']:.1f}% reduction, {row['Total_Time']:.3f}s time, {row['Time_Per_Formula_Safe']:.6f}s/formula")
    
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
    
    # ===============================
    # COMPREHENSIVE ANALYSIS METHODS  
    # ===============================
    
    def load_comprehensive_data(self) -> pd.DataFrame:
        """Load and preprocess the reduction data for comprehensive analysis."""
        
        if not os.path.exists(self.results_file):
            raise ValueError(f"Results file not found: {self.results_file}")
        
        df = pd.read_csv(self.results_file)
        
        # Add derived columns for better analysis
        df['Formulas_Reduced'] = df['Original_Count'] - df['Optimized_Count']
        df['Time_Per_Formula'] = df['Total_Time'] / df['Total_Formulas']
        df['Time_Per_Original_Formula'] = df['Total_Time'] / df['Original_Count']
        df['Efficiency_Score'] = df['Reduction_Percentage'] / (df['Time_Per_Formula'] * 1000)  # Scaled for readability
        
        # Categorize benchmarks by reduction level
        def categorize_reduction(percentage):
            if percentage == 0:
                return 'Zero'
            elif percentage < 25:
                return 'Low (0-25%)'
            elif percentage < 50:
                return 'Medium (25-50%)'
            elif percentage < 75:
                return 'High (50-75%)'
            else:
                return 'Very High (75%+)'
        
        df['Reduction_Category'] = df['Reduction_Percentage'].apply(categorize_reduction)
        
        # Categorize by formula count size to handle skewness
        def categorize_size(count):
            if count <= 4:
                return 'Tiny (≤4)'
            elif count <= 10:
                return 'Small (5-10)'
            elif count <= 50:
                return 'Medium (11-50)'
            elif count <= 100:
                return 'Large (51-100)'
            else:
                return 'Very Large (100+)'
        
        df['Size_Category'] = df['Total_Formulas'].apply(categorize_size)
        
        print(f"Loaded {len(df)} benchmarks")
        print(f"Zero reduction benchmarks: {len(df[df['Reduction_Percentage'] == 0])}")
        print(f"Formula count range: {df['Total_Formulas'].min():.0f} - {df['Total_Formulas'].max():.0f}")
        
        return df
    
    def analyze_zero_reduction_cases(self, df: pd.DataFrame) -> None:
        """Detailed analysis of benchmarks with 0% reduction."""
        
        zero_reduction = df[df['Reduction_Percentage'] == 0.0].copy()
        non_zero = df[df['Reduction_Percentage'] > 0.0].copy()
        
        print(f"\n=== ZERO REDUCTION ANALYSIS ===")
        print(f"Benchmarks with 0% reduction: {len(zero_reduction)}")
        print(f"Benchmarks with >0% reduction: {len(non_zero)}")
        
        if len(zero_reduction) == 0:
            print("No benchmarks with zero reduction found.")
            return
        
        # Create comprehensive analysis plot
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        
        # Plot 1: Formula count distribution for zero vs non-zero reduction
        ax1.hist(zero_reduction['Total_Formulas'], bins=10, alpha=0.7, 
                label=f'Zero Reduction (n={len(zero_reduction)})', 
                color=self.colors['zero_reduction'], edgecolor='white')
        ax1.hist(non_zero['Total_Formulas'], bins=20, alpha=0.5, 
                label=f'Non-Zero Reduction (n={len(non_zero)})', 
                color=self.colors['high_reduction'], edgecolor='white')
        ax1.set_xlabel('Number of Formulas')
        ax1.set_ylabel('Number of Benchmarks')
        ax1.set_title('Formula Count Distribution: Zero vs Non-Zero Reduction')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Plot 2: Timing analysis for zero reduction cases
        ax2.scatter(zero_reduction['Total_Formulas'], zero_reduction['Total_Time'],
                   s=80, alpha=0.8, color=self.colors['zero_reduction'], 
                   edgecolors='white', linewidth=1, label='Zero Reduction')
        ax2.scatter(non_zero['Total_Formulas'], non_zero['Total_Time'],
                   s=40, alpha=0.6, color=self.colors['primary'], 
                   label='Non-Zero Reduction')
        ax2.set_xlabel('Number of Formulas')
        ax2.set_ylabel('Total Processing Time (seconds)')
        ax2.set_title('Processing Time vs Formula Count')
        ax2.legend()
        ax2.grid(True, alpha=0.3)
        ax2.set_yscale('log')  # Log scale due to wide range
        
        # Plot 3: Time per formula comparison
        zero_time_per_formula = zero_reduction['Time_Per_Formula']
        non_zero_time_per_formula = non_zero['Time_Per_Formula']
        
        positions = [1, 2]
        bp = ax3.boxplot([zero_time_per_formula, non_zero_time_per_formula], 
                        positions=positions, patch_artist=True, 
                        labels=['Zero Reduction', 'Non-Zero Reduction'])
        bp['boxes'][0].set_facecolor(self.colors['zero_reduction'])
        bp['boxes'][1].set_facecolor(self.colors['high_reduction'])
        
        ax3.set_ylabel('Time per Formula (seconds)')
        ax3.set_title('Time per Formula: Zero vs Non-Zero Reduction')
        ax3.grid(True, alpha=0.3)
        
        # Plot 4: Zero reduction benchmarks details
        zero_sorted = zero_reduction.sort_values('Total_Time', ascending=True)
        ax4.barh(range(len(zero_sorted)), zero_sorted['Total_Time'], 
                color=self.colors['zero_reduction'], alpha=0.8)
        ax4.set_yticks(range(len(zero_sorted)))
        ax4.set_yticklabels([name.replace('_000', '') for name in zero_sorted['Benchmark']], 
                           fontsize=9)
        ax4.set_xlabel('Total Processing Time (seconds)')
        ax4.set_title('Zero Reduction Benchmarks (sorted by time)')
        ax4.grid(True, alpha=0.3)
        
        plt.suptitle('Zero Reduction Cases Analysis', fontsize=18, fontweight='bold', y=0.98)
        plt.tight_layout()
        
        # Save plot
        if self.save_plots:
            output_path = os.path.join(self.output_folder, 'zero_reduction_analysis.png')
            plt.savefig(output_path, dpi=300, bbox_inches='tight')
            print(f"Zero reduction analysis saved to {output_path}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
        
        # Print statistical comparison
        print(f"\nStatistical Comparison:")
        print(f"Zero Reduction - Avg formulas: {zero_reduction['Total_Formulas'].mean():.1f}")
        print(f"Non-Zero Reduction - Avg formulas: {non_zero['Total_Formulas'].mean():.1f}")
        print(f"Zero Reduction - Avg time per formula: {zero_reduction['Time_Per_Formula'].mean():.6f}s")
        print(f"Non-Zero Reduction - Avg time per formula: {non_zero['Time_Per_Formula'].mean():.6f}s")
        
        # Save detailed table
        if self.save_plots:
            zero_details = zero_reduction[['Benchmark', 'Total_Formulas', 'Total_Time', 
                                         'Time_Per_Formula', 'Original_Count', 'Optimized_Count']]
            zero_details.to_csv(os.path.join(self.output_folder, 'zero_reduction_details.csv'), 
                               index=False)
    
    def analyze_formula_count_distribution(self, df: pd.DataFrame) -> None:
        """Analyze and visualize the skewed distribution of formula counts."""
        
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        
        # Plot 1: Raw formula count distribution
        ax1.hist(df['Total_Formulas'], bins=20, alpha=0.7, 
                color=self.colors['primary'], edgecolor='white')
        ax1.axvline(df['Total_Formulas'].mean(), color=self.colors['zero_reduction'], 
                   linestyle='--', linewidth=2, label=f'Mean: {df["Total_Formulas"].mean():.1f}')
        ax1.axvline(df['Total_Formulas'].median(), color=self.colors['high_reduction'], 
                   linestyle='--', linewidth=2, label=f'Median: {df["Total_Formulas"].median():.1f}')
        ax1.set_xlabel('Number of Formulas')
        ax1.set_ylabel('Number of Benchmarks')
        ax1.set_title('Raw Formula Count Distribution (Heavily Skewed)')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Plot 2: Log-scale distribution
        ax2.hist(df['Total_Formulas'], bins=20, alpha=0.7, 
                color=self.colors['secondary'], edgecolor='white')
        ax2.set_xlabel('Number of Formulas')
        ax2.set_ylabel('Number of Benchmarks')
        ax2.set_title('Formula Count Distribution (Log Scale)')
        ax2.set_xscale('log')
        ax2.grid(True, alpha=0.3)
        
        # Plot 3: Categorized analysis
        size_counts = df['Size_Category'].value_counts()
        size_order = ['Tiny (≤4)', 'Small (5-10)', 'Medium (11-50)', 'Large (51-100)', 'Very Large (100+)']
        size_counts = size_counts.reindex(size_order, fill_value=0)
        
        colors = [self.colors['zero_reduction'], self.colors['low_reduction'], 
                 self.colors['medium_reduction'], self.colors['high_reduction'], 
                 self.colors['primary']]
        
        ax3.bar(range(len(size_counts)), size_counts.values, 
               color=colors[:len(size_counts)], alpha=0.8, edgecolor='white')
        ax3.set_xticks(range(len(size_counts)))
        ax3.set_xticklabels(size_counts.index, rotation=45, ha='right')
        ax3.set_ylabel('Number of Benchmarks')
        ax3.set_title('Benchmarks by Size Category')
        ax3.grid(True, alpha=0.3)
        
        # Plot 4: Performance by size category
        avg_reduction_by_size = df.groupby('Size_Category')['Reduction_Percentage'].mean()
        avg_reduction_by_size = avg_reduction_by_size.reindex(size_order, fill_value=0)
        
        ax4.bar(range(len(avg_reduction_by_size)), avg_reduction_by_size.values,
               color=colors[:len(avg_reduction_by_size)], alpha=0.8, edgecolor='white')
        ax4.set_xticks(range(len(avg_reduction_by_size)))
        ax4.set_xticklabels(avg_reduction_by_size.index, rotation=45, ha='right')
        ax4.set_ylabel('Average Reduction Percentage')
        ax4.set_title('Average Reduction by Size Category')
        ax4.grid(True, alpha=0.3)
        
        plt.suptitle('Formula Count Distribution Analysis', fontsize=18, fontweight='bold', y=0.98)
        plt.tight_layout()
        
        # Save plot
        if self.save_plots:
            output_path = os.path.join(self.output_folder, 'formula_count_distribution_analysis.png')
            plt.savefig(output_path, dpi=300, bbox_inches='tight')
            print(f"Formula count distribution analysis saved to {output_path}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_normalized_analysis(self, df: pd.DataFrame) -> None:
        """Create normalized analysis to handle skewed distributions."""
        
        # Create normalized metrics to handle skewness
        df['Normalized_Time'] = df['Time_Per_Formula']  # Already normalized by formula count
        df['Normalized_Reduction'] = df['Reduction_Percentage']
        
        # Create size-weighted analysis
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        
        # Plot 1: Reduction percentage vs normalized time (size indicated by point size)
        scatter = ax1.scatter(df['Normalized_Time'], df['Normalized_Reduction'], 
                             s=df['Total_Formulas']*2, alpha=0.6, 
                             c=df['Total_Formulas'], cmap='viridis', 
                             edgecolors='white', linewidth=0.5)
        ax1.set_xlabel('Time per Formula (seconds)')
        ax1.set_ylabel('Reduction Percentage (%)')
        ax1.set_title('Reduction vs Time (bubble size = formula count)')
        ax1.set_xscale('log')
        ax1.grid(True, alpha=0.3)
        
        # Add colorbar
        cbar = plt.colorbar(scatter, ax=ax1)
        cbar.set_label('Number of Formulas')
        
        # Plot 2: Box plot by size category
        size_order = ['Tiny (≤4)', 'Small (5-10)', 'Medium (11-50)', 'Large (51-100)', 'Very Large (100+)']
        reduction_by_size = [df[df['Size_Category'] == cat]['Reduction_Percentage'].values 
                           for cat in size_order if cat in df['Size_Category'].values]
        
        bp = ax2.boxplot(reduction_by_size, patch_artist=True, 
                        labels=[cat for cat in size_order if cat in df['Size_Category'].values])
        
        colors = [self.colors['zero_reduction'], self.colors['low_reduction'], 
                 self.colors['medium_reduction'], self.colors['high_reduction'], 
                 self.colors['primary']]
        
        for patch, color in zip(bp['boxes'], colors[:len(bp['boxes'])]):
            patch.set_facecolor(color)
            patch.set_alpha(0.7)
        
        ax2.set_ylabel('Reduction Percentage (%)')
        ax2.set_title('Reduction Distribution by Size Category')
        ax2.tick_params(axis='x', rotation=45)
        ax2.grid(True, alpha=0.3)
        
        # Plot 3: Efficiency score (reduction per unit time)
        ax3.scatter(df['Total_Formulas'], df['Efficiency_Score'], 
                   alpha=0.7, c=df['Reduction_Percentage'], cmap='RdYlGn', 
                   s=60, edgecolors='white', linewidth=0.5)
        ax3.set_xlabel('Number of Formulas')
        ax3.set_ylabel('Efficiency Score (Reduction % / Time)')
        ax3.set_title('Efficiency Score vs Formula Count')
        ax3.set_xscale('log')
        ax3.set_yscale('log')
        ax3.grid(True, alpha=0.3)
        
        # Plot 4: Weighted averages by size category
        weighted_stats = df.groupby('Size_Category').agg({
            'Reduction_Percentage': ['mean', 'std', 'count'],
            'Time_Per_Formula': ['mean', 'std'],
            'Total_Formulas': 'sum'
        }).round(4)
        
        # Flatten column names
        weighted_stats.columns = ['_'.join(col) for col in weighted_stats.columns]
        
        # Calculate weighted average reduction
        size_categories = weighted_stats.index
        weighted_reductions = weighted_stats['Reduction_Percentage_mean']
        formula_sums = weighted_stats['Total_Formulas_sum']
        
        # Create weighted bar plot
        bars = ax4.bar(range(len(size_categories)), weighted_reductions, 
                      width=0.8, alpha=0.8, color=colors[:len(size_categories)],
                      edgecolor='white')
        
        # Add formula count labels on bars
        for i, (bar, count) in enumerate(zip(bars, formula_sums)):
            height = bar.get_height()
            ax4.text(bar.get_x() + bar.get_width()/2., height + 1,
                    f'{int(count)} formulas', ha='center', va='bottom', fontsize=9)
        
        ax4.set_xticks(range(len(size_categories)))
        ax4.set_xticklabels(size_categories, rotation=45, ha='right')
        ax4.set_ylabel('Average Reduction Percentage (%)')
        ax4.set_title('Weighted Average Reduction by Size\n(with total formula counts)')
        ax4.grid(True, alpha=0.3)
        
        plt.suptitle('Normalized Analysis (Handling Skewed Distribution)', 
                    fontsize=18, fontweight='bold', y=0.98)
        plt.tight_layout()
        
        # Save plot
        if self.save_plots:
            output_path = os.path.join(self.output_folder, 'normalized_analysis.png')
            plt.savefig(output_path, dpi=300, bbox_inches='tight')
            print(f"Normalized analysis saved to {output_path}")
            
            # Save weighted statistics
            weighted_stats.to_csv(os.path.join(self.output_folder, 'weighted_statistics_by_size.csv'))
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
        
        # Print insights
        print(f"\n=== NORMALIZED ANALYSIS INSIGHTS ===")
        total_formulas = df['Total_Formulas'].sum()
        total_original = df['Original_Count'].sum()
        total_optimized = df['Optimized_Count'].sum()
        overall_reduction = ((total_original - total_optimized) / total_original) * 100
        
        print(f"Overall statistics (formula-weighted):")
        print(f"Total formulas processed: {total_formulas:.0f}")
        print(f"Total original count: {total_original:.0f}")
        print(f"Total optimized count: {total_optimized:.0f}")
        print(f"Overall reduction percentage: {overall_reduction:.2f}%")
        
        for cat in size_categories:
            cat_data = df[df['Size_Category'] == cat]
            if len(cat_data) > 0:
                cat_formulas = cat_data['Total_Formulas'].sum()
                cat_avg_reduction = cat_data['Reduction_Percentage'].mean()
                print(f"{cat}: {len(cat_data)} benchmarks, {cat_formulas:.0f} formulas, "
                      f"{cat_avg_reduction:.1f}% avg reduction")
    
    def create_comprehensive_summary(self, df: pd.DataFrame) -> None:
        """Create a comprehensive summary plot and report."""
        
        fig, ((ax1, ax2, ax3), (ax4, ax5, ax6)) = plt.subplots(2, 3, figsize=(20, 12))
        
        # Plot 1: Reduction category distribution
        reduction_counts = df['Reduction_Category'].value_counts()
        colors_reduction = [self.colors['zero_reduction'], self.colors['low_reduction'],
                          self.colors['medium_reduction'], self.colors['high_reduction'],
                          self.colors['primary']]
        
        wedges, texts, autotexts = ax1.pie(reduction_counts.values, labels=reduction_counts.index,
                                          autopct='%1.1f%%', colors=colors_reduction[:len(reduction_counts)],
                                          startangle=90)
        ax1.set_title('Distribution of Reduction Categories')
        
        # Plot 2: Time vs Reduction scatter with categories
        for i, category in enumerate(df['Reduction_Category'].unique()):
            cat_data = df[df['Reduction_Category'] == category]
            ax2.scatter(cat_data['Time_Per_Formula'], cat_data['Reduction_Percentage'],
                       label=category, alpha=0.7, s=50, 
                       color=colors_reduction[i % len(colors_reduction)])
        
        ax2.set_xlabel('Time per Formula (seconds)')
        ax2.set_ylabel('Reduction Percentage (%)')
        ax2.set_title('Time vs Reduction by Category')
        ax2.set_xscale('log')
        ax2.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
        ax2.grid(True, alpha=0.3)
        
        # Plot 3: Formula count vs Total time with reduction coloring
        scatter = ax3.scatter(df['Total_Formulas'], df['Total_Time'], 
                             c=df['Reduction_Percentage'], cmap='RdYlGn', 
                             s=60, alpha=0.7, edgecolors='white', linewidth=0.5)
        ax3.set_xlabel('Number of Formulas')
        ax3.set_ylabel('Total Time (seconds)')
        ax3.set_title('Formula Count vs Total Time\n(colored by reduction %)')
        ax3.set_xscale('log')
        ax3.set_yscale('log')
        ax3.grid(True, alpha=0.3)
        
        cbar = plt.colorbar(scatter, ax=ax3)
        cbar.set_label('Reduction %')
        
        # Plot 4: Top performing benchmarks
        top_performers = df.nlargest(10, 'Reduction_Percentage')
        ax4.barh(range(len(top_performers)), top_performers['Reduction_Percentage'],
                color=self.colors['high_reduction'], alpha=0.8)
        ax4.set_yticks(range(len(top_performers)))
        ax4.set_yticklabels([name.replace('_000', '') for name in top_performers['Benchmark']], 
                           fontsize=9)
        ax4.set_xlabel('Reduction Percentage (%)')
        ax4.set_title('Top 10 Performing Benchmarks')
        ax4.grid(True, alpha=0.3)
        
        # Plot 5: Efficiency analysis
        df_non_zero = df[df['Reduction_Percentage'] > 0]  # Exclude zero reduction for efficiency calc
        if len(df_non_zero) > 0:
            top_efficient = df_non_zero.nlargest(10, 'Efficiency_Score')
            ax5.barh(range(len(top_efficient)), top_efficient['Efficiency_Score'],
                    color=self.colors['primary'], alpha=0.8)
            ax5.set_yticks(range(len(top_efficient)))
            ax5.set_yticklabels([name.replace('_000', '') for name in top_efficient['Benchmark']], 
                               fontsize=9)
            ax5.set_xlabel('Efficiency Score')
            ax5.set_title('Top 10 Most Efficient Benchmarks')
            ax5.grid(True, alpha=0.3)
        
        # Plot 6: Size category performance summary
        size_summary = df.groupby('Size_Category').agg({
            'Reduction_Percentage': 'mean',
            'Time_Per_Formula': 'mean',
            'Total_Formulas': 'sum'
        }).round(4)
        
        x = range(len(size_summary))
        width = 0.35
        
        ax6_twin = ax6.twinx()
        
        bars1 = ax6.bar([i - width/2 for i in x], size_summary['Reduction_Percentage'], 
                       width, label='Avg Reduction %', color=self.colors['high_reduction'], alpha=0.8)
        bars2 = ax6_twin.bar([i + width/2 for i in x], size_summary['Time_Per_Formula'] * 1000, 
                            width, label='Avg Time/Formula (ms)', color=self.colors['secondary'], alpha=0.8)
        
        ax6.set_xlabel('Size Category')
        ax6.set_ylabel('Average Reduction (%)', color=self.colors['high_reduction'])
        ax6_twin.set_ylabel('Average Time per Formula (ms)', color=self.colors['secondary'])
        ax6.set_title('Performance Summary by Size Category')
        ax6.set_xticks(x)
        ax6.set_xticklabels(size_summary.index, rotation=45, ha='right')
        ax6.grid(True, alpha=0.3)
        
        # Add legends
        ax6.legend(loc='upper left')
        ax6_twin.legend(loc='upper right')
        
        plt.suptitle('Comprehensive LTL Reduction Analysis Summary', 
                    fontsize=20, fontweight='bold', y=0.98)
        plt.tight_layout()
        
        # Save plot
        if self.save_plots:
            output_path = os.path.join(self.output_folder, 'comprehensive_summary.png')
            plt.savefig(output_path, dpi=300, bbox_inches='tight')
            print(f"Comprehensive summary saved to {output_path}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def generate_detailed_report(self, df: pd.DataFrame) -> None:
        """Generate a detailed text report of the analysis."""
        
        if not self.save_plots:
            return
            
        report_path = os.path.join(self.output_folder, 'ltl_reduction_analysis_report.txt')
        
        with open(report_path, 'w') as f:
            f.write("=" * 80 + "\n")
            f.write("LTL REDUCTION ANALYSIS REPORT\n")
            f.write("=" * 80 + "\n")
            f.write(f"Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
            f.write(f"Total Benchmarks Analyzed: {len(df)}\n\n")
            
            # Overall statistics
            f.write("OVERALL STATISTICS\n")
            f.write("-" * 40 + "\n")
            total_formulas = df['Total_Formulas'].sum()
            total_original = df['Original_Count'].sum()
            total_optimized = df['Optimized_Count'].sum()
            overall_reduction = ((total_original - total_optimized) / total_original) * 100
            total_time = df['Total_Time'].sum()
            
            f.write(f"Total formulas processed: {total_formulas:,.0f}\n")
            f.write(f"Total original formula count: {total_original:,.0f}\n")
            f.write(f"Total optimized formula count: {total_optimized:,.0f}\n")
            f.write(f"Overall reduction achieved: {overall_reduction:.2f}%\n")
            f.write(f"Total processing time: {total_time:.2f} seconds\n")
            f.write(f"Average time per formula: {total_time/total_formulas:.6f} seconds\n\n")
            
            # Zero reduction analysis
            zero_reduction = df[df['Reduction_Percentage'] == 0.0]
            f.write("ZERO REDUCTION ANALYSIS\n")
            f.write("-" * 40 + "\n")
            f.write(f"Benchmarks with 0% reduction: {len(zero_reduction)}\n")
            f.write(f"Percentage of total benchmarks: {len(zero_reduction)/len(df)*100:.1f}%\n")
            
            if len(zero_reduction) > 0:
                f.write(f"Zero reduction formulas: {zero_reduction['Total_Formulas'].sum():.0f}\n")
                f.write(f"Percentage of total formulas: {zero_reduction['Total_Formulas'].sum()/total_formulas*100:.1f}%\n")
                f.write(f"Average formula count in zero reduction: {zero_reduction['Total_Formulas'].mean():.1f}\n")
                f.write(f"Average time per formula: {zero_reduction['Time_Per_Formula'].mean():.6f}s\n")
                f.write("\nZero reduction benchmarks:\n")
                for _, row in zero_reduction.iterrows():
                    f.write(f"  {row['Benchmark']}: {row['Total_Formulas']:.0f} formulas, "
                           f"{row['Total_Time']:.4f}s total\n")
            f.write("\n")
            
            # Size category analysis
            f.write("SIZE CATEGORY ANALYSIS\n")
            f.write("-" * 40 + "\n")
            size_stats = df.groupby('Size_Category').agg({
                'Reduction_Percentage': ['count', 'mean', 'std'],
                'Time_Per_Formula': 'mean',
                'Total_Formulas': 'sum'
            }).round(4)
            
            for category in size_stats.index:
                cat_data = df[df['Size_Category'] == category]
                f.write(f"{category}:\n")
                f.write(f"  Benchmarks: {len(cat_data)}\n")
                f.write(f"  Total formulas: {cat_data['Total_Formulas'].sum():.0f}\n")
                f.write(f"  Average reduction: {cat_data['Reduction_Percentage'].mean():.1f}%\n")
                f.write(f"  Average time per formula: {cat_data['Time_Per_Formula'].mean():.6f}s\n")
                zero_in_cat = len(cat_data[cat_data['Reduction_Percentage'] == 0])
                f.write(f"  Zero reduction cases: {zero_in_cat}\n\n")
            
            # Performance insights
            f.write("PERFORMANCE INSIGHTS\n")
            f.write("-" * 40 + "\n")
            
            # Best and worst performers
            best_reduction = df.loc[df['Reduction_Percentage'].idxmax()]
            worst_time = df.loc[df['Time_Per_Formula'].idxmax()]
            
            f.write(f"Best reduction: {best_reduction['Benchmark']} ({best_reduction['Reduction_Percentage']:.1f}%)\n")
            f.write(f"Slowest per formula: {worst_time['Benchmark']} ({worst_time['Time_Per_Formula']:.6f}s)\n")
            
            # Correlation analysis
            corr_reduction_time = df['Reduction_Percentage'].corr(df['Time_Per_Formula'])
            corr_size_reduction = df['Total_Formulas'].corr(df['Reduction_Percentage'])
            
            f.write(f"\nCorrelations:\n")
            f.write(f"Reduction % vs Time per formula: {corr_reduction_time:.3f}\n")
            f.write(f"Formula count vs Reduction %: {corr_size_reduction:.3f}\n")
            
            # Recommendations
            f.write("\nRECOMMENDATIONS\n")
            f.write("-" * 40 + "\n")
            
            if len(zero_reduction) > 0:
                avg_zero_size = zero_reduction['Total_Formulas'].mean()
                if avg_zero_size <= 10:
                    f.write("• Zero reduction cases are primarily small benchmarks (≤10 formulas)\n")
                    f.write("• Consider focusing optimization efforts on larger benchmark sets\n")
                else:
                    f.write("• Zero reduction cases include larger benchmarks - investigate optimization algorithms\n")
            
            if corr_reduction_time < -0.3:
                f.write("• Strong negative correlation between reduction and time - good efficiency\n")
            elif corr_reduction_time > 0.3:
                f.write("• Concerning positive correlation between reduction and time - review algorithms\n")
            
            if overall_reduction > 50:
                f.write(f"• Excellent overall reduction rate of {overall_reduction:.1f}%\n")
            elif overall_reduction > 25:
                f.write(f"• Good overall reduction rate of {overall_reduction:.1f}%\n")
            else:
                f.write(f"• Low overall reduction rate of {overall_reduction:.1f}% - room for improvement\n")
            
            f.write("\n" + "=" * 80 + "\n")
        
        print(f"Detailed report saved to {report_path}")
    
    def create_no_zero_analysis(self, df: pd.DataFrame) -> None:
        """Create comprehensive analysis excluding zero reduction cases."""
        
        # Filter out zero reduction cases
        no_zero_data = df[df['Reduction_Percentage'] > 0].copy()
        
        if len(no_zero_data) == 0:
            print("No non-zero reduction cases found.")
            return
        
        fig = plt.figure(figsize=(20, 16))
        
        # Set up the grid layout
        gs = fig.add_gridspec(4, 4, hspace=0.3, wspace=0.3)
        
        # Color scheme
        colors = ['#2E86AB', '#A23B72', '#F18F01', '#C73E1D', '#6A994E']
        
        # 1. Distribution of reduction percentages (top left)
        ax1 = fig.add_subplot(gs[0, 0])
        ax1.hist(no_zero_data['Reduction_Percentage'], bins=20, 
                color=colors[0], alpha=0.7, edgecolor='black')
        ax1.axvline(no_zero_data['Reduction_Percentage'].mean(), 
                   color='red', linestyle='--', linewidth=2, 
                   label=f'Mean: {no_zero_data["Reduction_Percentage"].mean():.1f}%')
        ax1.axvline(no_zero_data['Reduction_Percentage'].median(), 
                   color='orange', linestyle='--', linewidth=2,
                   label=f'Median: {no_zero_data["Reduction_Percentage"].median():.1f}%')
        ax1.set_xlabel('Reduction Percentage (%)')
        ax1.set_ylabel('Number of Benchmarks')
        ax1.set_title('Distribution of Reduction Percentages\n(Excluding Zero Cases)', fontweight='bold')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # 2. Box plot by size category (top middle)
        ax2 = fig.add_subplot(gs[0, 1])
        box_data = [group['Reduction_Percentage'].values 
                   for name, group in no_zero_data.groupby('Size_Category')]
        box_labels = [f'{cat}\n(n={len(group)})' 
                     for cat, group in no_zero_data.groupby('Size_Category')]
        
        bp = ax2.boxplot(box_data, labels=box_labels, patch_artist=True)
        for patch, color in zip(bp['boxes'], colors):
            patch.set_facecolor(color)
            patch.set_alpha(0.7)
        ax2.set_ylabel('Reduction Percentage (%)')
        ax2.set_title('Reduction by Benchmark Size\n(Non-Zero Cases)', fontweight='bold')
        ax2.grid(True, alpha=0.3)
        plt.setp(ax2.get_xticklabels(), rotation=45, ha='right')
        
        # 3. Scatter: Formula count vs Reduction (top right)
        ax3 = fig.add_subplot(gs[0, 2])
        scatter = ax3.scatter(no_zero_data['Total_Formulas'], 
                            no_zero_data['Reduction_Percentage'],
                            s=no_zero_data['Total_Time'] * 10,
                            c=no_zero_data['Optimized_Count'],
                            cmap='viridis', alpha=0.7, edgecolors='black')
        ax3.set_xlabel('Original Formula Count')
        ax3.set_ylabel('Reduction Percentage (%)')
        ax3.set_title('Formula Count vs Reduction\n(Bubble size = Time)', fontweight='bold')
        ax3.grid(True, alpha=0.3)
        cbar = plt.colorbar(scatter, ax=ax3)
        cbar.set_label('Optimized Formula Count')
        
        # 4. Time per formula analysis (top far right)
        ax4 = fig.add_subplot(gs[0, 3])
        time_per_formula = no_zero_data['Total_Time'] / no_zero_data['Total_Formulas']
        ax4.scatter(no_zero_data['Reduction_Percentage'], time_per_formula,
                   c=no_zero_data['Total_Formulas'], 
                   cmap='plasma', alpha=0.7, edgecolors='black')
        ax4.set_xlabel('Reduction Percentage (%)')
        ax4.set_ylabel('Time per Formula (seconds)')
        ax4.set_title('Reduction vs Processing Time\n(Non-Zero Cases)', fontweight='bold')
        ax4.grid(True, alpha=0.3)
        ax4.set_yscale('log')
        
        # 5. Category comparison chart (middle left, spans 2 columns)
        ax5 = fig.add_subplot(gs[1, :2])
        categories = no_zero_data.groupby('Size_Category')
        cat_names = []
        cat_reductions = []
        cat_counts = []
        cat_formulas = []
        
        for cat, group in categories:
            cat_names.append(str(cat))
            cat_reductions.append(group['Reduction_Percentage'].mean())
            cat_counts.append(len(group))
            cat_formulas.append(group['Total_Formulas'].sum())
        
        x = np.arange(len(cat_names))
        width = 0.35
        
        ax5_twin = ax5.twinx()
        bars1 = ax5.bar(x - width/2, cat_reductions, width, 
                       label='Avg Reduction %', color=colors[0], alpha=0.7)
        bars2 = ax5_twin.bar(x + width/2, cat_counts, width, 
                           label='Benchmark Count', color=colors[1], alpha=0.7)
        
        ax5.set_xlabel('Size Category')
        ax5.set_ylabel('Average Reduction Percentage (%)', color=colors[0])
        ax5_twin.set_ylabel('Number of Benchmarks', color=colors[1])
        ax5.set_title('Performance by Size Category (Non-Zero Cases)', fontweight='bold')
        ax5.set_xticks(x)
        ax5.set_xticklabels(cat_names, rotation=45, ha='right')
        ax5.grid(True, alpha=0.3)
        
        # Add value labels on bars
        for bar, val in zip(bars1, cat_reductions):
            height = bar.get_height()
            ax5.text(bar.get_x() + bar.get_width()/2., height + 1,
                    f'{val:.1f}%', ha='center', va='bottom')
        
        for bar, val in zip(bars2, cat_counts):
            height = bar.get_height()
            ax5_twin.text(bar.get_x() + bar.get_width()/2., height + 0.1,
                         f'{val}', ha='center', va='bottom')
        
        # 6. Efficiency analysis (middle right, spans 2 columns)
        ax6 = fig.add_subplot(gs[1, 2:])
        efficiency = no_zero_data['Reduction_Percentage'] / (
            no_zero_data['Total_Time'] / no_zero_data['Total_Formulas'])
        
        ax6.scatter(no_zero_data['Total_Formulas'], efficiency,
                   s=no_zero_data['Reduction_Percentage'] * 5,
                   c=no_zero_data['Total_Time'],
                   cmap='coolwarm', alpha=0.7, edgecolors='black')
        ax6.set_xlabel('Original Formula Count')
        ax6.set_ylabel('Efficiency (Reduction % / Time per Formula)')
        ax6.set_title('Optimization Efficiency Analysis\n(Bubble size = Reduction %)', fontweight='bold')
        ax6.set_xscale('log')
        ax6.set_yscale('log')
        ax6.grid(True, alpha=0.3)
        
        # 7. Comparative statistics table (bottom section)
        ax7 = fig.add_subplot(gs[2:, :])
        ax7.axis('off')
        
        # Calculate comparison statistics
        all_data_mean = df['Reduction_Percentage'].mean()
        all_data_weighted = (df['Reduction_Percentage'] * 
                           df['Total_Formulas']).sum() / df['Total_Formulas'].sum()
        
        no_zero_mean = no_zero_data['Reduction_Percentage'].mean()
        no_zero_weighted = (no_zero_data['Reduction_Percentage'] * 
                          no_zero_data['Total_Formulas']).sum() / no_zero_data['Total_Formulas'].sum()
        
        table_data = [
            ['Metric', 'All Data (with zeros)', 'Non-Zero Cases Only', 'Difference'],
            ['Number of Benchmarks', f'{len(df)}', f'{len(no_zero_data)}', 
             f'{len(df) - len(no_zero_data)} removed'],
            ['Average Reduction (%)', f'{all_data_mean:.2f}', f'{no_zero_mean:.2f}', 
             f'+{no_zero_mean - all_data_mean:.2f}'],
            ['Weighted Reduction (%)', f'{all_data_weighted:.2f}', f'{no_zero_weighted:.2f}', 
             f'+{no_zero_weighted - all_data_weighted:.2f}'],
            ['Median Reduction (%)', f'{df["Reduction_Percentage"].median():.2f}', 
             f'{no_zero_data["Reduction_Percentage"].median():.2f}', 
             f'+{no_zero_data["Reduction_Percentage"].median() - df["Reduction_Percentage"].median():.2f}'],
            ['Standard Deviation', f'{df["Reduction_Percentage"].std():.2f}', 
             f'{no_zero_data["Reduction_Percentage"].std():.2f}', 
             f'{no_zero_data["Reduction_Percentage"].std() - df["Reduction_Percentage"].std():.2f}'],
            ['Min Reduction (%)', f'{df["Reduction_Percentage"].min():.2f}', 
             f'{no_zero_data["Reduction_Percentage"].min():.2f}', f'+{no_zero_data["Reduction_Percentage"].min():.2f}'],
            ['Max Reduction (%)', f'{df["Reduction_Percentage"].max():.2f}', 
             f'{no_zero_data["Reduction_Percentage"].max():.2f}', 'Same'],
            ['Avg Time/Formula (s)', 
             f'{(df["Total_Time"] / df["Total_Formulas"]).mean():.4f}', 
             f'{(no_zero_data["Total_Time"] / no_zero_data["Total_Formulas"]).mean():.4f}', 
             f'+{(no_zero_data["Total_Time"] / no_zero_data["Total_Formulas"]).mean() - (df["Total_Time"] / df["Total_Formulas"]).mean():.4f}']
        ]
        
        # Create table
        table = ax7.table(cellText=table_data[1:], colLabels=table_data[0],
                         cellLoc='center', loc='center', 
                         colWidths=[0.25, 0.25, 0.25, 0.25])
        table.auto_set_font_size(False)
        table.set_fontsize(11)
        table.scale(1, 2)
        
        # Style the table
        for i in range(len(table_data)):
            for j in range(len(table_data[0])):
                cell = table[(i, j)]
                if i == 0:  # Header
                    cell.set_facecolor('#4472C4')
                    cell.set_text_props(weight='bold', color='white')
                elif j == 3:  # Difference column
                    if 'removed' in table_data[i][j] or 'Same' in table_data[i][j]:
                        cell.set_facecolor('#F2F2F2')
                    elif '+' in table_data[i][j]:
                        cell.set_facecolor('#D4EDDA')  # Light green for improvements
                    else:
                        cell.set_facecolor('#F8D7DA')  # Light red for decreases
                else:
                    cell.set_facecolor('#F8F9FA')
        
        plt.suptitle('LTL Reduction Analysis: Performance Without Zero Reduction Cases', 
                    fontsize=18, fontweight='bold', y=0.98)
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'ltl_reduction_no_zeros_analysis.png'), 
                       dpi=300, bbox_inches='tight', facecolor='white', edgecolor='none')
            print(f"No-zero reduction analysis saved to {os.path.join(self.output_folder, 'ltl_reduction_no_zeros_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def run_full_analysis(self, results_folder: str = "optimized_results") -> None:
        """Run the complete LTL reduction analysis including all comprehensive methods."""
        
        print("Starting comprehensive LTL reduction analysis...")
        print("=" * 60)
        
        print("1. Creating performance outliers analysis...")
        # Load standard data for outliers analysis
        summary_df, _ = self.load_optimization_data(results_folder)
        if summary_df is not None and not summary_df.empty:
            self.create_performance_outliers_analysis(summary_df)
        
    
        print("\n7. Generating normal reduction analysis...")
        summary_df, stats = self.analyze_ltl_reduction(results_folder)


        # Load data for comprehensive analysis
        df = self.load_comprehensive_data()
        
        # Run all analyses
        print("\n1. Analyzing zero reduction cases...")
        self.analyze_zero_reduction_cases(df)
        
        print("\n2. Analyzing formula count distribution...")
        self.analyze_formula_count_distribution(df)
        
        print("\n3. Creating normalized analysis...")
        self.create_normalized_analysis(df)
        
        print("\n4. Creating comprehensive summary...")
        self.create_comprehensive_summary(df)
        
        print("\n5. Creating no-zero reduction analysis...")
        self.create_no_zero_analysis(df)
        self.create_zero_vs_nonzero_scatter(df)

        print("\n7. Generating detailed report...")
        self.generate_detailed_report(df)
        
        
        # Save complete dataset with derived columns
        if self.save_plots:
            df.to_csv(os.path.join(self.output_folder, 'complete_analysis_dataset.csv'), index=False)
        
        print("\n" + "=" * 60)
        print("Comprehensive analysis completed successfully!")
        print(f"All results saved to: {self.output_folder}")
        print("\nGenerated files:")
        print("• zero_reduction_analysis.png")
        print("• formula_count_distribution_analysis.png") 
        print("• normalized_analysis.png")
        print("• comprehensive_summary.png")
        print("• ltl_reduction_no_zeros_analysis.png")
        print("• ltl_reduction_analysis_report.txt")
        print("• zero_reduction_details.csv")
        print("• weighted_statistics_by_size.csv")
        print("• complete_analysis_dataset.csv")
    
    # ===============================
    # END COMPREHENSIVE ANALYSIS
    # ===============================
    
    def analyze_ltl_reduction(self, results_folder: str = "optimized_results") -> Tuple[pd.DataFrame, Dict]:
        """
        Complete LTL reduction analysis with all visualizations and statistics.
        Handles cases where overall summary doesn't exist by building from individual files.
        
        Args:
            results_folder: Path to optimization results folder
            
        Returns:
            Tuple of (summary_df, comprehensive_stats)
        """
        print(f"Loading LTL optimization results from: {results_folder}")
        
        # Check if results folder exists
        if not os.path.exists(results_folder):
            raise FileNotFoundError(f"Results folder not found: {results_folder}")
        
        try:
            summary_df, class_reductions_df = self.load_optimization_data(results_folder)
        except Exception as e:
            print(f"Error loading optimization data: {e}")
            raise
        
        if summary_df is None or summary_df.empty:
            raise ValueError("No benchmark data found to analyze. Please ensure optimization results exist.")
        
        print(f"Analyzing {len(summary_df)} benchmark optimization results...")
        
        # Generate all visualizations
        self.create_detailed_reduction_chart(summary_df)
        self.create_detailed_reduction_chart_no_zeros(summary_df)
        self.create_detailed_timing_chart(summary_df)
        self.create_performance_outliers_analysis(summary_df)
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
    RESULTS_FILE = "optimized_results/calculated_benchmark_summary.csv"
    
    # Initialize analyzer
    analyzer = LTLReductionAnalyzer(
        save_plots=SAVE_PLOTS,
        show_plots=SHOW_PLOTS,
        output_folder=OUTPUT_FOLDER,
        results_file=RESULTS_FILE
    )
    
    # Run analysis
    try:
        if os.path.exists(RESULTS_FOLDER):
            print("Choose analysis type:")
            print("1. Standard reduction analysis (original functionality)")
            print("2. Comprehensive analysis (includes zero reduction, skewness handling)")
            print("3. Both analyses")
            
            # For automated execution, we'll run comprehensive analysis
            # You can modify this to accept user input if needed
            choice = "3"  # Change to "1" for standard only, "3" for both
            


            print("\n" + "="*60)
            print("RUNNING COMPREHENSIVE ANALYSIS")
            print("="*60)
            analyzer.run_full_analysis(RESULTS_FOLDER)
            
        else:
            print(f"Error: Results folder '{RESULTS_FOLDER}' not found.")
            print("Please run the LTL optimization process first to generate results.")
            print(f"Expected structure:")
            print(f"  {RESULTS_FOLDER}/")
            print(f"    ├── calculated_benchmark_summary.csv")
            print(f"    ├── benchmark_summary.csv (optional)")
            print(f"    └── benchmark_specific/")
            print(f"        ├── benchmark1_metrics_summary.csv")
            print(f"        ├── benchmark1_metrics_class_reductions.csv")
            print(f"        └── ...")
            
    except FileNotFoundError as e:
        print(f"Error: {e}")
        print("\nPlease ensure:")
        print("1. The optimization process has been run")
        print("2. Results are saved to the expected folder structure")
        print("3. Individual benchmark files exist in benchmark_specific/")
        
    except ValueError as e:
        print(f"Error: {e}")
        print("\nThe results folder exists but contains no valid data.")
        print("Please re-run the optimization process.")
        
    except Exception as e:
        print(f"Unexpected error during analysis: {e}")
        print("Please check the data files and try again.")


if __name__ == "__main__":
    main()
