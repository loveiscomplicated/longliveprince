#include "BFS.h"
#include <iostream>
#include <queue>

void BFS(int startNode, int numNodes, const std::vector<std::list<int>>& adj) {
    std::vector<bool> visited(numNodes, false);
    std::queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        std::cout << "Visited " << currentNode << std::endl;

        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
