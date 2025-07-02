#include "Kruskals.h"
#include <iostream>

DisjointSet::DisjointSet(int n) {
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int DisjointSet::find(int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

void DisjointSet::unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

void kruskalMST(int numVertices, std::vector<Edge>& edges) {
    std::vector<Edge> result;
    int i = 0; // Index used to pick next edge
    int e = 0; // Index used for result[]

    // Sort all the edges in non-decreasing order of their weight.
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(numVertices);

    while (e < numVertices - 1 && i < edges.size()) {
        Edge next_edge = edges[i++];

        int x = ds.find(next_edge.src);
        int y = ds.find(next_edge.dest);

        // If including this edge does't cause cycle, include it in result and increment the count of edges.
        if (x != y) {
            result.push_back(next_edge);
            ds.unite(x, y);
            e++;
        }
    }

    std::cout << "Following are the edges in the constructed MST" << std::endl;
    for (i = 0; i < e; ++i) {
        std::cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << std::endl;
    }
}
