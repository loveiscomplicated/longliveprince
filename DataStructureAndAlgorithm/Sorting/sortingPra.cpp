#include <iostream>
#include <vector>
#include <algorithm>

void insertionSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >=0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

void selectionSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < n; ++j) {
      if (arr[min_idx] > arr[j]) {
        min_idx = j;
      }
    }
    std::swap(arr[min_idx], arr[i]);
  }
}

void heapify(std::vector<int>& arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[largest] < arr[left]) {
    largest = left;
  }
  if (right < n && arr[largest] < arr[right]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i >= 0; --i) {
    std::swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {

  std::vector<int> myVector = {64, 34, 25, 12, 22, 11, 90};
  std::cout << "정렬 전" << std::endl;
  for (int i = 0; i < myVector.size(); ++i) {
    std::cout << myVector[i] << ' ';
  }
  std::cout << std::endl;

  heapSort(myVector);

  std::cout << "정렬 후" << std::endl;
  for (int i = 0; i < myVector.size(); ++i) {
    std::cout << myVector[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}