"""
Analysis script to compare Original LTL Optimizer vs Enhanced LTL Optimizer Alternative.

This script compares the performance metrics from two optimization approaches:
1. Original method (optimized_results/benchmark_specific)
2. Enhanced alternative method (optimized_results_alternative/benchmark_specific)

It generates bar graphs comparing:
- Total processing time
- Reduction percentage
- Performance by benchmark category
"""

import os
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from typing import Dict, List, Tuple
import glob
from pathlib import Path

def load_method_data(folder_path: str, method_name: str) -> pd.DataFrame:
    """
    Load all benchmark summary CSV files from a method folder.
    
    Args:
        folder_path: Path to the benchmark_specific folder
        method_name: Name of the method for identification
        
    Returns:
        DataFrame with all benchmark results
    """
    data_rows = []
    
    # Find all summary CSV files
    if method_name == "original":
        pattern = os.path.join(folder_path, "*_metrics_summary.csv")
    else:  # enhanced
        pattern = os.path.join(folder_path, "*_enhanced_metrics_summary.csv")
    
    csv_files = glob.glob(pattern)
    
    for csv_file in csv_files:
        try:
            # Extract benchmark name from filename
            filename = os.path.basename(csv_file)
            if method_name == "original":
                benchmark_name = filename.replace("_metrics_summary.csv", "")
            else:
                benchmark_name = filename.replace("_enhanced_metrics_summary.csv", "")
            
            # Load the CSV
            df = pd.read_csv(csv_file)
            if len(df) > 0:
                row = df.iloc[0].to_dict()
                row['benchmark_name'] = benchmark_name
                row['method'] = method_name
                data_rows.append(row)
                
        except Exception as e:
            print(f"Error loading {csv_file}: {e}")
            continue
    
    return pd.DataFrame(data_rows)

def categorize_benchmarks(benchmark_names: List[str]) -> Dict[str, List[str]]:
    """
    Categorize benchmarks by their type based on naming patterns.
    
    Args:
        benchmark_names: List of benchmark names
        
    Returns:
        Dictionary mapping category names to benchmark lists
    """
    categories = {
        'Mutual Exclusion': [],
        'Communication Protocols': [],
        'Distributed Algorithms': [],
        'Scheduling': [],
        'Model Checking Examples': [],
        'Other': []
    }
    
    for name in benchmark_names:
        name_lower = name.lower()
        
        if any(keyword in name_lower for keyword in ['peterson', 'lamport', 'bakery', 'fischer', 'szymanski', 'mcs']):
            categories['Mutual Exclusion'].append(name)
        elif any(keyword in name_lower for keyword in ['brp', 'iprotocol', 'protocols', 'rether', 'collision']):
            categories['Communication Protocols'].append(name)
        elif any(keyword in name_lower for keyword in ['leader', 'lann', 'election', 'public_subscribe']):
            categories['Distributed Algorithms'].append(name)
        elif any(keyword in name_lower for keyword in ['elevator', 'scheduler', 'phils', 'driving']):
            categories['Scheduling'].append(name)
        elif any(keyword in name_lower for keyword in ['anderson', 'at', 'bopdp', 'bridge', 'exit', 'extinction']):
            categories['Model Checking Examples'].append(name)
        else:
            categories['Other'].append(name)
    
    # Remove empty categories
    return {k: v for k, v in categories.items() if v}

def create_comparison_plots(original_data: pd.DataFrame, enhanced_data: pd.DataFrame, output_folder: str = "comparison_plots"):
    """
    Create comprehensive comparison plots between the two methods.
    
    Args:
        original_data: DataFrame with original method results
        enhanced_data: DataFrame with enhanced method results
        output_folder: Folder to save plots
    """
    os.makedirs(output_folder, exist_ok=True)
    
    # Merge data on benchmark name for direct comparison
    merged = pd.merge(original_data, enhanced_data, on='benchmark_name', suffixes=('_original', '_enhanced'))
    
    if len(merged) == 0:
        print("No common benchmarks found between the two methods!")
        return
    
    print(f"Comparing {len(merged)} common benchmarks between methods")
    
    # 1. Overall Performance Comparison Bar Charts
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 6))
    
    # Total Time Comparison
    x_pos = np.arange(len(merged))
    
    ax1.bar(x_pos - 0.2, merged['total_time_original'], 0.4, label='Original Method', alpha=0.7, color='skyblue')
    ax1.bar(x_pos + 0.2, merged['total_time_enhanced'], 0.4, label='Enhanced Method', alpha=0.7, color='lightcoral')
    
    ax1.set_xlabel('Benchmarks')
    ax1.set_ylabel('Total Time (seconds)')
    ax1.set_title('Total Processing Time Comparison')
    ax1.set_xticks(x_pos)
    ax1.set_xticklabels(merged['benchmark_name'], rotation=45, ha='right')
    ax1.legend()
    ax1.grid(True, alpha=0.3)
    
    # Reduction Percentage Comparison
    ax2.bar(x_pos - 0.2, merged['reduction_percentage_original'], 0.4, label='Original Method', alpha=0.7, color='skyblue')
    ax2.bar(x_pos + 0.2, merged['reduction_percentage_enhanced'], 0.4, label='Enhanced Method', alpha=0.7, color='lightcoral')
    
    ax2.set_xlabel('Benchmarks')
    ax2.set_ylabel('Reduction Percentage (%)')
    ax2.set_title('Formula Reduction Percentage Comparison')
    ax2.set_xticks(x_pos)
    ax2.set_xticklabels(merged['benchmark_name'], rotation=45, ha='right')
    ax2.legend()
    ax2.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_folder, 'overall_comparison.png'), dpi=300, bbox_inches='tight')
    plt.show()
    
    # 2. Summary Statistics Comparison
    fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(12, 10))
    
    # Average metrics comparison
    original_avg_time = merged['total_time_original'].mean()
    enhanced_avg_time = merged['total_time_enhanced'].mean()
    original_avg_reduction = merged['reduction_percentage_original'].mean()
    enhanced_avg_reduction = merged['reduction_percentage_enhanced'].mean()
    
    methods = ['Original', 'Enhanced']
    avg_times = [original_avg_time, enhanced_avg_time]
    avg_reductions = [original_avg_reduction, enhanced_avg_reduction]
    
    bars1 = ax1.bar(methods, avg_times, color=['skyblue', 'lightcoral'], alpha=0.7)
    ax1.set_ylabel('Average Time (seconds)')
    ax1.set_title('Average Processing Time')
    ax1.grid(True, alpha=0.3)
    
    # Add value labels on bars
    for bar, value in zip(bars1, avg_times):
        ax1.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 0.1, 
                f'{value:.2f}s', ha='center', va='bottom')
    
    bars2 = ax2.bar(methods, avg_reductions, color=['skyblue', 'lightcoral'], alpha=0.7)
    ax2.set_ylabel('Average Reduction (%)')
    ax2.set_title('Average Formula Reduction')
    ax2.grid(True, alpha=0.3)
    
    for bar, value in zip(bars2, avg_reductions):
        ax2.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 0.5, 
                f'{value:.1f}%', ha='center', va='bottom')
    
    # Time difference analysis
    time_diff = merged['total_time_enhanced'] - merged['total_time_original']
    reduction_diff = merged['reduction_percentage_enhanced'] - merged['reduction_percentage_original']
    
    ax3.hist(time_diff, bins=20, alpha=0.7, color='green', edgecolor='black')
    ax3.set_xlabel('Time Difference (Enhanced - Original) (seconds)')
    ax3.set_ylabel('Number of Benchmarks')
    ax3.set_title('Distribution of Time Differences')
    ax3.axvline(x=0, color='red', linestyle='--', alpha=0.7)
    ax3.grid(True, alpha=0.3)
    
    ax4.hist(reduction_diff, bins=20, alpha=0.7, color='purple', edgecolor='black')
    ax4.set_xlabel('Reduction Difference (Enhanced - Original) (%)')
    ax4.set_ylabel('Number of Benchmarks')
    ax4.set_title('Distribution of Reduction Differences')
    ax4.axvline(x=0, color='red', linestyle='--', alpha=0.7)
    ax4.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_folder, 'summary_statistics.png'), dpi=300, bbox_inches='tight')
    plt.show()
    
    # 3. Category-based Analysis
    all_benchmarks = list(merged['benchmark_name'])
    categories = categorize_benchmarks(all_benchmarks)
    
    if len(categories) > 1:
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 6))
        
        category_names = []
        original_cat_times = []
        enhanced_cat_times = []
        original_cat_reductions = []
        enhanced_cat_reductions = []
        
        for cat_name, benchmarks in categories.items():
            if len(benchmarks) > 0:
                cat_data = merged[merged['benchmark_name'].isin(benchmarks)]
                if len(cat_data) > 0:
                    category_names.append(f"{cat_name}\n({len(cat_data)} benchmarks)")
                    original_cat_times.append(cat_data['total_time_original'].mean())
                    enhanced_cat_times.append(cat_data['total_time_enhanced'].mean())
                    original_cat_reductions.append(cat_data['reduction_percentage_original'].mean())
                    enhanced_cat_reductions.append(cat_data['reduction_percentage_enhanced'].mean())
        
        x_pos = np.arange(len(category_names))
        
        # Category time comparison
        ax1.bar(x_pos - 0.2, original_cat_times, 0.4, label='Original Method', alpha=0.7, color='skyblue')
        ax1.bar(x_pos + 0.2, enhanced_cat_times, 0.4, label='Enhanced Method', alpha=0.7, color='lightcoral')
        
        ax1.set_xlabel('Benchmark Categories')
        ax1.set_ylabel('Average Time (seconds)')
        ax1.set_title('Average Processing Time by Category')
        ax1.set_xticks(x_pos)
        ax1.set_xticklabels(category_names, rotation=45, ha='right')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Category reduction comparison
        ax2.bar(x_pos - 0.2, original_cat_reductions, 0.4, label='Original Method', alpha=0.7, color='skyblue')
        ax2.bar(x_pos + 0.2, enhanced_cat_reductions, 0.4, label='Enhanced Method', alpha=0.7, color='lightcoral')
        
        ax2.set_xlabel('Benchmark Categories')
        ax2.set_ylabel('Average Reduction (%)')
        ax2.set_title('Average Formula Reduction by Category')
        ax2.set_xticks(x_pos)
        ax2.set_xticklabels(category_names, rotation=45, ha='right')
        ax2.legend()
        ax2.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.savefig(os.path.join(output_folder, 'category_comparison.png'), dpi=300, bbox_inches='tight')
        plt.show()
    
    # 4. Performance Scatter Plot
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
    
    # Time vs Time scatter
    ax1.scatter(merged['total_time_original'], merged['total_time_enhanced'], alpha=0.7, s=50)
    
    # Add diagonal line for reference
    max_time = max(merged['total_time_original'].max(), merged['total_time_enhanced'].max())
    ax1.plot([0, max_time], [0, max_time], 'r--', alpha=0.7, label='Equal performance')
    
    ax1.set_xlabel('Original Method Time (seconds)')
    ax1.set_ylabel('Enhanced Method Time (seconds)')
    ax1.set_title('Processing Time Correlation')
    ax1.legend()
    ax1.grid(True, alpha=0.3)
    
    # Reduction vs Reduction scatter
    ax2.scatter(merged['reduction_percentage_original'], merged['reduction_percentage_enhanced'], alpha=0.7, s=50)
    
    # Add diagonal line for reference
    max_reduction = max(merged['reduction_percentage_original'].max(), merged['reduction_percentage_enhanced'].max())
    ax2.plot([0, max_reduction], [0, max_reduction], 'r--', alpha=0.7, label='Equal performance')
    
    ax2.set_xlabel('Original Method Reduction (%)')
    ax2.set_ylabel('Enhanced Method Reduction (%)')
    ax2.set_title('Reduction Percentage Correlation')
    ax2.legend()
    ax2.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_folder, 'correlation_analysis.png'), dpi=300, bbox_inches='tight')
    plt.show()

def print_detailed_statistics(original_data: pd.DataFrame, enhanced_data: pd.DataFrame):
    """Print detailed comparison statistics."""
    merged = pd.merge(original_data, enhanced_data, on='benchmark_name', suffixes=('_original', '_enhanced'))
    
    print("\n" + "="*80)
    print("DETAILED COMPARISON STATISTICS")
    print("="*80)
    
    print(f"Total benchmarks compared: {len(merged)}")
    print(f"Original method benchmarks: {len(original_data)}")
    print(f"Enhanced method benchmarks: {len(enhanced_data)}")
    
    # Time analysis
    time_diff = merged['total_time_enhanced'] - merged['total_time_original']
    faster_enhanced = (time_diff < 0).sum()
    faster_original = (time_diff > 0).sum()
    
    print(f"\nTIME PERFORMANCE:")
    print(f"  Enhanced method faster: {faster_enhanced} benchmarks ({faster_enhanced/len(merged)*100:.1f}%)")
    print(f"  Original method faster: {faster_original} benchmarks ({faster_original/len(merged)*100:.1f}%)")
    print(f"  Average time difference: {time_diff.mean():.3f} seconds")
    print(f"  Median time difference: {time_diff.median():.3f} seconds")
    
    # Reduction analysis
    reduction_diff = merged['reduction_percentage_enhanced'] - merged['reduction_percentage_original']
    better_enhanced = (reduction_diff > 0).sum()
    better_original = (reduction_diff < 0).sum()
    
    print(f"\nREDUCTION PERFORMANCE:")
    print(f"  Enhanced method better reduction: {better_enhanced} benchmarks ({better_enhanced/len(merged)*100:.1f}%)")
    print(f"  Original method better reduction: {better_original} benchmarks ({better_original/len(merged)*100:.1f}%)")
    print(f"  Average reduction difference: {reduction_diff.mean():.3f}%")
    print(f"  Median reduction difference: {reduction_diff.median():.3f}%")
    
    # Overall metrics
    print(f"\nOVERALL AVERAGES:")
    print(f"  Original method - Avg time: {merged['total_time_original'].mean():.3f}s, Avg reduction: {merged['reduction_percentage_original'].mean():.1f}%")
    print(f"  Enhanced method - Avg time: {merged['total_time_enhanced'].mean():.3f}s, Avg reduction: {merged['reduction_percentage_enhanced'].mean():.1f}%")
    
    # Best/worst cases
    print(f"\nBEST ENHANCED IMPROVEMENTS:")
    best_time_improvement = merged.loc[time_diff.idxmin()]
    best_reduction_improvement = merged.loc[reduction_diff.idxmax()]
    
    print(f"  Biggest time improvement: {best_time_improvement['benchmark_name']} "
          f"({-time_diff.min():.3f}s faster)")
    print(f"  Biggest reduction improvement: {best_reduction_improvement['benchmark_name']} "
          f"({reduction_diff.max():.1f}% better)")
    
    print("="*80)

def main():
    """Main analysis function."""
    
    # Folder paths
    original_folder = "optimized_results/benchmark_specific"
    enhanced_folder = "optimized_results_alternative/benchmark_specific"
    output_folder = "method_comparison_analysis"
    
    print("LTL Optimizer Methods Comparison Analysis")
    print("="*50)
    
    # Check if folders exist
    if not os.path.exists(original_folder):
        print(f"Error: Original results folder not found: {original_folder}")
        return
    
    if not os.path.exists(enhanced_folder):
        print(f"Error: Enhanced results folder not found: {enhanced_folder}")
        return
    
    # Load data from both methods
    print("Loading original method data...")
    original_data = load_method_data(original_folder, "original")
    print(f"Loaded {len(original_data)} benchmarks from original method")
    
    print("Loading enhanced method data...")
    enhanced_data = load_method_data(enhanced_folder, "enhanced")
    print(f"Loaded {len(enhanced_data)} benchmarks from enhanced method")
    
    if len(original_data) == 0 or len(enhanced_data) == 0:
        print("Error: No data loaded from one or both methods!")
        return
    
    # Create output folder
    os.makedirs(output_folder, exist_ok=True)
    
    # Generate comparison plots
    print("\nGenerating comparison plots...")
    create_comparison_plots(original_data, enhanced_data, output_folder)
    
    # Print detailed statistics
    print_detailed_statistics(original_data, enhanced_data)
    
    # Save comparison data to CSV
    merged = pd.merge(original_data, enhanced_data, on='benchmark_name', suffixes=('_original', '_enhanced'))
    merged_path = os.path.join(output_folder, 'detailed_comparison.csv')
    merged.to_csv(merged_path, index=False)
    print(f"\nDetailed comparison data saved to: {merged_path}")
    
    print(f"\nAnalysis complete! Results saved to: {output_folder}")

if __name__ == "__main__":
    main()
