#include "DFS.h"
#include <iostream>

void DFS(int startNode, int numNodes, const std::vector<std::list<int>>& adj, std::vector<bool>& visited) {
    visited[startNode] = true;
    std::cout << "Visited " << startNode << std::endl;

    for (int neighbor : adj[startNode]) {
        if (!visited[neighbor]) {
            DFS(neighbor, numNodes, adj, visited);
        }
    }
}
