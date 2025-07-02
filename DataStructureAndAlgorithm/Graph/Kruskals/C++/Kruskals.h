#ifndef KRUSKALS_H
#define KRUSKALS_H

#include <vector>
#include <algorithm>

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    std::vector<int> parent;
    DisjointSet(int n);
    int find(int i);
    void unite(int i, int j);
};

void kruskalMST(int numVertices, std::vector<Edge>& edges);

#endif // KRUSKALS_H
