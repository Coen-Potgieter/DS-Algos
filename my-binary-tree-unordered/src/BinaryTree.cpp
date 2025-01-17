
#include "BinaryTree.h"

void BinaryTree::deleteTree(Node* root) {
    if (!root) {
        return;
    }

    this->deleteTree(root->left);
    this->deleteTree(root->right);

    delete root;
}

BinaryTree::~BinaryTree() {
    this->deleteTree(this->root);
}

void BinaryTree::insertBFS(const double element) {


    Node* newNode = new Node;
    newNode->data = element;
    newNode->left = nullptr;
    newNode->right = nullptr;
    this->size += 1;

    if (!this->root) {
        this->root = newNode;
        return;
    }

    std::queue<Node*> q;
    q.push(this->root);
    while (!q.empty()) {

        Node* currNode = q.front();
        q.pop();

        if (!currNode->left) {
            currNode->left = newNode;
            return;
        } else {
            q.push(currNode->left);
        }


        if (!currNode->right) {
            currNode->right = newNode;
            return;
        } else {
            q.push(currNode->right);
        }
    }

}



void BinaryTree::printTree() const {


    int currLevel = 0;
    int i = 1;
    int totalLevels = std::log2(this->size) + 1;

    std::string prePadSpace = "";
    for (int i = 0; i < totalLevels; i++) {
        prePadSpace += "  ";
    }

    std::queue<Node*> q;
    q.push(this->root);

    std::cout << prePadSpace;

    while (!q.empty()) {
        int newLevel = std::log2(i);
        if (newLevel > currLevel) {

            /* prePadSpace.pop_back(); */
            prePadSpace.pop_back();
            std::cout << std::endl << prePadSpace;

            currLevel += 1;
        }

        Node* currNode = q.front();
        q.pop();

        std::cout << currNode->data << " ";

        if (currNode->left) {
            q.push(currNode->left);
        }
        if (currNode->right) {
            q.push(currNode->right);
        }

        i += 1;
    }
    std::cout << std::endl;

}






