from collections import defaultdict

def topological_sort(graph):
    # graph is an adjacency list where graph[u] = [v1, v2, ...]
    # representing edges from u to v

    visited = set()
    recursion_stack = set()
    result = []

    def dfs(node):
        visited.add(node)
        recursion_stack.add(node)

        for neighbor in graph.get(node, []):
            if neighbor not in visited:
                if not dfs(neighbor):
                    return False
            elif neighbor in recursion_stack:
                # Cycle detected
                return False
        
        recursion_stack.remove(node)
        result.append(node)
        return True

    for node in graph:
        if node not in visited:
            if not dfs(node):
                print("Graph contains a cycle, topological sort not possible.")
                return None

    return result[::-1] # Reverse to get correct topological order
