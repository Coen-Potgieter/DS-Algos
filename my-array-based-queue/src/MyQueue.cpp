
#include "MyQueue.h"
#include <stdexcept>

MyQueue::MyQueue(const int maxSize) {
    this->arr = new double[maxSize];
    this->capacity = maxSize;
    this->front = -1;
    this->back = -1;
    this->size = 0;
}

MyQueue::~MyQueue() {
    delete[] this->arr;
    this->capacity = 0;
    this->front = -1;
    this->back = -1;
    this->size = 0;
}

void MyQueue::enqueue(const double element) {
    if (this->size >= this->capacity) {
        throw std::overflow_error("Queue is full...");
    }

    if (this->back >= (this->capacity - 1)) {
        this->back = 0;
    } else {
        this->back += 1;
    }
    this->arr[this->back] = element;
    if (this->front == -1) {
        this->front += 1;
    }
    this->size += 1;
}

void MyQueue::dequeue() {
    if (this->size <= 0) {
        throw std::overflow_error("Queue is empty...");
    }

    if (this->front >= (this->capacity - 1)) {
        this->front = 0;
    } else {
        this->front += 1;
    }

    this->size -= 1;
}

double MyQueue::peek() const {
    if (this->size <= 0) {
        throw std::overflow_error("Queue is empty...");
    }
    return this->arr[this->front];
}
bool MyQueue::contains(const double element) const {

    int currIdx = this->front;
    int numChecked = 0;
    while (numChecked < this->size) {
        if (this->arr[currIdx] == element) {
            return true;
        }
        currIdx = (currIdx + 1 >= this->capacity) ? 0 : currIdx + 1;
        numChecked += 1;
    }
    return false;
}


bool MyQueue::isEmpty() const {
    return (this->size <= 0);
}


void MyQueue::printQueue() const {

    // Define the separator
    const char separator = '|';

    // Create new array to hold the indicies where values are stored
    int* validIndicies = new int[this->size];
    for (int i = 0; i < this->size; i++) {
        validIndicies[i] = ((this->front + i) >= this->capacity) ? this->front + i - this->capacity : this->front + i;
    }

    // Print the array
    for (int i = 0; i < this->capacity; i++) {

        bool isPopulated = false;

        for (int j = 0; j < this->size; j++) {
            if (i == validIndicies[j]) {
                isPopulated = true;
                break;
            }
        }

        std::string elemToPrint = (isPopulated) ? std::format("{:.2f}", this->arr[i]) : "-";
        std::cout << elemToPrint << " " << separator << " ";
    }
    std::cout << std::endl;

    delete[] validIndicies;
}









