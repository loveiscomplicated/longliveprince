#include <iostream>
#include <string>
#include <vector>

using namespace std;

// convert user input(string) to vector<int>
vector<int> convertStr(string num) {
  vector<int> result;
  for (int i = num.size() - 1; i >= 0; --i) {
    result.push_back(num[i] - '0');
  }
  return result;
}

// multiplication
vector<int> mul(vector<int> A, vector<int> B) {
  vector<int> result(A.size() + B.size(), 0);
  for (int i = 0; i < B.size(); ++i) {
    for (int j = 0; j < A.size(); ++j) {
      int temp = (A[j] * B[i]) + result[i + j];
      result[i + j] = temp % 10;
      result[i + j + 1] += temp / 10;
    }
  }

  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }
  return result;
}

// print vector<int> result into number format
void printlnln(vector<int> result) {
  for (int i = result.size() - 1; i >= 0; --i) {
    cout << result[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // getting user input by string
  string strA;
  string strB;
  cin >> strA >> strB;
  
  // convert user input(string) to vector<int>
  vector<int> a = convertStr(strA);
  vector<int> b = convertStr(strB);

  // multiplication
  vector<int> result = mul(a, b);

  // print the result
  printlnln(result);
  

  
  return 0;
}