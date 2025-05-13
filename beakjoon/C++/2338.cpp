#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<int> addvec(vector<int>& vecA, vector<int>& vecB) {
  //assume that vecA is bigger than vecB
  vector<int> result(vecA.size() + 1, 0);
  for (int i = 0; i < vecB.size(); ++i) {
    result[i] += vecA[i] + vecB[i];
  }

  for (int i = vecB.size(); i < vecA.size(); ++i) {
    result[i] += vecA[i];
  }

  for (int i = 0; i < vecA.size(); ++i) {
    if (result[i] >= 10) {
      result[i + 1] = (result[i] - (result[i] % 10)) / 10;
      result[i] = result[i] % 10;
    }
  }
  vector<int> new_result;
  for (int i = result.size() - 1; i >= 0; --i) {
    new_result.push_back(result[i]);
  }
  return new_result;
}


int main() {
  string A;
  string B;

  getline(cin, A);
  getline(cin, B);

  vector<int> vecA;
  vector<int> vecB;
  
  for (int i = A.size() - 1; i >= 0; --i) {
    vecA.push_back((int)(A[i]) - 48);
  }

  for (int i = B.size() - 1; i >= 0; --i) {
    vecB.push_back((int)(B[i]) - 48);
  }

  vector<int> result = addvec(vecA, vecB);

  for (int i : result) {
    cout << i;
  }
  cout << endl;
  return 0;
}