
#include "MyQueue.h"
#include <stdexcept>


MyQueue::~MyQueue() {
    Node* trav = this->front;
    Node* tmp;

    while (trav) {
        tmp = trav;
        trav = trav->next;
        delete tmp;
    }
}

void MyQueue::enqueue(const double element) {

    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    if (!this->back) {
        this->front = newNode;
    } else {
        this->back->next = newNode;
    }

    this->back = newNode;
    this->size += 1;
}

void MyQueue::dequeue() {

    // complete this, worflow: 1. check if queue is empty | 2. store front in `tmp` | 3. move front to front->next | 4. free `tmp` | 5. decrease size
    if (this->size <= 0) {
        throw std::overflow_error("Queue is empty...");
    }

    Node* tmp = this->front;
    this->front = tmp->next;
    delete tmp;

    if (!this->front) {
        this->back = nullptr;
    }

    this->size -= 1;
}

double MyQueue::peek() const {
    if (this->isEmpty()) {
        throw std::overflow_error("Queue is empty...");
    }
    return this->front->data;
}


bool MyQueue::contains(const double element) const {
    Node* trav = this->front;
    while (trav) {
        if (trav->data == element) {
            return true;
        }
        trav = trav->next;
    }
    return false;
}
bool MyQueue::isEmpty() const {
    return (this->size <= 0);
}
void MyQueue::printQueue() const {

    Node* trav = this->front;
    while (trav) {
        std::cout << trav->data << " -> ";
        trav = trav->next;
    }
    std::cout << std::endl;
}








