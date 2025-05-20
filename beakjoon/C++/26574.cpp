#include <iostream>

using namespace std;

int main() {
  int num;
  cin >> num;

  int arr[num];

  for (int i = 0; i < num; ++i) {
    cin >> arr[i];
  }

  for (int i : arr) {
    cout << i << ' ' << i << endl;
  }

  return 0;
}