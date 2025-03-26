#include <iostream>
#include <string>

using namespace std;

class time_ {
  public:
  // variables
  int hour, minute, second;

  // 생성자 + string to time
  time_(string time_string) {
    hour = stoi(time_string.substr(0, 2));
    minute = stoi(time_string.substr(3, 2));
    second = stoi(time_string.substr(6, 2));
  }

  // time to string
  // 마지막에 답 낼 때 사용
  string time_to_string() {
    string time_string_result;

    string hour_string;
    string minute_string;
    string second_string;

    hour_string = to_string(hour);
    minute_string = to_string(minute);
    second_string = to_string(second);
    time_string_result = hour_string + ':' + minute_string + ':' + second_string;

    return time_string_result;
  }

  int compare(time_ time_start) {
    // compare
    // returns case number integer
    /*
    case 0) -> returns 0
    start와 now가 같은 경우
    즉 00:00:00이 답인 경우

    case 1) -> returns 양수 
    start-----(now)----(자정)-------start
    즉 24:00:00 - (now - start)를 해야 하는 경우

    case 2) -> returns 음수
    start-----(자정)------(now)-------start
    즉 start - now를 해야 하는 경우
    */
    int now_hour = hour;
    int now_min = minute;
    int now_sec = second;

    int start_hour = time_start.hour;
    int start_min = time_start.minute;
    int start_sec = time_start.minute;

    int compare_hour;
    int compare_min;
    int compare_sec;

    if (now_hour > start_hour) {
      compare_hour = 100;
    } else if (now_hour < start_hour) {
      compare_hour = -100;
    } else {
      compare_hour = 0;
    };

    if (now_min > start_min) {
      compare_min = 10;
    } else if (now_min < start_min) {
      compare_min = -10;
    } else {
      compare_min = 0;
    };

    if (now_sec > start_sec) {
      compare_sec = 1;
    } else if (now_sec < start_sec) {
      compare_sec = -1;
    } else {
      compare_sec = 0;
    };

    return compare_hour + compare_min + compare_sec;
  }

  // minus
  time_ minus(time_ down) {
    
  }
};


int main() {
  string start_string;
  string now_string;

  cin >> start_string;
  cin >> now_string;

  time_ start(start_string);
  time_ now(now_string);

  int compare = start.compare(now);
  

  if (compare >= 0) {
    int case_num = 1;
  } else {
    int case_num = 2;
  }

  return 0;
}