import spot

# Define an LTL formula
ltl_formula = "G(F a -> X b)"

# Parse the formula
parsed = spot.formula(ltl_formula)

# Print the parsed formula
print("Parsed formula:")
print(parsed)

# Translate it to a Büchi automaton
aut = spot.translate(parsed)

# Print basic info
print("\nAutomaton info:")
print(f"States: {aut.num_states()}")
print(f"Acceptance condition: {aut.get_acceptance()}\n")

# Print the automaton in HOA format (standard for Büchi automata)
print("HOA format:")
print(aut.to_str('hoa'))
