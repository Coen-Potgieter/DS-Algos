
#include <exception>
#include <iostream>
#include <stdexcept>
#include "MyDynamicArray.h"

int testMyDynamicArray();


int main() {
    return testMyDynamicArray();
}


int testMyDynamicArray() {

    // Testing Constructors
    try{
        MyDynamicArray *myArray1 = new MyDynamicArray(20);
        double startingElems[] = { 0.2, 1, 3, 10, 2.3};
        int sizeOfElems = sizeof(startingElems) / sizeof(startingElems[0]);
        MyDynamicArray *myArray2 = new MyDynamicArray(startingElems, sizeOfElems);
        myArray2->printArray();
        delete myArray1;
        delete myArray2;

    } catch (const std::exception& e) {
        std::cerr << "Error at Construction: " << e.what() << std::endl;
        return 1;
    }

    MyDynamicArray myArray(5);

    // Catching errors for bad idx bounds
    try {
        myArray.getAt(10);

        // If we don't get an error then we execute this
        std::cerr << "Did Not Catch Error..." << std::endl;
        return 1;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Successfully Caught Error: " << e.what() << std::endl;
    }

    myArray.setAt(0.1, 0);

    myArray.insert(0.3, 1);
    myArray.insert(3, 0);
    myArray.insert(3, myArray.getSize());
    myArray.remove(2);
    myArray.remove(myArray.getSize() - 1);

    myArray.printArray();

    for (int i = 1; i < 100; i++) {
        myArray.append(i);
    }
    myArray.printArray();
    return 0;
}
