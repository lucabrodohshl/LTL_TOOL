"""
Benchmark script for measuring LTL optimization performance.

This script uses the LTLOptimizer library to measure performance
across multiple benchmarks and generate comprehensive reports.
"""

import os
import time
import pandas as pd
from typing import Dict, List
from ltl_reducer import LTLOptimizer, OptimizationMetrics

START_FROM_BENCHMARK = 0
def create_detailed_csv_report(results: Dict[str, OptimizationMetrics], result_folder: str):
    """
    Create detailed CSV reports from benchmark results.
    
    Args:
        results: Dictionary mapping benchmark names to OptimizationMetrics
        result_folder: Folder to save detailed CSV reports
    """
    # Overall summary data
    summary_data = {
        "total_benchmarks": len(results),
        "total_formulas": sum(m.total_formulas for m in results.values()),
        "total_time": sum(m.total_time for m in results.values()),
        "average_reduction": sum(m.reduction_percentage for m in results.values()) / len(results) if results else 0,
        "best_reduction": max((m.reduction_percentage for m in results.values()), default=0),
        "worst_reduction": min((m.reduction_percentage for m in results.values()), default=0),
        "avg_time_per_formula": sum(m.total_time / m.total_formulas for m in results.values() if m.total_formulas > 0) / len(results) if results else 0,
        "avg_equivalence_class_time": sum(m.equivalence_class_time for m in results.values()) / len(results) if results else 0,
        "avg_containment_time": sum(m.containment_analysis_time for m in results.values()) / len(results) if results else 0,
    }
    
    # Save overall summary as CSV
    summary_df = pd.DataFrame([summary_data])
    summary_path = os.path.join(result_folder, "overall_summary.csv")
    summary_df.to_csv(summary_path, index=False)
    print(f"Overall summary saved to: {summary_path}")
    
    # Save performance analysis as CSV
    performance_data = []
    for benchmark_name, metrics in results.items():
        performance_data.append({
            "benchmark": benchmark_name,
            "time_per_formula": metrics.total_time / metrics.total_formulas if metrics.total_formulas > 0 else 0,
            "equivalence_class_time": metrics.equivalence_class_time,
            "containment_analysis_time": metrics.containment_analysis_time,
            "total_time": metrics.total_time,
            "reduction_efficiency": metrics.reduction_percentage / metrics.total_time if metrics.total_time > 0 else 0
        })
    
    performance_df = pd.DataFrame(performance_data)
    performance_path = os.path.join(result_folder, "performance_analysis.csv")
    performance_df.to_csv(performance_path, index=False)
    print(f"Performance analysis saved to: {performance_path}")


def create_csv_summary(results: Dict[str, OptimizationMetrics], output_file: str = "benchmark_summary.csv"):
    """
    Create a CSV summary of benchmark results for easy analysis.
    
    Args:
        results: Dictionary mapping benchmark names to OptimizationMetrics
        output_file: Output CSV file
    """
    data = []
    for benchmark_name, metrics in results.items():
        data.append({
            "Benchmark": benchmark_name,
            "Total_Formulas": metrics.total_formulas,
            "Total_Classes": metrics.total_classes,
            "Single_Formula_Classes": metrics.single_formula_classes,
            "Multi_Formula_Classes": metrics.multi_formula_classes,
            "Original_Count": metrics.original_formula_count,
            "Optimized_Count": metrics.optimized_formula_count,
            "Reduction_Percentage": metrics.reduction_percentage,
            "Equivalence_Class_Time": metrics.equivalence_class_time,
            "Containment_Analysis_Time": metrics.containment_analysis_time,
            "Total_Time": metrics.total_time,
            "Time_Per_Formula": metrics.total_time / metrics.total_formulas if metrics.total_formulas > 0 else 0
        })
    
    df = pd.DataFrame(data)
    df.to_csv(output_file, index=False)
    print(f"CSV summary saved to: {output_file}")
    return df


def print_performance_summary(results: Dict[str, OptimizationMetrics]):
    """Print a concise performance summary to console."""
    if not results:
        print("No results to summarize.")
        return
    
    total_benchmarks = len(results)
    total_formulas = sum(m.total_formulas for m in results.values())
    total_time = sum(m.total_time for m in results.values())
    avg_reduction = sum(m.reduction_percentage for m in results.values()) / total_benchmarks
    
    print("\n" + "=" * 80)
    print("OVERALL PERFORMANCE SUMMARY")
    print("=" * 80)
    print(f"Benchmarks processed: {total_benchmarks}")
    print(f"Total formulas: {total_formulas}")
    print(f"Total processing time: {total_time:.2f} seconds")
    print(f"Average time per benchmark: {total_time/total_benchmarks:.3f} seconds")
    print(f"Average time per formula: {total_time/total_formulas:.4f} seconds")
    print(f"Average reduction: {avg_reduction:.1f}%")
    print()
    
    # Top performers
    best_reduction = max(results.items(), key=lambda x: x[1].reduction_percentage)
    fastest_per_formula = min(results.items(), key=lambda x: x[1].total_time / x[1].total_formulas if x[1].total_formulas > 0 else float('inf'))
    
    print(f"Best reduction: {best_reduction[0]} ({best_reduction[1].reduction_percentage:.1f}%)")
    print(f"Fastest per formula: {fastest_per_formula[0]} ({fastest_per_formula[1].total_time / fastest_per_formula[1].total_formulas:.4f}s/formula)")
    print("=" * 80)


def main():
    """Main benchmark execution function."""
    
    # Configuration - using same folder structure as example_usage.py
    BENCHMARK_FOLDER = "benchmark_000"
    LTL_OUTPUT_FOLDER = "minimal_ltl"
    GRAPH_OUTPUT_FOLDER = "minimal_graph"  
    RESULT_FOLDER = "optimized_results"
    BENCHMARK_SPECIFIC_FOLDER = os.path.join(RESULT_FOLDER, "benchmark_specific")
    
    # Create output directories
    for folder in [LTL_OUTPUT_FOLDER, GRAPH_OUTPUT_FOLDER, RESULT_FOLDER, BENCHMARK_SPECIFIC_FOLDER]:
        if not os.path.exists(folder):
            os.makedirs(folder)
    
    # Initialize optimizer - save graphs but don't visualize
    optimizer = LTLOptimizer(
        enable_visualization=False,  # Don't show graphs
        save_graphs=True,           # Save graphs to files
        verbose=True
    )
    
    print(f"Starting benchmark analysis on folder: {BENCHMARK_FOLDER}")
    print(f"LTL outputs will be saved to: {LTL_OUTPUT_FOLDER}")
    print(f"Graphs will be saved to: {GRAPH_OUTPUT_FOLDER}")
    print(f"Results will be saved to: {RESULT_FOLDER}")
    print("-" * 80)
    
    # Process all benchmarks
    start_time = time.time()
    results = optimizer.process_multiple_benchmarks(
        benchmark_folder=BENCHMARK_FOLDER,
        ltl_output_folder=LTL_OUTPUT_FOLDER,
        graph_output_folder=GRAPH_OUTPUT_FOLDER,
        result_folder=RESULT_FOLDER, 
        start_from=START_FROM_BENCHMARK  
    )
    total_time = time.time() - start_time
    
    if not results:
        print("No benchmarks were successfully processed.")
        return
    
    # Generate reports - all as CSV
    print(f"\nProcessing completed in {total_time:.2f} seconds")
    print("Generating CSV reports...")
    
    # CSV summary
    df = create_csv_summary(
        results, 
        os.path.join(RESULT_FOLDER, "benchmark_summary.csv")
    )
    
    # Create detailed CSV report instead of JSON
    create_detailed_csv_report(results, RESULT_FOLDER)
    
    # Console summary
    print_performance_summary(results)
    
    # Additional analysis
    print("\nTop 5 benchmarks by reduction percentage:")
    top_reductions = sorted(results.items(), key=lambda x: x[1].reduction_percentage, reverse=True)[:5]
    for i, (name, metrics) in enumerate(top_reductions, 1):
        print(f"{i}. {name}: {metrics.reduction_percentage:.1f}% ({metrics.original_formula_count} -> {metrics.optimized_formula_count} formulas)")
    
    print("\nTop 5 fastest benchmarks (time per formula):")
    fastest = sorted(results.items(), key=lambda x: x[1].total_time / x[1].total_formulas if x[1].total_formulas > 0 else float('inf'))[:5]
    for i, (name, metrics) in enumerate(fastest, 1):
        time_per_formula = metrics.total_time / metrics.total_formulas if metrics.total_formulas > 0 else 0
        print(f"{i}. {name}: {time_per_formula:.4f}s per formula ({metrics.total_formulas} formulas)")


if __name__ == "__main__":
    main()
