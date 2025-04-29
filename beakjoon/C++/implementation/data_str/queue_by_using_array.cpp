/* needs to be tested!! */
#include <iostream>

using namespace std;

class queue {
  int* head;
  int* tail;
  int size; // the maximum size that queue can store
  int count; // how many elements are in the queue

  int* arr; // in order to maintain the memory even if the constructor function is quit.
  int* arrHead;
  int* arrTail;

  queue(int size1) {
    size = size1;

    arr = new int[size];
    for (int i = 0; i < size; i++) {
      arr[i] = 0; // initialize
    }

    head = &arr[0];
    tail = &arr[0];

    arrHead = &arr[0];
    arrTail = &arr[size - 1];
  }


  void push(int elem) {
    if (count == size) {
      cout << "the queue is fully occupied" << endl;
      return;
    }

    *tail = elem;
    if (tail == arrTail) {
      tail = arrHead;
    } else {
      tail++;
    }
    count++;
  }

  int pop() {
    if (count == 0) {
      cout << "the queue is empty. the returned value is meaningless" << endl;
      return -1;
    }
    int output = *head;
    if (head == arrTail) {
      head = arrHead;
    } else {
      head++;
    }
    return output;
  }

};

