class Node:
    def __init__(self, data) -> None:
        self.parent = self
        self.rank = 1
        self.data = data

    def __eq__(self, other) -> bool:
        if self.data == other.data:
            return True
        else:
            return False

class DisjointSet:
    def __init__(self) -> None:
        self.forest = dict()

    def MakeSet(self, x: Node) -> Node:
        if x.data not in self.forest:
            x.parent = x
            x.rank = 0
            self.forest[x.data] = x

    def Find(self, x: Node) -> Node:
        if x.parent != x:
            x.parent = self.Find(x.parent)
            return x.parent
        return x

    def Union(self, x: Node, y: Node) -> None:
        x = self.Find(x)
        y = self.Find(y)
        if x == y:
            return
        if x.rank < y.rank:
            self.forest[x.data] = y
            self.forest[y.data] = x
        self.forest[y.data].parent = x
        if x.rank == y.rank:
            self.forest[x.data].rank += 1

class Graph:
    def __init__(self, A: list, n: int) -> None:
        self.adj = A
        self.V = [ i for i in range(n) ]
        self.E = []
        for i in range(n):
            for j in range(i,n):
                if i != j:
                    self.E.append((i, j, A[i][j]))
        self.E.sort(key = lambda x : x[2])

def Kruskal(G: Graph) -> list:
    DS = DisjointSet()
    F = []
    for v in G.V:
        DS.MakeSet(Node(v))
    for edge in G.E:
        u = DS.Find(Node(edge[0]))
        v = DS.Find(Node(edge[1]))
        if u != v:
            DS.Print()
            F.append(edge)
            DS.Union(u,v)
    return F

n = 3
A = [[0,1,2],
     [1,0,3],
     [2,3,0]]

G = Graph(A, n)
mst = Kruskal(G)
print(mst)
