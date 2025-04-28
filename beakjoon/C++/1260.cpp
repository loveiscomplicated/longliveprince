#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

void dfs(vector<vector<int>> graph, int numstart) {

}

void bfs(vector<vector<int>> graph, int numstart) {
  
}

void quickSort(vector<int> &v, int left, int right) {
  /*
  left: pivot 포함 가장 왼쪽 인덱스
  right: pivot이랑 비교할 가장 오른쪽 인덱스
  */
  
  
  
}

void swap(vector<int> &v, int idx1, int idx2) {
  int temp = v[idx1];
  v[idx1] = v[idx2];
  v[idx2] = temp;
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