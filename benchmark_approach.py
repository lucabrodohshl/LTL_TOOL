

import spot
from collections import defaultdict
import re
import os
from tqdm import tqdm
import networkx as nx
import matplotlib.pyplot as plt


class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]
    
    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)


def is_refinement(ltl1: str, ltl2: str) -> bool:
    """
    Check if ltl1 refines ltl2 using automata language inclusion without complement/negation.

    Returns True if L(ltl1) ⊆ L(ltl2), False otherwise.
    """
    # Translate LTL to automata (BA)
    aut1 = spot.translate(ltl1, "BA", "high")  # high = optimize for smaller automaton
    aut2 = spot.translate(ltl2, "BA", "high")

    # Check language inclusion: aut1 ⊆ aut2
    # This is done by Spot without explicit complement/negation in user code.
    return aut1.inclusion(aut2)

def extract_atomic_propositions(formulas):
    """
    Extract all unique atomic propositions and build automata for each LTL formula.
    
    Args:
        formulas (List[str]): A list of LTL formulas as strings.
        
    Returns:
        Tuple[Set[str], List[spot.twa_graph]]: 
            - A set of all unique atomic propositions.
            - A list of automata (one for each formula).
    """
    all_props = set()
    all_automata = []
    for formula_str in formulas:
            try:
                formula = spot.formula(formula_str)
                props = spot.atomic_prop_collect(formula)
                all_props.update(props)
                
                automaton = spot.translate(formula)
                automaton.merge_edges()
                automaton = automaton.postprocess()
                all_automata.append(automaton)
            except Exception as e:
                print(f"Error processing formula '{formula_str}': {e}")

    return all_props, all_automata



def construct_automata_equivalence_classes(formulas):
    """
    Implements the AP-based Equivalence Class Construction algorithm,
    returning equivalence classes of automata.
    
    :param formulas: List of LTL formula strings.
    :return: Dict mapping representative index to list of automata in that equivalence class.
    """
    n = len(formulas)
    
    # Extract per-formula atomic propositions and automata
    props_per_formula = []
    automata = []
    
    for formula_str in formulas:
        try:
            formula = spot.formula(formula_str) 
            props = spot.atomic_prop_collect(formula)
            props_per_formula.append(set(props))
            aut = spot.translate(formula, "BA")  # high = optimize for smaller automaton
            aut.merge_edges()
            aut = aut.postprocess()
            automata.append(aut)
        except Exception as e:
            print(f"Error processing formula '{formula_str}': {e}")
            props_per_formula.append(set())
            automata.append(None)

    # Step 1: Populate L
    L = defaultdict(list)  # Map from atomic prop -> list of indices
    UF = DisjointSetUnion(n)

    for i, props in enumerate(props_per_formula):
        for literal in props:
            L[literal].append(i)

    # Step 2: Union formulas sharing atomic propositions
    for indices in L.values():
        for j in range(1, len(indices)):
            UF.union(indices[0], indices[j])

    # Step 3: Group automata by representative
    classes = defaultdict(list)
    for i in range(n):
        rep = UF.find(i)
        if automata[i] is not None:
            classes[rep].append(automata[i])

    return dict(classes)




SRC_FOLDER = "benchmark_000"
benchmark_folder = "anderson.1_000"


for benchmark_folder in tqdm(sorted(os.listdir(SRC_FOLDER))):

    properties_file = os.path.join(SRC_FOLDER, benchmark_folder, "properties.ltl")

    with open(properties_file, 'r') as f:
            lines = f.readlines()
            ltl_formulas = [line.strip() for line in lines if line.strip()]


    equivalence_classes=construct_automata_equivalence_classes(ltl_formulas)


    tot_once = 0
    tot_not_once = 0
    for rep, indices in tqdm(equivalence_classes.items(), position=0, leave=True):
        tot=0
        if len(indices)>1:
            tqdm.write(f"Class led by formula {rep}:{len(indices)}")
            tot_not_once+= tot
        else:
            tot_once+=1
        n = len(indices)
        edges = [set() for _ in range(n)]
        reverse_edges = [set() for _ in range(n)]
        for i in tqdm(range(n), desc=f"Building containment graph for class {rep}", position=1, leave=False):
            aut_i = indices[i]
            for j in range(n):
                if i == j:
                    continue
                aut_j = indices[j]
                #print(aut_j)
                #try:
                if aut_j.contains(aut_i):
                        edges[i].add(j)
                        reverse_edges[j].add(i)
                #except Exception as e:
                #        print(e)
        if False:
            # Visualization with networkx
            G = nx.DiGraph()
            # Use formula strings as node labels
            formula_strings = [ltl_formulas[i] for i in range(n)]
            for idx, formula in enumerate(formula_strings):
                G.add_node(formula)
            for i in range(n):
                for j in edges[i]:
                    G.add_edge(formula_strings[i], formula_strings[j])

            plt.figure(figsize=(12, 8))
            pos = nx.spring_layout(G, seed=42)
            nx.draw(G, pos, with_labels=True, node_size=1500, font_size=8, arrows=True)
            plt.title(f"Containment Graph for Class led by formula {rep}")
            plt.show()

        dominated = set()
        for i in range(n):
            dominated.update(edges[i])
        #tqdm.write(f"Dominated formulas (indices): {dominated}")
        minimal_candidates = [i for i in range(n) if i not in dominated]
        #tqdm.write(f"Minimal candidates (indices): {minimal_candidates}")
        
        
        # Calculate reduction metrics
        total_formulas = len(indices)
        minimal_count = len(minimal_candidates)
        reduction_percentage = ((total_formulas - minimal_count) / total_formulas * 100) if total_formulas > 0 else 0
        
        tqdm.write(f"Reduction: {total_formulas} -> {minimal_count} formulas ({reduction_percentage:.1f}% reduction)")
        tqdm.write("-" * 50)

    # Final summary statistics
    tqdm.write("\n" + "=" * 60)
    tqdm.write("FINAL SUMMARY")
    tqdm.write("=" * 60)
    tqdm.write(f"Total formulas processed: {len(ltl_formulas)}")
    tqdm.write(f"Number of equivalence classes: {len(equivalence_classes)}")
    tqdm.write(f"Classes with single formula: {tot_once}")
    tqdm.write(f"Classes with multiple formulas: {len(equivalence_classes) - tot_once}")
    
    # Calculate overall reduction potential
    total_original = len(ltl_formulas)
    total_after_reduction = tot_once  # Single formulas remain as-is
    
    # Add minimal candidates from multi-formula classes
    for rep, indices in equivalence_classes.items():
        if len(indices) > 1:
            n = len(indices)
            edges = [set() for _ in range(n)]
            for i in range(n):
                aut_i = indices[i]
                for j in range(n):
                    if i != j:
                        aut_j = indices[j]
                        if aut_j.contains(aut_i):
                            edges[i].add(j)
            
            dominated = set()
            for i in range(n):
                dominated.update(edges[i])
            minimal_count = len([i for i in range(n) if i not in dominated])
            total_after_reduction += minimal_count
    
    overall_reduction = ((total_original - total_after_reduction) / total_original * 100) if total_original > 0 else 0
    tqdm.write(f"Overall reduction potential: {total_original} -> {total_after_reduction} formulas ({overall_reduction:.1f}% reduction)")
    tqdm.write("=" * 60)
