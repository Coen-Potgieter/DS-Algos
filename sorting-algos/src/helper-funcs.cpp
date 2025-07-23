

#include "helper-funcs.h"

void swap(std::vector<double>& inp, size_t idx1, size_t idx2) {
    if (idx2 <= idx1)
        throw std::invalid_argument(
            "First Index Must Be Smaller Than The Second Index");

    if (inp.size() <= idx2) {
        std::string errorMessage =
            "Index " + std::to_string(idx2) + " Does Not Exist";
        throw std::invalid_argument(errorMessage);
    }

    double tmp = inp.at(idx1);
    inp[idx1] = inp.at(idx2);
    inp[idx2] = tmp;
}
