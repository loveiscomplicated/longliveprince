#include <iostream>
#include <string>
#include <vector>

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

class calculatorLong {
  public:
    bool aIsBiggerThanAbs(longNum& numA, longNum& numB);
    vector<int> addAbs(longNum& numA, longNum& numB);
    vector<int> subtractAbs(string& A, string& B); // A - B
    vector<int> multiplyAbs(longNum& numA, longNum& numB);

    bool aIsBiggerThan(longNum& numA, longNum& numB);
    void add(string& A, string& B);
    void subtract(string& A, string& B); // A - B
    void multiply(string& A, string& B);
    
    
};


void calculatorLong::add(string& A, string& B) {
  longNum numA;
  numA = longNum(A);

  longNum numB;
  numB = longNum(B);

  longNum result;
  if (numA.positive != numB.positive) {
    if (numA.positive == true && numB.positive == false) {
      if (aIsBiggerThanAbs(numA, numB)) {
        result.numVec = subtractAbs(A, B);
        result.positive = true;
      } else {
        result.numVec = subtractAbs(A, B);
        result.positive = false;
      }
    } else if (numA.positive == false && numB.positive == true) {
      if (aIsBiggerThanAbs(numA, numB)) {
        result.numVec = subtractAbs(A, B);
        result.positive = false;
      } else {
        result.numVec = subtractAbs(A, B);
        result.positive = true;
      }
    }
  } else {
    result.positive = numA.positive;
    result.numVec = addAbs(numA, numB);
  }

  if (result.numVec.size() == 1 && result.numVec[0] == 0) {
    cout << '0' << endl;
    return;
  }

  if (result.positive == false) {
    cout << '-';
  }
  for (int i = result.numVec.size() - 1; i >=0; --i) {
    cout << result.numVec[i];
  }
  cout << endl;
  return;
}

void calculatorLong::subtract(string& A, string& B) { // A - B
  longNum numA;
  numA = longNum(A);

  longNum numB;
  numB = longNum(B);

  longNum result;
  if (numA.positive == true && numB.positive == false) {
    result.positive = true;
    result.numVec = addAbs(numA, numB);
  } else if (numA.positive == false && numB.positive == true) {
    result.positive = false;
    result.numVec = addAbs(numA, numB);
  } else if (numA.positive == true && numB.positive == true) {
    if (aIsBiggerThanAbs(numA, numB)) {
      result.positive = true;
      result.numVec = subtractAbs(A, B);
    } else {
      result.positive = false;
      result.numVec = subtractAbs(B, A);
    }
  } else if (numA.positive == false && numB.positive == false) {
    if (aIsBiggerThanAbs(numA, numB)) {
      result.positive = false;
      result.numVec = subtractAbs(A, B);
    } else {
      result.positive = true;
      result.numVec = subtractAbs(B, A);
    }
  }
  
  if (result.positive == false) {
    cout << '-';
  }
  for (int i = result.numVec.size() - 1; i >=0; --i) {
    cout << result.numVec[i];
  }
  cout << endl;
}

void calculatorLong::multiply(string& A, string& B) {
  longNum numA;
  numA = longNum(A);

  longNum numB;
  numB = longNum(B);

  longNum result;
  if (numA.positive == numB.positive) {
    result.positive = true;
  } else {
    result.positive = false;
  }
  result.numVec = multiplyAbs(numA, numB);

  if (result.positive == false) {
    cout << '-';
  }
  for (int i = result.numVec.size() - 1; i >=0; --i) {
    cout << result.numVec[i];
  }
  cout << endl;
}

bool calculatorLong::aIsBiggerThanAbs(longNum& numA, longNum& numB) {
  int sizeA = numA.numVec.size();
  int sizeB = numB.numVec.size();
  bool aIsBigger = true; // 같을 경우 numA가 크다고 반환
  if (sizeA > sizeB) {
    return true;
  } else if (sizeA < sizeB) {
    return false;
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

bool calculatorLong::aIsBiggerThan(longNum& numA, longNum& numB) {
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

vector<int> calculatorLong::addAbs(longNum& numA, longNum& numB) {
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
      result[i + 1] += x10;
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

vector<int> calculatorLong::subtractAbs(string& A, string& B) {
  // assume that A >= B
  longNum numA;
  numA = longNum(A);
  longNum numB;
  numB = longNum(B);

  vector<int>& vecA = numA.numVec;
  vector<int>& vecB = numB.numVec;
  vector<int> result;
  if (vecA.size() == vecB.size()) {
    bool eq = true;
    for (int i = 0; i < vecA.size(); ++i) {
      if (vecA[i] != vecB[i]) {
        eq = false;
      }
    }
    if (eq) {
      result.push_back(0);
      return result;
    }
  }
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

vector<int> calculatorLong::multiplyAbs(longNum& numA, longNum& numB) {
  vector<int>& vecA = numA.numVec;
  vector<int>& vecB = numB.numVec;
  vector<vector<int> > result(vecB.size());

  for (int i = 0; i < vecB.size(); ++i) {
    for (int j = 0; j < vecA.size(); ++j) {
      result[i].push_back(vecA[j] * vecB[i]);
    }
    for (int k = 0; k < result[i].size() - 1; ++k) {
      if (result[i][k] >= 10) {
        int x = result[i][k];
        int x1 = x % 10;
        int x10 = (x - (x % 10)) / 10;
        result[i][k] = x1;
        result[i][k + 1] = x10;
      }
    }

    if (result[i][result[i].size() - 1] >= 10) {
      int y = result[i][result[i].size() - 1];
      int y1 = y % 10;
      int y10 = (y - (y % 10)) / 10;
      result[i][result[i].size() - 1] = y1;
      result[i].push_back(y10);
    }
  }

  vector<int> result2;

  for (int i = 0; i < result.size(); ++i) {
    if (i == 0) {
      for (int j = 0; j < result[i].size(); ++j) {
        result2.push_back(result[i][j]);
      }
    } else {
      for (int j = 0; j < result[i].size(); ++j) {
        if (j == result[j].size() - 1) {
          result2.push_back(result[i][j]);
        } else {
          result[i][j] += result[i][j];
        }
      }
    }
  }

  for (int i = 0; i < result2.size() - 1; ++i) {
    if (result2[i] >= 10) {
      int z = result2[i];
      int z1 = z % 10;
      int z10 = (z - z % 10) / 10;
      result2[i] = z1;
      result2[i + 1] += z10;
    }
  }

  if (result2[result2.size() - 1] >= 10) {
    int w = result2[result2.size() - 1];
    int w1 = w % 10;
    int w10 = (w - w % 10) / 10;
    result2[result2.size() - 1] = w1;
    result2.push_back(w10);
  }

  return result2;
}

int main() {
  bool running = true;

  while (running) {
    string A;
    string B;

    getline(cin, A);
    getline(cin, B);

    if (A[0] == 'p') {
      running = false;
      break;
    }
    longNum numA;
    numA = longNum(A);

    longNum numB;
    numB = longNum(B);
    
    calculatorLong cal;

    cout << A << " add " << B << ": ";
    cal.add(A, B);
    cout << A << " sub " << B << ": ";
    cal.subtract(A, B);
    cout << A << " mul " << B << ": ";
    cal.multiply(A, B);
  }

  

  return 0;
}