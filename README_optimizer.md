# LTL Formula Optimizer Library

A professional Python library for optimizing Linear Temporal Logic (LTL) formula sets using automata-based equivalence classes and containment analysis.

## Features

- **Automated Formula Grouping**: Groups formulas into equivalence classes based on atomic propositions
- **Containment Analysis**: Builds containment graphs to identify minimal representative formulas
- **Performance Measurement**: Comprehensive timing and reduction metrics
- **Batch Processing**: Process multiple benchmark folders efficiently
- **Visualization Support**: Optional NetworkX-based containment graph visualization
- **Professional API**: Clean, documented interface suitable for research and production use

## Installation

### Requirements

```bash
pip install spot-dl tqdm networkx matplotlib pandas
```

### Files

- `ltl_optimizer.py` - Main library with `LTLOptimizer` class
- `benchmark_performance.py` - Batch benchmark processing script
- `example_usage.py` - Usage examples and demonstrations

## Quick Start

### Basic Usage

```python
from ltl_optimizer import LTLOptimizer

# Initialize optimizer
optimizer = LTLOptimizer(enable_visualization=False, verbose=True)

# Analyze custom formulas
formulas = ["G(a)", "F(b)", "G(a) & X(a)", "F(b) | G(c)"]
metrics = optimizer.optimize_formulas(formulas, "my_benchmark")

print(f"Reduction: {metrics.reduction_percentage:.1f}%")
print(f"Time: {metrics.total_time:.3f} seconds")
```

### Process Single Benchmark

```python
# Process a benchmark folder containing properties.ltl
metrics = optimizer.process_benchmark_folder("benchmark_000/anderson.1_000")
metrics.save_to_json("results.json")
```

### Batch Processing

```python
# Process all benchmarks in a folder
results = optimizer.process_multiple_benchmarks(
    benchmark_folder="benchmark_000",
    output_dir="results/"
)
```

## API Reference

### LTLOptimizer Class

#### Constructor

```python
LTLOptimizer(enable_visualization=False, verbose=True)
```

- `enable_visualization`: Enable NetworkX graph visualizations
- `verbose`: Show progress bars and detailed output

#### Methods

**`optimize_formulas(formulas, benchmark_name)`**
- Optimize a list of LTL formula strings
- Returns `OptimizationMetrics` object

**`process_benchmark_folder(benchmark_path)`**
- Process a folder containing `properties.ltl` file
- Returns `OptimizationMetrics` object

**`process_multiple_benchmarks(benchmark_folder, output_dir=None)`**
- Process multiple benchmark folders
- Returns dictionary mapping benchmark names to metrics

### OptimizationMetrics Class

Contains comprehensive optimization results:

```python
@dataclass
class OptimizationMetrics:
    total_formulas: int
    total_classes: int
    single_formula_classes: int
    multi_formula_classes: int
    
    equivalence_class_time: float
    containment_analysis_time: float
    total_time: float
    
    original_formula_count: int
    optimized_formula_count: int
    reduction_percentage: float
    
    class_reductions: List[Dict[str, Any]]
```

**Methods:**
- `to_dict()`: Convert to dictionary
- `save_to_json(filepath)`: Save metrics to JSON file

## Running Benchmarks

### Full Benchmark Suite

```bash
python benchmark_performance.py
```

This will:
1. Process all benchmarks in `benchmark_000/` folder
2. Generate individual JSON results for each benchmark
3. Create comprehensive performance report
4. Generate CSV summary for analysis
5. Print detailed console summary

### Custom Configuration

Edit `benchmark_performance.py` to modify:

```python
BENCHMARK_FOLDER = "your_benchmark_folder"
OUTPUT_DIR = "your_results_folder"
ENABLE_VISUALIZATION = True  # For visual analysis
```

## Output Files

### Individual Benchmark Results
- `{benchmark_name}_metrics.json` - Detailed metrics for each benchmark

### Summary Reports
- `performance_report.json` - Comprehensive analysis report
- `benchmark_summary.csv` - Tabular summary for spreadsheet analysis

### Example Output Structure

```
benchmark_results/
├── anderson.1_000_metrics.json
├── anderson.2_000_metrics.json
├── ...
├── performance_report.json
└── benchmark_summary.csv
```

## Example Results

```
OPTIMIZATION SUMMARY
============================================================
Total formulas processed: 156
Number of equivalence classes: 45
Classes with single formula: 23
Classes with multiple formulas: 22

Performance:
  Equivalence class construction: 0.123s
  Containment analysis: 2.456s
  Total time: 2.579s

Optimization Results:
  Original formulas: 156
  Optimized formulas: 89
  Reduction: 43.0%
============================================================
```

## Advanced Usage

### Custom Analysis

```python
# Access detailed per-class information
for class_info in metrics.class_reductions:
    print(f"Class {class_info['representative']}: "
          f"{class_info['original_count']} → {class_info['minimal_count']} "
          f"({class_info['reduction_percentage']:.1f}% reduction)")
```

### Performance Profiling

```python
# Measure different phases
print(f"Equivalence classes: {metrics.equivalence_class_time:.3f}s")
print(f"Containment analysis: {metrics.containment_analysis_time:.3f}s")
print(f"Time per formula: {metrics.total_time / metrics.total_formulas:.6f}s")
```

### Visualization

```python
# Enable visualization for detailed analysis
optimizer = LTLOptimizer(enable_visualization=True)
# Will show NetworkX graphs for each multi-formula equivalence class
```

## Algorithm Overview

1. **Equivalence Class Construction**: Groups formulas sharing atomic propositions
2. **Automata Translation**: Converts LTL formulas to Büchi automata using Spot
3. **Containment Graph Building**: Constructs directed graph where edges represent language inclusion
4. **Minimal Set Identification**: Finds non-dominated nodes as minimal representatives

## Performance Characteristics

- **Time Complexity**: O(n²) for containment checking within each equivalence class
- **Memory Usage**: Proportional to number of automata and their sizes
- **Scalability**: Efficient for typical benchmark sizes (10-1000 formulas per class)

## Troubleshooting

### Common Issues

1. **Import Error for `spot`**: Install with `pip install spot-dl`
2. **Memory Issues**: Reduce batch size or disable visualization for large benchmarks
3. **File Not Found**: Ensure benchmark folders contain `properties.ltl` files

### Debug Mode

```python
optimizer = LTLOptimizer(verbose=True)
# Shows detailed progress and error messages
```

## Contributing

The library is designed for research use. Key extension points:

- **Custom Equivalence Relations**: Modify `_construct_equivalence_classes()`
- **Alternative Containment Checks**: Extend `_build_containment_graph()`
- **Additional Metrics**: Extend `OptimizationMetrics` class
- **Visualization Options**: Customize `_visualize_containment_graph()`

## License

This library is part of the LTL_TOOL research project.
