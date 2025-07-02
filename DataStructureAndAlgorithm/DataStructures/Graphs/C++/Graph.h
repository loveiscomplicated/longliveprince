#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <iostream>

class Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjLists;
    bool isDirected;

public:
    Graph(int vertices, bool directed = false);
    void addEdge(int src, int dest);
    void printGraph();
    void BFS(int startVertex);
    void DFS(int startVertex);
    void DFSUtil(int v, std::vector<bool>& visited);
};

#endif // GRAPH_H
