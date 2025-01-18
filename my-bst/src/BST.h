

#include <queue>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

#ifndef BST_H
#define BST_H

class BST {
private:

    struct Node {
        double data;
        Node* left;
        Node* right;
        Node(const double newElem): data(newElem), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;
    int size = 0;

    void deleteTree(Node* root);

    Node* add(Node* root, const double& element);
    bool contains(Node* node, const double& element) const;
    Node* search(Node* node, const double& element) const;


public:
    BST() = default;
    ~BST();

    void insert(const double& element);
    bool contains(const double& element) const;
    void printTree() const;

    void printNode(const double& element) const {
        Node* target = search(this->root, element);
        std::cout << "Data: " << target->data << std::endl;
        std::cout << "Left: " << target->left << std::endl;
        std::cout << "Right: " << target->right << std::endl;
    }

};

#endif
