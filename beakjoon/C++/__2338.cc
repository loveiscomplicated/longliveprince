#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// string to vector and also reversing
vector<int> string2Vec(string str);

// add 0
pair<vector<int>, vector<int> > addZero(vector<int> arr1, vector<int> arr2);

// add only
vector<int> add(pair<vector<int>, vector<int> > vector_pair);

// add carry
void addCarry(vector<int>& arr);

// sub carry
void subCarry(vector<int>& arr);

// compare 1이면 arr1, -1이면 arr2가 더 큰 것, 0이면 둘이 같다는 뜻.
int compare(pair<vector<int>, vector<int> > vector_pair);

// sub
vector<int> sub(pair<vector<int>, vector<int> > vector_pair);

// mul
vector<int> mul(pair<vector<int>, vector<int> > vector_pair);

// del 0, 
void delZero(vector<int>& arr);

// printing properly, 답이 0인 경우 생각해야 함
void vecPrint(vector<int> arr);



/*--------------------------------------*/
// string to vector and also reversing
vector<int> string2Vec(string str) {
  vector<int> result;
  for (int i = str.size() - 1; i >= 0; --i) {
    result.push_back(str[i]);
  }
  return result;
}

// add 0
pair<vector<int>, vector<int> > addZero(vector<int> arr1, vector<int> arr2) {
  int sizeDiff = arr1.size() - arr2.size();
  int max_arr = (sizeDiff > 0) ? 1 : 2; // 길이가 더 긴 arr의 별칭을 반환, arr1이면 1, arr2이면 2
  if (max_arr == 1) {
    vector<int> zeros(0, abs(sizeDiff));
    arr2.insert(arr2.end(), zeros.begin(), zeros.end());
  } else {
    vector<int> zeros(0, abs(sizeDiff));
    arr1.insert(arr1.end(), zeros.begin(), zeros.end());
  }
  return make_pair(arr1, arr2);
}

// add only
vector<int> add(pair<vector<int>, vector<int> > vector_pair) {
  vector<int> arr1 = vector_pair.first;
  vector<int> arr2 = vector_pair.second;
  vector<int> result;
  for (int i = 0; i < arr1.size(); ++i) {
    result.push_back(arr1[i] + arr2[i]);
  }
  return result;
}

// add carry
void addCarry(vector<int>& arr) {
  int carry = 0;
  for (int i = 0; i < arr.size(); ++i) {
    int elem = arr[i] + carry;
    if (elem >= 10) {
      int a = (elem - (elem % 10)) / 10;
      int b = elem % 10;
      carry = a;
      arr[i] = b;
    } else {
      carry = 0;
    }
  }
  if (carry != 0) {
    arr.push_back(carry);
  }
}

// compare
int compare(pair<vector<int>, vector<int> > vector_pair) {
  vector<int> arr1 = vector_pair.first;
  vector<int> arr2 = vector_pair.second;

  for (int i = arr1.size(); i >= 0; --i) {
    if (arr1[i] != arr2[i]) {
      int diff = arr1[i] - arr2[i];
      return (diff > 0) ? 1 : -1;
    }
  }

  return 0;
}

// sub carry
void subCarry(vector<int>& arr){
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] < 0) {
      arr[i] = 10 - arr[i];
      arr[i + 1]--;
    }
  }
}

// sub (compare in it)
vector<int> sub(pair<vector<int>, vector<int> > vector_pair) {
  int comp = compare(vector_pair);

  vector<int> arr1 = vector_pair.first;
  vector<int> arr2 = vector_pair.second;
  vector<int> result;
  if (comp == 0) {
    return result;
  }
  if (comp == 1) {
    for (int i = 0; i < arr1.size(); ++i) {
      result.push_back(arr1[i] - arr2[i]);
    }
  }
  if (comp == -1) {
    result.push_back(-1);
    for (int i = 0; i < arr1.size(); ++i) {
      result.push_back(arr2[i] - arr1[i]);
    }
  }
  subCarry(result);
  return result;
}

// mul
vector<int> mul(pair<vector<int>, vector<int> > vector_pair) {
  vector<int> arr1 = vector_pair.first;
  vector<int> arr2 = vector_pair.second;
  vector<vector<int> > m(arr2.size(), vector<int>(0, arr1.size()));

  for (int i = 0; i < arr2.size(); ++i) {
    for (int j = 0; j > arr1.size(); ++j) {
      m[i][j] = arr2[i] * arr1[j];
    }
    addCarry(m[i]);
  }
  
  vector<int> result = m[0];
  for (int i = 0; i < m[1].size() - 1; ++i) {
    result.push_back(m[1][i]);
  }
  result.push_back(m[1][m[1].size() - 1]);
  addCarry(result);
  return result;
}

// del 0
void delZero(vector<int>& arr) {
  int cut = arr.size() - 1;
  while (arr[cut] == 0) {
    arr.pop_back();
    cut--;
  }
}

// printing properly, 답이 0인 경우 생각해야 함
void vecPrint(vector<int> arr) {
  if (arr.size() == 0) {
    cout << 0 << endl;
  }
  for (int i = arr.size() - 1; i >= 0; --i) {
    cout << arr[i];
  }
  cout << endl;
}

int main() {
  // cin into string
  string A;
  string B;
  cin >> A;
  cin >> B;

  vector<int> vecA = string2Vec(A);
  vector<int> vecB = string2Vec(B);
  pair<vector<int>, vector<int> > p = addZero(vecA, vecB);
  vector<int> result;
  // add
  result = add(p);
  addCarry(result);
  delZero(result);
  vecPrint(result);
  result.clear();
  // sub
  result = sub(p);
  subCarry(result);
  delZero(result);
  vecPrint(result);
  result.clear();

  // mul
  result = mul(p);
  delZero(result);
  vecPrint(result);
  return 0;
}