#include <iostream>
#include <vector>

struct stuff {
  int weight;
  int value;
  stuff(int w, int v) : weight(w), value(v) {}
};

void sortByWeight(std::vector<stuff>& data) {
  // using insertionSort
  int n = data.size();
  for (int i = 1; i < n - 1; ++i) {
    stuff key = stuff(data[i].weight, data[i].value);
    int j = i - 1;
    while (j >= 0 && key.weight < data[j].weight) {
      data[j + 1] = data[j];
      --j;
    }
    data[j] = key;
  }
}

int searchMaxNum(std::vector<stuff> data) {
  // returns maximum number of data that can be used
  
}

int main() {
  std::vector<stuff> data;

  // getting input
  int n;
  int maxWeight;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    stuff elem = stuff(a, b);
    data.push_back(elem);
  }

  // processing data
  // sort by weight
  sortByWeight(data);

  // binary search method
  
}