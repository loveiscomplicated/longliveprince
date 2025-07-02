#include "LinearSearch.h"

bool linearSearch(const std::vector<int>& arr, int target) {
    for (int x : arr) {
        if (x == target) {
            return true;
        }
    }
    return false;
}
