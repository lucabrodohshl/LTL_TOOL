class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]
    
    def union(self, x, y):
        self.parent[self.find(x)] = self.find(y)

def group_sets_by_literals(sets):
    n = len(sets)
    dsu = DSU(n)
    literal_to_indices = {}

    # Map literals to sets they occur in
    for i, s in enumerate(sets):
        for literal in s:
            if literal not in literal_to_indices:
                literal_to_indices[literal] = []
            literal_to_indices[literal].append(i)
    # Union sets that share literals
    for indices in literal_to_indices.values():
        for i in range(1, len(indices)):
            dsu.union(indices[i], indices[0])

    # Group sets by root parent
    from collections import defaultdict
    groups = defaultdict(list)
    for i in range(n):
        root = dsu.find(i)
        groups[root].append(sets[i])

    return list(groups.values())


sets = [
    {"a", "b"},
    {"a","c", "a^b"},
    {"d", "f^c"},
    {"e"},
    {"c", "d"}
]

result = group_sets_by_literals(sets)
for group in result:
    print(group)
