
#include <stdexcept>
#include <iostream>

#ifndef MYDYNAMICARRAY_H
#define MYDYNAMICARRAY_H

class MyDynamicArray {

private:
    double* arr;
    int arrLength; // What the User thinks the size is
    int arrCapacity; // What the actual size is

    void increaseCapacity();
    void checkForBounds(const int idx) const;

public:

    // Constructors
    MyDynamicArray(const int initialSize);
    MyDynamicArray(const double* initialVals, const int initialSize);

    // Destructor
    ~MyDynamicArray();

    // Getters
    int getSize() const;
    double getAt(const int idx) const;

    void setAt(const double element, const int idx);
    void insert(const double element, const int idx);
    void remove(const int idx);
    void append(const double element);
    void printArray() const;
};

#endif
