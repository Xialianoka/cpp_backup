#include <iostream>
#include <vector>
#include <algorithm>

#include "getRandomArray.cpp"
#include "printVec.cpp"

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

/*
冒泡排序（大数向后冒）
和选择排序类似，不过这里把最大的往后挪，并且依次互换
1. 第一层for循环从i - 1开始，保存大数该去的位置
2. 第二层for循环从0开始，保证把大的数往后冒，不够大就不管了
该算法具有稳定性，在交换过程可以保证必须严格大于才做交换
*/
void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return;
    }
    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums, j, j + 1);
            }
        }
    }
}

int main()
{
    vector<int> nums;
    getRandomNum(nums, 100000, 100);
    vector<int> help(nums);
    bubbleSort(nums);
    sort(help.begin(), help.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (help[i] != nums[i]) {
            cout << "false" << endl;
        }
    }
    
    cout << "true" << endl;
    return 0;
}