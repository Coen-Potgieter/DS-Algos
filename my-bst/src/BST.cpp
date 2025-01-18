
#include "BST.h"

void BST::deleteTree(Node* root) {
    if (!root) {
        return;
    }

    this->deleteTree(root->left);
    this->deleteTree(root->right);

    delete root;
}

BST::Node* BST::add(Node* node, const double& element) {

    if (!node) { // If nullptr
        node = new Node(element);
    } else if (element < node->data) { // recurse down left
        node->left = this->add(node->left, element);
    } else if (element > node->data) { // recurse down right
        node->right = this->add(node->right, element);
    } else {
        // This is the condition for equal elements
        //  - Here we are skipping the insertion, but after this recursive func is done the size is incremented
        //  - Thus, we decrement it here to cancel out
        this->size -= 1;
    }
    return node;
}

BST::~BST() {
    this->deleteTree(this->root);
}

void BST::insert(const double& element) {

    // If tree is uninitialised
    if (!this->root) {
        this->root = new Node(element);
    } else {
        this->add(this->root, element);
    }
    // increment tree size
    this->size += 1;
}

bool BST::contains(const double& element) const {
    return contains(this->root, element);
}

bool BST::contains(Node* node, const double& element) const {

    if (!node) { // nullptr
        return false;
    } else if (node->data == element) {
        return true;
    } else if (element < node->data) { // target may be in left subtree
        return this->contains(node->left, element);
    } else { // Target May be in the right subtree
        return this->contains(node->right, element);
    }
}

BST::Node* BST::search(Node* node, const double& element) const {
    if (element == node->data) {
        return node;
    } else if (element < node->data) {
        return node->left;
    } else {
        return node->right;
    }
}

void BST::printTree() const {

    if (!this->root) {
        std::cout << "BST is empty" << std::endl;
        return;
    }

    std::queue<Node*> q;
    q.push(this->root);
    int nodeIdx = 0;

    while (!q.empty()) {

        Node* currNode = q.front();
        q.pop();

        std::cout << "Node #" << nodeIdx << ": " << std::endl;
        std::cout << "\tAddress: " << currNode << ": " << std::endl;
        std::cout << "\tData: " << currNode->data << std::endl;
        std::cout << "\tLeft: " << currNode->left << std::endl;
        std::cout << "\tRight: " << currNode->right << std::endl;

        if (currNode->left) {
            q.push(currNode->left);
        }
        if (currNode->right) {
            q.push(currNode->right);
        }
        nodeIdx += 1;
    }
    std::cout << std::endl;
}






