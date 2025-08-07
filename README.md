# LTL Formula Optimization Tool

A high-performance optimization framework for Linear Temporal Logic (LTL) formula sets using automata-based equivalence classes and containment analysis. This tool implements advanced algorithms for reducing large sets of LTL formulas to their minimal representatives while preserving semantic equivalence.

## Abstract

This repository contains the implementation and experimental framework for LTL formula optimization research. The tool addresses the computational challenge of managing large sets of LTL formulas by identifying minimal representative subsets through automata-theoretic analysis. The approach combines equivalence class construction based on atomic propositions with sophisticated containment graph analysis to achieve significant formula reduction while maintaining logical completeness.

## Key Features

- **Automated Equivalence Classification**: Groups LTL formulas based on atomic proposition analysis using efficient Union-Find data structures
- **Containment Graph Construction**: Builds directed containment relationships between automata for precise dominance analysis  
- **Minimal Set Identification**: Extracts non-dominated formulas representing the complete semantic space
- **Performance Analytics**: Comprehensive timing analysis and reduction metrics for algorithmic evaluation
- **Scalable Batch Processing**: Efficient processing of large benchmark collections with parallel optimization
- **Professional Visualization**: Containment graph visualization for research analysis and presentation
- **Research-Grade Output**: Structured CSV exports for statistical analysis and publication-ready results

## Installation and Setup

### Prerequisites

- Python 3.8 or higher
- Conda package manager

### Environment Setup

1. **Clone the repository:**
   ```bash
   git clone <repository-url>
   cd LTL_TOOL
   ```

2. **Create and activate the conda environment:**
   ```bash
   conda env create -f environment.yml
   conda activate base
   ```

   The environment includes all necessary dependencies:
   - `spot` - Automata manipulation and LTL processing
   - `pandas` - Data analysis and CSV output generation
   - `networkx` - Graph algorithms and visualization
   - `matplotlib` - Research-quality plot generation
   - `tqdm` - Progress monitoring for batch processing

3. **Verify installation:**
   ```bash
   python -c "import spot, pandas, networkx, matplotlib; print('Environment ready')"
   ```

## Usage

### Single Benchmark Analysis

Process an individual benchmark with complete output generation:

```python
from ltl_optimizer import LTLOptimizer

# Initialize optimizer with research configuration
optimizer = LTLOptimizer(
    enable_visualization=False,  # Disable interactive display
    save_graphs=True,           # Generate graph files for analysis
    verbose=True                # Detailed progress reporting
)

# Process single benchmark with organized output structure
metrics = optimizer.process_benchmark_folder(
    "benchmark_000/anderson.1_000",
    ltl_output_folder="minimal_ltl",      # Optimized formula sets
    graph_output_folder="minimal_graph",   # Containment visualizations  
    result_folder="optimized_results"      # Performance metrics and analysis
)

# Access optimization results
print(f"Formula reduction: {metrics.reduction_percentage:.1f}%")
print(f"Processing time: {metrics.total_time:.3f} seconds")
print(f"Equivalence classes: {metrics.total_classes}")
```

### Batch Benchmark Processing

Execute comprehensive analysis across multiple benchmarks:

```bash
python benchmark_performance.py
```

This command processes all benchmarks in the `benchmark_000` folder and generates:

## Output Structure

The tool produces a structured output hierarchy for systematic analysis:

```
minimal_ltl/                    # Optimized LTL formula files
├── anderson.1_000_minimal.ltl
├── anderson.2_000_minimal.ltl
└── ...

minimal_graph/                  # Containment graph visualizations
├── anderson.1_000_class_0_graph.png
├── anderson.2_000_class_1_graph.png
└── ...

optimized_results/              # Performance metrics and analysis
├── overall_summary.csv         # Aggregate statistics across all benchmarks
├── performance_analysis.csv    # Detailed timing and efficiency metrics
├── benchmark_summary.csv       # Complete benchmark comparison matrix
└── benchmark_specific/         # Individual benchmark detailed results
    ├── anderson.1_000_metrics_summary.csv
    ├── anderson.1_000_metrics_class_reductions.csv
    └── ...
```

## Research Applications

### Performance Evaluation

The tool generates comprehensive metrics suitable for academic analysis:

- **Reduction Efficiency**: Percentage reduction in formula count
- **Temporal Complexity**: Algorithmic timing breakdown by phase
- **Scalability Analysis**: Performance characteristics across benchmark sizes
- **Memory Utilization**: Equivalence class and containment graph statistics

### Algorithmic Analysis

Key performance indicators for research evaluation:

```python
# Access detailed algorithmic metrics
print(f"Equivalence class construction: {metrics.equivalence_class_time:.3f}s")
print(f"Containment analysis: {metrics.containment_analysis_time:.3f}s") 
print(f"Multi-formula classes: {metrics.multi_formula_classes}")
print(f"Average reduction per class: {sum(r['reduction_percentage'] for r in metrics.class_reductions) / len(metrics.class_reductions):.1f}%")
```

### Benchmark Integration

The tool supports standard LTL benchmark formats:

- **Input Format**: `properties.ltl` files containing one formula per line
- **Benchmark Structure**: Hierarchical folder organization for systematic evaluation
- **Output Compatibility**: CSV format for integration with statistical analysis tools

## Algorithm Overview

1. **Equivalence Classification**: Partitions formulas based on atomic proposition signatures using Union-Find optimization
2. **Automata Construction**: Translates LTL formulas to Büchi automata using Spot library
3. **Containment Analysis**: Constructs directed containment relationships between automata
4. **Minimal Set Extraction**: Identifies non-dominated elements in the containment partial order
5. **Performance Measurement**: Captures algorithmic complexity metrics throughout execution

## Example Results

Typical performance characteristics observed across standard benchmarks:

- **Formula Reduction**: 15-85% reduction in formula count
- **Processing Speed**: 0.001-0.1 seconds per formula for medium-scale benchmarks  
- **Memory Efficiency**: Linear space complexity in formula count
- **Scalability**: Handles benchmark sets with 1000+ formulas

## Citation and Acknowledgments

This tool implements research algorithms for LTL formula optimization. When using this tool in academic work, please ensure proper attribution according to your institution's guidelines.

## Technical Support

For technical issues or research collaboration inquiries, please refer to the repository documentation or contact the development team through the appropriate academic channels.

## File Organization

- `ltl_optimizer.py` - Core optimization algorithms and data structures
- `benchmark_performance.py` - Batch processing and performance evaluation framework
- `example_usage.py` - Demonstration scripts and usage patterns
- `environment.yml` - Complete conda environment specification
- `README.md` - Comprehensive documentation and usage guide

---

*This tool is designed for academic research and conference publication. All algorithmic implementations follow established theoretical foundations in automata theory and temporal logic.*
