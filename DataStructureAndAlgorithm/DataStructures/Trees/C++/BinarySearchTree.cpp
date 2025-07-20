#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

void BinarySearchTree::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void BinarySearchTree::insert(int data) {
    root = insert(root, data);
}

BinarySearchTree::Node* BinarySearchTree::insert(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void BinarySearchTree::remove(int data) {
    root = remove(root, data);
}

BinarySearchTree::Node* BinarySearchTree::remove(Node* node, int data) {
    if (node == nullptr) return node; // 아예 비어 있거나 data를 못 찾은 경우

    if (data < node->data) { 
        node->left = remove(node->left, data);
    } else if (data > node->data) {
        node->right = remove(node->right, data);
    } else { // 제거해야 할 위치를 찾은 경우
        if (node->left == nullptr) { // 자식이 아예 없거나 오른쪽에만 있는 경우
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) { // 자식이 왼쪽에만 있는 경우
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right); // 자식이 둘 있는 경우, 오른쪽 서브트리에서 최솟값을 찾아 덮어씌우기, 원래 최솟값이 있던 자리는 제거
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

BinarySearchTree::Node* BinarySearchTree::findMin(Node* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

bool BinarySearchTree::search(int data) {
    return search(root, data);
}

bool BinarySearchTree::search(Node* node, int data) {
    if (node == nullptr) return false;
    if (node->data == data) return true;
    return data < node->data ? search(node->left, data) : search(node->right, data);
}

void BinarySearchTree::printInorder() {
    inorderTraversal(root);
    std::cout << std::endl;
}

void BinarySearchTree::inorderTraversal(Node* node) {
    if (node) {
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }
}
