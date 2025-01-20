
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

    // Test Insertion
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
    myBST.printBST();


    // Test Removing ( all 4 cases)
    //  - Case I
    std::cout << std::endl << "Case I: Removing Leaf Node: [1]..." << std::endl;
    myBST.remove(1);
    myBST.printBST();

    //  - Case II
    std::cout << std::endl << "Case II: Removing Node With Only Left Subtree: [4]..." << std::endl;
    myBST.remove(4);
    myBST.printBST();

    //  - Case III
    std::cout << std::endl << "Case III: Removing Node With Only Right Subtree: [25]..." << std::endl;
    myBST.remove(25);
    myBST.printBST();

    //  - Case IV
    std::cout << std::endl << "Case IV: Removing Node With Both Left & Right Subtree: [7]..." << std::endl;
    myBST.remove(7);
    myBST.printBST();

    //  - My Case
    std::cout << std::endl << "My Case: Remove Only Node From BST" << std::endl;
    std::cout << "Before Removal" << std::endl;
    myBST.emptyTree();
    myBST.insert(5);
    myBST.printBST();
    std::cout << "After Removal" << std::endl;
    myBST.remove(5);
    myBST.printBST();

    // Test traversal
    std::cout << std::endl << std::endl << "Testing Traversal..." << std::endl;
    myBST.insert(11);
    myBST.insert(6);
    myBST.insert(3);
    myBST.insert(8);
    myBST.insert(1);
    myBST.insert(5);
    myBST.insert(15);
    myBST.insert(13);
    myBST.insert(12);
    myBST.insert(14);
    myBST.insert(17);
    myBST.insert(19);
    myBST.printBST();

    std::cout << "PREORDER: ";
    myBST.printTraversal(BST::TRAVERSAL::PREORDER);
    std::cout << "INORDER: ";
    myBST.printTraversal(BST::TRAVERSAL::INORDER);
    std::cout << "POSTORDER: ";
    myBST.printTraversal(BST::TRAVERSAL::POSTORDER);
    std::cout << "LEVEL ORDER: ";
    myBST.printTraversal(BST::TRAVERSAL::LEVEL_ORDER);
    return 0;
}
