#include "CountingSort.h"
#include <algorithm> // For std::max_element

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = arr[0];
    for (int x : arr) {
        if (x > max_val) {
            max_val = x;
        }
    }

    std::vector<int> count(max_val + 1, 0);
    for (int x : arr) {
        count[x]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}
