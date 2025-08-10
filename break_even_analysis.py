"""
Break-Even Analysis: When LTL Optimization Pays Off

This script analyzes the characteristics that determine when LTL optimization
provides net benefits vs. when the overhead outweighs the gains.
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os
import seaborn as sns
from typing import Tuple, Dict
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

try:
    import seaborn as sns
    HAS_SEABORN = True
    sns.set_palette("Set2")
except ImportError:
    HAS_SEABORN = False

try:
    from scipy import stats
    HAS_SCIPY = True
except ImportError:
    HAS_SCIPY = False


class BreakEvenAnalyzer:
    """
    Analyzer for determining when LTL optimization provides net benefits.
    """
    
    def __init__(self, save_plots: bool = True, show_plots: bool = False, 
                 output_folder: str = "comparative_analysis"):
        self.save_plots = save_plots
        self.show_plots = show_plots
        self.output_folder = output_folder
        
        if self.save_plots and not os.path.exists(self.output_folder):
            os.makedirs(self.output_folder)
    
    def load_comprehensive_data(self, baseline_file: str, optimized_file: str, 
                              benchmark_specific_folder: str, 
                              calculated_summary_file: str) -> pd.DataFrame:
        """
        Load all data sources for comprehensive break-even analysis.
        
        Returns:
            DataFrame with all metrics combined
        """
        print("Loading comprehensive data for break-even analysis...")
        
        # Load timing data
        baseline_df = pd.read_csv(baseline_file)
        if 'Unnamed: 0' in baseline_df.columns:
            baseline_df = baseline_df.drop('Unnamed: 0', axis=1)
            
        optimized_df = pd.read_csv(optimized_file)
        if 'Unnamed: 0' in optimized_df.columns:
            optimized_df = optimized_df.drop('Unnamed: 0', axis=1)
        
        # Load reduction data
        if os.path.exists(calculated_summary_file):
            reduction_df = pd.read_csv(calculated_summary_file)
        else:
            print(f"Warning: {calculated_summary_file} not found, using empty reduction data")
            reduction_df = pd.DataFrame()
        
        # Find common benchmarks across all datasets
        baseline_benchmarks = set(baseline_df['Benchmark'])
        optimized_benchmarks = set(optimized_df['Benchmark'])
        
        if not reduction_df.empty:
            reduction_benchmarks = set(reduction_df['Benchmark'])
            common_benchmarks = baseline_benchmarks.intersection(optimized_benchmarks).intersection(reduction_benchmarks)
        else:
            common_benchmarks = baseline_benchmarks.intersection(optimized_benchmarks)
        
        print(f"Common benchmarks across all datasets: {len(common_benchmarks)}")
        
        # Build comprehensive dataset
        comprehensive_data = []
        
        for benchmark in common_benchmarks:
            # Get baseline data
            baseline_row = baseline_df[baseline_df['Benchmark'] == benchmark].iloc[0]
            baseline_time = baseline_row['Total Elapsed Time (seconds)']
            baseline_props = baseline_row['Num Properties']
            baseline_avg_time = baseline_row['Average Elapsed Time (seconds)']
            
            # Get optimized data
            optimized_row = optimized_df[optimized_df['Benchmark'] == benchmark].iloc[0]
            optimized_time = optimized_row['Total Elapsed Time (seconds)']
            optimized_props = optimized_row['Num Properties']
            optimized_avg_time = optimized_row['Average Elapsed Time (seconds)']
            
            # Get reduction data
            if not reduction_df.empty:
                reduction_row = reduction_df[reduction_df['Benchmark'] == benchmark]
                if not reduction_row.empty:
                    reduction_pct = reduction_row.iloc[0]['Reduction_Percentage']
                    original_count = reduction_row.iloc[0]['Original_Count']
                    optimized_count = reduction_row.iloc[0]['Optimized_Count']
                else:
                    reduction_pct = 0
                    original_count = baseline_props
                    optimized_count = optimized_props
            else:
                reduction_pct = ((baseline_props - optimized_props) / baseline_props) * 100 if baseline_props > 0 else 0
                original_count = baseline_props
                optimized_count = optimized_props
            
            # Get optimization overhead
            overhead_file = os.path.join(benchmark_specific_folder, f"{benchmark}_metrics_summary.csv")
            if os.path.exists(overhead_file):
                try:
                    overhead_df = pd.read_csv(overhead_file)
                    optimization_time = overhead_df['total_time'].iloc[0] if 'total_time' in overhead_df.columns else 0
                    equivalence_time = overhead_df['equivalence_class_time'].iloc[0] if 'equivalence_class_time' in overhead_df.columns else 0
                    containment_time = overhead_df['containment_analysis_time'].iloc[0] if 'containment_analysis_time' in overhead_df.columns else 0
                except Exception as e:
                    # Fallback: try to get from reduction_df if available
                    if not reduction_df.empty:
                        reduction_row = reduction_df[reduction_df['Benchmark'] == benchmark]
                        if not reduction_row.empty:
                            optimization_time = reduction_row.iloc[0]['Total_Time'] if 'Total_Time' in reduction_row.columns else 0
                            equivalence_time = reduction_row.iloc[0]['Equivalence_Class_Time'] if 'Equivalence_Class_Time' in reduction_row.columns else 0
                            containment_time = reduction_row.iloc[0]['Containment_Analysis_Time'] if 'Containment_Analysis_Time' in reduction_row.columns else 0
                        else:
                            optimization_time = 0
                            equivalence_time = 0
                            containment_time = 0
                    else:
                        optimization_time = 0
                        equivalence_time = 0
                        containment_time = 0
            else:
                # Fallback: try to get from reduction_df if available
                if not reduction_df.empty:
                    reduction_row = reduction_df[reduction_df['Benchmark'] == benchmark]
                    if not reduction_row.empty:
                        optimization_time = reduction_row.iloc[0]['Total_Time'] if 'Total_Time' in reduction_row.columns else 0
                        equivalence_time = reduction_row.iloc[0]['Equivalence_Class_Time'] if 'Equivalence_Class_Time' in reduction_row.columns else 0
                        containment_time = reduction_row.iloc[0]['Containment_Analysis_Time'] if 'Containment_Analysis_Time' in reduction_row.columns else 0
                    else:
                        optimization_time = 0
                        equivalence_time = 0
                        containment_time = 0
                else:
                    optimization_time = 0
                    equivalence_time = 0
                    containment_time = 0
            
            # Calculate derived metrics
            total_optimized_time = optimized_time + optimization_time
            mc_speedup = baseline_time / optimized_time if optimized_time > 0 else 1
            net_speedup = baseline_time / total_optimized_time if total_optimized_time > 0 else 1
            
            mc_improvement = ((baseline_time - optimized_time) / baseline_time) * 100 if baseline_time > 0 else 0
            net_improvement = ((baseline_time - total_optimized_time) / baseline_time) * 100 if baseline_time > 0 else 0
            
            overhead_ratio = optimization_time / baseline_time if baseline_time > 0 else 0
            time_saved_mc = baseline_time - optimized_time
            time_saved_net = baseline_time - total_optimized_time
            
            # Categorize performance
            if net_speedup > 1.1:
                performance_category = "Strong Benefit"
            elif net_speedup > 1.0:
                performance_category = "Marginal Benefit"
            elif net_speedup > 0.9:
                performance_category = "Marginal Loss"
            else:
                performance_category = "Strong Loss"
            
            # Categorize by problem size
            if original_count >= 100:
                size_category = "Large"
            elif original_count >= 20:
                size_category = "Medium"
            elif original_count >= 5:
                size_category = "Small"
            else:
                size_category = "Tiny"
            
            comprehensive_data.append({
                'benchmark': benchmark,
                'baseline_time': baseline_time,
                'optimized_time': optimized_time,
                'optimization_time': optimization_time,
                'total_optimized_time': total_optimized_time,
                'equivalence_time': equivalence_time,
                'containment_time': containment_time,
                'baseline_props': baseline_props,
                'optimized_props': optimized_props,
                'original_count': original_count,
                'optimized_count': optimized_count,
                'reduction_percentage': reduction_pct,
                'mc_speedup': mc_speedup,
                'net_speedup': net_speedup,
                'mc_improvement': mc_improvement,
                'net_improvement': net_improvement,
                'overhead_ratio': overhead_ratio,
                'time_saved_mc': time_saved_mc,
                'time_saved_net': time_saved_net,
                'performance_category': performance_category,
                'size_category': size_category,
                'baseline_avg_time': baseline_avg_time,
                'optimized_avg_time': optimized_avg_time
            })
        
        return pd.DataFrame(comprehensive_data)
    
    def create_break_even_analysis(self, df: pd.DataFrame) -> None:
        """
        Create comprehensive break-even analysis visualization.
        """
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(20, 14))
        fig.suptitle('Break-Even Analysis: When LTL Optimization Pays Off', 
                    fontsize=16, fontweight='bold')
        
        # 1. Reduction percentage vs net speedup
        beneficial = df[df['net_speedup'] > 1]
        detrimental = df[df['net_speedup'] <= 1]
        
        ax1.scatter(beneficial['reduction_percentage'], beneficial['net_speedup'], 
                   alpha=0.7, s=80, color='green', label=f'Beneficial ({len(beneficial)})')
        ax1.scatter(detrimental['reduction_percentage'], detrimental['net_speedup'], 
                   alpha=0.7, s=80, color='red', label=f'Detrimental ({len(detrimental)})')
        
        ax1.axhline(y=1, color='black', linestyle='--', linewidth=2, label='Break-even')
        ax1.set_xlabel('Reduction Percentage (%)')
        ax1.set_ylabel('Net Speedup (including overhead)')
        ax1.set_title('Reduction Percentage vs Net Performance')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Add trend line
        if HAS_SCIPY and len(df) > 3:
            slope, intercept, r_value, p_value, std_err = stats.linregress(df['reduction_percentage'], df['net_speedup'])
            line_x = np.linspace(df['reduction_percentage'].min(), df['reduction_percentage'].max(), 100)
            line_y = slope * line_x + intercept
            ax1.plot(line_x, line_y, 'blue', linestyle='-', linewidth=2, alpha=0.7, 
                    label=f'Trend (R²={r_value**2:.3f})')
            ax1.legend()
        
        # 2. Problem size vs overhead ratio
        size_order = ['Tiny', 'Small', 'Medium', 'Large']
        size_colors = {'Tiny': 'lightblue', 'Small': 'orange', 'Medium': 'lightgreen', 'Large': 'purple'}
        
        for size in size_order:
            size_data = df[df['size_category'] == size]
            if not size_data.empty:
                ax2.scatter(size_data['overhead_ratio'] * 100, size_data['net_speedup'], 
                           alpha=0.7, s=80, color=size_colors[size], label=f'{size} ({len(size_data)})')
        
        ax2.axhline(y=1, color='black', linestyle='--', linewidth=2, label='Break-even')
        ax2.set_xlabel('Overhead Ratio (%)')
        ax2.set_ylabel('Net Speedup')
        ax2.set_title('Problem Size vs Optimization Overhead')
        ax2.legend()
        ax2.grid(True, alpha=0.3)
        
        # 3. Baseline time vs benefit analysis
        ax3.scatter(df['baseline_time'], df['time_saved_net'], alpha=0.7, s=80)
        
        # Color points by performance category
        perf_colors = {'Strong Benefit': 'darkgreen', 'Marginal Benefit': 'lightgreen', 
                      'Marginal Loss': 'orange', 'Strong Loss': 'red'}
        for category in perf_colors:
            cat_data = df[df['performance_category'] == category]
            if not cat_data.empty:
                ax3.scatter(cat_data['baseline_time'], cat_data['time_saved_net'], 
                           alpha=0.7, s=80, color=perf_colors[category], label=f'{category} ({len(cat_data)})')
        
        ax3.axhline(y=0, color='black', linestyle='--', linewidth=2, label='Break-even')
        ax3.set_xlabel('Baseline Time (seconds)')
        ax3.set_ylabel('Net Time Saved (seconds)')
        ax3.set_title('Baseline Time vs Net Benefit')
        ax3.set_xscale('log')
        ax3.legend()
        ax3.grid(True, alpha=0.3)
        
        # 4. Break-even threshold analysis
        # Calculate break-even reduction percentage for different overhead ratios
        overhead_ratios = np.linspace(0, 1, 100)
        break_even_reductions = []
        
        for overhead_ratio in overhead_ratios:
            # For break-even: baseline_time = optimized_time + overhead
            # If optimized_time = baseline_time * (1 - reduction_pct/100)
            # And overhead = baseline_time * overhead_ratio
            # Then: baseline_time = baseline_time * (1 - reduction_pct/100) + baseline_time * overhead_ratio
            # Solving: 1 = (1 - reduction_pct/100) + overhead_ratio
            # reduction_pct/100 = overhead_ratio
            # reduction_pct = overhead_ratio * 100
            break_even_reduction = overhead_ratio * 100
            break_even_reductions.append(break_even_reduction)
        
        ax4.plot(overhead_ratios * 100, break_even_reductions, 'blue', linewidth=3, 
                label='Break-even threshold')
        
        # Plot actual data points
        ax4.scatter(df['overhead_ratio'] * 100, df['reduction_percentage'], 
                   c=df['net_speedup'], cmap='RdYlGn', alpha=0.7, s=80, 
                   vmin=0.5, vmax=2.0)
        
        # Add colorbar
        cbar = plt.colorbar(ax4.collections[0], ax=ax4)
        cbar.set_label('Net Speedup')
        
        ax4.set_xlabel('Overhead Ratio (%)')
        ax4.set_ylabel('Reduction Percentage (%)')
        ax4.set_title('Break-Even Threshold Analysis')
        ax4.legend()
        ax4.grid(True, alpha=0.3)
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'break_even_analysis.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Break-even analysis saved to: {os.path.join(self.output_folder, 'break_even_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_detailed_threshold_analysis(self, df: pd.DataFrame) -> None:
        """
        Create detailed analysis of when optimization is beneficial.
        """
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(20, 12))
        fig.suptitle('Detailed Threshold Analysis: Optimization Success Factors', 
                    fontsize=16, fontweight='bold')
        
        # 1. Reduction percentage distribution by outcome
        beneficial = df[df['net_speedup'] > 1]
        detrimental = df[df['net_speedup'] <= 1]
        
        ax1.hist(beneficial['reduction_percentage'], bins=20, alpha=0.7, 
                color='green', label=f'Beneficial (n={len(beneficial)})', density=True)
        ax1.hist(detrimental['reduction_percentage'], bins=20, alpha=0.7, 
                color='red', label=f'Detrimental (n={len(detrimental)})', density=True)
        
        ax1.axvline(x=beneficial['reduction_percentage'].median(), color='darkgreen', 
                   linestyle='--', linewidth=2, label=f'Beneficial median: {beneficial["reduction_percentage"].median():.1f}%')
        ax1.axvline(x=detrimental['reduction_percentage'].median(), color='darkred', 
                   linestyle='--', linewidth=2, label=f'Detrimental median: {detrimental["reduction_percentage"].median():.1f}%')
        
        ax1.set_xlabel('Reduction Percentage (%)')
        ax1.set_ylabel('Density')
        ax1.set_title('Reduction Percentage Distribution by Outcome')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # 2. Problem size effect
        size_order = ['Tiny', 'Small', 'Medium', 'Large']
        beneficial_by_size = []
        total_by_size = []
        
        for size in size_order:
            size_data = df[df['size_category'] == size]
            beneficial_count = len(size_data[size_data['net_speedup'] > 1])
            total_count = len(size_data)
            beneficial_by_size.append(beneficial_count)
            total_by_size.append(total_count)
        
        success_rates = [b/t*100 if t > 0 else 0 for b, t in zip(beneficial_by_size, total_by_size)]
        
        bars = ax2.bar(size_order, success_rates, alpha=0.8, color=['lightblue', 'orange', 'lightgreen', 'purple'])
        ax2.set_xlabel('Problem Size Category')
        ax2.set_ylabel('Success Rate (%)')
        ax2.set_title('Optimization Success Rate by Problem Size')
        ax2.grid(True, alpha=0.3, axis='y')
        
        # Add count labels on bars
        for bar, beneficial, total in zip(bars, beneficial_by_size, total_by_size):
            height = bar.get_height()
            ax2.text(bar.get_x() + bar.get_width()/2., height + 1,
                    f'{beneficial}/{total}', ha='center', va='bottom', fontsize=10, fontweight='bold')
        
        # 3. Overhead time vs baseline time
        ax3.scatter(df['baseline_time'], df['optimization_time'], alpha=0.7, s=80, 
                   c=df['net_speedup'], cmap='RdYlGn', vmin=0.5, vmax=2.0)
        
        # Add trend line
        log_baseline = np.log10(df['baseline_time'][df['baseline_time'] > 0])
        log_overhead = np.log10(df['optimization_time'][df['optimization_time'] > 0])
        
        if HAS_SCIPY and len(log_baseline) > 3:
            slope, intercept, r_value, p_value, std_err = stats.linregress(log_baseline, log_overhead)
            x_trend = np.logspace(np.log10(df['baseline_time'].min()), np.log10(df['baseline_time'].max()), 100)
            y_trend = 10**(slope * np.log10(x_trend) + intercept)
            ax3.plot(x_trend, y_trend, 'blue', linestyle='-', linewidth=2, alpha=0.7, 
                    label=f'Trend (R²={r_value**2:.3f})')
        
        ax3.set_xlabel('Baseline Time (seconds)')
        ax3.set_ylabel('Optimization Time (seconds)')
        ax3.set_title('Optimization Overhead vs Baseline Time')
        ax3.set_xscale('log')
        ax3.set_yscale('log')
        ax3.legend()
        ax3.grid(True, alpha=0.3)
        
        # Add colorbar
        cbar = plt.colorbar(ax3.collections[0], ax=ax3)
        cbar.set_label('Net Speedup')
        
        # 4. Critical thresholds summary
        ax4.axis('off')
        
        # Calculate key thresholds
        beneficial_mask = df['net_speedup'] > 1
        
        avg_reduction_beneficial = df[beneficial_mask]['reduction_percentage'].mean()
        avg_reduction_detrimental = df[~beneficial_mask]['reduction_percentage'].mean()
        
        avg_overhead_beneficial = df[beneficial_mask]['overhead_ratio'].mean() * 100
        avg_overhead_detrimental = df[~beneficial_mask]['overhead_ratio'].mean() * 100
        
        threshold_text = f"""
KEY FINDINGS - OPTIMIZATION SUCCESS THRESHOLDS

Success Rate: {len(df[beneficial_mask])}/{len(df)} ({len(df[beneficial_mask])/len(df)*100:.1f}%)

BENEFICIAL CASES (Net Speedup > 1.0):
• Average reduction: {avg_reduction_beneficial:.1f}%
• Average overhead ratio: {avg_overhead_beneficial:.1f}%
• Median baseline time: {df[beneficial_mask]['baseline_time'].median():.1f}s
• Size distribution: {df[beneficial_mask]['size_category'].value_counts().to_dict()}

DETRIMENTAL CASES (Net Speedup ≤ 1.0):
• Average reduction: {avg_reduction_detrimental:.1f}%
• Average overhead ratio: {avg_overhead_detrimental:.1f}%
• Median baseline time: {df[~beneficial_mask]['baseline_time'].median():.1f}s
• Size distribution: {df[~beneficial_mask]['size_category'].value_counts().to_dict()}

RECOMMENDATIONS:
• Optimization most beneficial for problems with >30% reduction potential
• Avoid optimization when overhead ratio >50% of baseline time
• Large problems (>100 properties) show highest success rates
• Problems <1 second baseline rarely benefit from optimization
        """
        
        ax4.text(0.05, 0.95, threshold_text, transform=ax4.transAxes, fontsize=11,
                verticalalignment='top', fontfamily='monospace',
                bbox=dict(boxstyle="round,pad=0.5", facecolor="lightgray", alpha=0.8))
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'threshold_analysis.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Threshold analysis saved to: {os.path.join(self.output_folder, 'threshold_analysis.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def generate_break_even_report(self, df: pd.DataFrame) -> None:
        """
        Generate comprehensive break-even analysis report.
        """
        print("\n" + "=" * 80)
        print("BREAK-EVEN ANALYSIS REPORT")
        print("=" * 80)
        
        beneficial = df[df['net_speedup'] > 1]
        detrimental = df[df['net_speedup'] <= 1]
        
        print(f"\nOverall Performance:")
        print(f"  Total benchmarks: {len(df)}")
        print(f"  Beneficial cases: {len(beneficial)} ({len(beneficial)/len(df)*100:.1f}%)")
        print(f"  Detrimental cases: {len(detrimental)} ({len(detrimental)/len(df)*100:.1f}%)")
        
        print(f"\nBeneficial Cases Analysis:")
        print(f"  Average reduction: {beneficial['reduction_percentage'].mean():.1f}%")
        print(f"  Median reduction: {beneficial['reduction_percentage'].median():.1f}%")
        print(f"  Average overhead ratio: {beneficial['overhead_ratio'].mean()*100:.1f}%")
        print(f"  Average net speedup: {beneficial['net_speedup'].mean():.2f}x")
        print(f"  Average baseline time: {beneficial['baseline_time'].mean():.1f}s")
        
        print(f"\nDetrimental Cases Analysis:")
        print(f"  Average reduction: {detrimental['reduction_percentage'].mean():.1f}%")
        print(f"  Median reduction: {detrimental['reduction_percentage'].median():.1f}%")
        print(f"  Average overhead ratio: {detrimental['overhead_ratio'].mean()*100:.1f}%")
        print(f"  Average net speedup: {detrimental['net_speedup'].mean():.2f}x")
        print(f"  Average baseline time: {detrimental['baseline_time'].mean():.1f}s")
        
        print(f"\nSize Category Analysis:")
        for size in ['Tiny', 'Small', 'Medium', 'Large']:
            size_data = df[df['size_category'] == size]
            if not size_data.empty:
                beneficial_count = len(size_data[size_data['net_speedup'] > 1])
                success_rate = beneficial_count / len(size_data) * 100
                print(f"  {size}: {beneficial_count}/{len(size_data)} beneficial ({success_rate:.1f}%)")
        
        print(f"\nCritical Thresholds:")
        # Find thresholds where success rate drops significantly
        sorted_by_reduction = df.sort_values('reduction_percentage')
        for threshold in [10, 20, 30, 40, 50]:
            above_threshold = df[df['reduction_percentage'] >= threshold]
            if not above_threshold.empty:
                beneficial_count = len(above_threshold[above_threshold['net_speedup'] > 1])
                success_rate = beneficial_count / len(above_threshold) * 100
                print(f"  ≥{threshold}% reduction: {success_rate:.1f}% success rate ({beneficial_count}/{len(above_threshold)})")
        
        print("=" * 80)
        
        # Save detailed data
        if self.save_plots:
            detailed_path = os.path.join(self.output_folder, 'break_even_detailed_data.csv')
            df.to_csv(detailed_path, index=False)
            print(f"Detailed break-even data saved to: {detailed_path}")
    
    def run_break_even_analysis(self, baseline_file: str = "baseline_timing_summary.csv",
                               optimized_file: str = "ltlreduction_timing_summary.csv",
                               benchmark_specific_folder: str = "optimized_results/benchmark_specific",
                               calculated_summary_file: str = "optimized_results/calculated_benchmark_summary.csv") -> None:
        """
        Run complete break-even analysis.
        """
        print("Starting Break-Even Analysis: When LTL Optimization Pays Off")
        print("=" * 70)
        
        # Load comprehensive data
        df = self.load_comprehensive_data(baseline_file, optimized_file, 
                                        benchmark_specific_folder, calculated_summary_file)
        
        print("\nGenerating break-even visualizations...")
        
        # Create visualizations
        self.create_break_even_analysis(df)
        self.create_detailed_threshold_analysis(df)
        
        # Generate report
        self.generate_break_even_report(df)
        
        print(f"\nBreak-even analysis complete! Results saved to: {self.output_folder}")


def main():
    """Main execution function."""
    
    # Configuration
    BASELINE_FILE = "baseline_timing_summary.csv"
    OPTIMIZED_FILE = "ltlreduction_timing_summary.csv"
    BENCHMARK_SPECIFIC_FOLDER = "optimized_results/benchmark_specific"
    CALCULATED_SUMMARY_FILE = "optimized_results/calculated_benchmark_summary.csv"
    SAVE_PLOTS = True
    SHOW_PLOTS = False
    OUTPUT_FOLDER = "comparative_analysis"
    
    # Initialize analyzer
    analyzer = BreakEvenAnalyzer(
        save_plots=SAVE_PLOTS,
        show_plots=SHOW_PLOTS,
        output_folder=OUTPUT_FOLDER
    )
    
    # Check if required files exist
    required_files = [BASELINE_FILE, OPTIMIZED_FILE, BENCHMARK_SPECIFIC_FOLDER]
    for file_path in required_files:
        if not os.path.exists(file_path):
            print(f"Error: Required file/folder '{file_path}' not found.")
            return
    
    # Run break-even analysis
    analyzer.run_break_even_analysis(
        baseline_file=BASELINE_FILE,
        optimized_file=OPTIMIZED_FILE,
        benchmark_specific_folder=BENCHMARK_SPECIFIC_FOLDER,
        calculated_summary_file=CALCULATED_SUMMARY_FILE
    )


if __name__ == "__main__":
    main()
