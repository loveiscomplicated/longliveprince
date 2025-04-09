#include <iostream>

using namespace std;

int factorial(int n) {

  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}


int GCD(int a, int b) {
  int big;
  int small;
  if (a > b) {
    big = a;
    small = b;
  } else {
  big = b;
  small = a;
  }

  if (big % small == 0) {
    return small;
  } else {
    
  }

}
int main() {
  cout << factorial(5) << endl;
  return 0;
}