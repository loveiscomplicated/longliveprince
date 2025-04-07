#include <iostream>
#include <cmath>

using namespace std;



int main() {
  int temp;
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    cin >> temp;
    sum = sum + pow(temp, 2); 
  }
  int result = sum % 10;
  cout << result << endl;
}