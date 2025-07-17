

#include <iostream>
#include <math.h>
#include <queue>
#include <sstream>
#include <string>

#ifndef BST_H
#define BST_H

class BST {
private:
  struct Node {
    double data;
    Node *left;
    Node *right;
    Node(const double newElem) : data(newElem), left(nullptr), right(nullptr) {}
  };

  Node *root = nullptr;
  int size = 0;

  void deleteTree(Node *root);

  Node *add(Node *root, const double &element);
  bool contains(Node *node, const double &element) const;
  Node *search(Node *node, const double &element) const;
  Node *remove(Node *node, const double &element);
  Node *findMax(Node *startingNode) const;
  Node *findMin(Node *startingNode) const;
  void printPreorder(Node *node) const;
  void printInOrder(Node *node) const;
  void printPostorder(Node *node) const;
  void printLevelOrder(Node *node) const;

  void printBST(const std::string &prefix, const Node *node, bool isLeft) const;

public:
  enum TRAVERSAL {
    PREORDER,
    INORDER,
    POSTORDER,
    LEVEL_ORDER,
  };

  BST() = default;
  ~BST();

  void insert(const double &element);
  bool contains(const double &element) const;
  double returnMaxVal() const;
  double returnMinVal() const;
  bool remove(const double &element);
  void printTraversal(TRAVERSAL traverseOption) const;

  void emptyTree();

  void printBST() const;
};

#endif
