
#include <vector>
#include <iostream>
#include "quick-sort.h"

int main() {

    std::vector<double> inp = { 1, 80, 38, -1, 100, 1000, 1029 };

    quickSort2(inp, 0, inp.size() - 1);

    for (const double& elem : inp) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
    return 0;

}
