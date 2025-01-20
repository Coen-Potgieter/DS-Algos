
#include <climits>
#include <iostream>
#include <vector>


int maxSumSubArrayNaive(const std::vector<int>& nums, const int k);
int maxSumSubArraySlidingWindow(const std::vector<int>& nums, const int k);
int variableSizeSlidingWindow(const std::vector<int>& nums, const int s);

int main() {

    std::vector<int> inp = { 1, 2, 6, 2, 4, 1 };
    std::cout << maxSumSubArrayNaive(inp, 3) << std::endl;
    std::cout << maxSumSubArraySlidingWindow(inp, 3) << std::endl;
    std::cout << variableSizeSlidingWindow(inp, 12) << std::endl;
    return 0;
}


int sumArray(const std::vector<int> inp) {
    int runningSum = 0;
    for (const int& elem : inp) {
        runningSum += elem;
    }
    return runningSum;
}

int maxSumSubArrayNaive(const std::vector<int>& nums, const int k) {
    std::vector<int> subArr(k, 0);
    int runningMax = 0;
    int subSum;
    for (int i = 0; i <= (nums.size() - k); i++) {
        for (int j = 0; j < k; j++) {
            subArr[j] = nums[i + j];
        }

        subSum = sumArray(subArr);
        if (subSum > runningMax) runningMax = subSum;
    }
    return runningMax;
}


int maxSumSubArraySlidingWindow(const std::vector<int>& nums, const int k) {
    int runningMax = 0;
    int windowSum = 0;

    for (int i = 0; i <= nums.size(); i++) {
        // Continuosly add to windowSum
        windowSum += nums[i];

        if (i >= (k - 1)) {
            // Only check max when window is large enough
            if (windowSum > runningMax) runningMax = windowSum;

            // Shrink the window
            windowSum -= nums[i - (k - 1)];
        }
    }
    return runningMax;
}

int variableSizeSlidingWindow(const std::vector<int>& nums, const int s) {

    int windowSum = 0;
    int minLength = INT_MAX;
    int start = 0;

    for (int end = 0; end < nums.size(); end++) {
        windowSum += nums[end];

        while (windowSum >= s) {
            if ((end - start + 1) < minLength) minLength = end - start + 1;
            windowSum -= nums[start];
            start ++;
        }
    }
    return minLength;
}
