

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
    Node* remove(Node* node, const double& element);
    Node* findMax(Node* startingNode) const;
    Node* findMin(Node* startingNode) const;

    // Helper function for in-order traversal
    void printInOrder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        printInOrder(node->left);             // Visit left subtree
        std::cout << node->data << " ";      // Print node's data
        printInOrder(node->right);           // Visit right subtree
    }


    void printPreorder() const;
    void printInorder() const;
    void printPostorder() const;



public:

    enum TRAVERSAL {
        PREORDER,
        INORDER,
        POSTORDER,
        LEVEL_ORDER,
    };

    BST() = default;
    ~BST();

    void insert(const double& element);
    bool contains(const double& element) const;
    double returnMaxVal() const;
    double returnMinVal() const;
    bool remove(const double& element);

    void printTraversal(TRAVERSAL traverseOption) const;

    void printNode(const double& element) const {
        if (!this->contains(this->root, element)) {
            std::cout << "This node does not exist" << std::endl;
            return;
        }
        Node* target = search(this->root, element);
        std::cout << "Data: " << target->data << std::endl;
        std::cout << "Left: " << target->left << std::endl;
        std::cout << "Right: " << target->right << std::endl;
    }

    void printBST(const std::string& prefix, const Node* node, bool isLeft) {
        if( node != nullptr ) {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the value of the node
            std::cout << "[" << node->data << "]"<< std::endl;

            // enter the next tree level - left and right branch
            printBST( prefix + (isLeft ? "│   " : "    "), node->left, true);
            printBST( prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
    }
    void printBST() {
        printBST("", this->root, false);
    }

    void print() const {
        if (root == nullptr) {
            std::cout << "The tree is empty.\n";
        } else {
            printInOrder(root);
            std::cout << "\n";
        }
    }


};

#endif
