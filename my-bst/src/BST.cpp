
#include "BST.h"

void BST::deleteTree(Node* node) {
    if (!node) {
        return;
    }

    this->deleteTree(node->left);
    this->deleteTree(node->right);

    delete node;
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
        return this->search(node->left, element);
    } else {
        return this->search(node->right, element);
    }
}


BST::Node* BST::findMax(Node* startingNode) const {
    BST::Node* trav = startingNode;
    while (trav->right) {
        trav = trav->right;
    }
    return trav;
}
double BST::returnMaxVal() const {
    BST::Node* maxNode = this->findMax(this->root);
    return maxNode->data;
}


BST::Node* BST::findMin(Node* startingNode) const {
    BST::Node* trav = startingNode;
    while (trav->left) {
        trav = trav->left;
    }
    return trav;
}
double BST::returnMinVal() const {
    BST::Node* maxNode = this->findMin(this->root);
    return maxNode->data;
}

BST::Node* BST::remove(Node* node, const double& element) {

    // Navigate
    if (element < node->data) {
        node->left = this->remove(node->left, element);
    } else if (element > node->data) {
        node->right = this->remove(node->right, element);
    } else {
        // We have now found our target node

        //  - Case 1
        if ((!node->left) && (!node->right)) {
            // Return nullptr after deleting the node
            delete node;
            node = nullptr;
        }

        // - Case 2
        else if ((!node->left)) {
            // Return the node's right subtree after deleting it 
            BST::Node* tmp = node;
            node = node->right;
            delete tmp;
        }

        // - Case 3
        else if ((!node->right)) {
            // Return the node's left subtree after deleting it 
            BST::Node* tmp = node;
            node = node->left;
            delete tmp;
        }

        // - Case 4: 
        else {
            // Find Either (Largest node in Left subtree || Smallest node in Right subtree)

            // 1. Find Largest in left subtree
            /* BST::Node* tmp = this->findMax(node->left); */
            /* node->data = tmp->data; */
            /* node->left = this->remove(node->left, node->data); */

            // 2. Find Smallest in right subtree
            BST::Node* tmp = this->findMin(node->right);
            node->data = tmp->data;
            node->right = this->remove(node->right, node->data);
        }
    }
    return node;
}

bool BST::remove(const double& element) {

    // Only call remove method if the element exists in our BST
    if (!this->contains(this->root, element)) {
        return false;
    }

    // Assign the returned node to root
    this->root = this->remove(this->root, element);
    this->size -= 1;
    return true;
}

void BST::printTraversal(BST::TRAVERSAL traverseOption) const {

}




