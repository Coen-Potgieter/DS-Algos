# DS-Algos

## Description

- This Repo contains my various implementations of different Data Structures and Algorithms in C++
- The following descriptions are taken from my notes and give a broad overview of how I implemented each DS


# Data Structures

## Dynamic Array

> - We have many ways of implementing a dynamic array
> - One way is to use static Arrays

### Using Static Arrays

1. Create a Static Array with an initial size
2. Add Elements to the underlying static array keeping track of the number of elements
3. If Adding another element exceeds the initial capacity, then create a new static array with twice the capacity and copy the contents to this new static array

## Doubly Linked List

### Structure

1. Most of the complexity comes from keeping track of all the pointers and memory management
2. My implementation here consists of an embedded `struct` called `Node` which holds a `data` element and 2 `Node` pointers for `next` and `prev`
3. In our Main class we have a `size` member as well as 2 `Node` pointers for `head` & `tail`
- **Code**
    ```cpp
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

    public:
        // Other Methods
    };
    ```

### General Guidelines For Methods

#### To Traverse

- We create a new `trav` variable that is of type `Node*`
- We move into a while loop that checks if `trav` is `nullptr` by checking if `trav` is `True` (ie. `if (trav) {}`)
- If it is not `nullptr` then we set the new `trav` to `trav->nextNode`
- **Code**
    ```cpp
    void MyDoublyLinkedList::printList() const {
        std::cout << "Printing Doubly Linked List..." << std::endl;

        Node* trav = this->head;
        int locIdx = 1;
        while (trav) { // Check For nullptr
            std::cout << "Element At Loc " << locIdx << ": " << trav->data << std::endl;
            trav = trav->nextNode; // Move to next Node in List
            locIdx += 1;
        }
    }
    ```

#### To Move Around Pointers

- Nothing really to be explained here...
- Just think about it and use the diagrams above
- **Code**
    ```cpp
    void MyDoublyLinkedList::insertAt(const double element, const int loc) {
        Node* trav = this->head; // Set traversal pointer at head

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
    ```

#### Cleaning Up

- I just want to make note of the destructor for this class
- We have been dynamically allocating memory to these nodes and thus we must free them all in our destructor
- This requires a separate `tmp` pointer that stays behind why the `trav` pointer move forward
- The `tmp` pointer will then delete the left behind node
- **Code**
    ```cpp
    MyDoublyLinkedList::~MyDoublyLinkedList() {
        std::cout << std::endl << "Freeing Memory..." << std::endl;

        // need to cycle through all nodes and delete
        Node* trav = this->head;
        Node* tmp;
        while (trav) {
            tmp = trav;
            trav = trav->nextNode; // Move To Next Node, leaving `tmp` behind
            delete tmp; // free pointer at `tmp`
        }
    }
    ```



