#include <iostream>
#include <vector>

using namespace std;

void quichSort(vector<int> v) {
  
}

void dfs(vector<vector<int>> graph, int startNum) {

}

void bfs(vector<vector<int>> graph, int startNum) {
  
}

int main() {
  int node, edge, startNum;
  cin >> node >> edge >> startNum;

  vector<vector<int>> graph(node);
  
  for (int i = 0; i < edge; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }


  return 0;
}