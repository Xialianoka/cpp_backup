#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

#include "getRandomArray.cpp"
#include "printVec.cpp"

int maxBits(vector<int> &nums) {
    int maxNum = INT_MIN;
    for (const int i : nums) {
        maxNum = max(maxNum, i);
    }
    int res = 0;
    while (maxNum > 0) {
        maxNum /= 10;
        ++res;
    }
    return res;
}

int getDigit(int num, int d) {
    return num / (int) pow(10, d - 1) % 10;
}

void bucketSort(vector<int> &nums, int l, int r, int digit) {
    const int radix = 10;
    int i = 0, j = 0;
    vector<int> bucket(r - l + 1);
    for (int d = 1; d <= digit; ++d) {
        vector<int> count(radix, 0);
        for (i = l; i <= r; ++i) {
            j = getDigit(nums[i], d);
            ++count[j];
        }

        for (i = 1; i < radix; ++i) {
            count[i] += count[i - 1];
        }

        for (i = r; i >= l; --i) {
            j = getDigit(nums[i], d);
            bucket[count[j] - 1] = nums[i];
            --count[j];
        }

        for (i = l; i <= r; ++i) {
            nums[i] = bucket[i];
        }
    }
}

int main()
{
    vector<int> nums {2, 2, 3, 1, 9, 4, 32, 2352, 32, 235, 543, 6453, 3214, 2341};
    cout << "原数组：" << endl;
    printVec(nums);
    cout << endl;

    bucketSort(nums, 0, nums.size() - 1, maxBits(nums));
    cout << "排序后的数组：" << endl;
    printVec(nums);
    cout << endl;

    return 0;
}