#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct longNum {
  public:
  longNum();
  longNum(string numstr);
  vector<int> numVec;
  bool positive; // true: +, false: -
};

longNum::longNum() {
}

longNum::longNum(string numstr){
  if (numstr[0] == '-') {
    positive = false;
    for (int i = numstr.size() - 1; i >= 1; --i) {
      int number = numstr[i] - 48;
      numVec.push_back(number);
    }
  } else {
    positive = true;
    for (int i = numstr.size() - 1; i >= 0; --i) {
      int number = numstr[i] - 48;
      numVec.push_back(number);
    }
  }
}

vector<int> addAbs(longNum& numA, longNum& numB) {
  vector<int>& vecA = numA.numVec;
  vector<int>& vecB = numB.numVec;

  vector<int> result;
  for (int i = 0; i < vecB.size(); ++i) {
    result.push_back(vecA[i] + vecB[i]);
  }
  for (int i = vecB.size(); i < vecA.size(); ++i) {
    result.push_back(vecA[i]);
  }
  
  for (int i = 0; i < result.size() - 1; ++i) {
    if (result[i] >= 10) {
      int x10 = (result[i] - (result[i] % 10)) / 10;
      int x1 = result[i] % 10;

      result[i] = x1;
      result[i + 1] = x10;
    }
  }
  if (result[result.size() - 1] >= 10) {
    int lastidx = result.size() - 1;
    int x10 = (result[lastidx] - (result[lastidx] % 10)) / 10;
    int x1 = result[lastidx] % 10;

    result[lastidx] = x1;
    result.push_back(x10);
  }
  return result;
}
bool aIsBiggerThanAbs(longNum& numA, longNum& numB) {
  int sizeA = numA.numVec.size();
  int sizeB = numB.numVec.size();
  bool aIsBigger = true; // 같을 경우 numA가 크다고 반환
  if (sizeA > sizeB) {
    aIsBigger = true;
  } else if (sizeA < sizeB) {
    aIsBigger = false;
  }
  for (int i = sizeA - 1; i >= 0; --i) {
    if (numA.numVec[i] > numB.numVec[i]) {
      aIsBigger = true;
    } else if (numA.numVec[i] < numB.numVec[i]) {
      aIsBigger = false;
    } else {
      continue;
    }
  }
  return aIsBigger;
}

bool aIsBiggerThan(longNum& numA, longNum& numB) {
  bool result;
  if (numA.positive == numB.positive) {
    if (numA.positive == true) {
      result = aIsBiggerThanAbs(numA, numB);
    } else {
      result = !aIsBiggerThanAbs(numA, numB);
    }
  } else {
    if (numA.positive == true) {
      result = true;
    } else {
      result = false;
    }
  }
  return result;
}

vector<int> subtractAbs(longNum& numA, longNum& numB) {
  // assume that A >= B
  vector<int>& vecA = numA.numVec;
  vector<int>& vecB = numB.numVec;
  vector<int> result;
  for (int i = 0; i < vecB.size(); ++i) {
    result.push_back(vecA[i] - vecB[i]);
  }
  for (int i = vecB.size(); i < vecA.size(); ++i) {
    result.push_back(vecA[i]);
  }
  
  for (int i = 0; i < result.size(); ++i) {
    if (result[i] < 0) {
      result[i + 1]--;
      result[i] += 10;
    }
  }

  if (result.size() == 1 && result[0] == 0) {
    return result;
  }
  vector<int>::iterator iter = result.end() - 1;
  while (*iter == 0) {
    --iter;
    result.pop_back();
  }

  if (result.empty()) {
    result.push_back(0);
  }
  return result;
}


int main() {
  string A;
  string B;

  getline(cin, A);
  getline(cin, B);

  longNum numA;
  numA = longNum(A);

  longNum numB;
  numB = longNum(B);

  vector<int> result = subtractAbs(numA, numB);

  for (int i = result.size() - 1; i >= 0; --i) {
    cout << result[i];
  }
  cout << endl;


  return 0;
}