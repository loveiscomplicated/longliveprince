#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(vector<vector<int>> graph, int numstart) {

}

void bfs(vector<vector<int>> graph, int numstart) {
  
}

void quickSort(vector<int> v) {
  int pivot = v[0]; // 맨 처음 원소를 pivot으로 잡음
  vector<int>::iterator iter1 = v.begin() + 1;
  
}
int main() {
  int node, edge, numStart;
  cin >> node >> edge >> numStart;

  vector<vector<int>> graph(node);

  for (int i = 0; i < edge; i++) {
    int a, b;
    cin >> a >> b;  
    graph[a].push_back(b); // 벡터에 값 넣기
  }

  
  return 0;
}