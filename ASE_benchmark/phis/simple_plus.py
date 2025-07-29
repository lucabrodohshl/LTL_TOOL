phi = [
    # Simple disjunction with temporal operators
    "F(a) | F(b) | F(c)",

    # Long disjunctive sequence with future and global
    "F(x) | G(y) | F(z) | G(a) | F(b)",

    # Implication rewritten as disjunction with nested LTL
    "!G(p) | F(q | X(r))",

    # Long formula with implication and multiple operators
    "!F(a & X(b)) | G(c | d | X(e)) | F(f) | G(G(g | h))",

    # A chain of disjunctions with nested X and F
    "X(a) | X(X(b)) | F(c | X(d)) | G(e | F(f))",

    # Complex formula using nesting, G, F, and disjunction
    "G(F(a | b)) | F(G(c | d)) | X(F(e | f))",

    # Nested temporal expressions with implication rewritten
    "!X(p | q) | F(G(r | s)) | G(F(t | u))",

    # Complex winding formula with disjunctions and implications
    "!G(a & X(b)) | F(c | d) | G(X(e | f) | G(g)) | F(h | X(i))",

    # Simpler implication expanded to disjunction
    "!F(j) | X(k | l | F(m))",

    # Deeply nested implication with temporal disjunctions
    "!G(X(a | F(b))) | F(X(c | G(d | e))) | G(F(f | G(g)))"
]
