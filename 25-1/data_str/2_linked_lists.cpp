#include <iostream>
#include <string>

using namespace std;

template <typename E>
class SNode {
  private:
  E data;
  SNode* next;

  public:
  SNode(const E& data, SNode* next);
  
  friend class SLinkedList;
};

template <typename E>
class SLinkedList{
  public:
  SLinkedList(SNode<E>* head);
  ~SLinkedList();

  bool empty();
  const E& front() const; // front data 파악하기
  void pushFront(const E& e); // 맨 앞 노드를 바꾸기
  void pushback(const E& e);
  void add(int index, const E& e); // k번째 node가 되도록 추가하기, 잘못된 index 입력 시 오류류
  void popFront();

  //...
  private:
  SNode<E>* head; // singly linked list는 head만을 기억한다.
};

template <typename E>
SLinkedList<E>::SLinkedList(SNode<E>* h) { // 생성자
  head = h;
}

template <typename E>
SLinkedList<E>::~SLinkedList() { // 소멸자
  SNode* nextPTR = head -> next;
}

template <typename E>
bool SLinkedList<E>::empty() { // 비어 있는지 확인
  if (head == nullptr) {
    return false;
  }
  else {
    return true;
  }
}

template <typename E>
const E &SLinkedList<E>::front() const {
  return head -> data; 
  // 이건 사실 실제 값이 아닌 참조해서 리턴하고 있는 상황, 함수 리턴 자료형이 참조자이기 때문
}

template <typename E>
void SLinkedList<E>::pushFront(const E& e) {
  head = new SNode<E>(e, head)
}

template <typename E>
void SLinkedList<E>::pushback(const E& e) {
  SNode* temp_state = head;
  while(temp_state -> next != nullptr) { // tail 노드 찾기
    temp_state = temp_state -> next;
  }
  temp_state -> next = new SNode<E>(e, nullptr);
}




template <typename E>
void SLinkedList<E>::popFront() {
  if (head == nullptr) return;
  
  SNode* old = head;
  head = head -> next;
  delete old;
}
