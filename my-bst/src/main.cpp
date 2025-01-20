
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include "BST.h"

int testMyBST();


int main() {
    return testMyBST();
}


int testMyBST() {

    BST myBST;

    myBST.insert(5);
    myBST.printBST();
    myBST.remove(5);
    myBST.printBST();
    return 0;

    myBST.insert(5);
    myBST.insert(3);
    myBST.insert(7);
    myBST.printBST();
    myBST.remove(5);

    myBST.printBST();
    return 0;
    myBST.insert(7);
    myBST.insert(5);
    myBST.insert(20);
    myBST.insert(4);
    myBST.insert(2);
    myBST.insert(1);
    myBST.insert(3);
    myBST.insert(20);
    myBST.insert(18);
    myBST.insert(19);
    myBST.insert(11);
    myBST.insert(14);
    myBST.insert(12);
    myBST.insert(15);
    myBST.insert(25);
    myBST.insert(33);
    myBST.insert(28);
    myBST.insert(31);
    myBST.printBST();
    std::cout << "MAX: " << myBST.returnMaxVal() << std::endl;
    std::cout << "Min: " << myBST.returnMinVal() << std::endl;

    myBST.remove(7);
    myBST.printBST();

    return 0;

    myBST.insert(1);
    myBST.insert(2);
    myBST.insert(3);
    myBST.insert(4);
    myBST.insert(5);
    myBST.insert(-10);
    myBST.insert(-5);
    myBST.insert(-2);
    myBST.insert(-20);
    myBST.insert(-40);
    myBST.printBST();
    std::cout << "MAX: " << myBST.returnMaxVal() << std::endl;
    std::cout << "Min: " << myBST.returnMinVal() << std::endl;


    myBST.remove(-10);
    myBST.printBST();

    myBST.print();

    return 0;
    /* std::cout << myBST.contains(1) << std::endl; */
    /* std::cout << myBST.contains(6) << std::endl; */
    /* std::cout << myBST.contains(5) << std::endl; */
    /* std::cout << myBST.contains(-2) << std::endl; */

    double elemToRemove = -5;
    std::string removeMssg = (myBST.remove(elemToRemove)) ? "Succesfully Removed " + std::to_string(elemToRemove) : "Failed to Remove " + std::to_string(elemToRemove);
    std::cout << removeMssg << std::endl;

    /* myBST.remove(5); */

    myBST.printBST();

    return 0;
}
