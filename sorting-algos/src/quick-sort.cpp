
#include "quick-sort.h"



void swap(std::vector<double>& arr, int idx1, int idx2) {
    if (idx1 == idx2) return;
    double tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int partition(std::vector<double>& arr, int lo, int hi) {
    int pivot = hi; 
    int leftWall = lo; 
    int i = lo; 
    while (i <= hi) { 
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

void quickSort2(std::vector<double>& arr, int lo, int hi) {
    if (lo < hi) {
        int pivotIdx = partition2(arr, lo, hi);
        quickSort2(arr, lo, pivotIdx - 1);
        quickSort2(arr, pivotIdx + 1, hi);
    }
}

int partition2(std::vector<double>& arr, int lo, int hi) {

    int pivotVal = arr[lo];

    int left = lo + 1;
    int right = hi;

    while (1) {

        while (left <= right && arr[left] < pivotVal) {
            left++;
        }

        while (left <= right && arr[right] > pivotVal) {
            right--;
        }

        if (left > right) {
            break;
        }
        
        swap(arr, left, right);
        left++;
        right--;
    }
    swap(arr, lo, right);
    return right;
}













