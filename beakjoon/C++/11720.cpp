#include <iostream>
#include <string>

int main() {
  int size;
  std::cin >> size;

  std::string numStr;

  std::cin >> numStr;

  int sum = 0;

  for (int i = 0; i < size; ++i) {
    int a = (int)numStr[i] - 48;
    sum += a;
  }

  std::cout << sum << std::endl;
  return 0;
}