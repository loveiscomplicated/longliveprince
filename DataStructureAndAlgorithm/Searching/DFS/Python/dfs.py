def dfs(graph, start_node, visited=None):
    if visited is None:
        visited = set()
    visited.add(start_node)
    print(f"Visited {start_node}")

    for neighbor in graph.get(start_node, []):
        if neighbor not in visited:
            dfs(graph, neighbor, visited)
