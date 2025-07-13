#include "InsertionSort.h"
#include <iostream>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// 삽입 정렬 함수
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    // 두 번째 원소부터 시작 (첫 번째 원소는 이미 정렬된 것으로 간주)
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // 현재 삽입할 원소 (key)
        int j = i - 1;    // key를 비교할 정렬된 부분의 마지막 인덱스

        // key보다 큰 원소들을 오른쪽으로 한 칸씩 이동
        // j가 0보다 크거나 같고, key보다 arr[j]가 크다면 계속 반복
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // 현재 arr[j]를 한 칸 오른쪽(j+1)으로 이동
            j = j - 1;           // 다음 비교를 위해 j를 감소
        }
        arr[j + 1] = key; // key 값을 올바른 위치에 삽입

        // 각 단계별 정렬 과정 출력 (선택 사항)
        std::cout << "Step " << i << " : ";
        for (int k : arr) {
            std::cout << k << " ";
        }
        std::cout << std::endl;
    }
}

int main() {

  std::vector<int> myVector = {64, 34, 25, 12, 22, 11, 90};
  std::cout << "정렬 전" << std::endl;
  for (int i = 0; i < myVector.size(); ++i) {
    std::cout << myVector[i] << ' ';
  }
  std::cout << std::endl;

  insertionSort(myVector);

  std::cout << "정렬 후" << std::endl;
  for (int i = 0; i < myVector.size(); ++i) {
    std::cout << myVector[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}