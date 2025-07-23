
#include "bubble-sort.h"

void bubbleSort(std::vector<double>& inp) {
    size_t vecSize = inp.size();

    // For n times
    for (size_t i = 0; i < vecSize; i++) {
        // Loop through every pair
        for (size_t j = 0; j < vecSize - 1; j++) {
            if (inp.at(j) > inp.at(j + 1)) swap(inp, j, j + 1);
        }
    }
}
