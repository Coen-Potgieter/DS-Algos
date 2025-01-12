
#include "MyDoublyLinkedList.h"
#include <stdexcept>

void MyDoublyLinkedList::boundsCheck(const int loc) const {
    if ((loc < 1) || (this->size + 1 < loc)) {
        throw std::invalid_argument("Given Location is Out of bounds... Must be between [1, size + 1]");
    }
}

MyDoublyLinkedList::~MyDoublyLinkedList() {

    std::cout << std::endl << "Freeing Memory..." << std::endl;
    int locIdx = 1;

    // need to cycle through all nodes and delete
    Node* trav = this->head;
    Node* tmp;
    while (trav) {
        tmp = trav;
        trav = trav->nextNode;
        delete tmp;
        std::cout << "Cleared Memory for Node " << locIdx << "/" << this->size << std::endl;
        locIdx += 1;
    }
}

double MyDoublyLinkedList::getHead() const {
    return this->head->data;
}
double MyDoublyLinkedList::getTail() const {
    return this->tail->data;
}
double MyDoublyLinkedList::getElem(const int loc) const {

    if ((loc < 1) || (this->size < loc)) {
        throw std::invalid_argument("Given Location is Out of bounds... Must be between [1, size]");
    }

    Node* trav = this->head;
    int locIdx = 1;
    while (1) {
        if (locIdx == loc) {
            return trav->data;
            break;
        }
        trav = trav->nextNode;
        locIdx += 1;
    }
}
int MyDoublyLinkedList::getLoc(const double element) const {

    // Set traversal pointer at head
    Node* trav = this->head;
    int locIdx = 1;

    // Traverse to node with correct value
    while (1) {
        if (!trav) {
            return -1;
        }
        if (trav->data == element) {
            return locIdx;
            break;
        }
        trav = trav->nextNode;
        locIdx += 1;
    }

}
int MyDoublyLinkedList::getSize() const {
    return this->size;
}

void MyDoublyLinkedList::insertAtHead(const double element) {

    Node* newNode = new Node;
    newNode->data = element;
    newNode->prevNode = nullptr;
    newNode->nextNode = this->head;

    // If head is null then our list is not populated and thus have to set tail as well
    if (!this->head) {
        this->tail = newNode;
    } else {
        this->head->prevNode = newNode;
    }
    this->head = newNode;
    this->size += 1;
}

void MyDoublyLinkedList::insertAtTail(const double element) {

    Node* newNode = new Node;
    newNode->data = element;
    newNode->nextNode = nullptr;
    newNode->prevNode = this->tail;

    // If head is null then list is unitialised
    if (!this->head) {
        this->head = newNode;
    } else {
        this->tail->nextNode = newNode;
    }
    this->tail = newNode;
    this->size += 1;
}

void MyDoublyLinkedList::insertAt(const double element, const int loc) {

    this->boundsCheck(loc); // Check that given `loc` is valid

    // If loc is at head or tail then out source to those methods
    if (loc == 1) {
        this->insertAtHead(element);
        return;
    } else if (loc == (this->size + 1)) {
        this->insertAtTail(element);
        return;
    }

    // Set traversal pointer at head
    Node* trav = this->head;

    // Traverse to node before insertion point
    int locIdx = 1;
    while (locIdx != (loc - 1)) {
        trav = trav->nextNode;
        locIdx += 1;
    }

    // Create node and move around pointers
    Node* newNode = new Node;
    newNode->data = element;
    newNode->nextNode = trav->nextNode;
    newNode->prevNode = trav;
    trav->nextNode->prevNode = newNode;
    trav->nextNode = newNode;
    this->size += 1; // Increment Size
}

void MyDoublyLinkedList::removeHead() {
    Node* trav = this->head;

    // If there are no nodes
    if (!trav) {
        std::cerr << "List is Empty" << std::endl;
        return;
    }

    // If we have one node
    if (!trav->nextNode) {
        delete trav;
        this->head = nullptr;
        this->tail = nullptr;
        this->size -= 1;
        return;
    }

    trav->nextNode->prevNode = nullptr;
    this->head = trav->nextNode;
    delete trav;
    this->size -=1;
}

void MyDoublyLinkedList::removeTail() {
    Node* trav = this->tail;

    // If there are no nodes
    if (!trav) {
        std::cerr << "List is Empty" << std::endl;
        return;
    }

    // If we have one node
    if (!trav->prevNode) {
        delete trav;
        this->head = nullptr;
        this->tail = nullptr;
        this->size -= 1;
        return;
    }

    trav->prevNode->nextNode = nullptr;
    this->tail = trav->prevNode;
    delete trav;
    this->size -=1;
}
void MyDoublyLinkedList::remove(const double element) {

    // Set traversal pointer at head
    Node* trav = this->head;

    // Traverse to node with correct value
    while (1) {
        if (!trav) {
            throw std::invalid_argument("Given Element To delete Does Not exist");
        }
        if (trav->data == element) {
            break;
        }
        trav = trav->nextNode;
    }

    // Base cases
    if (!trav->nextNode) {
        this->removeTail();
        return;
    }
    if (!trav->prevNode) {
        this->removeHead();
        return;
    }

    // Move Around pointers and free `trav`
    trav->prevNode->nextNode = trav->nextNode;
    trav->nextNode->prevNode = trav->prevNode;
    delete trav;
    this->size -= 1;
}

void MyDoublyLinkedList::printList() const {
    std::cout << "Printing Doubly Linked List..." << std::endl;

    Node* trav = this->head;
    int locIdx = 1;
    while (trav) {
        std::cout << "Element At Loc " << locIdx << ": " << trav->data << std::endl;
        trav = trav->nextNode;
        locIdx += 1;
    }
}
void MyDoublyLinkedList::printListBackwards() const {

    std::cout << "Printing Doubly Linked List Backwards..." << std::endl;

    Node* trav = this->tail;
    int locIdx = this->size;
    while (trav) {
        std::cout << "Element At Loc " << locIdx << ": " << trav->data << std::endl;
        trav = trav->prevNode;
        locIdx -= 1;
    }

}









