# Takes adj. matrix input, returns adj. list
def get_edge_list(adjacency_matrix: list, n: int) -> list:
    edge_list = []

    # Loop through lower triangle of matrix, since it is symmetric
    for i in range(n):
        for j in range(i):

            # Don't include the diagonal
            if i != j:
                edge_list.append((i, j, adjacency_matrix[i][j]))
    return edge_list

# Takes input n and an edge_list, returns an mst
def kruskals(edge_list: list, n: int) -> list:

    # Array to store edges in our mst
    mst = []

    #Set these up to mimic disjoint set structure
    parent = dict()
    rank = dict()

    # Init parent to itself, rank to 0
    for i in range(n):
        parent[i] = i
        rank[i] = 0

    # Go through the sorted edges, and if u,v aren't already connected,
    #   then we add this edge to the mst, and union the sets they belong to
    for edge in edge_list:
        u = find(edge[0], parent)
        v = find(edge[1], parent)
        if u != v:
            mst.append(edge)
            union(u, v, parent, rank)
    return mst

# Recursive function to get the root vertex of the disjoint set
def find(x: int, parent: dict) -> int:
    if parent[x] != x:
        return find(parent[x], parent)
    else:
        return x

# Function to take two elements and in a balanced way join their sets together
def union(x: int, y: int, parent: dict, rank: dict) -> None:
    x = find(x, parent)
    y = find(y, parent)

    # Check if they already belong to the same set
    if x == y:
        return

    # Choose x or y as root depending on rank
    if rank[x] < rank[y]:
        parent[y] = x
    else:
        parent[x] = y

        # If the ranks are equal, change one
        if rank[y] == rank[x]:
            rank[y] += 1

def first_second_third_mst(input_file_path, output_file_path):
    file_in = open(input_file_path, 'r')
    n = int(file_in.readline())
    a = [list(map(int, file_in.readline().split(','))) for i in range(n)]
    edge_list = get_edge_list(a, n) # O(V^2)
    edge_list.sort(key = lambda x : x[2]) # O(E log E)
    result = my_first_second_third_mst(n, a, edge_list) # O(V E)
    file_out = open(output_file_path, 'w')
    file_out.write(str(result[0]))
    file_out.write('\n')
    file_out.write(str(result[1]))
    file_out.write('\n')
    file_out.write(str(result[2]))
    file_out.write('\n')

# Counts the weights given a list of edges
def total(mst: list) -> int:
    result = 0
    for edge in mst:
        result += edge[2]
    return result

# Gets the first, second and third msts
def my_first_second_third_mst(n, a, edge_list):

    # Gets first mst
    mst = kruskals(edge_list, n)
    first, second, third = -1, -1, -1
    if n > 1:
        first = total(mst)
    minus1 = []

    # Remove each existing edge and make an mst from that
    for edge in mst:
        new_li = edge_list.copy()
        new_li.remove(edge)
        minus1.append(total(kruskals(new_li, n)))
    if n > 2:
        second = min(minus1)
    minus1.remove(second)
    third = min(minus1)
    return (first, second, third)

