
#include <iostream>
#include <vector>

#include "binary-sort.h"
#include "bubble-sort.h"
#include "quick-sort.h"

void printVector(const std::vector<double>& inpVector,
                 std::string_view textBefore = "");
int testQuickSort(std::vector<double> inpVector);
int testBinarySort(std::vector<double> inpVector);
int testBubbleSort(std::vector<double> inpVector);

int main() {
    std::vector<double> inp = {1, 80, 38, -1, 100, 1000, 1029};
    /* return testQuickSort(inp); */
    /* return testBinarySort(inp); */
    return testBubbleSort(inp);
}

int testQuickSort(std::vector<double> inpVector) {
    quickSort2(inpVector, 0, inpVector.size() - 1);

    printVector(inpVector);
    return 0;
}

int testBubbleSort(std::vector<double> inpVector) {
    bubbleSort(inpVector);

    printVector(inpVector);
    return 0;
}
int testBinarySort(std::vector<double> inpVector) {
    binarySort(inpVector);

    return 0;
}

void printVector(const std::vector<double>& inpVector,
                 std::string_view textBefore) {
    std::cout << textBefore;
    for (const double& elem : inpVector) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";
}
