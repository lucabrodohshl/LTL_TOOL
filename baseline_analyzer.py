"""
Baseline Timing Analysis and Visualization Tool

This script analyzes baseline timing results from CSV files and generates
comprehensive visualizations and statistical summaries.
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os
from typing import Optional, Tuple

# Try to import seaborn, use fallback if not available
try:
    import seaborn as sns
    HAS_SEABORN = True
except ImportError:
    HAS_SEABORN = False


class BaselineAnalyzer:
    """
    Analyzer for baseline timing results with customizable visualization options.
    """
    
    def __init__(self, save_plots: bool = True, show_plots: bool = False, output_folder: str = "baseline_analysis"):
        """
        Initialize the baseline analyzer.
        
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
        plt.style.use('default')  # Use default style
        if HAS_SEABORN:
            sns.set_palette("husl")
    
    def load_baseline_data(self, csv_file: str) -> pd.DataFrame:
        """
        Load baseline timing data from CSV file.
        
        Args:
            csv_file: Path to baseline timing CSV file
            
        Returns:
            Loaded pandas DataFrame
        """
        df = pd.read_csv(csv_file)
        
        # Clean benchmark names (remove index column if present)
        if 'Unnamed: 0' in df.columns:
            df = df.drop('Unnamed: 0', axis=1)
        
        # Sort by benchmark name for consistent ordering
        df = df.sort_values('Benchmark').reset_index(drop=True)
        
        return df
    
    def create_timing_overview(self, df: pd.DataFrame) -> None:
        """
        Create comprehensive timing overview visualization.
        
        Args:
            df: DataFrame with baseline timing data
        """
        fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
        fig.suptitle('Baseline Timing Analysis Overview', fontsize=16, fontweight='bold')
        
        # 1. Total Elapsed Time by Benchmark
        benchmarks = df['Benchmark']
        times = df['Total Elapsed Time (seconds)']
        
        ax1.bar(range(len(benchmarks)), times, alpha=0.7, color='steelblue')
        ax1.set_xlabel('Benchmark Index')
        ax1.set_ylabel('Total Elapsed Time (seconds)')
        ax1.set_title('Total Elapsed Time by Benchmark')
        ax1.grid(True, alpha=0.3)
        
        # Highlight timeouts
        timeout_mask = df['Timeouts'] > 0
        if timeout_mask.any():
            timeout_indices = np.where(timeout_mask)[0]
            timeout_times = times[timeout_mask]
            ax1.bar(timeout_indices, timeout_times, alpha=0.9, color='red', label='Has Timeouts')
            ax1.legend()
        
        # 2. Average Time per Property
        avg_times = df['Average Elapsed Time (seconds)']
        ax2.scatter(df['Num Properties'], avg_times, alpha=0.6, s=60)
        ax2.set_xlabel('Number of Properties')
        ax2.set_ylabel('Average Time per Property (seconds)')
        ax2.set_title('Average Time vs Number of Properties')
        ax2.set_yscale('log')
        ax2.grid(True, alpha=0.3)
        
        # 3. Timeout Analysis
        timeout_counts = df['Timeouts']
        total_properties = df['Num Properties']
        timeout_rates = (timeout_counts / total_properties * 100).fillna(0)
        
        non_zero_timeouts = timeout_rates[timeout_rates > 0]
        if len(non_zero_timeouts) > 0:
            ax3.bar(range(len(non_zero_timeouts)), non_zero_timeouts, alpha=0.7, color='orange')
            ax3.set_xlabel('Benchmark (Timeouts Only)')
            ax3.set_ylabel('Timeout Rate (%)')
            ax3.set_title('Timeout Rates by Benchmark')
            ax3.grid(True, alpha=0.3)
        else:
            ax3.text(0.5, 0.5, 'No Timeouts Detected', ha='center', va='center', transform=ax3.transAxes)
            ax3.set_title('Timeout Analysis')
        
        # 4. Performance Distribution
        log_times = np.log10(times[times > 0])
        ax4.hist(log_times, bins=20, alpha=0.7, color='green', edgecolor='black')
        ax4.set_xlabel('Log10(Total Elapsed Time)')
        ax4.set_ylabel('Frequency')
        ax4.set_title('Performance Distribution (Log Scale)')
        ax4.grid(True, alpha=0.3)
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'timing_overview.png'), dpi=300, bbox_inches='tight')
            print(f"Timing overview saved to: {os.path.join(self.output_folder, 'timing_overview.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_benchmark_timing_chart(self, df: pd.DataFrame) -> None:
        """
        Create detailed benchmark timing chart with benchmark names on x-axis.
        
        Args:
            df: DataFrame with baseline timing data
        """
        plt.figure(figsize=(20, 8))
        
        benchmarks = df['Benchmark']
        times = df['Total Elapsed Time (seconds)']
        
        # Create bar chart
        bars = plt.bar(range(len(benchmarks)), times, alpha=0.7, color='steelblue')
        
        # Highlight timeouts in red
        timeout_mask = df['Timeouts'] > 0
        for i, (has_timeout, bar) in enumerate(zip(timeout_mask, bars)):
            if has_timeout:
                bar.set_color('red')
                bar.set_alpha(0.8)
        
        plt.xlabel('Benchmark Name', fontsize=12)
        plt.ylabel('Total Elapsed Time (seconds)', fontsize=12)
        plt.title('Total Elapsed Time by Benchmark', fontsize=14, fontweight='bold')
        plt.xticks(range(len(benchmarks)), benchmarks, rotation=45, ha='right')
        plt.grid(True, alpha=0.3, axis='y')
        
        # Add average line
        avg_time = times.mean()
        plt.axhline(y=avg_time, color='orange', linestyle='--', linewidth=2, 
                   label=f'Average: {avg_time:.2f}s')
        plt.legend()
        
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'benchmark_timing_chart.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Benchmark timing chart saved to: {os.path.join(self.output_folder, 'benchmark_timing_chart.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def create_performance_heatmap(self, df: pd.DataFrame) -> None:
        """
        Create performance heatmap showing multiple metrics.
        
        Args:
            df: DataFrame with baseline timing data
        """
        # Prepare data for heatmap
        metrics_data = df[['Benchmark', 'Total Elapsed Time (seconds)', 
                          'Average Elapsed Time (seconds)', 'Num Properties', 'Timeouts']].copy()
        
        # Normalize metrics for better visualization
        metrics_normalized = metrics_data.copy()
        metrics_normalized['Total Time (normalized)'] = (metrics_data['Total Elapsed Time (seconds)'] - 
                                                        metrics_data['Total Elapsed Time (seconds)'].min()) / \
                                                       (metrics_data['Total Elapsed Time (seconds)'].max() - 
                                                        metrics_data['Total Elapsed Time (seconds)'].min())
        
        metrics_normalized['Avg Time (normalized)'] = (metrics_data['Average Elapsed Time (seconds)'] - 
                                                      metrics_data['Average Elapsed Time (seconds)'].min()) / \
                                                     (metrics_data['Average Elapsed Time (seconds)'].max() - 
                                                      metrics_data['Average Elapsed Time (seconds)'].min())
        
        metrics_normalized['Properties (normalized)'] = (metrics_data['Num Properties'] - 
                                                        metrics_data['Num Properties'].min()) / \
                                                       (metrics_data['Num Properties'].max() - 
                                                        metrics_data['Num Properties'].min())
        
        metrics_normalized['Timeout Rate'] = metrics_data['Timeouts'] / metrics_data['Num Properties']
        
        # Create heatmap
        heatmap_data = metrics_normalized[['Total Time (normalized)', 'Avg Time (normalized)', 
                                          'Properties (normalized)', 'Timeout Rate']].T
        
        plt.figure(figsize=(16, 6))
        
        if HAS_SEABORN:
            sns.heatmap(heatmap_data, 
                       xticklabels=metrics_data['Benchmark'], 
                       yticklabels=['Total Time', 'Avg Time', 'Num Properties', 'Timeout Rate'],
                       cmap='YlOrRd', 
                       annot=False, 
                       cbar_kws={'label': 'Normalized Score'})
        else:
            # Fallback heatmap using matplotlib
            im = plt.imshow(heatmap_data, cmap='YlOrRd', aspect='auto')
            plt.xticks(range(len(metrics_data['Benchmark'])), metrics_data['Benchmark'], rotation=45, ha='right')
            plt.yticks(range(4), ['Total Time', 'Avg Time', 'Num Properties', 'Timeout Rate'])
            plt.colorbar(im, label='Normalized Score')
        
        plt.title('Performance Heatmap (Normalized Metrics)', fontsize=14, fontweight='bold')
        plt.xlabel('Benchmark', fontsize=12)
        plt.ylabel('Metric', fontsize=12)
        plt.xticks(rotation=45, ha='right')
        plt.tight_layout()
        
        if self.save_plots:
            plt.savefig(os.path.join(self.output_folder, 'performance_heatmap.png'), 
                       dpi=300, bbox_inches='tight')
            print(f"Performance heatmap saved to: {os.path.join(self.output_folder, 'performance_heatmap.png')}")
        
        if self.show_plots:
            plt.show()
        else:
            plt.close()
    
    def generate_statistics_report(self, df: pd.DataFrame) -> None:
        """
        Generate comprehensive statistics report.
        
        Args:
            df: DataFrame with baseline timing data
        """
        stats = {
            'Total Benchmarks': len(df),
            'Total Properties': df['Num Properties'].sum(),
            'Total Runtime': df['Total Elapsed Time (seconds)'].sum(),
            'Average Runtime per Benchmark': df['Total Elapsed Time (seconds)'].mean(),
            'Median Runtime per Benchmark': df['Total Elapsed Time (seconds)'].median(),
            'Average Properties per Benchmark': df['Num Properties'].mean(),
            'Total Timeouts': df['Timeouts'].sum(),
            'Benchmarks with Timeouts': (df['Timeouts'] > 0).sum(),
            'Overall Timeout Rate': (df['Timeouts'].sum() / df['Num Properties'].sum() * 100),
            'Fastest Benchmark': df.loc[df['Total Elapsed Time (seconds)'].idxmin(), 'Benchmark'],
            'Slowest Benchmark': df.loc[df['Total Elapsed Time (seconds)'].idxmax(), 'Benchmark'],
            'Most Properties': df.loc[df['Num Properties'].idxmax(), 'Benchmark'],
            'Fewest Properties': df.loc[df['Num Properties'].idxmin(), 'Benchmark']
        }
        
        print("\n" + "=" * 60)
        print("BASELINE TIMING ANALYSIS REPORT")
        print("=" * 60)
        
        for key, value in stats.items():
            if isinstance(value, float):
                if 'Time' in key or 'Runtime' in key:
                    print(f"{key}: {value:.2f} seconds")
                elif 'Rate' in key:
                    print(f"{key}: {value:.2f}%")
                else:
                    print(f"{key}: {value:.2f}")
            else:
                print(f"{key}: {value}")
        
        print("=" * 60)
        
        # Save statistics to CSV
        if self.save_plots:
            stats_df = pd.DataFrame(list(stats.items()), columns=['Metric', 'Value'])
            stats_path = os.path.join(self.output_folder, 'baseline_statistics.csv')
            stats_df.to_csv(stats_path, index=False)
            print(f"Statistics saved to: {stats_path}")
    
    def analyze_baseline(self, csv_file: str) -> pd.DataFrame:
        """
        Complete baseline analysis with all visualizations and statistics.
        
        Args:
            csv_file: Path to baseline timing CSV file
            
        Returns:
            Loaded and processed DataFrame
        """
        print(f"Loading baseline data from: {csv_file}")
        df = self.load_baseline_data(csv_file)
        
        print(f"Analyzing {len(df)} benchmarks...")
        
        # Generate all visualizations
        self.create_benchmark_timing_chart(df)
        self.create_timing_overview(df)
        self.create_performance_heatmap(df)
        
        # Generate statistics report
        self.generate_statistics_report(df)
        
        print(f"\nAnalysis complete! Results saved to: {self.output_folder}")
        return df


def main():
    """Main execution function."""
    
    # Configuration
    CSV_FILE = "baseline_timing_summary.csv"
    SAVE_PLOTS = True
    SHOW_PLOTS = False  # Set to True to display plots interactively
    OUTPUT_FOLDER = "baseline_analysis"
    
    # Initialize analyzer
    analyzer = BaselineAnalyzer(
        save_plots=SAVE_PLOTS,
        show_plots=SHOW_PLOTS,
        output_folder=OUTPUT_FOLDER
    )
    
    # Run analysis
    if os.path.exists(CSV_FILE):
        df = analyzer.analyze_baseline(CSV_FILE)
        
        # Print key findings
        avg_total_time = df['Total Elapsed Time (seconds)'].mean()
        print(f"\nKey Finding: Average total elapsed time across all benchmarks: {avg_total_time:.2f} seconds")
        
    else:
        print(f"Error: CSV file '{CSV_FILE}' not found.")
        print("Please ensure the baseline timing summary file exists in the current directory.")


if __name__ == "__main__":
    main()
