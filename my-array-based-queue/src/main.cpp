
#include <exception>
#include <iostream>
#include <stdexcept>
#include "MyQueue.h"

int testMyQueue();


int main() {
    return testMyQueue();
}


int testMyQueue() {

    MyQueue myQueue(10);

    myQueue.enqueue(1.3);
    myQueue.enqueue(2.3);
    myQueue.enqueue(3.3);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.enqueue(3.3);
    myQueue.dequeue();

    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.enqueue(3.3);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    std::cout << myQueue.contains(3.3) << std::endl;
    myQueue.printQueue();

    return 0;
    // Test Pushing
    // 1.4 should be at the top


    // Test popping


    // Test Peeking

    // Test bounds

    // Add A lot of elems and test searching & size
    

    /* myStack3.push(1); */
}
