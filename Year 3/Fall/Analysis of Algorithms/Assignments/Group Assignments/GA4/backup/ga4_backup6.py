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
    totals = []
    mst = []
    parent = []
    rank = []
    for i in range(n):
        mst_i = []
        mst.append(mst_i)
        parent_i = dict()
        parent.append(parent_i)
        rank_i = dict()
        rank.append(rank_i)
        for j in range(n):
            parent[i][j] = j
            rank[i][j] = 0

    count = 0
    # Go through the sorted edges, and if u,v aren't already connected,
    #   then we add this edge to the mst, and union the sets they belong to
    for edge in edge_list:
        u = find(edge[0], parent[0])
        v = find(edge[1], parent[0])
        if u != v:
            mst[0].append(edge)
            union(u, v, parent[0], rank[0])
        if u != v or count >= n - 1:
            count += 1

        for i in range(1, n):
            u = find(edge[0], parent[i])
            v = find(edge[1], parent[i])
            if u != v and count != n - i:
                mst[i].append(edge)
                union(u, v, parent[i], rank[i])

    for tree in mst:
        totals.append(total(tree))

    print(totals)

    first, second, third = -1, -1, -1

    if n > 1:
        first = min(totals)
        totals.remove(first)
    if n > 2:
        second = min(totals)
        totals.remove(second)
        third = min(totals)

    return (first, second, third)

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
    result = kruskals(edge_list, n) # O(V E)
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

first_second_third_mst("test0.in", "test0.out")
first_second_third_mst("test1.in", "test1.out")
first_second_third_mst("test3.in", "test3.out")
first_second_third_mst("test20.in", "test20.out")
#first_second_third_mst("test100.in", "test100.out")
#first_second_third_mst("test500.in", "test500.out")
#first_second_third_mst("test1000.in", "test1000.out")
