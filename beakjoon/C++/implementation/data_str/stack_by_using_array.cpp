#include <iostream>

using namespace std;

class stack {
  public:
    int* head;


    stack(int size) {
      arr = new int(size);
      head = &arr[0];
      arrHead = &arr[0];
      arrTail = &arr[size - 1];
    }

    bool isEmpty() {
      if (head == arrHead) {
        return true;
      } else {
        return false;
      }
    }

    bool isFull() {
      if (head == arrTail) {
        return true;
      } else {
        return false;
      }
    }

    void push(int elem) {
      if (isFull() == true) {
        cout << "the stack is full, we cannot push the element" << endl;
        throw runtime_error("stackFullError");
        return;
      }
      ++head;
      *head = elem;
    }

    int pop() {
      if (isEmpty() == true) {
        cout << "the stack is empty, we cannot pop any element" << endl;
        throw runtime_error("stackEmptyError");
      }
      int temp = *head;
      --head;
      return temp;
    }

  private:
    int* arr;
    int* arrHead;
    int* arrTail;
};


int main() {
  
  return 0;
}