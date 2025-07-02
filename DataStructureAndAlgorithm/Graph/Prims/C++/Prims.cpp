#include "Prims.h"
#include <queue>
#include <iostream>

// Pair of (weight, vertex)
using PQElement = std::pair<int, int>;

void primMST(int startNode, int numVertices, const std::vector<std::list<AdjPair>>& adj) {
    std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement>> pq;

    std::vector<int> key(numVertices, std::numeric_limits<int>::max());
    std::vector<int> parent(numVertices, -1);
    std::vector<bool> inMST(numVertices, false);

    pq.push({0, startNode});
    key[startNode] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = i->first;
            int weight = i->second;

            if (inMST[v] == false && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    std::cout << "Edge \tWeight" << std::endl;
    for (int i = 1; i < numVertices; ++i) {
        std::cout << parent[i] << " - " << i << " \t" << key[i] << std::endl;
    }
}
