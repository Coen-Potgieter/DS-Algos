
#include <exception>
#include <iostream>

void printArr(const double* arr, const int& size);
int binarySearch(const double* arr, int lo, int hi, const double& target);
int binarySearchRec(const double* arr, int lo, int hi, const double& target);


int main() {

    double target = 90;
    double arr[] = { 1, 20, 38, 90, 100, 110, 1029 };
    int hi = sizeof(arr) / sizeof(arr[0]);

    const int targetIdx = binarySearchRec(arr, 0, hi, target);


    printArr(arr, hi);
    std::cout << "Index of Element " << target << ": " << targetIdx << std::endl;
    return 0;
}



int binarySearch(const double* arr, int lo, int hi, const double& target) {

    while (lo <= hi) {
       
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (target < arr[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;

}

int binarySearchRec(const double* arr, int lo, int hi, const double& target) {

    if (lo > hi) {
        return -1;
    }

    int mid = lo + ((hi - lo) / 2);

    if (arr[mid] == target) {
        return mid;
    }

    if (target < arr[mid]) {
        hi = mid - 1;
    } else {
        lo = mid + 1;
    }

    return binarySearchRec(arr, lo, hi, target);
}



// helper funcs not apart of binary search

void printArr(const double* arr, const int& size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Element @ Index " << i << ": " << arr[i] << std::endl;
    }
}
