EDGE_MAX = 10000000

def first_second_third_mst(input_file_path, output_file_path):
    file_in = open(input_file_path, 'r')
    n = int(file_in.readline())
    A = [list(map(int, file_in.readline().split(','))) for i in range(0,n)]
    first_mst = mst(A,n)
    second_mst = mst(A,n)
    third_mst = mst(A,n)
    file_out = open(output_file_path, 'w')
    file_out.write(str(first_mst) + '\n' + str(second_mst) + '\n' + str(third_mst) + '\n')
    pass

def mst(A, n):
    C = dict()
    E = dict()
    for v in range(0,n):
        C[v] = EDGE_MAX
        E[v] = -1
    Q = [i for i in range(0,n)]
    F = dict()
    while len(Q) != 0:
        v = Q[0]
        if len(Q) != n:
            for v_0 in Q:
                if C[v_0] < C[v]:
                    v = v_0
        Q.remove(v)
        if E[v] != -1:
            F[((v, E[v]))] = True
        for w in Q:
            if A[v][w] < C[w]:
                C[w] = A[v][w]
                E[w] = v
    result = compute_cost(F,A)
    remove_max_edge(F,A)
    return result

def kth_min(array, k):
    cp = array.copy()
    result = EDGE_MAX
    for i in range(0,k):
        result = min(cp)
        cp.remove(result)
    return result

def compute_cost(F,A):
    result = 0
    for edge in F:
        result += A[edge[0]][edge[1]]
    return result

def remove_max_edge(F,A):
    edge_to_remove = (0,0)
    for edge in F:
        if (A[edge[0]][edge[1]] > A[edge_to_remove[0]][edge_to_remove[1]]
            and A[edge[0]][edge[1]] != EDGE_MAX
            and A[edge[0]][edge[1]] != max(filter(lambda x : x != EDGE_MAX, A[edge[0]]))):
            A[edge[0]][edge[1]] = EDGE_MAX

first_second_third_mst('test0.in', 'test0.out')
first_second_third_mst('test1.in', 'test1.out')
