"""
Benchmark script for measuring LTL optimization performance.

This script uses the LTLOptimizer library to measure performance
across multiple benchmarks and generate comprehensive reports.
"""

import os
import time
import json
import pandas as pd
from typing import Dict, List
from ltl_optimizer import LTLOptimizer, OptimizationMetrics


def create_performance_report(results: Dict[str, OptimizationMetrics], output_file: str = "performance_report.json"):
    """
    Create a comprehensive performance report from benchmark results.
    
    Args:
        results: Dictionary mapping benchmark names to OptimizationMetrics
        output_file: Output file for the report
    """
    report = {
        "summary": {
            "total_benchmarks": len(results),
            "total_formulas": sum(m.total_formulas for m in results.values()),
            "total_time": sum(m.total_time for m in results.values()),
            "average_reduction": sum(m.reduction_percentage for m in results.values()) / len(results) if results else 0,
            "best_reduction": max((m.reduction_percentage for m in results.values()), default=0),
            "worst_reduction": min((m.reduction_percentage for m in results.values()), default=0),
        },
        "per_benchmark": {name: metrics.to_dict() for name, metrics in results.items()},
        "performance_analysis": {
            "avg_time_per_formula": sum(m.total_time / m.total_formulas for m in results.values() if m.total_formulas > 0) / len(results) if results else 0,
            "avg_equivalence_class_time": sum(m.equivalence_class_time for m in results.values()) / len(results) if results else 0,
            "avg_containment_time": sum(m.containment_analysis_time for m in results.values()) / len(results) if results else 0,
        }
    }
    
    with open(output_file, 'w') as f:
        json.dump(report, f, indent=2)
    
    print(f"Performance report saved to: {output_file}")
    return report


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
    
    # Configuration
    BENCHMARK_FOLDER = "benchmark_000"
    OUTPUT_DIR = "benchmark_results"
    ENABLE_VISUALIZATION = False  # Set to True for visual analysis
    
    # Create output directory
    if not os.path.exists(OUTPUT_DIR):
        os.makedirs(OUTPUT_DIR)
    
    # Initialize optimizer
    optimizer = LTLOptimizer(
        enable_visualization=ENABLE_VISUALIZATION,
        verbose=True
    )
    
    print(f"Starting benchmark analysis on folder: {BENCHMARK_FOLDER}")
    print(f"Results will be saved to: {OUTPUT_DIR}")
    print(f"Visualization enabled: {ENABLE_VISUALIZATION}")
    print("-" * 80)
    
    # Process all benchmarks
    start_time = time.time()
    results = optimizer.process_multiple_benchmarks(
        benchmark_folder=BENCHMARK_FOLDER,
        output_dir=OUTPUT_DIR
    )
    total_time = time.time() - start_time
    
    if not results:
        print("No benchmarks were successfully processed.")
        return
    
    # Generate reports
    print(f"\nProcessing completed in {total_time:.2f} seconds")
    print("Generating reports...")
    
    # Performance report (JSON)
    report = create_performance_report(
        results, 
        os.path.join(OUTPUT_DIR, "performance_report.json")
    )
    
    # CSV summary
    try:
        df = create_csv_summary(
            results, 
            os.path.join(OUTPUT_DIR, "benchmark_summary.csv")
        )
    except ImportError:
        print("pandas not available, skipping CSV summary")
    
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
