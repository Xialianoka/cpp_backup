#include <iostream>
#include <algorithm>

#include "getRandomArray.cpp"
#include "printVec.cpp"

using namespace std;

/*
插入排序
插入和冒泡类似，但也有区别，插入排序是将数组看做有序和无序部分，将
无序部分的元素找到其在有序部分中的位置，使得整体有序。
1. 第一层for循环表示无序的元素
2. 第二层循环表示有序的元素，并在这层循环实现插入逻辑
该算法具有稳定性，可以保证插入的时候不破坏本来的先后顺序
*/
void insertionSort(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return;
    }
    for (int i = 1; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}

int main()
{
    vector<int> nums;
    getRandomNum(nums, 1000, 100);
    vector<int> help(nums);

    insertionSort(nums);
    sort(help.begin(), help.end());

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != help[i]) {
            cout << "false" << endl;
            return 0;
        }
    }

    cout << "true" << endl;
    return 0;

}

