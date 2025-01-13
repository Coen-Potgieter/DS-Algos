
#include <exception>
#include <iostream>
#include <stdexcept>
#include "MyStack.h"

int testMyStack();


int main() {
    return testMyStack();
}


int testMyStack() {

    MyStack myStack;
    // Test Pushing
    
    myStack.push(1);
    myStack.push(1.1);
    myStack.push(1.2);
    myStack.push(1.3);
    myStack.push(1.4);
    // 1.4 should be at the top
    myStack.printStack();

    std::cout << std::endl;
    // Test popping
    for (int i = 0; i < 3; i++) {
        std::cout << "Popped: " << myStack.pop() << std::endl;
    }
    myStack.printStack();

    // Test Peeking
    std::cout << "Top Element is: " << myStack.peek() << std::endl;

    // Add A lot of elems and test searching & size
    
    for (int i = 1; i < 1001; i++) {
        myStack.push(i / 9.3);
    }
    myStack.printStack();

    std::cout << "Size: " << myStack.getSize() << std::endl;
    std::cout << "Location of 1: " << myStack.findLoc(1) << std::endl;
    return 0;
}
