#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void swap(vector<int> &v, int idx1, int idx2) {
  vector<int>::iterator iter1 = v.begin() + idx1;
  vector<int>::iterator iter2 = v.begin() + idx2;
  iter_swap(iter1, iter2);
}

void quickSort(vector<int> &v, int left, int right) {
  /*
  left: pivot 포함 가장 왼쪽 인덱스, 즉 pivot의 인덱스
  right: pivot이랑 비교할 가장 오른쪽 인덱스
  */
  if (left == right) 
  { 
    // 1개를 sort해야 하는 경우, 바로 리턴
    return;
  } else if ((left + 1) == right) {
    if (v[left] > v[right]) {
      // swap
      swap(v, left, right);
    }
    return;
  }
  
  int pivot = v[left];
  
  vector<int>::iterator iterLeft = v.begin() + left + 1;
  vector<int>::iterator iterRight = v.begin() + right;

  
  
  
  

}


int main() {
  return 0;
}