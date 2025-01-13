
#include "MyStack.h"
#include <stdexcept>

MyStack::MyStack(const int maxSize) {
    this->arr = new double[maxSize];
    this->maxSize = maxSize;
    this->top = -1;
}

MyStack::~MyStack() {
    delete[] this->arr;
}



void MyStack::push(const double element) {

    if (this->top >= (this->maxSize - 1)) {
        throw std::overflow_error("Stack is at full capacity, cannot push more onto it...");
    }

    this->top += 1;
    this->arr[this->top] = element;
}

double MyStack::pop() {

    if (this->top <= -1) {
        throw std::underflow_error("Stack is Empty...");
    }

    this->top -= 1;
    return this->arr[this->top + 1];
}


double MyStack::peek() const {
    if (this->top == -1) {
        throw std::underflow_error("Stack is Empty...");
    }
    return this->arr[this->top];
}
int MyStack::getSize() const {
    return this->top + 1;
}


int MyStack::findLoc(const double element) const {

    for (int i = 0; i <= this->top; i++) {
        if (this->arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void MyStack::printStack() const {

    for (int i = this->top; i >= 0; i--) {
        std::cout << "Element " << this->top - i << " From Top: " << this->arr[i] << std::endl;
    }
}


