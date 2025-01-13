
#include "MyStack.h"
#include <stdexcept>

MyStack::~MyStack() {

    Node* trav = this->top;
    Node* tmp;

    while (trav) {
        tmp = trav;
        trav = trav->next;
        delete tmp;
    }
}



void MyStack::push(const double element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = this->top;
    this->top = newNode;
    this->size += 1;
}

double MyStack::pop() {

    if (!this->top) {
        throw std::underflow_error("Stack is Empty...");
    }

    Node* tmp = this->top;
    this->top = tmp->next;
    double poppedVal = tmp->data;
    delete tmp;
    this->size -= 1;
    return poppedVal;
}


double MyStack::peek() const {
    if (!this->top) {
        throw std::underflow_error("Stack is Empty...");
    }
    return this->top->data;
}
int MyStack::getSize() const {
    return this->size;
}


int MyStack::findLoc(const double element) const {
    Node* trav = this->top;

    int runningLoc = 1;
    while (trav) {
        if (trav->data == element) {
            return runningLoc;
        }
        trav = trav->next;
        runningLoc += 1;
    }
    return -1;
}

void MyStack::printStack() const {

    Node* trav = this->top;
    int runningIdx = 0;
    while (trav) {
        std::cout << "Element " << runningIdx << " Places From the Top: " << trav->data << std::endl;
        trav = trav->next;
        runningIdx += 1;
    }
}


