
#include <vector>

#ifndef QUICKSORT_H
#define QUICKSORT_H

void swap(std::vector<double>& arr, int idx1, int idx2);
int partition(std::vector<double>& arr, int lo, int hi);
void quickSort(std::vector<double>& arr, int lo, int hi);

void quickSort2(std::vector<double>& arr, int lo, int hi);
int partition2(std::vector<double>& arr, int lo, int hi);

#endif
