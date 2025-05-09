#include <iostream>
#include <vector>

// Question 5: Find all duplicates in an array

int countDigits(int n) { // O(log10n) -- very small
  int count = 0;
  while (n != 0) {
    n = n / 10;
    ++count;
  }
  return count;
}

int getDigit(int n, int digit) {
  int pow = 1;
  while (digit > 0) {
    pow *= 10;
    --digit;
  }
  int result = (n / pow) % 10;
  return result;
}

void radixSort(std::vector<int>& nums) {
  std::vector<std::vector<int> > digit(10);

  int maxDigit = 1;
  for(int i = 0; i < nums.size(); ++i) { // O(N)
    if (maxDigit < countDigits(nums[i])) {
      maxDigit = countDigits(nums[i]);
    }
  }

  for(int i = 1; i <= maxDigit; ++i) {
    for (int iter = nums.size() - 1; iter >= 0; --iter) {
      int elem = nums[iter]; 
      nums.pop_back();
      int n = getDigit(elem, i); // get i-th digit, i goes from 1 to maxDigit
      switch (n) {
        case 0:
          digit[0].push_back(elem);
          break;
        case 1:
          digit[1].push_back(elem);
          break;
        case 2:
          digit[2].push_back(elem);
          break;
        case 3:
          digit[3].push_back(elem);
          break;
        case 4:
          digit[4].push_back(elem);
          break;
        case 5:
          digit[5].push_back(elem);
          break;
        case 6:
          digit[6].push_back(elem);
          break;
        case 7:
          digit[7].push_back(elem);
          break;
        case 8:
          digit[8].push_back(elem);
          break;
        case 9:
          digit[9].push_back(elem);
          break;
      }
    }

    for (int a = 0; a < 10; ++a) {
      if (digit[a].size()) {
        for (int b = digit[a].size() - 1; b >= 0; --b) {
          nums.push_back(digit[a][b]);
          digit[a].pop_back();
        }
      }
    }
  }
}

std::vector<int> findDuplicates(std::vector<int>& nums) {
  // WRITE YOUR CODE
  radixSort(nums);
  std::vector<int> result;
  std::vector<int>::iterator it_1 = nums.begin();
  std::vector<int>::iterator it_2 = nums.begin() + 1;
  
  while (it_2 != nums.end()) {
    if (*it_1 == *it_2) {
      result.push_back(*it_2);
    }
    it_1++;
    it_2++;
  }
}