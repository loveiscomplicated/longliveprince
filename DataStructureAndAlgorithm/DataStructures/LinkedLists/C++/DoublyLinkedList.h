#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void append(int data);
    void prepend(int data);
    void deleteWithValue(int data);
    void printList();
    void printListReverse();
};

#endif // DOUBLYLINKEDLIST_H
