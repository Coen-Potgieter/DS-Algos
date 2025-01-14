
#include <stdexcept>
#include <iostream>
#include <string>
#include <format>

#ifndef QUEUE_H
#define QUEUE_H

class MyQueue {

private:

    struct Node {
        double data;
        Node* next;
    };

    Node* front = nullptr;
    Node* back = nullptr;
    int size = 0;

public:

    // Constructors
    MyQueue() = default;

    // Destructor
    ~MyQueue();

    void enqueue(const double element);
    void dequeue();
    double peek() const;
    bool contains(const double element) const;
    bool isEmpty() const;

    void printQueue() const;
};

#endif
