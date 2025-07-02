#include <iostream>
#include <vector>

using namespace std;  

int main() {
  vector<int> stdd = {1, 1, 2, 2, 2, 8};

  for (int i = 0; i < stdd.size(); ++i) {
    int a;
    cin >> a;
    cout << stdd[i] - a << ' ';
  }
  cout << endl;
  return 0;
}