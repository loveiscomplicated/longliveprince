#ifndef BST_MINE_H
#define BST_MINE_H

class BST{
private:
  struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val, Node* l = nullptr, Node* r = nullptr)
      : data(val), left(l), right(r) {}
  };

  Node* insert(Node* node, int data);
  Node* remove(Node* node, int data);
  Node* findMin(Node* node);
  bool search(Node* node, int data);
  void inorderTraversal(Node* node);

public:
  BST();
  ~BST();
  void deleteTree(Node* node);
  
  Node* root;

  void insert(int data);
  void remove(int data);
  bool search(int data);
  void printInorder();
};

#endif