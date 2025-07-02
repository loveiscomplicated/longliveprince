#include "SinglyLinkedList.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void SinglyLinkedList::append(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = newNode;
}

void SinglyLinkedList::prepend(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::deleteWithValue(int data) {
    if (head == nullptr) return;

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }

    if (current->next == nullptr) return; // Not found

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void SinglyLinkedList::printList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

bool SinglyLinkedList::search(int data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}
