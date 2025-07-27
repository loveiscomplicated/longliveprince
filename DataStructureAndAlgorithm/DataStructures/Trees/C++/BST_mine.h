#ifndef BST_MINE_H
#define BST_MINE_H

class BST {
private:
  struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
  };

  Node* root;

  Node* insert(Node* node, int data);
  Node* remove(Node* node, int data);
  Node* findMin(Node* node);
  bool search(Node* node, int data);
  void InorderTraversal(Node* node);

public:
  BST();
  ~BST();
  void deleteTree(Node* node);

  void insert(int data);
  void remove(int data);
  bool search(int data);
  void printInorder();
};

#endif