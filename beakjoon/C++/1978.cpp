#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> prime() {
  std::vector<bool> resultVec(1001, true); //1-based, doesn't consider 0-th index
  resultVec[0] = false;
  resultVec[1] = false;
  for (int i = 2; i <= std::sqrt(1000); ++i) {
    if (resultVec[i] == false) {
      continue;
    }
    for (int j = i * i; j <= 1000; j += i) {
      resultVec[j] = false;
    }
  }
  return resultVec;
}


int main() {
  
  int size;
  std::cin >> size;
  
  int arr[size];
  for (int i = 0; i < size; ++i) {
    std::cin >> arr[i];
  }  
  
  std::vector<bool> primeVec = prime();

  int result = 0;
  
  for (int i = 0; i < size; ++i) {
    result += primeVec[arr[i]];
  }
  
  std::cout << result << std::endl;
  return 0;
}