#include "Dijkstras.h"
#include <queue>
#include <iostream>

// Pair of (distance, vertex)
using PQElement = std::pair<int, int>;

void dijkstra(int startNode, int numVertices, const std::vector<std::list<AdjPair>>& adj) {
    // Create a priority queue to store vertices that are being processed
    // in the form (distance, vertex)
    std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> pq;

    // Create a vector for distances and initialize all distances as infinite
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());

    // Insert source itself in priority queue and initialize its distance as 0.
pq.push({0, startNode});
    dist[startNode] = 0;

    /* Looping till priority queue becomes empty (or all distances are finalized) */
    while (!pq.empty()) {
        // The first element of pair is the minimum distance
        // vertex from source. Second part is the vertex number
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            // Get vertex label and weight of current adjacent of u
            int v = i->first;
            int weight = i->second;

            // If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances stored in dist[]
    std::cout << "Vertex   Distance from Source" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << "\t\t" << dist[i] << std::endl;
    }
}

