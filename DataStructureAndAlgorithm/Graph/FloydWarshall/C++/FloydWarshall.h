#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include <vector>
#include <limits>

// Infinity constant
const int INF = std::numeric_limits<int>::max();

void floydWarshall(std::vector<std::vector<int>>& graph);

#endif // FLOYDWARSHALL_H
