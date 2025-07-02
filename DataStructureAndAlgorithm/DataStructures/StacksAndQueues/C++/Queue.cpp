#include "Queue.h"
#include <stdexcept>

void Queue::enqueue(int data) {
    deq.push_back(data);
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    int val = deq.front();
    deq.pop_front();
    return val;
}

int Queue::front() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return deq.front();
}

bool Queue::isEmpty() {
    return deq.empty();
}

int Queue::size() {
    return deq.size();
}
