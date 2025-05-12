#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<int> addvec(vector<int>& vecA, vector<int>& vecB) {
  int sizeBig;
  int sizeSmall;
  bool AisBig; // True - vecA // False - vecB
  if (vecA.size() <= vecB.size()) {
    sizeBig = vecB.size();
    sizeSmall = vecA.size();
    AisBig = false;
  } else {
    sizeBig = vecA.size();
    sizeSmall = vecB.size();
    AisBig = true;
  }

  vector<int> result(sizeBig, 0);

  for (int i = 0; i < sizeSmall; ++i) {
    int x = vecA[i] + vecB[i];
    result[i] += x;
    
    result[i + 1] += result[i] - (result[i] % 10);
    result[i] %= 10;
  }

  for (int i = sizeSmall; i < sizeBig; ++i) {
    if (AisBig) {
      result[i] += vecA[i];
    } else {
      result[i] += vecB[i];
    }
  }
  
  return result;
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