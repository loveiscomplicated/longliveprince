#include <iostream>
#include <vector>
#include <algorithm>

int countDigits(int n) {
  int count = 0;
  while (n != 0) {
    n /= 10;
    ++count;
  }
  return count;
}

int getDigit(int n, int digit) {
  int pow = 1;
  while (digit > 1) {
    pow *= 10;
    --digit;
  }
  return (n / pow) % 10;
}

// Radix Sort
void radixSort(std::vector<int>& nums) {
  std::vector<std::vector<int>> digit(10);

  int maxDigit = 1;
  for (int n : nums) {
    maxDigit = std::max(maxDigit, countDigits(n));
  }

  for (int i = 1; i <= maxDigit; ++i) {
    std::vector<int> temp = nums;
    nums.clear();

    for (int iter = temp.size() - 1; iter >= 0; --iter) {
      int elem = temp[iter];
      int n = getDigit(elem, i);

      switch (n) {
        case 0: digit[0].push_back(elem); break;
        case 1: digit[1].push_back(elem); break;
        case 2: digit[2].push_back(elem); break;
        case 3: digit[3].push_back(elem); break;
        case 4: digit[4].push_back(elem); break;
        case 5: digit[5].push_back(elem); break;
        case 6: digit[6].push_back(elem); break;
        case 7: digit[7].push_back(elem); break;
        case 8: digit[8].push_back(elem); break;
        case 9: digit[9].push_back(elem); break;
      }
    }

    for (int d = 0; d < 10; ++d) {
      for (int val : digit[d]) {
        nums.push_back(val);
      }
      digit[d].clear();
    }
  }
}

std::vector<int> findDuplicates(std::vector<int>& nums) {
  radixSort(nums);
  std::vector<int> result;

  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] == nums[i - 1]) {
      if (result.empty() || result.back() != nums[i]) {
        result.push_back(nums[i]);
      }
    }
  }

  return result;
}
