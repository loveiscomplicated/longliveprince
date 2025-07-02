#include "Graph.h"
#include <vector>

Graph::Graph(int vertices, bool directed) : numVertices(vertices), isDirected(directed) {
    adjLists.resize(vertices);
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    if (!isDirected) {
        adjLists[dest].push_back(src);
    }
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Adjacency list of vertex " << i << ": ";
        for (int vertex : adjLists[i]) {
            std::cout << vertex << " -> ";
        }
        std::cout << "nullptr" << std::endl;
    }
}

void Graph::BFS(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    std::list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    while (!queue.empty()) {
        int currVertex = queue.front();
        std::cout << "Visited " << currVertex << std::endl;
        queue.pop_front();

        for (int adjVertex : adjLists[currVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

void Graph::DFSUtil(int v, std::vector<bool>& visited) {
    visited[v] = true;
    std::cout << "Visited " << v << std::endl;

    for (int adjVertex : adjLists[v]) {
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited);
        }
    }
}

void Graph::DFS(int startVertex) {
    std::vector<bool> visited(numVertices, false);
    DFSUtil(startVertex, visited);
}
