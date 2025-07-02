def bellman_ford(graph, start_node):
    # graph is a dictionary where keys are nodes and values are lists of (neighbor, weight) tuples
    # Example: graph = {0: [(1, 4), (2, 2)], 1: [(3, 2)], 2: [(1, 1), (3, 5)], 3: []}

    distances = {node: float('inf') for node in graph}
    distances[start_node] = 0

    # Relax edges |V| - 1 times
    for _ in range(len(graph) - 1):
        for node in graph:
            for neighbor, weight in graph[node]:
                if distances[node] != float('inf') and distances[node] + weight < distances[neighbor]:
                    distances[neighbor] = distances[node] + weight

    # Check for negative cycles
    for node in graph:
        for neighbor, weight in graph[node]:
            if distances[node] != float('inf') and distances[node] + weight < distances[neighbor]:
                print("Graph contains negative weight cycle")
                return None

    return distances
