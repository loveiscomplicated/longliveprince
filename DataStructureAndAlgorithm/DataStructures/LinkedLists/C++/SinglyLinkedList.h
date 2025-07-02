#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void append(int data);
    void prepend(int data);
    void deleteWithValue(int data);
    void printList();
    bool search(int data);
};

#endif // SINGLYLINKEDLIST_H
