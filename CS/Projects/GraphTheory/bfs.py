# Let us make an unweighted graph and then perform a breadth-first search on it.

# NODES: a, b, c, d, e, f, g

def print_matrix(m):
    for i in range(0, len(m)):
        print(m[i])

vertices = ['a', 'b', 'c', 'd', 'e', 'f', 'g']

edges = [ "ab", "ac", "ad", "bd", "bf", "cg", "ce", "fg" ]
n = len(vertices)

adjacency_matrix = []

for i in range(n):
    adjacency_matrix.append([0] * n)

for i in range(len(edges)):

print_matrix(adjacency_matrix)

