#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class cal {
  public:
  cal(int a, int b) { // 생성자
    string strA = to_string(a);
    string strB = to_string(b);

    for (int i = strA.size(); i >= 0; i--) {
      vecA.push_back(int(strA[i]) - 48);
    }

    for (int i = strB.size(); i >= 0; i--) {
      vecA.push_back(int(strB[i]) - 48);
    }
  }

  vector<int> calMulti() { // 곱하기
    vector<int> result;
    for (int i = 0; i < 35; i++) { // 벡터 초기화
      result.push_back(0);
    }

    int partialSum = 0;
 
    for (int b = 0; b < vecB.size(); b++) {
      for (int a = 0; a < vecA.size(); a++) {
        partialSum += vecA[a]*vecB[b];
      }
      if (partialSum < 10) {
        result[b] += partialSum;
      }
    }


    return result;
  }

  vector<int> calDiv() { // 나누기
    vector<int> result;
    for (int i = 0; i < 35; i++) { // 벡터 초기화
      result.push_back(0);
    }


    return result;
  }


  vector<int> vecA;
  vector<int> vecB;
};


unsigned long long factorial(int a) {
  while (true) {
    if (a == 0) {
      return 1;
    } else {
      return a * factorial(a - 1);
    }
  }
}





int main() {
  /*
  // input 받기
  int T;
  cin >> T;
  int n;
  int m;
  for (int i = 0; i < T; i++) {
    cin >> n >> m;
  }
  */

  for (int i = 0; i < 30; i++) {
    cout << i << ' ' << factorial(i) / 1000 << endl;
  }

  
  
  
  
  return 0;
}