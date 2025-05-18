#include <iostream>


int main() {
  int max;
  int a;
  int idx = 1;

  std::cin >> a;
  max = a;

  for (int i = 0; i < 8; ++i) {
    int b;
    std::cin >> b;
    if (max < b) {
      max = b;
      idx = i + 2;
    }
  }

  std::cout << max << std::endl;
  std::cout << idx << std::endl;
  return 0;
}
