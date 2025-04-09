#include <iostream>
#include <string>

using namespace std;

void underscore(int total, int now) {
  int k = total - now; // 이제 k만큼 "____"를 반복하면 됨
  for (int k = total - now; k > 0; k--) {
    cout << "____";
  }
}

void recur(int total, int n) {
  string a1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
  string a2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
  string a3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
  string a4 = "____\"재귀함수가 뭔가요?\"";
  string end = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
  string b = "라고 답변하였지.";
  

  if (n == 0) {
    underscore(total, n);
    cout << end << endl;
  } else {
    underscore(total, n); // total과 n이 계속 초기화되어서 underscore의 int k가 자꾸 0이 됨
    cout << a1 << endl;
    underscore(total, n);
    cout << a2 << endl;
    underscore(total, n);
    cout << a3 << endl;
    underscore(total, n);
    cout << a4 << endl;
    recur(total, n - 1);
    underscore(total, n - 1);
    cout << b << endl;
  }
}



int main() {
  int total;
  cin >> total;
  int n = total;
  string start = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n\"재귀함수가 뭔가요?\"";
  cout << start << endl;
  recur(total, n);
  cout << "라고 답변하였지." << endl;
  return 0;
}





