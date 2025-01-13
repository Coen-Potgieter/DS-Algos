
#include <stdexcept>
#include <iostream>

#ifndef STACK_H
#define STACK_H

class MyStack {

private:

    double* arr;
    int top;
    int maxSize;

public:

    // Constructors
    MyStack(const int maxSize);

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
