#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// find current index of iterator
// distance(v.begin(), low);

// swaping value by iterator
// iter_swap(iter1, iter2)

void quickSort(vector<int> &v, vector<int>::iterator left, vector<int>::iterator right) {
  /*
  v: 정렬을 진행할 벡터
  pivotIter: 정렬이 이루어질 범위의 왼쪽 끝
  right: 정렬이 이루어질 범위의 오른쪽 끝


  1
  만약 left가 right보다 왼쪽에 있을 때

    (2-1)
    만약 left가 pivot보다 작거나 같다면
      ++left
    그렇지 않다면
      left stop
    left stop할 때까지 반복

    (2-2)
    만약 right가 pivot보다 크다면
      --right
    그렇지 않다면
      right stop
    right stop할 때까지 반복


    left와 right 둘 다 stop했다면
      left와 right swap
      다시 2-1부터 진행
    
  그렇지 않다면 right과 pivot을 swap
  */

  if (left >= right) {
    return; // Base case: return when the left index is greater than or equal to right index
  }

  vector<int>::iterator pivot = left;
  vector<int>::iterator i = left + 1;
  vector<int>::iterator j = right;
  while(i <= j) {
    while (i <= right && *i <= *pivot) {
      ++i;
    }
    while (j > left && *j > *pivot) {
      --j;
    }
    if (i < j) {
      iter_swap(i ,j);
    }
  }
  iter_swap(pivot, j);
  quickSort(v, left, j - 1);
  quickSort(v, j + 1, right);
}



int main() {

  // test case 1
  vector<int> v1 = {6,5,4,3,2,1};
  vector<int>::iterator pivot = v1.begin();
  vector<int>::iterator right = v1.end() - 1;
  quickSort(v1, pivot, right);
  
  for (int num : v1) {
    cout << num << endl;
  }
  return 0;
}