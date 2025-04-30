#include <iostream>

using namespace std;

struct BSTnode {
  int elem;
  BSTnode* leftNode;
  BSTnode* rightNode;
  
  BSTnode(int elemInput, BSTnode* leftNodeInput = nullptr, BSTnode* rightNodeInput = nullptr) {
    elem = elemInput;
    leftNode = leftNodeInput;
    rightNode = rightNodeInput;
  }
};

class BST {
  public:
  BSTnode* ptr;

  BST() {
    BSTnode* ptr = nullptr;
  }

  void insert(int num) {
    if (ptr == nullptr) {
      ptr -> elem = num;
      return;
    }
    
    if (ptr->elem < num) {
      if (ptr -> leftNode == nullptr) {

      }
      else {

      }
    } 
    else (ptr->elem > num) {
      
    }
  }

  bool isEmpty() {
    if (ptr == nullptr) {
      return true;
    } else {
      return false;
    }
  }

  bool search(BSTnode* ptr, int q) {
    if (isEmpty() == true) {
      return false;
    }

    if (ptr -> elem < q) {
      return search(ptr->leftNode, q);
    }
    else if (ptr -> elem > q) {
      return search(ptr -> rightNode, q);
    }
    else {
      return true; // 없는 경우, 리프 노드에서 nullptr 만나고 1번 case로 감 - false 반환
    }
  }
  
  int findMin(BSTnode* ptr) {
    if (ptr -> leftNode == nullptr) {
      return ptr -> elem;
    }
    else {
      return findMin(ptr -> leftNode);
    }
  }

  int findMax() {
    if (ptr -> rightNode == nullptr) {
      return ptr -> elem;
    }
    else {
      return findMin(ptr -> rightNode);
    }
  }
};