#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 버블 정렬을 사용해 사전순 정렬 구현
void dictSort(vector<string>& vec2) {
  for (int i = 0; i < vec2.size() - 1; ++i) {
    for (int j = 0; j < vec2.size() - i - 1; ++j) {
      if (vec2[j] > vec2[j + 1]) {
        swap(vec2[j], vec2[j + 1]);
      }
    }
  }
}

int main() {
  int num;
  cin >> num;
  vector<string> vec;

  for (int i = 0; i < num; ++i) {
    string a;
    cin >> a;
    vec.push_back(a);
  }

  // 길이순 정렬 (선택 정렬)
  for (int i = 0; i < num - 1; ++i) {
    int minSize = vec[i].size();
    int idx = i;
    for (int j = i + 1; j < num; ++j) {
      int strSize = vec[j].size();
      if (minSize > strSize) {
        minSize = strSize;
        idx = j;
      }
    }
    if (idx != i) {
      swap(vec[i], vec[idx]);
    }
  }

  vector<string> result;
  vector<string> vec2;

  vec2.push_back(vec[0]);
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i].size() == vec[i - 1].size()) {
      vec2.push_back(vec[i]);
    } else {
      dictSort(vec2); // 사전순 정렬
      result.insert(result.end(), vec2.begin(), vec2.end());
      vec2.clear();
      vec2.push_back(vec[i]);
    }
  }

  // 마지막 그룹 처리
  if (!vec2.empty()) {
    dictSort(vec2);
    result.insert(result.end(), vec2.begin(), vec2.end());
  }

  // 출력
  for (const string& str : result) {
    cout << str << endl;
  }

  return 0;
}
