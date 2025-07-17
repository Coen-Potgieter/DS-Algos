
#include <vector>
#include <iostream>


std::vector<int> twoPointerMerge(std::vector<int> A, std::vector<int> B);


int main() {

    std::vector<int> A = { 1,2,3,5,9, 10 };
    std::vector<int> B = { 6,9,10,34};

    std::vector<int> C = twoPointerMerge(A, B);

    for (const int elem : C) {
        std::cout << elem << std::endl;
    }

    return 0;
}

std::vector<int> twoPointerMerge(std::vector<int> A, std::vector<int> B) {
    size_t ptrA = 0;
    size_t ptrB = 0;

    std::vector<int> C;

    while (ptrA < A.size() && ptrB < B.size()) {
        if (A[ptrA] <= B[ptrB]) {
            C.push_back(A[ptrA]);
            ptrA += 1;
        } else {
            C.push_back(B[ptrB]);
            ptrB += 1;
        }
    }

    while (ptrA < A.size()) {
        C.push_back(A[ptrA]);
        ptrA += 1;
    }

    while (ptrB < B.size()) {
        C.push_back(B[ptrB]);
        ptrB += 1;
    }

    return C;
}
