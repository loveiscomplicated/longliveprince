#ifndef QUEUE_H
#define QUEUE_H

#include <deque>

class Queue {
private:
    std::deque<int> deq;

public:
    void enqueue(int data);
    int dequeue();
    int front();
    bool isEmpty();
    int size();
};

#endif // QUEUE_H
