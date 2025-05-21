#include <iostream>
#include <string>
#include <vector>

// M의 분해합 => N
// N의 생성자 => M
/*
9 => 9 + 9 = 18 
99 => 18 + 99  = 117
999 => 27 + 999 = 1026
9999 => 10,035
99999 => 100.044
999999 => 1,000,053
1000000 => 1000001
*/
int constructor(std::string num) {
  int numInt = std::stoi(num);
  int result = numInt;
  for (int i = 0; i < num.size(); ++i) {
    result += num[i] - '0';
  }
  return result;
}

int find(std::string numStr) {
  int numInt = std::stoi(numStr);
  int start = numInt - 9 * numStr.length();
  
  int value = 0;

  for (int i = start; i < numInt; ++i) {
    if (constructor(std::to_string(i)) == numInt) {
      value = i;
      break;
    }
  }
  return value;
}


int main() {
  std::string numStr;
  std::cin >> numStr;
  int result = find(numStr);
  std::cout << result << std::endl;
  return 0;
}