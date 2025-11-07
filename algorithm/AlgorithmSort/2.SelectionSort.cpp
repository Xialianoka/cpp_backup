#include <iostream>
#include <algorithm>

#include "getRandomArray.cpp"
#include "printVec.cpp"

using namespace std;

void myswap(vector<int> &nums, int i, int minIndex) {
    int tmp = nums[i];
    nums[i] = nums[minIndex];
    nums[minIndex] = tmp;
}

/*
选择排序
从数组的0下标开始遍历数组，每次遍历选取最小的数放到当前遍历的最前端：
1. 第一个for循环用来保存当前最小值该在的位置
2. 第二个for循环用来遍历寻找最小值
该算法不具备稳定性，在交换过程中会破坏稳定性
*/
void SelectionSort(vector<int>& nums) {
    if (nums.size() < 2) {
        return;
    }
    for (int i = 0; i < nums.size(); ++i) { // 保存最小值该在哪
        int minIndex = i;   // 保存最小值的数组索引
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[minIndex] > nums[j]) { // 寻找最小值
                minIndex = j;
            }
        }
        myswap(nums, minIndex, i);
    }
}

int main()
{
    vector<int> num;
    getRandomNum(num, 1000, 100);
    vector<int> help(num);

    SelectionSort(num);
    sort(help.begin(), help.end());
    for( int i = 0; i < num.size(); i++) {
        if (help[i] != num[i]) {
            cout << "g" << endl;
            return 0;
        }
    }

    cout << "y" << endl;
    return 0;
}

