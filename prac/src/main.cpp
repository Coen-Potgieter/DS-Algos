#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Node {
    int value;
    Node *left;
    Node *right;
    Node(const int newElem) : value(newElem), left(nullptr), right(nullptr) {}
};

enum PrintMethod { PREORDER, POSTORDER, INORDER, LEVELORDER };

Node *makeTree(const std::vector<int> &inp);
Node *findNode(Node *node, const int &value);
bool nodeExists(Node *root, const int &value);
Node *insertTree(Node *node, const int &value);
void printTree(Node *root, PrintMethod printMethod);

int binarySearchIterative(std::vector<int> inp, const int &target);
int binarySearchRecursiveHandler(std::vector<int> inp, const int &target);
void sortArray(std::vector<int> &inp, const bool asc = true);

int main() {
    std::vector<int> myInp = {11, 6, 15, 3, 8, 13, 17, 1, 5, 12, 14, 19};

    int targetIdx = binarySearchIterative(myInp, 6);
    int targetIdx2 = binarySearchRecursiveHandler(myInp, 6);
    std::cout << targetIdx << '\n';
    std::cout << targetIdx2 << '\n';
    return 0;

    Node *myRoot = nullptr;
    try {
        myRoot = makeTree(myInp);
    } catch (const std::invalid_argument &e) {
        std::cout << e.what() << '\n';
        return 1;
    }

    std::cout << "LEVEL ORDER:\n    ";
    printTree(myRoot, PrintMethod::LEVELORDER);
    std::cout << "PRE ORDER:\n    ";
    printTree(myRoot, PrintMethod::PREORDER);
    std::cout << "IN ORDER:\n    ";
    printTree(myRoot, PrintMethod::INORDER);
    std::cout << "POST ORDER:\n    ";
    printTree(myRoot, PrintMethod::POSTORDER);

    int checkVal = 2;

    std::cout << "Does " << checkVal << " Exist? -> ";
    if (nodeExists(myRoot, checkVal))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}

int binarySearchIterative(std::vector<int> inp, const int &target) {
    bool isSorted =
        (std::is_sorted(inp.begin(), inp.end()) ||
         std::is_sorted(inp.begin(), inp.end(), std::greater<int>()));

    if (!isSorted) {
        sortArray(inp, true);
    }

    std::cout << "Sorted Array:\n   ";
    for (const int &elem : inp) {
        std::cout << elem << ", ";
    }
    std::cout << '\n';

    int hi = inp.size() - 1;
    int lo = 0;

    while (1) {
        int mid = lo + ((hi - lo) / 2);

        if (inp.at(mid) == target) {
            return mid;
        }

        if (lo > hi) {
            return -1;
        }
        if (target > inp.at(mid)) {
            lo = mid + 1;
        } else if (target < inp.at(mid)) {
            hi = mid - 1;
        }
    }
}

int binarySearchRecursive(const std::vector<int> &inp, int lo, int hi,
                          const int &target) {
    int mid = lo + ((hi - lo) / 2);

    if (inp.at(mid) == target)
        return mid;
    else if (lo > hi)
        return -1;
    else if (target < inp.at(mid))
        hi = mid - 1;
    else if (target > inp.at(mid))
        lo = mid + 1;

    return binarySearchRecursive(inp, lo, hi, target);
}

int binarySearchRecursiveHandler(std::vector<int> inp, const int &target) {
    bool isSorted =
        (std::is_sorted(inp.begin(), inp.end()) ||
         std::is_sorted(inp.begin(), inp.end(), std::greater<int>()));

    if (!isSorted) {
        sortArray(inp, true);
    }

    std::cout << "Sorted Array:\n   ";
    for (const int &elem : inp) {
        std::cout << elem << ", ";
    }
    std::cout << '\n';

    return binarySearchRecursive(inp, 0, inp.size() - 1, target);
}

bool compare(bool asc, int num1, int num2) {
    if (asc) {
        return (num1 > num2) ? true : false;
    } else {
        return (num1 < num2) ? true : false;
    }
}

void sortArray(std::vector<int> &inp, const bool asc) {
    for (size_t i = 0; i < inp.size(); i++) {
        for (size_t j = 0; j < inp.size() - 1; j++) {
            if (compare(asc, inp.at(j), inp.at(j + 1))) {
                int tmp = inp.at(j);
                inp[j] = inp.at(j + 1);
                inp[j + 1] = tmp;
            }
        }
    }
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

Node *findNode(Node *node, const int &value) {
    if (!node)
        node = nullptr;
    else if (value < node->value)
        node = findNode(node->left, value);
    else if (value > node->value)
        node = findNode(node->right, value);

    return node;
}

bool nodeExists(Node *root, const int &value) {
    if (!findNode(root, value))
        return false;
    else
        return true;
}

Node *insertTree(Node *node, const int &value) {
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

Node *removeNode(Node *node, const int &value) {}

void inOrderPrint(Node *node) {
    // If null node then return
    if (!node) return;

    inOrderPrint(node->left);
    std::cout << node->value << ", ";
    inOrderPrint(node->right);
}

void preOrderPrint(Node *node) {
    // If null node then return
    if (!node) return;

    std::cout << node->value << ", ";
    preOrderPrint(node->left);
    preOrderPrint(node->right);
}

void postOrderPrint(Node *node) {
    // If null node then return
    if (!node) return;

    postOrderPrint(node->left);
    postOrderPrint(node->right);
    std::cout << node->value << ", ";
}

void printTree(Node *root, PrintMethod printMethod) {
    if (printMethod == PrintMethod::LEVELORDER) {
        std::queue<Node *> myQueue;

        myQueue.push(root);

        while (!myQueue.empty()) {
            Node *currNode = myQueue.front();
            myQueue.pop();
            std::cout << currNode->value << ", ";
            if (currNode->left) myQueue.push(currNode->left);
            if (currNode->right) myQueue.push(currNode->right);
        }

        std::cout << '\n';
    } else if (printMethod == PrintMethod::INORDER) {
        inOrderPrint(root);

        std::cout << '\n';
    } else if (printMethod == PrintMethod::PREORDER) {
        preOrderPrint(root);

        std::cout << '\n';
    } else if (printMethod == PrintMethod::POSTORDER) {
        postOrderPrint(root);

        std::cout << '\n';
    }
}
