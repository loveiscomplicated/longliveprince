#include <iostream>
#include <vector>

using namespace std;

void quickSort (vector<int> &v, vector<int>::iterator left, vector<int>::iterator right) {
  if (left >= right) {
    return;
  }

  vector<int>::iterator pivot = left;
  vector<int>::iterator i = left + 1;
  vector<int>::iterator j = right;

  while (i <= j) {
    while (i <= right && *i <= *pivot) {
      ++i;
    }
    while (j > left && *j > *pivot) {
      --j;
    }
    if (i < j) {
      iter_swap(i, j);
    }
  }
  iter_swap(pivot, j);
  quickSort(v, left, j - 1);
  quickSort(v, j + 1, right);
}


void dfs(vector<vector<int> > graph, int node, int startNum) {
  bool visited[node + 1];
  for (int i = 0; i <= node; ++i) {
    visited[i] = false;
  }

  stack stk(node);
  pr p;

  // stack에 startNum 넣기

  // Stack에서 하나 꺼내기
  // 거기 노드로 이동
  // 앞에서부터 들어갈 수 있는지 확인
  // 들어갈 수 있으면
  //  스택에 푸쉬하고
  //  출력하고
  //  다음 노드로 이동 -> 앞에서부터 들어갈 수 있는지 확인인
  // 들어갈 수 없으면 
  // 스택에서 하나 꺼내기
  // 그 노드로 이동 -> 앞에서부터 들어갈 수 있는지 확인

  int* currentNode = &graph[stk.pop()][0];

  bool* visit(vector<int>*& currentNode, bool*& visited) {
    
  }


  

  
}
class stack {
  public:
    int* head;
    int* arr;
    int size;
    int count;

    stack(int size1) {
      arr = new int[size1];
      size = size1;
      head = &arr[0];
      count = 0;
    }

    void push(int elem) {
      if (count == size) {
        cout << "stackFullError" << endl;
        return ;
      }
      ++head;
      *head = elem;
      ++count;
    }

    int pop() {
      if (count == 0) {
        cout << "stack is empty" << endl;
        return;
      }
      int temp = *head;
      --head;
      return temp;
    }
};


class queue {
  public:
  int* head;
  int* tail;
  int size; // the maximum size that queue can store
  int count; // how many elements are in the queue

  int* arr; // in order to maintain the memory even if the constructor function is quit.
  int* arrHead;
  int* arrTail;

  queue(int size1) {
    size = size1;

    arr = new int[size];
    for (int i = 0; i < size; i++) {
      arr[i] = 0; // initialize
    }

    head = &arr[0];
    tail = &arr[0];

    arrHead = &arr[0];
    arrTail = &arr[size - 1];

    count = 0;
  }

  void push(int elem) {
    if (count == size) {
      cout << "the queue is fully occupied" << endl;
      return;
    }

    *tail = elem;
    if (tail == arrTail) {
      tail = arrHead;
    } else {
      tail++;
    }
    count++;
  }

  int pop() {
    if (count == 0) {
      cout << "the queue is empty. the returned value is meaningless" << endl;
      return -1;
    }
    int output = *head;
    if (head == arrTail) {
      head = arrHead;
    } else {
      head++;
    }
    return output;
  }

};

class pr { // 출력, 그리고 여태까지 몇 번 출력했는지 알 수 있는 함수
  public:
    int count;

    pr() {
      count = 0;
    }

    void print(int num) {
      cout << num << ' ';
      count++;
    }

    int getcount() {
      return count;
    }
};

void bfs(vector<vector<int> > graph, int node, int startNum) {
  bool visited[node + 1]; // random access가 가능하다는 것이 좋다 ㅋ.ㅋ
  for (int i = 0; i <= node; i++) {
    visited[i] = false;
  }

  queue q(node);
  pr a;

  q.push(startNum);
  a.print(startNum);
  visited[startNum] = true;

  while (a.count < node) {
    int nodeNum = q.pop();
    for (int i = 0; i < graph[nodeNum].size(); i++) {
      if (visited[graph[nodeNum][i]] == false) {
        q.push(graph[nodeNum][i]);
        a.print(graph[nodeNum][i]);
        visited[graph[nodeNum][i]] = true;
      } 
    }
  }
}

int main() {
  int node, edge, startNum;
  cin >> node >> edge >> startNum;

  // node 이름이 1부터 시작하므로, 편의를 위해 0번 인덱스는 비워둔다
  vector<vector<int> > graph(node + 1); 

  int a, b;
  for (int i = 0; i < edge; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // 탐색을 위해 각 노드에 연결된 다른 노드들을 오름차순으로 정렬한다.
  // 최적화를 위해 정렬 알고리즘은 quickSort를 사용한다.
  for (int i = 1; i <= node; i++) {
    quickSort(graph[i], graph[i].begin(), graph[i].end() - 1);
  }
  


  //test
  for (int i = 1; i <= node; i++) {
    cout << i << "th node" << endl;
    for (int j = 0; j < graph[i].size(); j++) {
      cout << graph[i][j] << ' ';
    } 
    cout << endl;
  }
  return 0;
}