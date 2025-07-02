#ifndef DFS_H
#define DFS_H

#include <vector>
#include <list>

void DFS(int startNode, int numNodes, const std::vector<std::list<int>>& adj, std::vector<bool>& visited);

#endif // DFS_H
