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

/*
std::vector<int> constructorVec(std::string num) {
  std::vector<int> resultVec;
  int numInt = std::stoi(num);
  for (int i = 0; i <= numInt; ++i) {
    resultVec.push_back(constructor(std::to_string(i)));
  }

  return resultVec;
}
*/


std::vector<int> constructorVec(int quotient) {
  std::vector<int> resultVec;
  for (int i = 0; i < 10; ++i) {
    resultVec.push_back(constructor(std::to_string(quotient*10 + i)));
  }
  return resultVec;
}

int find(std::string numStr) {
  int numInt = std::stoi(numStr);
  int quotient = (numInt - (numInt % 11)) / 11;
  quotient--;
  std::vector<int> compareVec = constructorVec(quotient);

  int result = 0;

  for (int i = 0; i < compareVec.size(); ++i) {
    if (numInt == compareVec[i]) {
      result = quotient*10 + i;
      break;
    }
  }

  if (result == 0) {
    quotient++;
    std::vector<int> compareVec2 = constructorVec(quotient);
    for (int i = 0; i < compareVec2.size(); ++i) {
      if (numInt == compareVec2[i]) {
        result = quotient*10 + i;
        break;
      }
    }    
  }

  return result;
}


int main() {
  std::string numStr;
  std::cin >> numStr;
  int result = find(numStr);
  std::cout << result << std::endl;
  return 0;
}