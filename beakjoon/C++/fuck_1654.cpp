#include <iostream>
#include <vector>

int getN (std::vector<int> vec, int mid) {
  int result = 0;
  for (int i = 0; i < vec.size(); ++i) {
    int elem = vec[i] / mid;
    result += elem;
  }
  return result;
}

int BSearch(std::vector<int> vec, int n, int max) {
  int min = 1;
  int result = 0;
  while (min <= max) {
    int mid = (min + max) / 2;
    int count = getN(vec, mid);

    if (count >= n) {
      result = mid;
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }

  return result;
}


int main() {
  int k, n;
  std::cin >> k >> n;

  int max = 0;
  std::vector<int> vec;
  for (int i = 0; i < k; ++i) {
    int elem;
    std::cin >> elem;
    vec.push_back(elem);

    // find max
    if (max < elem) {
      max = elem;
    }
  }

  int result = BSearch(vec, n, max);
  std::cout << result << std::endl;
  
  return 0;
}