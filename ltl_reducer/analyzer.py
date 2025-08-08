"""
LTL Analysis Orchestrator

This module provides a comprehensive orchestrator class that coordinates all LTL analysis tools
and saves results in an organized folder structure under "analysis_results".
"""

import os
import sys
import shutil
from datetime import datetime
from pathlib import Path
from typing import Dict, List, Optional, Tuple

# Add the analyzers directory to the path
sys.path.append(os.path.join(os.path.dirname(__file__), 'analyzers'))

# Import all analyzers
from ltl_reduction_analyzer import LTLReductionAnalyzer
from ltl_complexity_analyzer import LTLComplexityAnalyzer
from complexity_impact_summary import create_professional_complexity_summary


class LTLAnalysisOrchestrator:
    """
    Comprehensive orchestrator for all LTL analysis tools.
    
    This class coordinates the execution of:
    1. LTL Reduction Analysis
    2. LTL Complexity Analysis  
    3. Complexity Impact Summary
    
    Results are organized in a structured "analysis_results" folder with subfolders
    for each analysis type.
    """
    
    def __init__(self, 
                 base_results_folder: str = "analysis_results",
                 optimized_results_path: str = "optimized_results",
                 show_plots: bool = False):
        """
        Initialize the analysis orchestrator.
        
        Args:
            base_results_folder: Parent folder for all analysis results
            optimized_results_path: Path to the optimized results data
            show_plots: Whether to display plots interactively
        """
        self.base_results_folder = base_results_folder
        self.optimized_results_path = optimized_results_path
        self.show_plots = show_plots
        
        # Create timestamp for this analysis session
        self.timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        
        # Setup folder structure
        self.setup_folder_structure()
        
        # Initialize analyzers with their respective output folders
        self.reduction_analyzer = None
        self.complexity_analyzer = None
        
        print(f" LTL Analysis Orchestrator initialized")
        print(f" Results will be saved to: {self.base_results_folder}")
        print(f" Analysis session: {self.timestamp}")
        
    def setup_folder_structure(self) -> None:
        """Create the organized folder structure for analysis results."""
        
        # Create base results folder
        os.makedirs(self.base_results_folder, exist_ok=True)
        
        # Define subfolders for each analysis type
        self.folders = {
            'reduction_analysis': os.path.join(self.base_results_folder, 'reduction_analysis'),
            'complexity_analysis': os.path.join(self.base_results_folder, 'complexity_analysis'),
            'complexity_impact': os.path.join(self.base_results_folder, 'complexity_impact'),
            'summary_reports': os.path.join(self.base_results_folder, 'summary_reports')
        }
        
        # Create all subfolders
        for folder_name, folder_path in self.folders.items():
            os.makedirs(folder_path, exist_ok=True)
            print(f" Created folder: {folder_path}")
    
    def run_reduction_analysis(self, analysis_type: str = "both") -> Tuple[bool, str]:
        """
        Run the LTL reduction analysis.
        
        Args:
            analysis_type: Type of analysis ("standard", "comprehensive", or "both")
            
        Returns:
            Tuple of (success, message)
        """
        try:
            print(f"\n Starting LTL Reduction Analysis...")
            
            # Initialize reduction analyzer with output to reduction_analysis folder
            self.reduction_analyzer = LTLReductionAnalyzer(
                save_plots=True,
                show_plots=self.show_plots,
                output_folder=self.folders['reduction_analysis'],
                results_file=f"{self.optimized_results_path}/calculated_benchmark_summary.csv"
            )
            
            # Run the analysis based on type
            print(f"   Running comprehensive reduction analysis...")
            self.reduction_analyzer.run_full_analysis(self.optimized_results_path)
            
            print("✅ LTL Reduction Analysis completed successfully!")
            return True, "Reduction analysis completed successfully"
            
        except Exception as e:
            error_msg = f" Error in reduction analysis: {str(e)}"
            print(error_msg)
            return False, error_msg
    
    def run_complexity_analysis(self, benchmark_folder: str = "benchmark_000") -> Tuple[bool, str]:
        """
        Run the LTL complexity analysis.
        
        Args:
            benchmark_folder: Folder containing benchmark models
            
        Returns:
            Tuple of (success, message)
        """
        try:
            print(f"\n Starting LTL Complexity Analysis...")
            # Initialize complexity analyzer with output to complexity_analysis folder
            self.complexity_analyzer = LTLComplexityAnalyzer(
                output_folder=self.folders['complexity_analysis']
            )
            
            # Run complexity analysis
            print(f"   Analyzing complexity metrics for benchmarks in: {benchmark_folder}")
            self.complexity_analyzer.analyze_benchmark_complexity(
                benchmark_folder=benchmark_folder,
                timing_results_folder=self.optimized_results_path
            )
            
            print(" LTL Complexity Analysis completed successfully!")
            return True, "Complexity analysis completed successfully"
            
        except Exception as e:
            error_msg = f" Error in complexity analysis: {str(e)}"
            print(error_msg)
            return False, error_msg
    
    def run_complexity_impact_summary(self,complexity_timing_path = "complexity_timing_analysis/complexity_timing_analysis.csv") -> Tuple[bool, str]:
        """
        Run the complexity impact summary analysis.
        
        Returns:
            Tuple of (success, message)
        """
        try:
            print(f"\nStarting Complexity Impact Summary...")
            
            # Change to the complexity impact folder temporarily
            original_cwd = os.getcwd()
            
            # Check if complexity timing analysis exists
            
            if not os.path.exists(complexity_timing_path):
                print(f"     Warning: {complexity_timing_path} not found. Skipping complexity impact summary.")
                return True, "Complexity impact summary skipped - no timing data available"
            
            # Run the complexity impact summary
            print("   Generating professional complexity impact report...")
            create_professional_complexity_summary()
            
            # Move generated files to our organized folder structure
            source_folder = "complexity_analysis_reports"
            if os.path.exists(source_folder):
                # Copy files to our organized structure
                for file in os.listdir(source_folder):
                    source_path = os.path.join(source_folder, file)
                    dest_path = os.path.join(self.folders['complexity_impact'], file)
                    shutil.copy2(source_path, dest_path)
                    print(f"    Moved {file} to complexity_impact folder")
                
                # Clean up original folder
                shutil.rmtree(source_folder)
            
            print(" Complexity Impact Summary completed successfully!")
            return True, "Complexity impact summary completed successfully"
            
        except Exception as e:
            error_msg = f" Error in complexity impact summary: {str(e)}"
            print(error_msg)
            return False, error_msg
        finally:
            # Ensure we're back in the original directory
            os.chdir(original_cwd)
    
    def generate_master_summary(self, results: Dict[str, Tuple[bool, str]]) -> None:
        """
        Generate a master summary report of all analyses.
        
        Args:
            results: Dictionary of analysis results
        """
        try:
            print(f"\n Generating Master Summary Report...")
            
            summary_file = os.path.join(self.folders['summary_reports'], f'master_analysis_summary_{self.timestamp}.txt')
            
            with open(summary_file, 'w') as f:
                f.write("=" * 80 + "\n")
                f.write("LTL ANALYSIS ORCHESTRATOR - MASTER SUMMARY REPORT\n")
                f.write("=" * 80 + "\n\n")
                
                f.write(f"Analysis Session: {self.timestamp}\n")
                f.write(f"Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
                f.write(f"Base Results Folder: {self.base_results_folder}\n\n")
                
                f.write("ANALYSIS RESULTS OVERVIEW:\n")
                f.write("-" * 40 + "\n")
                
                total_analyses = len(results)
                successful_analyses = sum(1 for success, _ in results.values() if success)
                
                for analysis_name, (success, message) in results.items():
                    status = " SUCCESS" if success else "❌ FAILED"
                    f.write(f"{analysis_name:25s}: {status}\n")
                    if not success:
                        f.write(f"{'':27s}  {message}\n")
                f.write(f"\nSUMMARY: {successful_analyses}/{total_analyses} analyses completed successfully\n\n")
                
                f.write("FOLDER STRUCTURE:\n")
                f.write("-" * 40 + "\n")
                for folder_name, folder_path in self.folders.items():
                    file_count = len([f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f))])
                    f.write(f"{folder_name:20s}: {folder_path} ({file_count} files)\n")
                
                f.write(f"\nDETAILED ANALYSIS DESCRIPTIONS:\n")
                f.write("-" * 40 + "\n")
                f.write("1. Reduction Analysis: LTL formula reduction performance metrics,\n")
                f.write("   timing analysis, outliers detection, and comprehensive visualizations.\n\n")
                f.write("2. Complexity Analysis: Formula complexity metrics including structural,\n")
                f.write("   temporal, and automata-based complexity measurements.\n\n")
                f.write("3. Complexity Impact: Professional analysis of how complexity affects\n")
                f.write("   optimization performance and processing time.\n\n")
                
                f.write("For detailed results, see the respective analysis folders.\n")
                f.write("=" * 80 + "\n")
            
            print(f" Master summary saved to: {summary_file}")
            
        except Exception as e:
            print(f"  Warning: Could not generate master summary: {str(e)}")
    
    def run_complete_analysis(self, 
                            reduction_type: str = "both",
                            benchmark_folder: str = "benchmark_000",
                            complexity_timing_path = "complexity_timing_analysis/complexity_timing_analysis.csv") -> Dict[str, Tuple[bool, str]]:
        """
        Run all analyses in sequence.
        
        Args:
            reduction_type: Type of reduction analysis ("standard", "comprehensive", or "both")
            benchmark_folder: Folder containing benchmark models
            
        Returns:
            Dictionary with results for each analysis
        """
        print("\n" + "=" * 60)
        print(" STARTING COMPLETE LTL ANALYSIS ORCHESTRATION")
        print("=" * 60)
        
        results = {}
        
        # 1. Run reduction analysis
        results['Reduction Analysis'] = self.run_reduction_analysis(reduction_type)
        
        # 2. Run complexity analysis
        results['Complexity Analysis'] = self.run_complexity_analysis(benchmark_folder)
        
        # 3. Run complexity impact summary
        results['Complexity Impact'] = self.run_complexity_impact_summary(complexity_timing_path)
        
        # 4. Generate master summary
        self.generate_master_summary(results)
        
        # Print final summary
        print("\n" + "=" * 60)
        print(" ANALYSIS ORCHESTRATION COMPLETE")
        print("=" * 60)
        
        successful_count = sum(1 for success, _ in results.values() if success)
        total_count = len(results)
        
        print(f" Overall Success Rate: {successful_count}/{total_count} analyses completed")
        print(f" All results saved to: {self.base_results_folder}")
        
        for analysis_name, (success, message) in results.items():
            status = "ok " if success else "not ok"
            print(f"   {status} {analysis_name}")
            
        if successful_count == total_count:
            print("\n All analyses completed successfully!")
        else:
            print(f"\n  {total_count - successful_count} analyses had issues. Check individual error messages above.")
        
        return results
    
    def list_generated_files(self) -> None:
        """Print a comprehensive list of all generated files."""
        print(f"\n GENERATED FILES SUMMARY")
        print("=" * 50)
        
        total_files = 0
        for folder_name, folder_path in self.folders.items():
            if os.path.exists(folder_path):
                files = [f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f))]
                print(f"\n {folder_name.replace('_', ' ').title()}:")
                if files:
                    for file in sorted(files):
                        file_path = os.path.join(folder_path, file)
                        file_size = os.path.getsize(file_path) / 1024  # Size in KB
                        print(f"    {file} ({file_size:.1f} KB)")
                        total_files += 1
                else:
                    print("   (No files generated)")
        
        print(f"\n Total files generated: {total_files}")
