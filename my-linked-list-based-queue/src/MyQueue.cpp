
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
    this->back->next = newNode;
    this->back = newNode;
    this->size += 1;

    // TODO: init this->front if queue is empty
}

void MyQueue::dequeue() {

    // complete this, worflow: 1. check if queue is empty | 2. store front in `tmp` | 3. move front to front->next | 4. free `tmp` | 5. decrease size
    Node* tmp = this->front;
    /* this->front */

    

    this->size -= 1;
}

