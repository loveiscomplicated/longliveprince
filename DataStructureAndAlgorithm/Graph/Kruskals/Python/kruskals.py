class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i != root_j:
            self.parent[root_i] = root_j
            return True
        return False

def kruskal_mst(num_vertices, edges):
    # edges is a list of tuples: (weight, u, v)
    edges.sort()
    
    ds = DisjointSet(num_vertices)
    mst = []
    min_cost = 0

    for weight, u, v in edges:
        if ds.union(u, v):
            mst.append((u, v, weight))
            min_cost += weight

    print("Edges in the MST:")
    for u, v, weight in mst:
        print(f"{u} - {v} : {weight}")
    print(f"Minimum Cost Spanning Tree: {min_cost}")
    return mst
