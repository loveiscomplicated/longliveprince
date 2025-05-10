#include <iostream>
#include <vector>


// Question 6: k-th nearest obstacle queries

class MaxHeap {
  public:
  std::vector<int> vec;
  MaxHeap(std::vector<std::vector<int>>& queries, int k);
  void insert(int elem);

  private:
  void heapify(std::vector<int>& vec, int idx);
  void makeHeap(std::vector<int>& vec);
  int size;
};

MaxHeap::MaxHeap(std::vector<std::vector<int>>& queries, int k) {
  size = k;
  for (int i = 0; i < size; ++i) { // O(k)
    vec.push_back(queries[i][0] + queries[i][1]);
  }
  makeHeap(vec);
}

void MaxHeap::heapify(std::vector<int>& vec, int idx) { // O(log k)
  int largest = idx;
  int left = idx * 2 + 1; // 0-based
  int right = idx * 2 + 2;

  if (left < vec.size() && vec[left] > vec[largest]) {
    largest = left;
  }
  if (right < vec.size() && vec[right] > vec[largest]) {
    largest = right;
  }
  if (largest != idx) {
    std::swap(vec[largest], vec[idx]);
    heapify(vec, largest);
  }
}

void MaxHeap::makeHeap(std::vector<int>& vec) { // O(k)
  for (int i = static_cast<int>((vec.size() - 1) / 2); i >= 0; --i) {
    heapify(vec, i);
  }
}

void MaxHeap::insert(int elem) {
  if (elem < vec[0]) {
    //Remove top element and insert new element from input array if current max is larger than this.
    vec[0] = elem; 
    heapify(vec, 0);
  }
}

std::vector<int> resultsArray(std::vector<std::vector<int>>& queries, int k) {
  // WRITE YOUR CODE
  std::vector<int> result;
  MaxHeap H = MaxHeap(queries, k);
  
  for (int i = 0; i < k; ++i) {
    result.push_back(-1);
  }
  
  for (int j = k; j < queries.size(); ++j) {
    H.insert(queries[j][0] + queries[j][1]);
    result.push_back(H.vec[0]);
  }
  
  return result;
}