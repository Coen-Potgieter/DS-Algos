
#include "MyDynamicArray.h"
#include <stdexcept>


// Private Helper Functions
void MyDynamicArray::increaseCapacity() {

    // Note: Choice between these two are if we have spare memory or spare compute
    this->arrCapacity *= 2; // Double our capacity
    /* this->arrCapacity += 8; // increase our capacity by 8 */

    double* newArr = new double[this->arrCapacity]; // Create New Array with this new capacity

    // Populate old values into new array
    for (int i = 0; i < this->arrLength; i++) {
        newArr[i] = this->arr[i];
    }
    delete[] this->arr; // Deallocate the old array 
    this->arr = newArr; // Allocate the new array
    return;
}

void MyDynamicArray::checkForBounds(const int idx) const {
    // Throw Error if given index is not within bounds
    if ((idx < 0) || (idx >= this->arrLength)) {
        throw std::invalid_argument("Index out of bounds");
    }
    return;
}

// Constructors/Destructors
MyDynamicArray::MyDynamicArray(const int initialSize) {
    if (initialSize < 0) {
        throw std::invalid_argument("Initial Size Must be a Positive Value");
    }

    // Capacity will be a multiple of 8, but must also be larger than the length of the array
    int initialCap = 8;
    while (initialCap < initialSize) {
        initialCap *= 2;
    }
    this->arrLength = initialSize;
    this->arrCapacity = initialCap;

    // Allocate memory and set values to 0
    this->arr = new double[this->arrCapacity];
    for (int i = 0; i < this->arrLength; i++) {
        this->arr[i] = 0;
    }
}

MyDynamicArray::MyDynamicArray(const double* initialVals, const int initialSize) {

    if (initialSize < 0) {
        throw std::invalid_argument("Initial Size Must be a Positive Value");
    }

    // Capacity will be a multiple of 8, but must also be larger than the length of the array
    int initialCap = 8;
    while (initialCap < initialSize) {
        initialCap *= 2;
    }
    this->arrLength = initialSize;
    this->arrCapacity = initialCap;

    this->arr = new double[this->arrCapacity]; // Allocate Memory

    // Set the first `length` elements 
    for (int i = 0; i < this->arrLength; i++) {
        this->arr[i] = initialVals[i];
    }

    // No need to set uninitialised values since user cant access them
}

MyDynamicArray::~MyDynamicArray() {
    // Simply Deallocate memory
    delete[] this->arr;
}

// Getters
int MyDynamicArray::getSize() const {
    return this->arrLength;
}
double MyDynamicArray::getAt(const int idx) const {
    this->checkForBounds(idx);
    return this->arr[idx];
}
void MyDynamicArray::setAt(const double element, const int idx) {
    this->checkForBounds(idx);
    this->arr[idx] = element;
}

// Operations
void MyDynamicArray::append(const double element) {
    // if length == capacity then appending new element will exceed cap, therefore increase cap
    if (this->arrLength == this->arrCapacity) {
        this->increaseCapacity();
    }

    this->arr[this->arrLength] = element; // Set appended element at `newLength - 1`
    this->arrLength += 1; // Set `newLength`
}

void MyDynamicArray::insert(const double element, const int idx) {

    if (idx == this->arrLength) {
        this->append(element);
        return;
    }

    this->checkForBounds(idx);
    // if length == capacity then inserting new element will exceed cap, therefore increase cap
    if (this->arrLength == this->arrCapacity) {
        this->increaseCapacity();
    }

    // Start at the back of the array
    for (int i = this->arrLength; i > idx; i--) {
        this->arr[i] = this->arr[i-1];
    }
    this->arr[idx] = element;
    this->arrLength += 1;
}

void MyDynamicArray::remove(const int idx) {

    this->checkForBounds(idx);

    this->arrLength -= 1;

    // Start at the removed index
    for (int i = idx; i < this->arrLength; i++) {
        this->arr[i] = this->arr[i+1];
    }
}


void MyDynamicArray::printArray() const {
    std::cout << "Printing Dynamic Array..." << std::endl;
    for (int i = 0; i < this->arrLength; i++) {
        std::cout << "Element at Index " << i << ": " << this->arr[i] << std::endl;
    }
}
