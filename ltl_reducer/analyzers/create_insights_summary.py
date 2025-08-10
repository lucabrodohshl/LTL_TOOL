"""
Summary visualization of break-even analysis key findings
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

def create_summary_insights(
    break_even_data_file='analysis_results/comparative_analysis/break_even_detailed_data.csv',
    output_folder='analysis_results/comparative_analysis'
):
    """Create a publication-ready summary of key insights."""
    
    # Load the detailed data
    df = pd.read_csv(break_even_data_file)
    
    fig, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2, figsize=(16, 12))
    fig.suptitle('Key Insights: When LTL Optimization Provides Net Benefits', 
                fontsize=16, fontweight='bold')
    
    # 1. Success rate by reduction threshold
    thresholds = [0, 10, 20, 30, 40, 50]
    success_rates = []
    counts = []
    
    for threshold in thresholds:
        above_threshold = df[df['reduction_percentage'] >= threshold]
        if len(above_threshold) > 0:
            beneficial_count = len(above_threshold[above_threshold['net_speedup'] > 1])
            success_rate = beneficial_count / len(above_threshold) * 100
            success_rates.append(success_rate)
            counts.append(f"{beneficial_count}/{len(above_threshold)}")
        else:
            success_rates.append(0)
            counts.append("0/0")
    
    bars = ax1.bar(range(len(thresholds)), success_rates, alpha=0.8, 
                   color=['red' if sr < 80 else 'orange' if sr < 95 else 'green' for sr in success_rates])
    ax1.set_xlabel('Minimum Reduction Percentage (%)')
    ax1.set_ylabel('Success Rate (%)')
    ax1.set_title('Success Rate by Reduction Threshold')
    ax1.set_xticks(range(len(thresholds)))
    ax1.set_xticklabels([f'≥{t}%' for t in thresholds])
    ax1.grid(True, alpha=0.3, axis='y')
    
    # Add count labels
    for bar, count in zip(bars, counts):
        height = bar.get_height()
        ax1.text(bar.get_x() + bar.get_width()/2., height + 1,
                count, ha='center', va='bottom', fontsize=9, fontweight='bold')
    
    # 2. Problem size vs success rate
    size_order = ['Tiny', 'Small', 'Medium', 'Large']
    size_success_rates = []
    size_counts = []
    
    for size in size_order:
        size_data = df[df['size_category'] == size]
        if len(size_data) > 0:
            beneficial_count = len(size_data[size_data['net_speedup'] > 1])
            success_rate = beneficial_count / len(size_data) * 100
            size_success_rates.append(success_rate)
            size_counts.append(f"{beneficial_count}/{len(size_data)}")
        else:
            size_success_rates.append(0)
            size_counts.append("0/0")
    
    colors = ['lightcoral', 'lightblue', 'lightgreen', 'purple']
    bars = ax2.bar(size_order, size_success_rates, alpha=0.8, color=colors)
    ax2.set_xlabel('Problem Size Category')
    ax2.set_ylabel('Success Rate (%)')
    ax2.set_title('Success Rate by Problem Size')
    ax2.grid(True, alpha=0.3, axis='y')
    
    # Add count labels
    for bar, count in zip(bars, size_counts):
        height = bar.get_height()
        ax2.text(bar.get_x() + bar.get_width()/2., height + 1,
                count, ha='center', va='bottom', fontsize=9, fontweight='bold')
    
    # 3. Overhead ratio distribution
    beneficial = df[df['net_speedup'] > 1]
    detrimental = df[df['net_speedup'] <= 1]
    
    bins = np.logspace(-4, 2, 30)  # From 0.01% to 100%
    
    ax3.hist(beneficial['overhead_ratio'] * 100, bins=bins, alpha=0.7, 
            color='green', label=f'Beneficial (n={len(beneficial)})', density=True)
    ax3.hist(detrimental['overhead_ratio'] * 100, bins=bins, alpha=0.7, 
            color='red', label=f'Detrimental (n={len(detrimental)})', density=True)
    
    ax3.axvline(x=beneficial['overhead_ratio'].median() * 100, color='darkgreen', 
               linestyle='--', linewidth=2, label=f'Beneficial median: {beneficial["overhead_ratio"].median()*100:.1f}%')
    ax3.axvline(x=detrimental['overhead_ratio'].median() * 100, color='darkred', 
               linestyle='--', linewidth=2, label=f'Detrimental median: {detrimental["overhead_ratio"].median()*100:.1f}%')
    
    ax3.set_xlabel('Overhead Ratio (%)')
    ax3.set_ylabel('Density')
    ax3.set_title('Overhead Ratio Distribution')
    ax3.set_xscale('log')
    ax3.legend()
    ax3.grid(True, alpha=0.3)
    
    # 4. Key recommendations box
    ax4.axis('off')
    
    # Calculate key statistics
    beneficial_mask = df['net_speedup'] > 1
    
    recommendations = f"""
KEY RECOMMENDATIONS FOR LTL OPTIMIZATION

SUCCESS FACTORS:
✓ Reduction ≥10%: {(df[df['reduction_percentage'] >= 10]['net_speedup'] > 1).mean()*100:.1f}% success rate
✓ Small problems (5-20 props): {(df[df['size_category'] == 'Small']['net_speedup'] > 1).mean()*100:.1f}% success rate
✓ Overhead <10% of baseline: High success probability

AVOID OPTIMIZATION WHEN:
✗ Reduction <10%: Only {(df[df['reduction_percentage'] < 10]['net_speedup'] > 1).mean()*100:.1f}% success rate  
✗ Tiny problems (<5 props): Only {(df[df['size_category'] == 'Tiny']['net_speedup'] > 1).mean()*100:.1f}% success rate
✗ Baseline time <1s: High overhead-to-benefit ratio

OPTIMAL TARGETS:
• Problems with 5-100 properties
• Expected reduction >20%  
• Baseline time >10 seconds
• Complex formulas (high containment analysis benefit)

BREAK-EVEN POINT:
Overhead ratio ≈ Reduction percentage
(e.g., 30% reduction can tolerate 30% overhead)
    """
    
    ax4.text(0.05, 0.95, recommendations, transform=ax4.transAxes, fontsize=11,
            verticalalignment='top', fontfamily='monospace',
            bbox=dict(boxstyle="round,pad=0.5", facecolor="lightblue", alpha=0.8))
    
    plt.tight_layout()
    plt.savefig(
        os.path.join(output_folder,
        'optimization_insights_summary.png'),
        dpi=300, bbox_inches='tight'
    )
    print("Summary insights saved to: comparative_analysis/optimization_insights_summary.png")
    plt.show()

if __name__ == "__main__":
    create_summary_insights()
