from collections import defaultdict, deque

class Graph:
    def __init__(self, directed=False):
        self.graph = defaultdict(list)
        self.directed = directed

    def add_edge(self, u, v):
        self.graph[u].append(v)
        if not self.directed:
            self.graph[v].append(u)

    def print_graph(self):
        for vertex in self.graph:
            print(f"Vertex {vertex}:", " -> ".join(map(str, self.graph[vertex])))

    def bfs(self, start_vertex):
        visited = {start_vertex}
        queue = deque([start_vertex])
        while queue:
            vertex = queue.popleft()
            print(f"Visited {vertex}")
            for neighbour in self.graph[vertex]:
                if neighbour not in visited:
                    visited.add(neighbour)
                    queue.append(neighbour)

    def dfs(self, start_vertex):
        visited = set()
        self._dfs_util(start_vertex, visited)

    def _dfs_util(self, vertex, visited):
        visited.add(vertex)
        print(f"Visited {vertex}")
        for neighbour in self.graph[vertex]:
            if neighbour not in visited:
                self._dfs_util(neighbour, visited)
