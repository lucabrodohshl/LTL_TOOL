import random
import math

LTL_KEYWORDS_UNARY = {'G', 'F', 'X', '!', 'true', 'false'}
LTL_KEYWORDS_BINARY = {'U', 'W', 'R', '&', '|', '->', '<->'}
DEFAULT_ATOMIC_PROPOSITIONS_POOL = [f'p{i}' for i in range(1, 1000)] # Larger pool for better class separation

# --- Configuration ---
DEFAULT_MAX_DEPTH = 3
DEFAULT_AP_PER_FORMULA_AVG = 3
# --- End Configuration ---

def generate_random_atomic_proposition_from_subset(ap_subset, num_aps_to_select):
    """Selects APs from a given subset."""
    if not ap_subset:
        return "true"
    
    selected_count = min(len(ap_subset), max(1, int(random.gauss(num_aps_to_select, 1))))
    if selected_count <= 0: # Ensure at least one AP if possible
        selected_count = 1 if ap_subset else 0
    if not ap_subset:
        return "true"
        
    selected_aps = random.sample(ap_subset, min(len(ap_subset), selected_count))

    if not selected_aps:
        return "true"

    if len(selected_aps) == 1 or random.random() < 0.7:
        return random.choice(selected_aps)
    else:
        op = random.choice(['&', '|'])
        # Ensure we have at least two APs for binary op
        ap1 = selected_aps[0]
        ap2 = selected_aps[1] if len(selected_aps) > 1 else selected_aps[0] # reuse if only one
        return f"({ap1} {op} {ap2})"

def generate_ltl_formula_recursive(current_depth, max_depth, current_ap_subset, ap_per_formula_avg):
    """
    Generates a random LTL formula recursively using APs from current_ap_subset.
    """
    if current_depth >= max_depth or random.random() < 0.4:
        return generate_random_atomic_proposition_from_subset(current_ap_subset, ap_per_formula_avg)

    operator_type = random.choice(['unary', 'binary'])

    if operator_type == 'unary' or current_depth == max_depth - 1:
        op = random.choice(list(LTL_KEYWORDS_UNARY - {'true', 'false'}))
        sub_formula = generate_ltl_formula_recursive(current_depth + 1, max_depth, current_ap_subset, ap_per_formula_avg)
        if op == '!':
            return f"!({sub_formula})"
        return f"{op}({sub_formula})"
    else:
        op = random.choice(list(LTL_KEYWORDS_BINARY))
        sub_formula1 = generate_ltl_formula_recursive(current_depth + 1, max_depth, current_ap_subset, ap_per_formula_avg)
        sub_formula2 = generate_ltl_formula_recursive(current_depth + 1, max_depth, current_ap_subset, ap_per_formula_avg)
        return f"({sub_formula1} {op} {sub_formula2})"

def get_aps_from_formula_string(formula_str, ap_pool):
    """Extracts APs present in a formula string."""
    present_aps = set()
    # This is a simple way; a proper parser would be more robust.
    # It assumes APs are distinct words not overlapping with keywords.
    words = formula_str.replace('(', ' ').replace(')', ' ').split()
    for word in words:
        if word in ap_pool:
            present_aps.add(word)
    return present_aps


def generate_ltl_set_with_classes(
    num_formulas,
    num_target_classes, # New parameter
    implication_density_percent,
    max_depth=DEFAULT_MAX_DEPTH,
    ap_pool=None,
    ap_per_formula_avg=DEFAULT_AP_PER_FORMULA_AVG
):
    if ap_pool is None:
        ap_pool = DEFAULT_ATOMIC_PROPOSITIONS_POOL
    
    if num_target_classes <= 0:
        raise ValueError("Number of target classes must be positive.")
    if num_target_classes > len(ap_pool) and num_target_classes > num_formulas :
        print(f"Warning: Target classes ({num_target_classes}) > APs ({len(ap_pool)}). May not achieve perfect separation.")
    if num_target_classes > num_formulas:
         print(f"Warning: Target classes ({num_target_classes}) > Formulas ({num_formulas}). Some classes might be empty.")


    # 1. Partition APs for target classes
    class_ap_subsets = [set() for _ in range(num_target_classes)]
    ap_pool_copy = list(ap_pool)
    random.shuffle(ap_pool_copy) # Shuffle for random distribution

    # Distribute APs somewhat evenly, ensuring each class gets some if possible
    min_aps_per_class = 1 # Try to give at least one AP to each class
    
    for i in range(len(ap_pool_copy)):
        class_idx = i % num_target_classes
        class_ap_subsets[class_idx].add(ap_pool_copy[i])

    # Ensure each class has at least min_aps_per_class if ap_pool is large enough
    if len(ap_pool_copy) >= num_target_classes * min_aps_per_class:
        temp_ap_pool = list(ap_pool_copy) # Work with a copy for this step
        for i in range(num_target_classes):
            while len(class_ap_subsets[i]) < min_aps_per_class and temp_ap_pool:
                # Steal an AP from another class if necessary, or just add if available
                # This part can be complex to make perfect. For now, the modulo distribution
                # should give a reasonable spread. If a class is empty, it means ap_pool was too small.
                # A simpler guarantee: if a class subset is empty and temp_ap_pool has APs, assign one.
                if not class_ap_subsets[i] and temp_ap_pool:
                     class_ap_subsets[i].add(temp_ap_pool.pop(random.randrange(len(temp_ap_pool))))


    # 2. Assign formulas to target classes
    formula_class_assignments = [-1] * num_formulas
    formulas_in_class = [[] for _ in range(num_target_classes)] # Store indices of formulas
    for i in range(num_formulas):
        class_idx = i % num_target_classes
        formula_class_assignments[i] = class_idx
        formulas_in_class[class_idx].append(i)

    generated_formulas = [""] * num_formulas
    formula_actual_aps = [set() for _ in range(num_formulas)] # Store APs used by each formula

    # 3. Generate initial formulas within their assigned classes
    for i in range(num_formulas):
        target_class_idx = formula_class_assignments[i]
        current_ap_subset = list(class_ap_subsets[target_class_idx]) # Convert set to list for sampling

        if not current_ap_subset: # Fallback if a class ended up with no APs
            current_ap_subset = list(ap_pool) # Use global pool

        # Heuristic: Try to share an AP with a previous formula in the same class
        shared_ap_candidate = None
        if len(formulas_in_class[target_class_idx]) > 1 and i != formulas_in_class[target_class_idx][0]:
            # Find a previously generated formula in the same class
            prev_formula_indices_in_class = [idx for idx in formulas_in_class[target_class_idx] if idx < i]
            if prev_formula_indices_in_class:
                prev_formula_idx = random.choice(prev_formula_indices_in_class)
                if formula_actual_aps[prev_formula_idx]:
                    shared_ap_candidate = random.choice(list(formula_actual_aps[prev_formula_idx]))
        
        # Temporarily add the shared AP candidate to the current subset for generation
        # to increase its chance of being picked by generate_random_atomic_proposition_from_subset
        generation_aps = list(current_ap_subset)
        if shared_ap_candidate and shared_ap_candidate not in generation_aps:
            # Only add if it's actually from the broader pool (or a valid AP)
            # This logic needs to be careful not to force APs outside the class's intended subset too much
            # For now, we rely on generate_random_atomic_proposition_from_subset to pick from its given list
            pass # The current_ap_subset already defines the boundary

        formula_A = generate_ltl_formula_recursive(0, max_depth, current_ap_subset, ap_per_formula_avg)
        generated_formulas[i] = formula_A
        formula_actual_aps[i] = get_aps_from_formula_string(formula_A, ap_pool)


    # 4. Embed Implications
    num_implications_to_create = int(num_formulas * (implication_density_percent / 100.0))
    indices_to_modify_for_B = random.sample(range(num_formulas), num_implications_to_create)

    for target_idx_B in indices_to_modify_for_B:
        possible_A_indices = [i for i in range(num_formulas) if i != target_idx_B]
        if not possible_A_indices:
            continue
        
        idx_A = random.choice(possible_A_indices)
        formula_A_for_implication = generated_formulas[idx_A]
        
        # Generate Remainder R. Try to use APs from B's original class for R.
        class_of_B = formula_class_assignments[target_idx_B]
        aps_for_R = list(class_ap_subsets[class_of_B]) if class_ap_subsets[class_of_B] else list(ap_pool)

        formula_R = generate_ltl_formula_recursive(0, max_depth, aps_for_R, ap_per_formula_avg)
        
        new_formula_B = f"({formula_A_for_implication} | {formula_R})"
        generated_formulas[target_idx_B] = new_formula_B
        formula_actual_aps[target_idx_B] = get_aps_from_formula_string(new_formula_B, ap_pool)
        # Note: The APs of B might now include APs from A's class.
        # This can "merge" intended equivalence classes if A and B were from different target classes.
        # This is a complex interaction to perfectly control with simple generation.

    return generated_formulas, class_ap_subsets # Also return the AP distribution for analysis

if __name__ == "__main__":
    num_formulas_total = 20
    target_classes = 5
    implication_density = 30

    print(f"--- Generating {num_formulas_total} LTL formulas, aiming for ~{target_classes} classes, with ~{implication_density}% implication density ---")
    formulas, ap_class_dist = generate_ltl_set_with_classes(
        num_formulas_total,
        target_classes,
        implication_density
    )
    print("\nTarget AP distribution for classes:")
    for i, ap_set in enumerate(ap_class_dist):
        print(f"Class {i}: {sorted(list(ap_set))}")

    print("\nGenerated Formulas:")
    for i, f_str in enumerate(formulas):
        # For verification, let's see the APs used in each formula
        used_aps = get_aps_from_formula_string(f_str, DEFAULT_ATOMIC_PROPOSITIONS_POOL)
        print(f"{i+1}: {f_str} (APs: {sorted(list(used_aps))})")

    print(f"\n--- Example: Aiming for {num_formulas_total} classes (each formula its own class) ---")
    # To make each formula its own class, ensure num_target_classes = num_formulas
    # and that the AP pool is large enough.
    formulas_N_classes, _ = generate_ltl_set_with_classes(5, 5, 0, ap_pool=[f'p{i}' for i in range(1, 26)]) # 5 APs per formula
    print("\nGenerated Formulas (target N classes):")
    for i, f_str in enumerate(formulas_N_classes):
        used_aps = get_aps_from_formula_string(f_str, DEFAULT_ATOMIC_PROPOSITIONS_POOL)
        print(f"{i+1}: {f_str} (APs: {sorted(list(used_aps))})")


    print(f"\n--- Example: Aiming for 1 class ---")
    formulas_1_class, _ = generate_ltl_set_with_classes(5, 1, 50)
    print("\nGenerated Formulas (target 1 class):")
    for i, f_str in enumerate(formulas_1_class):
        used_aps = get_aps_from_formula_string(f_str, DEFAULT_ATOMIC_PROPOSITIONS_POOL)
        print(f"{i+1}: {f_str} (APs: {sorted(list(used_aps))})")