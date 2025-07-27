#include "BST_mine.h"
#include <iostream>

BST::BST()
  : root(nullptr) {}

BST::~BST() {
  deleteTree(root);
}

void BST::deleteTree(Node* node) {
  deleteTree(node->left);
  deleteTree(node->right);
  delete node;
}

void BST::insert(int data) {
  root = insert(root, data);
}

BST::Node* BST::insert(Node* node, int data) {
  if (node == nullptr) return new Node(data);

  if (data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(node->right, data);
  }
  return node;
}

void BST::remove(int data) {
  root = remove(root, data);
}

BST::Node* BST::remove(Node* node, int data) {
  if (node == nullptr) return node;
  
  if (data < node->data) {
    node->left = remove(node->left, data);
  } else if (data > node->data) {
    node->right = remove(node->right, data);
  } else {
    if (node->left == nullptr) {
      Node* temp = node->right;
      delete node;
      return temp;
    } else if (node->right == nullptr) {
      Node* temp = node->left;
      delete node;
      return temp;
    } else {
      Node* temp = findMin(node->right);
      node->data = temp->data;
      node->right = remove(node->right, temp->data);
    }
  }
  return node;
}

BST::Node* BST::findMin(Node* node) {
  while (node && node->left) {
    node = node->left;
  }
  return node;
}

bool BST::search(int data) {
  return search(root, data);
}

bool BST::search(Node* node, int data) {
  if (node == nullptr) return false;
  if (data == node->data) return true;
  
  return data < node->data ? search(node->left, data) : search(node->right, data);
}

void BST::printInorder() {
  inorderTraversal(root);
}

void BST::inorderTraversal(Node* node) {
  inorderTraversal(node->left);
  std::cout << node->data << std::endl;
  inorderTraversal(node->right);
}
