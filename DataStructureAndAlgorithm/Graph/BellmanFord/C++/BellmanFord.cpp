#include "BellmanFord.h"
#include <iostream>

void bellmanFord(int startNode, int numVertices, const std::vector<Edge>& edges) {
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
    dist[startNode] = 0;

    // Relax all edges |V| - 1 times.
    for (int i = 0; i < numVertices - 1; ++i) {
        for (const Edge& edge : edges) {
            if (dist[edge.src] != std::numeric_limits<int>::max() &&
                dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    // Check for negative-weight cycles.
    for (const Edge& edge : edges) {
        if (dist[edge.src] != std::numeric_limits<int>::max() &&
            dist[edge.src] + edge.weight < dist[edge.dest]) {
            std::cout << "Graph contains negative weight cycle" << std::endl;
            return;
        }
    }

    std::cout << "Vertex   Distance from Source" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << "\t\t" << dist[i] << std::endl;
    }
}
