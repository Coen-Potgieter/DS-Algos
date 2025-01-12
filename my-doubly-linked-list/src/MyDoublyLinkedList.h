
#include <stdexcept>
#include <iostream>

#ifndef MYDOUBLYLINKEDLIST_H
#define MYDOUBLYLINKEDLIST_H

class MyDoublyLinkedList {

private:
    struct Node {
        double data;
        Node* nextNode;
        Node* prevNode;
    };
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    void boundsCheck(const int loc) const;

public:
    MyDoublyLinkedList() = default;
    ~MyDoublyLinkedList();

    void insertAtHead(const double element);
    void insertAtTail(const double element);
    void insertAt(const double element, const int loc);
    void remove(const double element); // Delete by element
    void removeHead(); // Delete by element
    void removeTail(); // Delete by element
    
    double getHead() const;
    double getTail() const;
    double getElem(const int loc) const;
    int getLoc(const double element) const;
    int getSize() const;
    void printList() const;
    void printListBackwards() const;
};

#endif
