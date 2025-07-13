#include <iostream>
#include <vector>
#include <algorithm> // swap 함수를 사용하기 위함

// 버블 정렬 함수
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();

    // 배열의 모든 원소를 한 번씩 비교하기 위한 외부 루프
    // 마지막 i개 원소는 이미 정렬되었으므로 n-1-i 까지만 비교
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false; // 이번 패스에서 원소 교환이 있었는지 확인하는 플래그

        // 인접한 원소들을 비교하고 교환하기 위한 내부 루프
        // j가 n-1-i까지 가는 이유는 마지막 i개 원소는 이미 정렬되었기 때문
        for (int j = 0; j < n - 1 - i; ++j) {
            // 현재 원소가 다음 원소보다 크면 (오름차순 정렬)
            if (arr[j] > arr[j + 1]) {
                // 두 원소의 위치를 바꾼다
                std::swap(arr[j], arr[j + 1]);
                swapped = true; // 교환이 발생했음을 기록
            }
        }

        // 만약 이번 패스에서 아무런 교환도 일어나지 않았다면
        // 배열이 이미 정렬되었다는 의미이므로 정렬을 중단한다.
        if (!swapped) {
            break;
        }

        std::cout << "패스 " << i + 1 << " 후: ";
        for (int k : arr) {
            std::cout << k << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> myVector = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "원래 배열: ";
    for (int x : myVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    bubbleSort(myVector);

    std::cout << "정렬된 배열: ";
    for (int x : myVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}