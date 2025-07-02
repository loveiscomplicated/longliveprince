#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::append(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void DoublyLinkedList::prepend(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void DoublyLinkedList::deleteWithValue(int data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            if (current->prev) {
                current->prev->next = current->next;
            } else { // It's the head
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else { // It's the tail
                tail = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

void DoublyLinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

void DoublyLinkedList::printListReverse() {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->prev;
    }
    std::cout << "nullptr" << std::endl;
}
