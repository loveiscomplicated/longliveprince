#include <iostream>

using namespace std;

int main() {
  char* arr = new char[10]();
  cout << "----" << endl;
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << endl;
    cout << '1' << endl;
  }
  return 0;
}