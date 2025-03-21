#include <iostream>
#include <string>

using namespace std;

struct time_ {
  int h;
  int m;
  int s;
};

time_ string_to_time(string string_time) {
  time_ time1;

  time1.h = stoi(string_time.substr(0, 2));
  time1.m = stoi(string_time.substr(3, 2));
  time1.s = stoi(string_time.substr(6, 2));

  return time1;
}

string time_to_string(time_ input_t) {
  string h = to_string(input_t.h);
  string m = to_string(input_t.m);
  string s = to_string(input_t.s);
  string result = h + m + s;
  return result;
}

  /*
  빼기 함수만 만들어서 문제를 풀면 됨 (잘못 생각하면 더하기 함수를 만들어야 함)
  |-----------------------------(자정)------------------------|
  이라고 했을 때
  case 1) 자정 전
  case 2) 자정 후 라고 하자

  case 1) 이면 24:00:00 - (now - start)
  case 2) 이면 start - now
  이렇게 계산하면 됨

  시간 숫자만 놓고 봤을 때 
  now > start 이면 case 1
  now < start 이면 case 2

  그럼 이제부터 해야 할 것은
  0. 시간 구조체 만들기
  1. 문자열을 구조체로 변환하는 함수 (input 받을 때 코드가 더러워지지 않도록)
  2. 구조체를 문자열로 변환하는 함수 (cout할 때 코드가 더러워지지 않도록)
  3. 시간 비교 함수
  4. 빼기 함수
  */

int compare_time(time_ now, time_ start) {

  if (now.h > start.h) {
    return 1;
  } else if (now.h < start.h) {
    return 2;
  } else {
    if (now.m > start.h) {
      return 1;
    } else if (now.m < start.h) {
      return 2;
    } else {
      if (now.s > start.s) {
        return 1;
      } else if (now.s < start.s) {
        return 2;
      } else {
        return 0;
      }
    }
  }
}

/*
minus 함수 case 정리
위에서 아래로 뺀다고 했을 때,

1. 위의 초가 딸림 + 분도 딸림
2. 위의 초가 딸림 + 분은 안 딸림
3. 위의 초는 안 딸림 + 분은 딸림
4. 위의 초는 안 딸림 + 분도 안 딸림
*/

time_ minus_1(time_ up, time_ down) {
  time_ result;
  if (up.s < down.s) {
    up.m--;
    result.s = 60 + up.s - down.s;
    // 이제부터 분 계산
    if (up.m < down.m) {
      result.h = up.h - 1 - down.h;
      result.m = 60 + up.m - down.m;
    } else {
      result.h = up.h - down.h;
      result.m = up.m - down.m;
    }
    
  } else {
    result.s = up.s - down.s;
    if (up.m < down.m) {
      result.h = up.h - 1 - down.h;
      result.m = 60 + up.m - down.m;
    } else {
      result.h = up.h - down.h;
      result.m = up.m - down.m;
    }
  }
  return result;
}

int main() {
  string now_string;
  string start_string;

  cin >> now_string;
  cin >> start_string;

  time_ now = string_to_time(now_string);
  time_ start = string_to_time(start_string);

  int case_num = compare_time(now, start);

  switch (case_num) {
    case 0:
      cout << "00:00:00" << endl;
      break;

    case 1:
      time_ gap_1 = minus_1(now, start);
      time_ gap_2 = minus_1(string_to_time("23:59:59"), gap_1);
      cout << time_to_string(gap_2) << endl;
      break;

    case 2:
      time_ gap_3 = minus_1(start, now);
      cout << time_to_string(gap_3) << endl;
      break;
  }
  return 0;
}