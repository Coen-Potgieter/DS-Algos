

#include <queue>
#include <iostream>
#include <math.h>

#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {
private:

    struct Node {
        double data;
        Node* left;
        Node* right;
    };
    Node* root = nullptr;
    int size = 0;

    void deleteTree(Node* root);

public:
    BinaryTree() = default;
    ~BinaryTree();

    void insertBFS(const double element);

    void printTree() const;


};

#endif
