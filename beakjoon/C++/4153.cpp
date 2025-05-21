#include <iostream>

bool val(int a, int b, int c) {
  if (a == 0 && b == 0 && c == 0) {
    return false;
  }

  int max = a;
  int s1 = b;
  int s2 = c;

  if (max < b) {
    max = b;
    s1 = a;
    s2 = c;
  }
  if (max < c) {
    max = c;
    s1 = a;
    s2 = b;
  }
  
  int bit = max * max;
  int bit2 = s1*s1 + s2*s2;
  if (bit == bit2) {
    std::cout << "right" << std::endl;
  } else {
    std::cout << "wrong" << std::endl;
  }
  return true;
}

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  bool running = val(a, b, c);

  while (running) {
    std::cin >> a >> b >> c;
    running = val(a, b, c);
  }
  return 0;
}