
#include <stdexcept>
#include <iostream>
#include <string>
#include <format>

#ifndef QUEUE_H
#define QUEUE_H

class MyQueue {

private:

    double* arr;
    int capacity;
    int front;
    int back;
    int size;

public:

    // Constructors
    MyQueue(const int maxSize);

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
