
#include <exception>
#include <iostream>
#include <stdexcept>
#include "MyDoublyLinkedList.h"

int testMyDoublyLinkedList();

int main() {
    return testMyDoublyLinkedList();
}

int testMyDoublyLinkedList() {

    MyDoublyLinkedList myLinkedList;
    // Test Removing of empty list
    myLinkedList.removeHead();
    myLinkedList.removeTail();

    // Test (Insertion @ head & tail) && (removing from list with one elem) 
    myLinkedList.insertAtHead(0.1);
    myLinkedList.removeHead();
    myLinkedList.insertAtTail(0.1);
    myLinkedList.removeTail();
    myLinkedList.printList(); // Should be empty

    // Insert some values via location and check results
    myLinkedList.insertAt(0.4, 1);
    myLinkedList.insertAt(0.3, 1);
    myLinkedList.insertAt(0.1, 1);
    myLinkedList.insertAt(0.2, 2);
    std::cout << std::endl << "List Should Contain 0.1 -> 0.2 -> 0.3 -> 0.4" << std::endl;
    myLinkedList.printList();

    // Testing Removal by Element in the following cases
    //  1. element at head
    //  2. element at tail
    //  3. element in middle
    //  4. element doesn't exist
    myLinkedList.remove(0.1); // 1.
    myLinkedList.remove(0.4); // 2. 
    myLinkedList.insertAtHead(0.99); 
    myLinkedList.insertAtTail(0.99);  
    myLinkedList.remove(0.2); // 3.
    
    try{
        myLinkedList.remove(100);
        std::cerr << "Did not catch element not found error..." << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Successfully Cauth Error For Element Not Found: " <<  e.what() << std::endl;
    }

    // Test Out of bounds insertion 
    try {
        myLinkedList.insertAt(10.3, 0);
        std::cerr << "Did not catch out of bounds error..." << std::endl;
        return 1;

    } catch (const std::exception& e) {
        std::cerr << "Successfully Cauth Error For 0 Location: " <<  e.what() << std::endl;
    }

    const int size = myLinkedList.getSize();
    try {
        myLinkedList.insertAt(10.3, size + 2);
        std::cerr << "Did not catch out of bounds error..." << std::endl;
        return 1;

    } catch (const std::exception& e) {
        std::cerr << "Successfully Cauth Error For (size + 2) Location: " << e.what() << std::endl;
    }


    // Then Finnaly some getter methods

    myLinkedList.insertAtTail(20);
    std::cout << std::endl;
    myLinkedList.printList();
    std::cout << "Element @ Head: " << myLinkedList.getHead() << std::endl;
    std::cout << "Element @ Tail: " << myLinkedList.getTail() << std::endl;
    std::cout << "Size Of List: " << myLinkedList.getSize() << std::endl;
    std::cout << "Element @ Location 2: " << myLinkedList.getElem(2) << std::endl;
    std::cout << "Location of Element With Value 0.3: " << myLinkedList.getLoc(0.3) << std::endl;

    return 0;
}

