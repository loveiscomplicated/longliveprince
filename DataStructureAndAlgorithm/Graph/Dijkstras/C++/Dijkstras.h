#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H

#include <vector>
#include <list>
#include <limits>

// Pair of (vertex, weight)
using AdjPair = std::pair<int, int>;

void dijkstra(int startNode, int numVertices, const std::vector<std::list<AdjPair>>& adj);

#endif // DIJKSTRAS_H
