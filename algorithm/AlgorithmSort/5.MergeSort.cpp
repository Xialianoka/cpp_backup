#include <iostream>
#include <vector>
#include <algorithm>

#include "getRandomArray.cpp"

using namespace std;

/*
    归并排序（递归方式实现）：
    三个函数，其作用分别为
    - mergeSort()算法入口函数
    - process()递归过程函数
    - merge()合并函数
    算法将一个整体数组分为左右两部分，经过一系列操作使得左右两部分
    分别有序，最后将左右两部分合并在一起使得整体有序，用到了分治思
    想，将整体大的问题分解为子问题，求解子问题最后得到大问题。
*/
void mergeSort(vector<int> &nums);
void process(vector<int> &nums, int l, int r);
void merge(vector<int> &nums, int l, int m, int r);

/*
    归并排序（非递归方式实现）：
    - mergeSort()算法入口函数
    - merge()归并函数
    算法自底向上合并数组每个子数组，用循环迭代方式模拟分割：
    i从1开始代表长度为1的子数组，每次循环成倍增长模拟合并，
*/
void mergeSort1(vector<int>& nums);
void merge1(vector<int>& nums, int l, int m, int r);

int main()
{
    int maxtimes = 10000;  // 测试次数
    int maxsize = 1000; // 数组最大长度
    int maxvalue = 1000;    // 数组最大绝对值

    vector<int> nums1;
    vector<int> nums2;
    for (int i = 0; i < maxtimes; ++i) {
        getRandomNum(nums1, maxsize, maxvalue);
        nums2 = nums1;
        mergeSort1(nums1);
        sort(nums2.begin(), nums2.end());
        if (nums2 != nums1) {
            cout << "No!!!" << endl;
            return 0;
        }
    }
    cout << "Nice!!!" << endl;
    return 0;
}

void mergeSort(vector<int> &nums) {
    if (nums.size() < 2) return;
    process(nums, 0, nums.size() - 1);
}

void process(vector<int> &nums, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = l + ((r - l) >> 1);
    process(nums, l, mid);
    process(nums, mid + 1, r);
    merge(nums, l, mid, r);
}

void merge(vector<int> &nums, int l, int m, int r) {
    vector<int> help(r - l + 1, 0);
    int i = 0;
    int p1 = l, p2 = m + 1;
    while (p1 <= m && p2 <= r) {
        help[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
    }

    while (p1 <= m) {
        help[i++] = nums[p1++];
    }
    while (p2 <= r) {
        help[i++] = nums[p2++];
    }

    for (i = 0; i < help.size(); ++i) {
        nums[i + l] = help[i];
    }
}

void mergeSort1(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i += i) {
        for (int left = 0; left < n - i; left += (i + i)) {
            int mid = left + i - 1;
            int right = min(left + i + i - 1, n - 1);
            merge1(nums, left, mid, right);
        }
    }
}

void merge1(vector<int>& nums, int l, int m, int r) {
    vector<int> help(r - l + 1, 0);
    int p1 = l, p2 = m + 1;
    int i = 0;
    while (p1 <= m && p2 <= r) {
        help[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
    }
    while (p1 <= m) {
        help[i++] = nums[p1++];
    }
    while (p2 <= r) {
        help[i++] = nums[p2++];
    }

    i = 0;
    while (i < help.size()) {
        nums[l++] = help[i++];
    }
}

