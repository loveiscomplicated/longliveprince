#include <iostream>

int main() {
  int size;
  std::cin >> size;
  int max;
  int min;

  int input;
  std::cin >> input;

  max = input;
  min = input;

  for (int i = 0; i < size - 1; ++i) {
    std::cin >> input;
    if (max < input) {
      max = input;
    }
    if (min > input) {
      min = input;
    }
  }

  std::cout << min << ' ' << max << std::endl;
  return 0;
}