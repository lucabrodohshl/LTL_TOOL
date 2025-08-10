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

import analysis_config

# Add ltl_reducer to path for imports
sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ltl_reducer'))

from ltl_reducer.analyzer import LTLAnalysisOrchestrator
from ltl_reducer import ComparativeAnalyzer, BreakEvenAnalyzer, create_summary_insights





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

    parser.add_argument(
        '--skip-mc_analysis',
        action='store_true',
        help='Skip model checking analysis'
    )

    
    parser.add_argument(
        '--skip-comparative',
        action='store_true',
        help='Skip comparative analysis'
    )
    parser.add_argument(
        '--skip-break-even',
        action='store_true',
        help='Skip break-even analysis'
    )



    return parser.parse_args()


def validate_inputs(args):
    """Validate input arguments and paths."""
    errors = []
    
    # Check if benchmark folder exists
    if not args.skip_complexity and not os.path.exists(analysis_config.BENCHMARK_FOLDER):
        errors.append(f"Benchmark folder not found: {analysis_config.BENCHMARK_FOLDER}")

    # Check if optimized results folder exists
    if not os.path.exists(analysis_config.OPTIMIZED_RESULTS_FOLDER):
        errors.append(f"Optimized results folder not found: {analysis_config.OPTIMIZED_RESULTS_FOLDER}")

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



def comparative_analysis():
    """Main execution function."""
    

    
    # Initialize analyzer
    analyzer = ComparativeAnalyzer(
        save_plots=analysis_config.SAVE_PLOTS,
        show_plots=analysis_config.SHOW_PLOTS,
        output_folder=os.path.join(analysis_config.RESULTS_FOLDER,
            analysis_config.OUTPUT_FOLDER
        )
    )
    
    # Check if required files exist
    if not os.path.exists(analysis_config.BASELINE_FILE):
        print(f"Error: Baseline file '{analysis_config.BASELINE_FILE}' not found.")
        return

    if not os.path.exists(analysis_config.OPTIMIZED_FILE):
        print(f"Error: Optimized file '{analysis_config.OPTIMIZED_FILE}' not found.")
        return

    if not os.path.exists(analysis_config.BENCHMARK_SPECIFIC_FOLDER):
        print(f"Error: Benchmark specific folder '{analysis_config.BENCHMARK_SPECIFIC_FOLDER}' not found.")
        return
    
    # Run complete analysis
    analyzer.run_complete_analysis(
        baseline_file=analysis_config.BASELINE_FILE,
        optimized_file=analysis_config.OPTIMIZED_FILE,
        benchmark_specific_folder=analysis_config.BENCHMARK_SPECIFIC_FOLDER
    )




def break_even_analysis():
    """Main execution function."""
    
    analyzer = BreakEvenAnalyzer(
        save_plots=analysis_config.SAVE_PLOTS,
        show_plots=analysis_config.SHOW_PLOTS,
        output_folder=os.path.join(analysis_config.RESULTS_FOLDER,
            analysis_config.OUTPUT_FOLDER
        )
    )
    
    # Check if required files exist
    required_files = [
        analysis_config.BASELINE_FILE, 
        analysis_config.OPTIMIZED_FILE,
        analysis_config.BENCHMARK_SPECIFIC_FOLDER
    ]
    for file_path in required_files:
        if not os.path.exists(file_path):
            print(f"Error: Required file/folder '{file_path}' not found.")
            return
    
    # Run break-even analysis
    analyzer.run_break_even_analysis(
        baseline_file=analysis_config.BASELINE_FILE,
        optimized_file=analysis_config.OPTIMIZED_FILE,
        benchmark_specific_folder=analysis_config.BENCHMARK_SPECIFIC_FOLDER,
        calculated_summary_file=analysis_config.CALCULATED_SUMMARY_FILE
    )







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
        base_results_folder=analysis_config.RESULTS_FOLDER,
        optimized_results_path=analysis_config.OPTIMIZED_RESULTS_FOLDER,
        show_plots=analysis_config.SHOW_PLOTS,
    )
    
    # Run individual analyses or complete suite
    if args.skip_reduction and args.skip_complexity and args.skip_impact and args.skip_mc_analysis and args.skip_comparative:
        print(" Error: All analyses are skipped. Nothing to do.")
        sys.exit(1)
    
    results = {}
    
    # Run individual analyses if not skipped
    if not args.skip_reduction:
        results['Reduction Analysis'] = orchestrator.run_reduction_analysis(args.reduction_type)
    
    if not args.skip_complexity:
        results['Complexity Analysis'] = orchestrator.run_complexity_analysis(analysis_config.BENCHMARK_FOLDER)
    
    if not args.skip_impact:
        print(" Warning: Complexity impact is a to-do.")

        #results['Complexity Impact'] = orchestrator.run_complexity_impact_summary()
    
    if not args.skip_mc_analysis:
        results['Model Checking Analysis'] = orchestrator.run_model_checking_analysis(
            model_checking_path=analysis_config.OPTIMIZED_FILE
            )
    
    if not args.skip_comparative:
        print(" Running comparative analysis...")
        comparative_analysis()
    if not args.skip_break_even:
        print(" Running break-even analysis...")
        break_even_analysis()
    
    if not args.skip_comparative and not args.skip_break_even:
        # Create summary insights if both analyses were run
        print(" Creating summary insights...")
        create_summary_insights(
            break_even_data_file=os.path.join(
                analysis_config.RESULTS_FOLDER,
                analysis_config.OUTPUT_FOLDER,
                'break_even_detailed_data.csv'),
            output_folder=os.path.join(analysis_config.RESULTS_FOLDER,
                                        analysis_config.OUTPUT_FOLDER)
        )
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
        
        print(f"\n All results saved to: {analysis_config.RESULTS_FOLDER}")
        
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
