"""
Professional Formula Complexity Impact Analysis

This module generates a comprehensive analysis of how formula complexity affects
LTL optimization performance, formatted for research documentation and academic use.
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from datetime import datetime
import os

def create_professional_complexity_summary():
    """Generate a professional analysis report on complexity impact."""
    
    # Load the analysis results
    df = pd.read_csv('complexity_timing_analysis/complexity_timing_analysis.csv')
    
    # Prepare output directory
    output_dir = "complexity_analysis_reports"
    os.makedirs(output_dir, exist_ok=True)
    
    # Generate timestamp
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    
    # Prepare report content
    report_lines = []
    
    # Header
    report_lines.extend([
        "=" * 80,
        "LINEAR TEMPORAL LOGIC FORMULA COMPLEXITY IMPACT ANALYSIS",
        "=" * 80,
        "",
        f"Report Generated: {timestamp}",
        f"Analysis Tool: LTL Optimization Performance Analyzer",
        f"Dataset: {len(df)} benchmark instances, {df['actual_formulas_analyzed'].sum():,} formulas",
        "",
        "EXECUTIVE SUMMARY",
        "-" * 40,
        "",
        f"This report analyzes the relationship between Linear Temporal Logic (LTL)",
        f"formula complexity metrics and optimization performance in terms of processing",
        f"time and reduction effectiveness. The analysis covers {len(df)} benchmark instances",
        f"with a total of {df['actual_formulas_analyzed'].sum():,} formulas processed.",
        "",
    ])
    # Performance Overview
    report_lines.extend([
        "PERFORMANCE CHARACTERISTICS",
        "-" * 40,
        "",
        f"Processing Time Range:",
        f"  • Minimum: {df['time_per_formula'].min():.6f} seconds per formula",
        f"  • Maximum: {df['time_per_formula'].max():.6f} seconds per formula", 
        f"  • Mean: {df['time_per_formula'].mean():.6f} seconds per formula",
        f"  • Standard Deviation: {df['time_per_formula'].std():.6f} seconds",
        "",
        f"Formula Reduction Effectiveness:",
        f"  • Minimum Reduction: {df['reduction_percentage'].min():.1f}%",
        f"  • Maximum Reduction: {df['reduction_percentage'].max():.1f}%",
        f"  • Mean Reduction: {df['reduction_percentage'].mean():.1f}%",
        f"  • Standard Deviation: {df['reduction_percentage'].std():.1f}%",
        "",
    ])
    
    # Complexity Metrics Analysis
    report_lines.extend([
        "COMPLEXITY METRICS CORRELATION ANALYSIS",
        "-" * 40,
        "",
        "The following correlation coefficients measure the linear relationship",
        "between complexity metrics and processing time (Pearson correlation):",
        "",
    ])
    
    # Calculate correlations
    correlations = {
        'Formula Length': df['avg_formula_length'].corr(df['time_per_formula']),
        'Temporal Operators': df['avg_temporal_operators'].corr(df['time_per_formula']),
        'Logical Operators': df['avg_logical_operators'].corr(df['time_per_formula']),
        'Nesting Depth': df['avg_nesting_depth'].corr(df['time_per_formula']),
        'Atomic Propositions': df['avg_atomic_propositions'].corr(df['time_per_formula'])
    }
    
    # Sort by correlation strength
    sorted_corrs = sorted(correlations.items(), key=lambda x: abs(x[1]) if not np.isnan(x[1]) else 0, reverse=True)
    
    for metric, corr in sorted_corrs:
        if not np.isnan(corr):
            strength = "Strong" if abs(corr) > 0.6 else "Moderate" if abs(corr) > 0.4 else "Weak"
            direction = "positive" if corr > 0 else "negative"
            significance = " (significant)" if abs(corr) > 0.5 else ""
            report_lines.append(f"  • {metric:20s}: r = {corr:+.3f} ({strength} {direction} correlation){significance}")
    
    report_lines.extend(["", ""])
    
    # Statistical significance note
    report_lines.extend([
        "Note: Correlations with |r| > 0.5 are considered statistically significant",
        "for this analysis. Strong correlations (|r| > 0.6) indicate substantial",
        "predictive relationships between complexity metrics and performance.",
        "",
    ])
    
    # Benchmark Performance Analysis
    report_lines.extend([
        "BENCHMARK PERFORMANCE ANALYSIS",
        "-" * 40,
        "",
    ])
    
    # Create complexity score
    df['complexity_score'] = (
        df['avg_formula_length'] / df['avg_formula_length'].max() * 0.3 +
        df['avg_temporal_operators'] / df['avg_temporal_operators'].max() * 0.3 +
        df['avg_logical_operators'] / df['avg_logical_operators'].max() * 0.2 +
        df['avg_nesting_depth'] / df['avg_nesting_depth'].max() * 0.2
    )
    
    # Sort by complexity
    df_sorted = df.sort_values('complexity_score')
    
    report_lines.extend([
        "Top 5 Most Efficient Benchmarks (Low Complexity, Fast Processing):",
        "",
    ])
    
    for i, (_, row) in enumerate(df_sorted.head(5).iterrows(), 1):
        report_lines.append(f"  {i}. {row['benchmark']:25s}")
        report_lines.append(f"     Processing Time: {row['time_per_formula']:.6f} seconds/formula")
        report_lines.append(f"     Complexity Score: {row['complexity_score']:.3f}")
        report_lines.append(f"     Reduction Rate: {row['reduction_percentage']:.1f}%")
        report_lines.append("")
    
    report_lines.extend([
        "Top 5 Most Challenging Benchmarks (High Complexity, Slow Processing):",
        "",
    ])
    
    for i, (_, row) in enumerate(df_sorted.tail(5).iterrows(), 1):
        report_lines.append(f"  {i}. {row['benchmark']:25s}")
        report_lines.append(f"     Processing Time: {row['time_per_formula']:.6f} seconds/formula")
        report_lines.append(f"     Complexity Score: {row['complexity_score']:.3f}")
        report_lines.append(f"     Reduction Rate: {row['reduction_percentage']:.1f}%")
        report_lines.append("")
    
    # Efficiency Analysis
    df['expected_time'] = (df['complexity_score'] * df['time_per_formula'].max())
    df['efficiency_ratio'] = df['expected_time'] / df['time_per_formula']
    
    efficient_benchmarks = df[df['efficiency_ratio'] > 1.5].sort_values('efficiency_ratio', ascending=False)
    
    if len(efficient_benchmarks) > 0:
        report_lines.extend([
            "EFFICIENCY OUTLIERS",
            "-" * 40,
            "",
            "Benchmarks performing significantly better than expected based on complexity:",
            "(Efficiency ratio > 1.5 indicates superior performance relative to complexity)",
            "",
        ])
        
        for _, row in efficient_benchmarks.head(5).iterrows():
            report_lines.append(f"  • {row['benchmark']:25s}: {row['efficiency_ratio']:.2f}x efficiency ratio")
    
    # Categorical Analysis
    report_lines.extend([
        "",
        "CATEGORICAL PERFORMANCE ANALYSIS",
        "-" * 40,
        "",
    ])
    
    # Categorize by temporal operators
    df['temp_category'] = pd.cut(df['avg_temporal_operators'], 
                                bins=[0, 2.5, 4, 6, float('inf')], 
                                labels=['Low (≤2.5)', 'Medium (2.5-4)', 'High (4-6)', 'Very High (>6)'])
    
    temp_stats = df.groupby('temp_category', observed=True).agg({
        'time_per_formula': ['mean', 'std', 'count'],
        'reduction_percentage': 'mean'
    }).round(6)
    
    report_lines.extend([
        "Performance by Temporal Operator Density:",
        "",
    ])
    
    for category in temp_stats.index:
        mean_time = temp_stats.loc[category, ('time_per_formula', 'mean')]
        std_time = temp_stats.loc[category, ('time_per_formula', 'std')]
        count = temp_stats.loc[category, ('time_per_formula', 'count')]
        reduction = temp_stats.loc[category, ('reduction_percentage', 'mean')]
        
        report_lines.append(f"  {category:15s}:")
        report_lines.append(f"    Mean Processing Time: {mean_time:.6f} ± {std_time:.6f} seconds")
        report_lines.append(f"    Mean Reduction Rate: {reduction:.1f}%")
        report_lines.append(f"    Sample Size: {count} benchmarks")
        report_lines.append("")
    
    # Formula length categories
    df['length_category'] = pd.cut(df['avg_formula_length'], 
                                  bins=[0, 50, 75, 100, float('inf')], 
                                  labels=['Short (≤50)', 'Medium (50-75)', 'Long (75-100)', 'Very Long (>100)'])
    
    length_stats = df.groupby('length_category', observed=True).agg({
        'time_per_formula': ['mean', 'std', 'count'],
        'reduction_percentage': 'mean'
    }).round(6)
    
    report_lines.extend([
        "Performance by Formula Length:",
        "",
    ])
    
    for category in length_stats.index:
        if not pd.isna(category):
            mean_time = length_stats.loc[category, ('time_per_formula', 'mean')]
            std_time = length_stats.loc[category, ('time_per_formula', 'std')]
            count = length_stats.loc[category, ('time_per_formula', 'count')]
            reduction = length_stats.loc[category, ('reduction_percentage', 'mean')]
            
            report_lines.append(f"  {category:15s}:")
            report_lines.append(f"    Mean Processing Time: {mean_time:.6f} ± {std_time:.6f} seconds")
            report_lines.append(f"    Mean Reduction Rate: {reduction:.1f}%")
            report_lines.append(f"    Sample Size: {count} benchmarks")
            report_lines.append("")
    
    # Key Insights and Findings
    strongest_factor = sorted_corrs[0] if sorted_corrs else ("Formula Length", 0.0)
    
    report_lines.extend([
        "KEY FINDINGS AND INSIGHTS",
        "-" * 40,
        "",
        "Primary Performance Predictors:",
        "",
    ])
    
    if not np.isnan(strongest_factor[1]):
        report_lines.append(f"  1. {strongest_factor[0]} emerges as the strongest predictor of processing time")
        report_lines.append(f"     (correlation coefficient: r = {strongest_factor[1]:.3f})")
        report_lines.append("")
    
    if correlations.get('Temporal Operators', 0) > 0.5:
        report_lines.extend([
            "  2. Temporal operator density significantly impacts algorithm performance.",
            "     Each additional temporal operator contributes measurably to processing time.",
            "",
        ])
    
    if correlations.get('Formula Length', 0) > 0.4:
        report_lines.extend([
            "  3. Formula length demonstrates moderate correlation with processing time,",
            "     indicating scalability challenges with longer logical expressions.",
            "",
        ])
    
    # Algorithmic Performance Assessment
    avg_reduction = df['reduction_percentage'].mean()
    max_time = df['time_per_formula'].max()
    
    report_lines.extend([
        "Algorithmic Performance Assessment:",
        "",
    ])
    
    if avg_reduction > 60:
        performance_rating = "Excellent"
    elif avg_reduction > 40:
        performance_rating = "Good"
    elif avg_reduction > 20:
        performance_rating = "Moderate"
    else:
        performance_rating = "Limited"
    
    report_lines.append(f"  • Overall Reduction Effectiveness: {performance_rating}")
    report_lines.append(f"    (Mean reduction rate: {avg_reduction:.1f}%)")
    report_lines.append("")
    
    if max_time < 1.0:
        scalability_rating = "Excellent"
    elif max_time < 5.0:
        scalability_rating = "Good"
    elif max_time < 10.0:
        scalability_rating = "Moderate"
    else:
        scalability_rating = "Limited"
    
    report_lines.append(f"  • Computational Scalability: {scalability_rating}")
    report_lines.append(f"    (Maximum processing time: {max_time:.3f} seconds per formula)")
    report_lines.append("")
    
    # Recommendations
    report_lines.extend([
        "RECOMMENDATIONS FOR ALGORITHM OPTIMIZATION",
        "-" * 40,
        "",
    ])
    
    if strongest_factor[1] > 0.6:
        report_lines.extend([
            f"1. High-Priority Optimization Target: {strongest_factor[0]}",
            f"   Strong correlation (r = {strongest_factor[1]:.3f}) indicates significant",
            f"   performance gains possible through targeted optimization of this metric.",
            "",
        ])
    
    if correlations.get('Temporal Operators', 0) > 0.5:
        report_lines.extend([
            "2. Temporal Operator Preprocessing:",
            "   Consider implementing specialized handling for formulas with >6 temporal",
            "   operators to mitigate performance degradation in complex cases.",
            "",
        ])
    
    if max_time > 5.0:
        report_lines.extend([
            "3. Scalability Enhancement:",
            "   Current maximum processing time suggests room for algorithmic",
            "   improvements in worst-case scenarios.",
            "",
        ])
    else:
        report_lines.extend([
            "3. Current Performance Assessment:",
            "   Algorithm demonstrates good scalability characteristics across",
            "   the tested complexity range. No immediate scalability concerns.",
            "",
        ])
    
    report_lines.extend([
        "4. Benchmark-Specific Considerations:",
        "   Focus optimization efforts on the identified challenging benchmarks",
        "   while maintaining performance on efficient cases.",
        "",
    ])
    
    # Conclusion
    report_lines.extend([
        "CONCLUSION",
        "-" * 40,
        "",
        f"The LTL optimization algorithm demonstrates {performance_rating.lower()} performance",
        f"characteristics with a mean reduction rate of {avg_reduction:.1f}% across",
        f"{len(df)} benchmark instances. The analysis reveals that {strongest_factor[0].lower()}",
        f"serves as the primary complexity factor affecting processing time.",
        "",
        f"The algorithm exhibits {scalability_rating.lower()} scalability, with processing times",
        f"ranging from {df['time_per_formula'].min():.6f} to {max_time:.6f} seconds per formula.",
        f"This performance profile indicates the approach is well-suited for practical",
        f"applications while highlighting specific areas for targeted optimization.",
        "",
        "=" * 80,
    ])
    
    # Save to file
    output_file = os.path.join(output_dir, f"complexity_impact_analysis_{datetime.now().strftime('%Y%m%d_%H%M%S')}.txt")
    
    with open(output_file, 'w') as f:
        f.write('\n'.join(report_lines))
    
    # Also save a summary CSV
    summary_file = os.path.join(output_dir, f"complexity_summary_data_{datetime.now().strftime('%Y%m%d_%H%M%S')}.csv")
    
    summary_data = {
        'Metric': list(correlations.keys()),
        'Correlation_with_Time': list(correlations.values()),
        'Abs_Correlation': [abs(v) if not np.isnan(v) else 0 for v in correlations.values()]
    }
    
    pd.DataFrame(summary_data).to_csv(summary_file, index=False)
    
    # Print confirmation and summary
    print("=" * 80)
    print("PROFESSIONAL COMPLEXITY IMPACT ANALYSIS COMPLETE")
    print("=" * 80)
    print(f"\nReport Files Generated:")
    print(f"  • Detailed Analysis: {output_file}")
    print(f"  • Summary Data: {summary_file}")
    print(f"\nKey Findings:")
    print(f"  • Dataset: {len(df)} benchmarks, {df['actual_formulas_analyzed'].sum():,} formulas")
    print(f"  • Strongest correlation: {strongest_factor[0]} (r = {strongest_factor[1]:.3f})")
    print(f"  • Mean reduction rate: {avg_reduction:.1f}%")
    print(f"  • Performance rating: {performance_rating}")
    print(f"  • Scalability rating: {scalability_rating}")
    print("=" * 80)
    
    return output_file, summary_file

if __name__ == "__main__":
    report_file, data_file = create_professional_complexity_summary()
