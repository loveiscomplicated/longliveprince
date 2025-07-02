def floyd_warshall(graph):
    # graph is a V x V matrix where graph[i][j] is the weight of the edge from i to j
    # If there is no edge, graph[i][j] should be float('inf')
    # graph[i][i] should be 0

    V = len(graph)
    dist = list(map(lambda i: list(map(lambda j: j, i)), graph)) # Make a copy

    for k in range(V):
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    return dist
