#include <iostream>
#include <string>

using namespace std;

struct mydata {
  string name;
  int day;
  int month;
  int year;
  int days;
};

int day_live(mydata person) {
  // 2020년 기준으로 할 때 살아온 날짜의 수
  int days = 365*(2020 - person.year + 1) + 30*(12 - person.month) + 31 - person.day;
  return days;
}

int main() {
  int num_case;
  cin >> num_case;

  mydata arr[num_case];

  for (int i = 0; i < num_case; i++) {
    cin >> arr[i].name >> arr[i].day >> arr[i].month >> arr[i].year;
  }

  for (int i = 0; i < num_case; i++) {
    arr[i].days = day_live(arr[i]);
  }


  int young = 0;

  for (int i = 0; i < num_case; i++) {
    if (arr[young].days > arr[i].days) {
      young = i;
    }
  }
  
  int old = 0;

  for (int i = 0; i < num_case; i++) {
    if (arr[old].days < arr[i].days) {
      old = i;
    }
  }

  cout << arr[young].name << endl;
  cout << arr[old].name << endl;

  return 0;
}