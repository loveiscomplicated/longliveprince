import heapq

def prim_mst(graph, start_node):
    # graph is an adjacency list where graph[u] = [(v1, w1), (v2, w2), ...]
    # representing edges from u to v with weight w

    min_heap = [(0, start_node, -1)]  # (weight, vertex, parent)
    visited = set()
    mst_edges = []
    total_weight = 0

    while min_heap:
        weight, u, parent = heapq.heappop(min_heap)

        if u in visited:
            continue

        visited.add(u)
        if parent != -1:
            mst_edges.append((parent, u, weight))
            total_weight += weight

        for v, w in graph.get(u, []):
            if v not in visited:
                heapq.heappush(min_heap, (w, v, u))

    print("Edges in the MST:")
    for u, v, weight in mst_edges:
        print(f"{u} - {v} : {weight}")
    print(f"Minimum Cost Spanning Tree: {total_weight}")
    return mst_edges
