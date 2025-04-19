#include <iostream>

using namespace std;


/*
문제 조건을 제대로 확인할 수 없었음
퍼센트 할인을 할 때 소수 부분을 어떻게 처리할 것인지..-> 반올림을 하는지, 정교하게 계산을 하는지
반올림같은 걸 하면 math 인클루드해서 floor쓰면 됨
정교하게 계산해야 한다면 class로 만들어 써야 함
*/
int main() {

  int N;
  int A; // threshold
  int B; // percent
  double sum = 0;
  int elem;


  int flo = B / 100;

  cin >> N >> A >> B;

  for (int i = 0; i < N; i++) {
    cin >> elem;
    if (elem < 2*A) {
      sum += elem * (1 - (B / 100));
    } else {
      double a_price = elem - A;
      double b_price = elem * (1 - (B / 100));
      if (a_price > b_price) {
        sum += a_price;
      } else {
        sum += b_price;
      }
    }
  }

  cout << sum << endl;
  return 0;
}