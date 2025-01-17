
#include <exception>
#include <iostream>
#include <stdexcept>
#include "BinaryTree.h"

int testMyBinaryTree();


int main() {
    return testMyBinaryTree();
}


int testMyBinaryTree() {

    BinaryTree myTree;

    myTree.insertBFS(1);
    myTree.insertBFS(2);
    myTree.insertBFS(3);
    myTree.insertBFS(4);
    myTree.insertBFS(5);
    myTree.insertBFS(6);
    myTree.insertBFS(7);
    myTree.insertBFS(8);
    myTree.insertBFS(9);
    myTree.insertBFS(10);
    myTree.insertBFS(11);
    myTree.insertBFS(12);
    myTree.printTree();

    return 0;
}
