#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree {
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
    bool search(Node* node, int data);
    Node* findMin(Node* node);
    void inorderTraversal(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void deleteTree(Node* node);

    void insert(int data);
    void remove(int data);
    bool search(int data);
    void printInorder();
};

#endif // BINARYSEARCHTREE_H
