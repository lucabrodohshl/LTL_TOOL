"""
Example usage of the LTL Optimizer library.

This script demonstrates how to use the LTLOptimizer class
for single benchmark analysis and basic usage patterns.
"""

from ltl_optimizer import LTLOptimizer
import os
import time


def example_single_benchmark():
    """Example: Analyze a single benchmark."""
    
    # Initialize optimizer with visualization enabled for this example
    optimizer = LTLOptimizer(enable_visualization=False, verbose=True)
    
    # Example: Process a single benchmark folder
    benchmark_path = os.path.join("benchmark_000", "anderson.1_000")
    
    if os.path.exists(benchmark_path):
        print(f"Analyzing benchmark: {benchmark_path}")
        metrics = optimizer.process_benchmark_folder(benchmark_path)
        
        # Access specific metrics
        print(f"\nKey Results:")
        print(f"Reduction achieved: {metrics.reduction_percentage:.1f}%")
        print(f"Processing time: {metrics.total_time:.3f} seconds")
        print(f"Formulas: {metrics.original_formula_count} → {metrics.optimized_formula_count}")
        
        # Save metrics to file
        metrics.save_to_json("anderson_example_metrics.json")
        print("Metrics saved to anderson_example_metrics.json")
    else:
        print(f"Benchmark folder not found: {benchmark_path}")


def example_custom_formulas():
    """Example: Analyze custom LTL formulas."""
    
    # Custom set of LTL formulas
    formulas = [
        "G(a)",
        "F(b)",
        "G(a) & X(a)",
        "F(b) | G(c)",
        "G(a)",  # Duplicate
        "a U b",
        "G(F(a))",
        "F(G(b))"
    ]
    
    print("Analyzing custom formula set:")
    for i, formula in enumerate(formulas):
        print(f"  {i}: {formula}")
    
    optimizer = LTLOptimizer(enable_visualization=False, verbose=True)
    metrics = optimizer.optimize_formulas(formulas, "custom_example")
    
    print(f"\nOptimization completed:")
    print(f"Original: {len(formulas)} formulas")
    print(f"Optimized: {metrics.optimized_formula_count} formulas")
    print(f"Reduction: {metrics.reduction_percentage:.1f}%")


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
    """Run all examples."""
    
    print("LTL Optimizer Library - Examples")
    print("=" * 50)
    
    # Example 1: Single benchmark
    print("\n1. Single Benchmark Analysis")
    print("-" * 30)
    example_single_benchmark()
    
    # Example 2: Custom formulas
    print("\n\n2. Custom Formula Set Analysis")
    print("-" * 30)
    example_custom_formulas()
    
    # Example 3: Performance measurement
    print("\n\n3. Performance Measurement")
    print("-" * 30)
    example_performance_measurement()
    
    print("\n\nAll examples completed!")


if __name__ == "__main__":
    main()
