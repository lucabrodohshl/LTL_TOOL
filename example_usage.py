"""
Example usage of the LTL Optimizer library.

This script demonstrates how to use the LTLOptimizer class
for single benchmark analysis and basic usage patterns.
"""

from ltl_reducer import LTLOptimizer
import os
import time


def example_single_benchmark():
    """Example: Analyze a single benchmark."""
    
    # Initialize optimizer with visualization enabled for this example
    optimizer = LTLOptimizer(
        enable_visualization=False, 
        verbose=True, 
        save_graphs=True)
    
    # Example: Process a single benchmark folder
    benchmark_path = os.path.join("benchmark_000", "anderson.1_000")
    
    if os.path.exists(benchmark_path):
        print(f"Analyzing benchmark: {benchmark_path}")
        metrics = optimizer.process_benchmark_folder(benchmark_path,
                                                    ltl_output_folder = "minimal_ltl",
                                                    graph_output_folder = "minimal_graph",
                                                    result_folder = "optimized_results",
                                            
                                                    )   
        
        # Access specific metrics
        print(f"\nKey Results:")
        print(f"Reduction achieved: {metrics.reduction_percentage:.1f}%")
        print(f"Processing time: {metrics.total_time:.3f} seconds")
        print(f"Formulas: {metrics.original_formula_count} → {metrics.optimized_formula_count}")
        
        # Save metrics to file
        metrics.save_to_csv("anderson_example_metrics.csv")
        print("Metrics saved to anderson_example_metrics.csv")
    else:
        print(f"Benchmark folder not found: {benchmark_path}")


def example_performance_measurement():
    """Example: Measure performance across different formula set sizes."""
    
    optimizer = LTLOptimizer(enable_visualization=False, verbose=False)
    
    # Test with different sizes
    test_sizes = [10, 50, 100]
    
    print("Performance measurement across different formula set sizes:")
    print("-" * 60)
    
    for size in test_sizes:
        # Generate simple test formulas
        formulas = [f"G(p{i})" for i in range(size // 2)]
        formulas += [f"F(q{i})" for i in range(size // 2)]
        
        start_time = time.time()
        metrics = optimizer.optimize_formulas(formulas, f"test_size_{size}")
        end_time = time.time()
        
        print(f"Size {size:3d}: {end_time - start_time:.4f}s total, "
              f"{(end_time - start_time) / size:.6f}s per formula, "
              f"{metrics.reduction_percentage:.1f}% reduction")


def main():
    
    print("LTL Optimizer Library - Examples")
    print("=" * 50)
    
    # Example 1: Single benchmark
    print("\n1. Single Benchmark Analysis")
    print("-" * 30)
    example_single_benchmark()


if __name__ == "__main__":
    main()
