#include <iostream>
#include <string>

using namespace std;

int main() {
  int num;
  cin >> num;
  int a;
  string b;
  for (int i = 0; i < num; ++i) {
    cin >> a >> b;
    string result;
    for (int j = 0; j < b.size(); ++j) {
      for (int k = 0; k < a; ++ k) {
        result.push_back(b[j]);
      }
    }
    cout << result << endl;
  }
  
  return 0;
}