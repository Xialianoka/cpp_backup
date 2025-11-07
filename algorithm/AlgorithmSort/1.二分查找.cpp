#include <iostream>
#include <vector>

#include "getRandomArray.cpp"
#include "printVec.cpp"

using namespace std;

int process(vector<int> &nums, int L, int R) {
    if(L == R)
        return nums[L];
    int mid = L + ((R - L) >> 1);
    int leftMax = process(nums, L, mid);
    int rightMax = process(nums, mid + 1, R);
    return max(leftMax, rightMax);
}

int getMaxNum(vector<int> &nums) {
    return process(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums;
    getRandomNum(nums, 10000, 1000000);
    printVec(nums);
    cout << "最大值为：" << getMaxNum(nums) << endl;

    return 0;
}