"""
Benchmark script for measuring Enhanced LTL optimization performance.

This script uses the LTLOptimizerAlternative library to measure performance
across multiple benchmarks and generate comprehensive reports including
research-grade subformula analysis, lattice construction, and cross-formula refinement.
"""

import os
import time
import pandas as pd
from typing import Dict, List
from ltl_reducer.ltl_optimizer_alternative import LTLOptimizerAlternative, EnhancedOptimizationMetrics

START_FROM_BENCHMARK = 0
def create_detailed_csv_report(results: Dict[str, EnhancedOptimizationMetrics], result_folder: str):
    """
    Create detailed CSV reports from enhanced benchmark results.
    
    Args:
        results: Dictionary mapping benchmark names to EnhancedOptimizationMetrics
        result_folder: Folder to save detailed CSV reports
    """
    # Overall summary data including enhanced metrics
    summary_data = {
        "total_benchmarks": len(results),
        "total_formulas": sum(m.total_formulas for m in results.values()),
        "total_time": sum(m.total_time for m in results.values()),
        "average_reduction": sum(m.reduction_percentage for m in results.values()) / len(results) if results else 0,
        "average_subformula_coverage_reduction": sum(m.subformula_coverage_reduction for m in results.values()) / len(results) if results else 0,
        "average_syntactic_benefit": sum(m.syntactic_optimization_benefit for m in results.values()) / len(results) if results else 0,
        "best_reduction": max((m.reduction_percentage for m in results.values()), default=0),
        "worst_reduction": min((m.reduction_percentage for m in results.values()), default=0),
        "avg_time_per_formula": sum(m.total_time / m.total_formulas for m in results.values() if m.total_formulas > 0) / len(results) if results else 0,
        "avg_equivalence_class_time": sum(m.equivalence_class_time for m in results.values()) / len(results) if results else 0,
        "avg_containment_time": sum(m.containment_analysis_time for m in results.values()) / len(results) if results else 0,
        "avg_preprocessing_time": sum(m.preprocessing_time for m in results.values()) / len(results) if results else 0,
        "avg_subformula_time": sum(m.subformula_extraction_time for m in results.values()) / len(results) if results else 0,
        "avg_lattice_time": sum(m.lattice_construction_time for m in results.values()) / len(results) if results else 0,
        "avg_refinement_time": sum(m.refinement_analysis_time for m in results.values()) / len(results) if results else 0,
        "total_unique_subformulas": sum(m.unique_subformulas for m in results.values()),
        "avg_formulas_simplified": sum(m.formulas_simplified for m in results.values()) / len(results) if results else 0,
        "total_cross_formula_refinements": sum(m.cross_formula_refinements for m in results.values()),
        "total_syntactic_refinements": sum(m.syntactic_refinements for m in results.values()),
    }
    
    # Save overall summary as CSV
    summary_df = pd.DataFrame([summary_data])
    summary_path = os.path.join(result_folder, "overall_summary.csv")
    summary_df.to_csv(summary_path, index=False)
    print(f"Overall summary saved to: {summary_path}")
    
    # Save performance analysis as CSV with enhanced metrics
    performance_data = []
    for benchmark_name, metrics in results.items():
        performance_data.append({
            "benchmark": benchmark_name,
            "time_per_formula": metrics.total_time / metrics.total_formulas if metrics.total_formulas > 0 else 0,
            "equivalence_class_time": metrics.equivalence_class_time,
            "containment_analysis_time": metrics.containment_analysis_time,
            "preprocessing_time": metrics.preprocessing_time,
            "subformula_extraction_time": metrics.subformula_extraction_time,
            "lattice_construction_time": metrics.lattice_construction_time,
            "refinement_analysis_time": metrics.refinement_analysis_time,
            "total_time": metrics.total_time,
            "core_optimization_time": metrics.equivalence_class_time + metrics.containment_analysis_time,
            "enhancement_overhead": metrics.total_time - (metrics.equivalence_class_time + metrics.containment_analysis_time),
            "reduction_efficiency": metrics.reduction_percentage / metrics.total_time if metrics.total_time > 0 else 0,
            "subformula_efficiency": metrics.subformula_coverage_reduction / metrics.total_time if metrics.total_time > 0 else 0
        })
    
    performance_df = pd.DataFrame(performance_data)
    performance_path = os.path.join(result_folder, "performance_analysis.csv")
    performance_df.to_csv(performance_path, index=False)
    print(f"Performance analysis saved to: {performance_path}")
    
    # Enhanced analysis - subformula and lattice metrics
    enhanced_data = []
    for benchmark_name, metrics in results.items():
        enhanced_data.append({
            "benchmark": benchmark_name,
            "total_subformulas": metrics.total_subformulas,
            "unique_subformulas": metrics.unique_subformulas,
            "avg_subformulas_per_formula": metrics.avg_subformulas_per_formula,
            "lattice_nodes": metrics.lattice_nodes,
            "lattice_edges": metrics.lattice_edges,
            "lattice_levels": metrics.lattice_levels,
            "formulas_simplified": metrics.formulas_simplified,
            "simplification_reduction": metrics.simplification_reduction,
            "cross_formula_refinements": metrics.cross_formula_refinements,
            "syntactic_refinements": metrics.syntactic_refinements,
            "subformula_coverage_reduction": metrics.subformula_coverage_reduction,
            "syntactic_optimization_benefit": metrics.syntactic_optimization_benefit,
            "lattice_complexity": metrics.lattice_edges / metrics.lattice_nodes if metrics.lattice_nodes > 0 else 0
        })
    
    enhanced_df = pd.DataFrame(enhanced_data)
    enhanced_path = os.path.join(result_folder, "enhanced_analysis.csv")
    enhanced_df.to_csv(enhanced_path, index=False)
    print(f"Enhanced research analysis saved to: {enhanced_path}")


def create_csv_summary(results: Dict[str, EnhancedOptimizationMetrics], output_file: str = "benchmark_summary.csv"):
    """
    Create a CSV summary of enhanced benchmark results for easy analysis.
    
    Args:
        results: Dictionary mapping benchmark names to EnhancedOptimizationMetrics
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
            "Subformula_Coverage_Reduction": metrics.subformula_coverage_reduction,
            "Syntactic_Optimization_Benefit": metrics.syntactic_optimization_benefit,
            "Unique_Subformulas": metrics.unique_subformulas,
            "Lattice_Nodes": metrics.lattice_nodes,
            "Lattice_Levels": metrics.lattice_levels,
            "Cross_Formula_Refinements": metrics.cross_formula_refinements,
            "Syntactic_Refinements": metrics.syntactic_refinements,
            "Formulas_Simplified": metrics.formulas_simplified,
            "Simplification_Reduction": metrics.simplification_reduction,
            "Equivalence_Class_Time": metrics.equivalence_class_time,
            "Containment_Analysis_Time": metrics.containment_analysis_time,
            "Preprocessing_Time": metrics.preprocessing_time,
            "Subformula_Extraction_Time": metrics.subformula_extraction_time,
            "Lattice_Construction_Time": metrics.lattice_construction_time,
            "Refinement_Analysis_Time": metrics.refinement_analysis_time,
            "Total_Time": metrics.total_time,
            "Core_Optimization_Time": metrics.equivalence_class_time + metrics.containment_analysis_time,
            "Enhancement_Overhead": metrics.total_time - (metrics.equivalence_class_time + metrics.containment_analysis_time),
            "Time_Per_Formula": metrics.total_time / metrics.total_formulas if metrics.total_formulas > 0 else 0
        })
    
    df = pd.DataFrame(data)
    df.to_csv(output_file, index=False)
    print(f"CSV summary saved to: {output_file}")
    return df


def print_performance_summary(results: Dict[str, EnhancedOptimizationMetrics]):
    """Print a comprehensive performance summary including enhanced features to console."""
    if not results:
        print("No results to summarize.")
        return
    
    total_benchmarks = len(results)
    total_formulas = sum(m.total_formulas for m in results.values())
    total_time = sum(m.total_time for m in results.values())
    avg_reduction = sum(m.reduction_percentage for m in results.values()) / total_benchmarks
    avg_subformula_reduction = sum(m.subformula_coverage_reduction for m in results.values()) / total_benchmarks
    avg_syntactic_benefit = sum(m.syntactic_optimization_benefit for m in results.values()) / total_benchmarks
    
    total_core_time = sum(m.equivalence_class_time + m.containment_analysis_time for m in results.values())
    total_enhancement_overhead = total_time - total_core_time
    
    print("\n" + "=" * 100)
    print("ENHANCED LTL OPTIMIZATION PERFORMANCE SUMMARY")
    print("=" * 100)
    print(f"Benchmarks processed: {total_benchmarks}")
    print(f"Total formulas: {total_formulas}")
    print(f"Total processing time: {total_time:.2f} seconds")
    print(f"Average time per benchmark: {total_time/total_benchmarks:.3f} seconds")
    print(f"Average time per formula: {total_time/total_formulas:.4f} seconds")
    print()
    print("OPTIMIZATION RESULTS:")
    print(f"  Average formula reduction: {avg_reduction:.1f}%")
    print(f"  Average subformula coverage reduction: {avg_subformula_reduction:.1f}%")
    print(f"  Average syntactic optimization benefit: {avg_syntactic_benefit:.1f}%")
    print()
    print("TIMING BREAKDOWN:")
    print(f"  Core optimization time: {total_core_time:.2f}s ({total_core_time/total_time*100:.1f}%)")
    print(f"  Enhancement overhead: {total_enhancement_overhead:.2f}s ({total_enhancement_overhead/total_time*100:.1f}%)")
    print()
    print("RESEARCH FEATURES:")
    total_subformulas = sum(m.total_subformulas for m in results.values())
    unique_subformulas = sum(m.unique_subformulas for m in results.values())
    total_simplified = sum(m.formulas_simplified for m in results.values())
    total_refinements = sum(m.cross_formula_refinements for m in results.values())
    total_syntactic = sum(m.syntactic_refinements for m in results.values())
    
    print(f"  Total subformulas analyzed: {total_subformulas}")
    print(f"  Unique subformulas found: {unique_subformulas}")
    print(f"  Formulas simplified: {total_simplified}")
    print(f"  Cross-formula refinements: {total_refinements}")
    print(f"  Syntactic refinements: {total_syntactic}")
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
    LTL_OUTPUT_FOLDER = "minimal_ltl_alternative"
    GRAPH_OUTPUT_FOLDER = "minimal_graph_alternative"  
    RESULT_FOLDER = "optimized_results_alternative"
    BENCHMARK_SPECIFIC_FOLDER = os.path.join(RESULT_FOLDER, "benchmark_specific")
    
    # Create output directories
    for folder in [LTL_OUTPUT_FOLDER, GRAPH_OUTPUT_FOLDER, RESULT_FOLDER, BENCHMARK_SPECIFIC_FOLDER]:
        if not os.path.exists(folder):
            os.makedirs(folder)
    
    # Initialize enhanced optimizer with all research features enabled but safer settings
    optimizer = LTLOptimizerAlternative(
        enable_visualization=False,     # Don't show graphs during batch processing
        save_graphs=False,              # Don't save graphs to speed up processing
        verbose=True,                  # Show progress
        enable_preprocessing=True,      # Enable formula preprocessing and simplification
        enable_subformula_analysis=True, # Enable comprehensive subformula analysis
        enable_lattice_analysis=False   # Disable lattice analysis temporarily to avoid hanging
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
    
    # Enhanced analysis reporting
    print("\nTop 5 benchmarks by formula reduction percentage:")
    top_reductions = sorted(results.items(), key=lambda x: x[1].reduction_percentage, reverse=True)[:5]
    for i, (name, metrics) in enumerate(top_reductions, 1):
        print(f"{i}. {name}: {metrics.reduction_percentage:.1f}% ({metrics.original_formula_count} -> {metrics.optimized_formula_count} formulas)")
    
    print("\nTop 5 benchmarks by subformula coverage reduction:")
    top_subformula = sorted(results.items(), key=lambda x: x[1].subformula_coverage_reduction, reverse=True)[:5]
    for i, (name, metrics) in enumerate(top_subformula, 1):
        print(f"{i}. {name}: {metrics.subformula_coverage_reduction:.1f}% subformula reduction, {metrics.syntactic_optimization_benefit:.1f}% syntactic benefit")
    
    print("\nTop 5 most complex lattices:")
    top_lattice = sorted(results.items(), key=lambda x: x[1].lattice_nodes, reverse=True)[:5]
    for i, (name, metrics) in enumerate(top_lattice, 1):
        print(f"{i}. {name}: {metrics.lattice_nodes} nodes, {metrics.lattice_edges} edges, {metrics.lattice_levels} levels")
    
    print("\nTop 5 benchmarks with most cross-formula refinements:")
    top_refinements = sorted(results.items(), key=lambda x: x[1].cross_formula_refinements, reverse=True)[:5]
    for i, (name, metrics) in enumerate(top_refinements, 1):
        print(f"{i}. {name}: {metrics.cross_formula_refinements} cross-formula, {metrics.syntactic_refinements} syntactic refinements")
    
    print("\nTop 5 fastest benchmarks (time per formula):")
    fastest = sorted(results.items(), key=lambda x: x[1].total_time / x[1].total_formulas if x[1].total_formulas > 0 else float('inf'))[:5]
    for i, (name, metrics) in enumerate(fastest, 1):
        time_per_formula = metrics.total_time / metrics.total_formulas if metrics.total_formulas > 0 else 0
        core_time = metrics.equivalence_class_time + metrics.containment_analysis_time
        overhead = metrics.total_time - core_time
        print(f"{i}. {name}: {time_per_formula:.4f}s per formula (core: {core_time:.3f}s, overhead: {overhead:.3f}s)")
    
    print("\nBenchmarks with highest enhancement overhead:")
    highest_overhead = sorted(results.items(), key=lambda x: x[1].total_time - (x[1].equivalence_class_time + x[1].containment_analysis_time), reverse=True)[:5]
    for i, (name, metrics) in enumerate(highest_overhead, 1):
        core_time = metrics.equivalence_class_time + metrics.containment_analysis_time
        overhead = metrics.total_time - core_time
        overhead_percent = overhead / metrics.total_time * 100 if metrics.total_time > 0 else 0
        print(f"{i}. {name}: {overhead:.3f}s overhead ({overhead_percent:.1f}% of total time)")
    
    print(f"\n{'='*100}")
    print("Enhanced LTL optimization benchmark completed successfully!")
    print(f"Results saved to: {RESULT_FOLDER}")
    print(f"{'='*100}")


if __name__ == "__main__":
    main()
