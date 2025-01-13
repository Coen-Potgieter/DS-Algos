
#include <stdexcept>
#include <iostream>

#ifndef STACK_H
#define STACK_H

class MyStack {

private:

    struct Node {
        double data;
        Node* next;
    };

    int size = 0;
    Node* top = nullptr;

public:

    // Constructors
    MyStack() = default;

    // Destructor
    ~MyStack();

    // Getters

    void push(const double element);
    double pop();
    double peek() const;
    int getSize() const;
    int findLoc(const double element) const;

    void printStack() const;
};

#endif
