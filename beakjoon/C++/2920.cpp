#include <iostream>

using namespace std;



int main() {
  int arr[8];
  for (int i = 0; i < 8; i++) {
    int inpt;
    cin >> inpt;
    arr[i] = inpt; 
  }

  int check = 0;

  for (int i; i < 8; i++) {
    if ((i + 1) == arr[i]) {
      check++;
    } else if ((8 - i) == arr[i]) {
      check--;
    }
  }

  if (check == 8) {
    cout << "ascending" << endl;
  } else if (check == -8) {
    cout << "descending" << endl;
  } else {
    cout << "mixed" << endl;
  }
  return 0;
}