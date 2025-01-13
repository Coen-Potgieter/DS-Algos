
#include <exception>
#include <iostream>
#include <stdexcept>
#include "MyStack.h"

int testMyStack();


int main() {
    return testMyStack();
}


int testMyStack() {

    MyStack myStack(10);

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

    // Test bounds
    MyStack myStack2(3);

    try{
        myStack2.pop();
        std::cerr << "Did not catch Empty Stack Error on Pop..." << std::endl;
        myStack2.peek();
        std::cerr << "Did not catch Empty Stack Error on peek..." << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Caught Empty Stack Error: " << e.what() << std::endl;
    }

    myStack2.push(1);
    myStack2.push(1);
    myStack2.push(1);
    try{
        myStack2.push(1);
        std::cerr << "Did not catch Full Stack Error on Push..." << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Caught Full Stack Error: " << e.what() << std::endl;
    }

    // Add A lot of elems and test searching & size
    
    MyStack myStack3(1000);

    /* myStack3.push(1); */
    for (int i = 1; i < 1000; i++) {
        myStack3.push(i / 9.3);
    }
    myStack3.push(1);

    myStack3.printStack();
    std::cout << "Size: " << myStack3.getSize() << std::endl;
    std::cout << "Location of 1: " << myStack3.findLoc(1) << std::endl;
    return 0;
}
