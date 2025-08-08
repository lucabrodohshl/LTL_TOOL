#!/usr/bin/env python3
"""
LTL Analysis Suite - Main Entry Point

This script coordinates all LTL analysis tools through a comprehensive orchestrator.
It runs reduction analysis, complexity analysis, and complexity impact summaries,
organizing all results in a structured "analysis_results" folder.

Usage:
    python main.py                    # Run all analyses with default settings
    python main.py --reduction-type comprehensive   # Run only comprehensive reduction analysis
    python main.py --show-plots      # Display plots interactively
    python main.py --help           # Show help message
"""

import argparse
import sys
import os
from pathlib import Path

# Add ltl_reducer to path for imports
sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ltl_reducer'))

from ltl_reducer.analyzer import LTLAnalysisOrchestrator


def parse_arguments():
    """Parse command line arguments."""
    parser = argparse.ArgumentParser(
        description="LTL Analysis Suite - Comprehensive analysis of LTL formula optimization",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
    python main.py                                    # Run all analyses
    python main.py --reduction-type comprehensive    # Only comprehensive reduction analysis
    python main.py --benchmark-folder my_models      # Use different benchmark folder
    python main.py --show-plots                      # Display plots interactively
    python main.py --results-folder my_results       # Use different results folder
        """
    )
    
    parser.add_argument(
        '--reduction-type',
        choices=['standard', 'comprehensive', 'both'],
        default='both',
        help='Type of reduction analysis to run (default: both)'
    )
    
    parser.add_argument(
        '--benchmark-folder',
        default='benchmark_000',
        help='Folder containing benchmark models (default: benchmark_000)'
    )
    
    parser.add_argument(
        '--results-folder',
        default='analysis_results',
        help='Base folder for analysis results (default: analysis_results)'
    )
    
    parser.add_argument(
        '--optimized-results',
        default='optimized_results',
        help='Path to optimized results data (default: optimized_results)'
    )
    
    parser.add_argument(
        '--show-plots',
        action='store_true',
        help='Display plots interactively (default: False, only save plots)'
    )
    
    parser.add_argument(
        '--skip-reduction',
        action='store_true',
        help='Skip reduction analysis'
    )
    
    parser.add_argument(
        '--skip-complexity',
        action='store_true',
        help='Skip complexity analysis'
    )
    
    parser.add_argument(
        '--skip-impact',
        action='store_true',
        help='Skip complexity impact summary'
    )
    
    parser.add_argument(
        '--list-files',
        action='store_true',
        help='List all generated files after analysis'
    )
    
    return parser.parse_args()


def validate_inputs(args):
    """Validate input arguments and paths."""
    errors = []
    
    # Check if benchmark folder exists
    if not args.skip_complexity and not os.path.exists(args.benchmark_folder):
        errors.append(f"Benchmark folder not found: {args.benchmark_folder}")
    
    # Check if optimized results folder exists
    if not os.path.exists(args.optimized_results):
        errors.append(f"Optimized results folder not found: {args.optimized_results}")
    
    # Check if required files exist for complexity impact
    if not args.skip_impact:
        complexity_timing_path = "complexity_timing_analysis/complexity_timing_analysis.csv"
        if not os.path.exists(complexity_timing_path):
            print(f"  Warning: {complexity_timing_path} not found. Complexity impact will be skipped.")
    
    if errors:
        print(" Validation errors:")
        for error in errors:
            print(f"   - {error}")
        return False
    
    return True


def print_banner():
    """Print application banner."""
    print("=" * 70)
    print(" LTL ANALYSIS SUITE")
    print("=" * 70)
    print("Comprehensive Linear Temporal Logic Formula Analysis Framework")
    print()
    print("Components:")
    print("   Reduction Analysis    - Performance metrics and optimization analysis")
    print("   Complexity Analysis   - Formula complexity and structural metrics")
    print("   Impact Summary        - Complexity vs performance relationships")
    print("=" * 70)


def main():
    """Main entry point for the LTL analysis suite."""
    
    # Parse arguments
    args = parse_arguments()
    
    # Print banner
    print_banner()
    
    # Validate inputs
    if not validate_inputs(args):
        sys.exit(1)
    
    # Initialize orchestrator
    print(f"\n Initializing LTL Analysis Orchestrator...")
    orchestrator = LTLAnalysisOrchestrator(
        base_results_folder=args.results_folder,
        optimized_results_path=args.optimized_results,
        show_plots=args.show_plots
    )
    
    # Run individual analyses or complete suite
    if args.skip_reduction and args.skip_complexity and args.skip_impact:
        print(" Error: All analyses are skipped. Nothing to do.")
        sys.exit(1)
    
    results = {}
    
    # Run individual analyses if not skipped
    if not args.skip_reduction:
        results['Reduction Analysis'] = orchestrator.run_reduction_analysis(args.reduction_type)
    
    if not args.skip_complexity:
        results['Complexity Analysis'] = orchestrator.run_complexity_analysis(args.benchmark_folder)
    
    if not args.skip_impact:
        print(" Warning: Complexity impact is a to-do.")

        #results['Complexity Impact'] = orchestrator.run_complexity_impact_summary()
    
    # Generate master summary if we ran any analyses
    if results:
        orchestrator.generate_master_summary(results)
        
        # Print final results
        print("\n" + "=" * 60)
        print(" ANALYSIS COMPLETE")
        print("=" * 60)
        
        successful_count = sum(1 for success, _ in results.values() if success)
        total_count = len(results)
        
        print(f" Success Rate: {successful_count}/{total_count} analyses completed")
        
        for analysis_name, (success, message) in results.items():
            status = "ok" if success else "not ok"
            print(f"   {status} {analysis_name}")
            if not success:
                print(f"      Error: {message}")
        
        print(f"\n All results saved to: {args.results_folder}")
        
        # List generated files if requested
        if args.list_files:
            orchestrator.list_generated_files()
        
        if successful_count == total_count:
            print("\n All analyses completed successfully!")
            print("\nNext steps:")
            print("   Review the generated plots and reports")
            print("   Check the master summary for detailed insights")
            print("   Explore individual analysis folders for specific metrics")
        else:
            print(f"\n  {total_count - successful_count} analyses had issues.")
            print("Check the error messages above and verify your input data.")
            sys.exit(1)
    
    else:
        print("No analyses were run.")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n\n⏹  Analysis interrupted by user.")
        sys.exit(130)
    except Exception as e:
        print(f"\n Unexpected error: {str(e)}")
        print("Please check your inputs and try again.")
        sys.exit(1)
