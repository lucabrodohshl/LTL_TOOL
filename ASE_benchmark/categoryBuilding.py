


import spot
from collections import defaultdict
import re

from tqdm import tqdm

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]
    
    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)


def extract_atomic_propositions(phi):
    """
    Extract atomic propositions from LTL formulas.
    Assumes atomic propositions are lowercase words with optional underscores,
    and excludes LTL operators (e.g., G, F, X, &, |, !).
    
    :param phi: List of LTL formula strings
    :return: List of sets of atomic propositions (strings)
    """
    # LTL keywords and symbols to exclude
    ltl_keywords = {'G', 'F', 'X', 'U', 'W', 'R', 'true', 'false'}
    logical_symbols = {'&', '|', '!', '->', '<->', '(', ')'}

    prop_list = []

    for formula_str in phi:
        # Extract words (with optional underscores) that are entirely lowercase
        tokens = re.findall(r'\b[a-z_][a-z0-9_]*\b', formula_str)
        # Remove any LTL or logic keywords
        aps = {token for token in tokens if token not in ltl_keywords and token not in logical_symbols}
        prop_list.append(aps)

    return prop_list

def construct_equivalence_classes(phi):
    """
    Implements the AP-based Equivalence Class Construction algorithm.
    
    :param phi: List of sets, where each set contains the atomic propositions (APs) of a formula.
    :return: Dict mapping representative index to list of indices in that equivalence class.
    """
    n = len(phi)
    PropList = extract_atomic_propositions(phi)  # [AP_1, ..., AP_n]
    L = defaultdict(list)  # Map from literal -> list of indices
    UF = DisjointSetUnion(n)  # Disjoint-set forest

    # Step 1: Populate L
    for i in range(n):
        for literal in PropList[i]:
            L[literal].append(i)

    # Step 2: Union all formulas sharing a literal
    for literal, indices in L.items():
        for j in range(1, len(indices)):
            UF.union(indices[0], indices[j])

    # Step 3: Group formulas by their representative in UF
    C = defaultdict(list)
    for i in range(n):
        rep = UF.find(i)
        C[rep].append(i)

    return dict(C)


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




def split_by_or(phi):
    formula = spot.negative_normal_form(spot.formula(phi))
    subformulas = set()

    def collect_disjuncts(f):
        if f.kind() == spot.op_Or:
            for i in range(f.size()):
                collect_disjuncts(f[i])
        else:
            subformulas.add(str(f))

    collect_disjuncts(formula)
    return subformulas


def check_inclusions_in_classes(equivalence_classes, phi):
    aut_cache = {}

    def get_aut(formula):
        if formula not in aut_cache:
            aut_cache[formula] = spot.translate(formula, "BA", "high")
        return aut_cache[formula]

    for rep, indices in equivalence_classes.items():
        if len(indices) > 1:
            #print(f"Class led by formula {rep}:")
            #for idx in indices:
            #    print(f"  φ{idx+1}: {phi[idx]}")

            # Check inclusion for all pairs
            for i in range(len(indices)):
                aut_i = get_aut(phi[indices[i]])
                for j in range(i + 1, len(indices)):
                    aut_j = get_aut(phi[indices[j]])

                    incl_ij = aut_i.contains(aut_j)
                    incl_ji = aut_j.contains(aut_i)

                    #print(f"    Inclusion φ{phi[indices[i]]} IN    φ{phi[indices[j]]}? {incl_ij}")
                    #print(f"    Inclusion φ{phi[indices[j]]} IN    φ{phi[indices[i]]}? {incl_ji}")
# equivalence_classes = { "G(a)": [0, 2, 4], "F(b)": [1, 3] }
# phi = ["G(a)", "F(b)", "G(a) & X a", "F(b) | G(c)", "G(a)"]
# check_inclusions_in_classes(equivalence_classes, phi)


def construct_lattices(phi):
    """
    Given an LTL formula string phi,
    return the set of all subformulas (including phi itself).
    """
    formula = spot.negative_normal_form(spot.formula(phi))
    print(f" NNN: {formula}")
    subformulas = set()

    # Traverse the formula and collect each subformula as a string
    formula.traverse(lambda f: subformulas.add(str(f)))

    return subformulas

def get_minimal_subformulas(equivalence_classes, phi):
    aut_cache = {}

    def get_aut(formula):
        if formula not in aut_cache:
            aut_cache[formula] = spot.translate(formula, "BA", "high")
        return aut_cache[formula]

    minimal_per_class = {}

    for rep, indices in tqdm(equivalence_classes.items()):
        #print(rep,indices,len(indices) > 1)
        if len(indices) > 1:
            # Step 1: Flatten all disjuncts and assign a unique index
            flat_disjuncts = []
            idx_map = {}  # maps disjunct index → (formula_idx, subformula_str)
            formula_map = {}
            index_map = {}
            for idx in indices:
                index_map[idx]=[]
                for sub in split_by_or(phi[idx]):
                    idx_map[len(flat_disjuncts)] = (idx, sub)
                    formula_map[sub] = idx
                    index_map[idx] += [sub]
                    
                    flat_disjuncts.append(sub)
            #print(flat_disjuncts)
            #print("formula map",formula_map)
            #print(index_map)
            n = len(flat_disjuncts)
            edges = [set() for _ in range(n)]
            opposite_edges = [set() for _ in range(n)]
            
            # Step 2: Build containment graph
            for i in tqdm(range(n)):
                aut_i = get_aut(flat_disjuncts[i])
                for j in range(n):
                    if i != j:
                        aut_j = get_aut(flat_disjuncts[j])
                        if aut_j.contains(aut_i):
                            edges[i].add(j)
                            opposite_edges[j].add(i)
            
            # Step 3: Identify minimal dominating set
            dominated = set()
            for i in range(n):
                dominated.update(edges[i])
            #print(dominated)
            final_minimal  = []
            minimal = [flat_disjuncts[i] for i in range(n) if i not in dominated]
            #print(minimal)
            for l in index_map.values():
                #print(l)
                if (len(l)==1):
                    if l[0] in minimal:
                        final_minimal +=[l[0]]
                        #print("sinal",final_minimal)
                    continue
                sub_list = []
                candidates = []
                
                for at,sub in enumerate(l):
                    #print(sub)
                    if(sub in minimal):
                        if (len(opposite_edges[flat_disjuncts.index(sub)])==0):
                            if (len(edges[flat_disjuncts.index(sub)])!=0):
                                sub_list.append(sub)
                            else:
                                candidates.append(sub)
                if len(sub_list)==0:
                     if(len(candidates)!=0):
                        sub_list+=[candidates[0]]
                #print("sub_list",sub_list)
                final_minimal+=sub_list
            #print(final_minimal)
            minimal_per_class[rep] = final_minimal

           
            #print(f"\nContainment graph for class led by φ{rep}:")
            for i in range(n):
                src_idx, src_sub = idx_map[i]
                for j in edges[i]:
                    tgt_idx, tgt_sub = idx_map[j]
                    #print(f"  φ{src_idx}:{src_sub} includes φ{tgt_idx}:{tgt_sub}")

    return minimal_per_class



#from correctPhis.mdot import phi
from generate_synLTL import generate_ltl_set_with_classes


num_formulas_total = 500
target_classes = 20
implication_density = 1
print(f"--- Generating {num_formulas_total} LTL formulas, aiming for ~{target_classes} classes, with ~{implication_density}% implication density ---")
phi, ap_class_dist = generate_ltl_set_with_classes(
    num_formulas_total,
    target_classes,
    implication_density
)
#print("\nTarget AP distribution for classes:")
#for i, ap_set in enumerate(ap_class_dist):
#    print(f"Class {i}: {sorted(list(ap_set))}")

import time
start = time.time()
prop_list = extract_atomic_propositions(phi)
equivalence_classes = construct_equivalence_classes(phi)
end = time.time()
#print(equivalence_classes.values())
interval1 = end-start

subs = {}
print(len(equivalence_classes.values()))
tot_once = 0
tot_not_once = 0
for rep, indices in equivalence_classes.items():
    tot=0
    if len(indices)>1:
        for idx in indices:
         #   print(f"  φ{idx+1}: {phi[idx]}")
            subs[idx] = split_by_or(phi[idx])
            tot+=len(subs[idx])
        print(f"Class led by formula {rep}:{tot}")
        tot_not_once+= tot
    else:
        tot_once+=1

print("tot:", tot_not_once+tot_once)

#check_inclusions_in_classes(equivalence_classes, phi)
start = time.time()
minimal_subs = get_minimal_subformulas(equivalence_classes, phi)
end = time.time()

print(len(minimal_subs.values()))
print("\nMinimal Subformulas to Model Check:")
tot_now = 0
for rep, formulas in minimal_subs.items():
    print(f"Class led by φ{rep}:{len(formulas)}")
    tot_now+= len(formulas)
    #for f in formulas:
    #   print(f"  - {f}")

print("tot:", tot_now+tot_once)
print("tot time:", (interval1+ end-start) * 10**3)


#print("\nConnections")
#for rep, formulas in enumerate(connections):
#    print(f"Class led by φ{rep+1}:")
#    for f in formulas:
#        print(f"  - {f}")