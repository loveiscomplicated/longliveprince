#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> sq;
  for (int i = 0; i < 100; i++) {
    sq.push_back(0);
  }
  
  int elem;
  int sum = 0;
  int result1 = 0;
  int result2 = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> elem;
      sq[elem - 1]++;
      if (sq[elem] == 50) {
        result1 = elem;
        break;
      }
      sum += elem; // all pixel sum
    }
    if (sq[elem] == 50) {
      break;
    }
  }

  if (result1 != 0) {
    cout << result1 << endl;
  } else {
    cout << sum / (N*N);
  }

  return 0;
}



  /*
    for (int i = 0; i < N; i++) {
    cin >> elem;
    sq[elem-1]++;
    if (sq[elem-1] == 50) {
      result1 = elem;
      break;
    }
    sum += elem; // all pixel sum
  }

  if (result1 != 0) {
    result2 = result1;
  } else {
    result2 = sum / (N*N);
  }
  
  cout << elem << endl;
  */
