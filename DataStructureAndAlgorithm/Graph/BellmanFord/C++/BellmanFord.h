#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>
#include <limits>

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int startNode, int numVertices, const std::vector<Edge>& edges);

#endif // BELLMANFORD_H
