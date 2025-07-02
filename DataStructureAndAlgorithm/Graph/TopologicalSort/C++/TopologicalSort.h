#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include <vector>
#include <list>

void topologicalSort(int numVertices, const std::vector<std::list<int>>& adj);
void topologicalSortUtil(int v, const std::vector<std::list<int>>& adj, std::vector<bool>& visited, std::list<int>& stack);

#endif // TOPOLOGICALSORT_H
