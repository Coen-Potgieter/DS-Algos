#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct Node {
  int value;
  Node *left;
  Node *right;
  Node(const int newElem) : value(newElem), left(nullptr), right(nullptr) {}
};

Node *makeTree(const std::vector<int> &inp);
Node *insertTree(Node *node, const int &value);
void printTree(Node *root);

int main() {

  std::vector<int> myInp = {1, 2, 4, 5, 6, 6};

  Node *myRoot = nullptr;
  try {
    myRoot = makeTree(myInp);
  } catch (const std::invalid_argument &e) {
    std::cout << e.what() << '\n';
    return 1;
  }
  printTree(myRoot);
}

Node *makeTree(const std::vector<int> &inp) {

  if (inp.size() <= 0) {
    throw std::invalid_argument("Input Vector Is Empty...");
  }

  Node *myRoot = nullptr;
  for (const int elem : inp) {
    std::cout << "Inserting: " << elem << " Into The Tree!\n";
    myRoot = insertTree(myRoot, elem);
  }
  return myRoot;
}

Node *insertTree(Node *node, const int &value) {

  // This Shouldn't happen...
  if (!node) {
    node = new Node(value);
  } else if (value < node->value) {
    node->left = insertTree(node->left, value);
  } else if (value > node->value) {
    node->right = insertTree(node->right, value);
  } else if (value == node->value) {
  }
  return node;
}

void printTree(Node *root) {
  std::queue<Node *> myQueue;
  myQueue.push(root);

  while (!myQueue.empty()) {
    Node *currNode = myQueue.front();
    myQueue.pop();
    std::cout << currNode->value << ", ";
    if (currNode->left)
      myQueue.push(currNode->left);
    if (currNode->right)
      myQueue.push(currNode->right);
  }

  std::cout << '\n';
}
