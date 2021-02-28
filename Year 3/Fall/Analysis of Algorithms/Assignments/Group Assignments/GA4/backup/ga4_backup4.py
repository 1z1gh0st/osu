def get_edge_list(adjacency_matrix: list, n: int) -> list:
    edge_list = []
    for i in range(n):
        for j in range(i):
            if i != j:
                edge_list.append((i, j, adjacency_matrix[i][j]))
    return edge_list

def kruskals(edge_list: list, n: int) -> list:
    mst = []
    parent = dict()
    rank = dict()
    for i in range(n):
        parent[i] = i
        rank[i] = 0
    for edge in edge_list:
        u = find(edge[0], parent)
        v = find(edge[1], parent)
        if u != v:
            mst.append(edge)
            union(u, v, parent, rank)
    return mst

def find(x: int, parent: dict) -> int:
    if parent[x] != x:
        return find(parent[x], parent)
    else:
        return x

def union(x: int, y: int, parent: dict, rank: dict) -> None:
    x = find(x, parent)
    y = find(y, parent)
    if x == y:
        return
    if rank[x] < rank[y]:
        parent[y] = x
    else:
        parent[x] = y
        if rank[y] == rank[x]:
            rank[y] += 1

def print_ds(n, parent, rank):
    for i in range(n):
        print(i, parent[i], rank[i])

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

def total(mst: list) -> int:
    result = 0
    for edge in mst:
        result += edge[2]
    return result

def my_first_second_third_mst(n, a, edge_list):
    mst = kruskals(edge_list, n)
    first, second, third = -1, -1, -1
    if n > 1:
        first = total(mst)
    minus1 = []
    for edge in mst: # O(V - 1)
        new_li = edge_list.copy()
        new_li.remove(edge)
        minus1.append(total(kruskals(new_li, n))) # O(E)
    if n > 2:
        second = min(minus1)
    minus1.remove(second)
    third = min(minus1)
    return (first, second, third)

first_second_third_mst("test0.in", "test0.out")
first_second_third_mst("test1.in", "test1.out")
first_second_third_mst("test100.in", "test100.out")
first_second_third_mst("test1000.in", "test1000.out")
