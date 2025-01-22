
#include <vector>
#include <iostream>

void quickSort(std::vector<double>& arr, int lo, int hi);


int main() {

    std::vector<double> inp = { 1, 80, 38, -1, 100, 1000, 1029 };

    quickSort(inp, 0, inp.size() - 1);

    for (const double& elem : inp) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
    return 0;

}




void swap(std::vector<double>& arr, int elem1, int elem2) {
    double tmp = arr[elem1];
    arr[elem1] = arr[elem2];
    arr[elem2] = tmp;
}
int partition(std::vector<double>& arr, int lo, int hi) {

    // Not working because of changing pivot loc i think...
    
    // choose pivot
    int pivot = hi;

    // init leftWall
    int leftWall = lo;

    int i = lo + 1;
    while (i < arr.size()) {
        if (arr[i] < arr[pivot]) {
            swap(arr, i, leftWall);
            leftWall++;
        }
        i++;
    }

    swap(arr, leftWall, pivot);

    return leftWall;
}

void quickSort(std::vector<double>& arr, int lo, int hi) {

    if (lo < hi) {
        int pivotIdx = partition(arr, lo, hi);
        quickSort(arr, lo, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, hi);
    }

}
