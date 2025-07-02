#include "TopologicalSort.h"
#include <iostream>

void topologicalSortUtil(int v, const std::vector<std::list<int>>& adj, std::vector<bool>& visited, std::list<int>& stack) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, stack);
        }
    }
    stack.push_front(v);
}

void topologicalSort(int numVertices, const std::vector<std::list<int>>& adj) {
    std::list<int> stack;
    std::vector<bool> visited(numVertices, false);

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, stack);
        }
    }

    std::cout << "Topological Sort: ";
    for (int i : stack) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
