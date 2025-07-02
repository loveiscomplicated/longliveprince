#include "Stack.h"
#include <stdexcept>

void Stack::push(int data) {
    vec.push_back(data);
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    int val = vec.back();
    vec.pop_back();
    return val;
}

int Stack::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return vec.back();
}

bool Stack::isEmpty() {
    return vec.empty();
}

int Stack::size() {
    return vec.size();
}
