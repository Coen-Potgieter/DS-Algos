
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include "MyQueue.h"

int testMyQueue();


int main() {
    return testMyQueue();
}


int testMyQueue() {

    MyQueue myQueue;

    // Test enqueue & peek
    myQueue.enqueue(1.3);
    myQueue.enqueue(2.3);
    myQueue.enqueue(3.3);
    myQueue.printQueue();
    std::cout << "First Element: " << myQueue.peek() << std::endl << std::endl;

    // Test dequeue 
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.enqueue(5.6);
    myQueue.enqueue(5.91);
    myQueue.enqueue(1.6);
    myQueue.printQueue();

    // empty queue and test: isEmptyChecks & error checks
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.printQueue();

    std::string thingToPrint = (myQueue.isEmpty()) ? "Queue is Empty" : "Queue is Populated...";
    std::cout << thingToPrint << std::endl;

    try {
        myQueue.dequeue();
        std::cerr << "Did not catch dequeue empty queue error..." << std::endl;
        return 1;
    } catch(const std::exception& e) {
        std::cout << "Successfully caught dequeue error: " << e.what() << std::endl;
    }
    try {
        myQueue.peek();
        std::cerr << "Did not catch dequeue empty queue error..." << std::endl;
        return 1;
    } catch(const std::exception& e) {
        std::cout << "Successfully caught peek error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // populate queue and test `contains` method
    myQueue.enqueue(0.34);
    myQueue.enqueue(1);
    myQueue.enqueue(1);
    myQueue.enqueue(1);
    myQueue.enqueue(1);
    myQueue.enqueue(10.4);
    myQueue.printQueue();



    thingToPrint = (myQueue.contains(0.34)) ? "Queue Contains 0.34" : "Queue Does Not Contain 0.34";
    std::cout << thingToPrint << std::endl;

    thingToPrint = (myQueue.contains(10.4)) ? "Queue Contains 10.4" : "Queue Does Not Contain 10.4";
    std::cout << thingToPrint << std::endl;

    thingToPrint = (myQueue.contains(12.67)) ? "Queue Contains 12.67" : "Queue Does Not Contain 12.67";
    std::cout << thingToPrint << std::endl;
    return 0;
}
