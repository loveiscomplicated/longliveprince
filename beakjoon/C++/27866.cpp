#include <iostream>
#include <string>

int main() {
  std::string input;
  std::cin >> input;
  int idx;
  std::cin >> idx;
  std::cout << input[idx - 1] << std::endl;
  return 0;
}