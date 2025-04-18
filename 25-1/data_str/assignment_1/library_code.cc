// library_code.cc

#include <iostream>
#include <vector>


// Question 7: Linked List Implementation
struct Node {
    int val;
    Node* next;
};


class MyLinkedList {
    public:
        MyLinkedList() {
            head = nullptr;
            size = 0;
        }
        
        // find a node
        Node* findByPtr(int index) {
            if ((index < 0) || (index >= size)) {
                return nullptr;
            } else {
                Node* tempiter = head;
                for (int i = 0; i < index; i++) {
                    tempiter = tempiter -> next;
                }
                return tempiter;
            }
        }

        int get(int index) {
            // TODO: Implement
            if ((index < 0) || (index > size - 1)) {
                return -1;
            } else {
                return findByPtr(index)->val;
            }
        }
        
        void addAtHead(int val) {
            // TODO: Implement
            Node* NewNodeptr =  new Node; // create a new node
            NewNodeptr->val = val; // assign the value of new node
            NewNodeptr->next = head; // the next node has to be the previous head node
            head = NewNodeptr; // updating the head pointer pointing to new node
            size++; // updating the list size
        }
        
        void addAtTail(int val) {
            // TODO: Implement
            Node* NewNodeptr =  new Node; // create a new node
            NewNodeptr->val = val; // assign the value of new node
            NewNodeptr->next = nullptr;

            if (head == nullptr) {
                head = NewNodeptr;

            } else {
                Node* tempIter = head;
                for (int i = 0; i < (size - 1); i++) {
                    tempIter = tempIter->next;
                }
                tempIter->next = NewNodeptr;
            }
            size++;
        }
        
        void addAtIndex(int index, int val) {
            // TODO: Implement
            if (index == 0) { 
                addAtHead(val);
            } else if (index == size) {
                addAtTail(val);
            } else if ((index < 0) || (index > size)) {
                return;
            } else {
                Node* NewNodeptr =  new Node;
                NewNodeptr->next = findByPtr(index);
                NewNodeptr->val = val;
            
                findByPtr(index - 1)->next = NewNodeptr;
                size++;
            }
        }
        
        void deleteAtIndex(int index) {
            // TODO: Implement
            if ((index < 0) || (index >= size)) {
                return;
            } else if (index == 0) {
                Node* tempHead = head;
                head = head->next;
                delete tempHead;
                size--;
            } else {
                Node* tempPtr1 = findByPtr(index - 1);
                Node* tempPtr2 = findByPtr(index);
                Node* tempPtr3 = findByPtr(index + 1);
                
                tempPtr1->next = tempPtr3;
                delete tempPtr2;
                size--;
            }
        }
    
    private:
        Node* head;
        int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */



// Question 8: kth character after operations
char kthCharacter(long long k, std::vector<int>& operations) {
    // TODO: Implement
      int changes = 0; // shows how many does 'a' have to change
      long long length = power2(operations.size());
  
      while (!operations.empty()) {
          length /= 2;
          int elem = getBackAndPop(operations);
          char whichPart = frontOrBack(k, length * 2);
  
          if ((elem == 1) && (whichPart == 'b')) {
              changes++;
          }
  
          long long threshold = length / 2;
          if (k > threshold) {
              k -= threshold;
          }
      }
  
      // lower case alphabet : 97 ~ 122 in ascii code
      changes = 97 + (changes % 26);
      char resultChar = (char)changes;
    return resultChar;
  }
  
  char frontOrBack(long long k, long long length) {
      // k : kth
      // length : length of the string
      length /= 2;
      if (k <= length) {
          return 'f';
      } else {
          return 'b';
      }
  }
  
  int getBackAndPop(std::vector<int>& vec) {
      if (!vec.empty()) {
          int back = vec.back();	
          vec.pop_back();
          return back;
      } else {
          return -1; // error sign
      }
  }
  
  long long power2(int exp) {
      long long result = 1;
      long long base = 2;
  
      while (exp > 0) {
          if (exp % 2 == 1) {
              result *= base;
              exp--;
          } else {
              base *= 2;
              exp /= 2;
          }
      }
      return result;
  }

  
// Question 9: Median of two sorted arrays
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // TODO: Implement
    return 0.0;
}

// Question 10: Reverse linked list k nodes
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    
ListNode* reverseKGroup(ListNode* head, int k) {
    // TODO: Implement  
    if (k == 1) return head;

    ListNode* pointer = head;
    int index = 0;

    std::vector<ListNode*> slidingWindow(k);    // sliding window 생성하기

    ListNode* start = nullptr; // 이전 sliding window에서의 처음, 마지막 elem 기억하기
    ListNode* end = nullptr;


    while (true) { // iterator가 순회하다 끝에 도달하면 종료
        int count = 0;

        for (int i = 0; i < k; i++) { //슬라이딩 윈도우 초기화하기
            slidingWindow[i] = nullptr;
        }

        for (int i = 0; i < k; i++) { // 슬라이딩 윈도우 생성하기
            if (pointer == nullptr) break; // iterator가 순회하는 중간에 끝에 도달하면 일단 멈추기
            slidingWindow[i] = pointer;
            pointer = pointer -> next; // 맨 마지막에 pointer는 slidingWindow의 바로 다음 노드를 가리킴
            count++;
        }


        if (count < k) { // 슬라이딩 윈도우가 중간에 끊기면 정리하고 종료
            start -> next = slidingWindow[0];
            break;
        } 
        
        slidingWindow[0]->next = pointer; // 맨 마지막 슬라이딩 윈도우에서 그 다음 나머지 노드(nullptr 포함)로 연결하기 

        for (int i = k - 1; i > 0 ; i--) { // 윈도우 안에 있는 값 reversing
            slidingWindow[i] -> next = slidingWindow[i-1];
        }
        
        if (index == 0) { // index가 0이면 가장 처음 윈도우, head를 윈도우의 가장 마지막 노드로 수정하기
            index += k; // 굳이 반복문 안에 들어갈 필요 없음, 처음 윈도우인지 여부만 파악하면 됨
            start = slidingWindow[0]; // start, end값 처음으로 넣기
            end = slidingWindow[k - 1];
            head = slidingWindow[k - 1];
        } else {
            start -> next = slidingWindow[k - 1]; // k 개 단위끼리 연결하기
            start = slidingWindow[0]; // start, end값 기억하기
            end = slidingWindow[k - 1];
        }
    }
    return head;
}



