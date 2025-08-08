"""
LTL Reducer - Comprehensive LTL Formula Analysis Suite

This package provides a complete suite of tools for analyzing Linear Temporal Logic (LTL)
formula optimization performance, complexity metrics, and their relationships.

Main Components:
- analyzer.py: LTLAnalysisOrchestrator - coordinates all analyses
- main.py: Command-line interface for running complete analysis suite
- analyzers/: Individual analysis tools

Usage:
    # Run from command line
    python main.py
    
    # Or use programmatically
    from ltl_reducer import LTLAnalysisOrchestrator
    orchestrator = LTLAnalysisOrchestrator()
    results = orchestrator.run_complete_ltl_reduction_analysis()
"""

from .analyzer import LTLAnalysisOrchestrator
from .util import create_new_minimal_folder
__version__ = "1.0.0"
__author__ = "LTL Analysis Suite"
__all__ = ["LTLAnalysisOrchestrator", "create_new_minimal_folder"]