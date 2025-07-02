#ifndef PRIMS_H
#define PRIMS_H

#include <vector>
#include <list>
#include <limits>

// Pair of (weight, vertex)
using AdjPair = std::pair<int, int>;

void primMST(int startNode, int numVertices, const std::vector<std::list<AdjPair>>& adj);

#endif // PRIMS_H
