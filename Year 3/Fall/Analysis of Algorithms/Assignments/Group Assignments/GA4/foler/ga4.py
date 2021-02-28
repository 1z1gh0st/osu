def first_second_third_mst(input_file_path, output_file_path):
    file_in = open(input_file_path, 'r')
    n = int(file_in.readline())
    a = [list(map(int, file_in.readline().split(','))) for i in range(n)]
    edge_list = get_edge_list(a, n)
    edge_list.sort(key = lambda x : x[2])
    result = do_all(edge_list, n)

    file_out = open(output_file_path, 'w')
    file_out.write(str(result[0]))
    file_out.write('\n')
    file_out.write(str(result[1]))
    file_out.write('\n')
    file_out.write(str(result[2]))
    file_out.write('\n')

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
    counter = 0
    for edge in edge_list:
        print(counter)
        counter += 1
        u = find(edge[0], parent)
        v = find(edge[1], parent)
        if u != v:
            mst.append(edge)
            union(u, v, parent, rank)
    return mst

def do_all(edge_list: list, n: int) -> tuple:
    if n < 2:
        return (1, "None", "None")
    if n < 3:
        return (edge_list[0][2], "None", "None")
    else:
        mst = kruskals(edge_list, n)
        first = total(mst)
        same_count = 0
        deltas = []
        idx = 0
        for edge in mst:
            print(idx)
            idx += 1
            new_el = edge_list.copy()
            new_el.remove(edge)
            delta = total(kruskals(new_el, n)) - first
            if delta == 0:
                same_count += 1
            deltas.append(delta)
            if same_count > 2:
                return (first, first, first)
        second = first + min(deltas)
        deltas.remove(second - first)
        third = first + min(deltas)
        return (first, second, third)

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

def total(mst: list) -> int:
    result = 0
    for edge in mst:
        result += edge[2]
    return result
