
#include <exception>
#include <iostream>
#include <stdexcept>
#include "BST.h"

int testMyBST();


int main() {
    return testMyBST();
}


int testMyBST() {

    BST myBST;

    myBST.insert(1);
    myBST.insert(2);
    myBST.insert(3);
    myBST.insert(4);
    myBST.insert(5);
    myBST.insert(-10);
    myBST.insert(-5);
    myBST.insert(-2);
    myBST.printTree();
    std::cout << myBST.contains(1) << std::endl;
    std::cout << myBST.contains(6) << std::endl;
    std::cout << myBST.contains(5) << std::endl;
    std::cout << myBST.contains(-2) << std::endl;


    myBST.printNode(-10);



    return 0;
}
