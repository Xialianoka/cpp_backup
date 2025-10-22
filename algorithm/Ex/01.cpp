/*
    一、实现三个最基础的排序算法：
    1.选择排序，时间复杂度O(n²)
    2.插入排序，时间复杂度O(n²)
    3.冒泡排序，时间复杂度O(n²)
    二、实现对数器，用于检测算法正确性
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

void selectionSort(vector<int> &nums);
void insertSort(vector<int> &nums);
void bubbleSort(vector<int> &nums);
void mergeSort(vector<int> &nums);
void mySwap(vector<int> &nums, int a, int b);
vector<int> getRandomArray(int maxSize, int maxValue);

int main() {

    int maxTimes = 100000;   // 执行次数
    int maxValue = 1000; // 随机数组最大值([-maxValue, maxValue])
    int maxSize = 1000;  // 随机数组长度
    vector<int> nums1;
    vector<int> nums2;
    // 对数器
    for (int i = 1; i <= maxTimes; ++i) {
        nums1 = getRandomArray(maxSize, maxValue);
        nums2 = nums1;
        selectionSort(nums1);
        sort(nums2.begin(), nums2.end());
        if (nums2 != nums1) {
            cout << "Shit!!!!" << endl;
            return 0;
        }
    }
    cout << "nice!!!" << endl;
    return 0;
}

/*
    选择排序的实现方法：
    首先排除长度不符合要求的情况；
    两层for循环，外层表示目前要解决的数组下标位置
    内层负责遍历数组寻找符合条件的下标
*/
void selectionSort(vector<int> &nums){

    if (nums.size() < 2) {
        return;
    }
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            minIndex = nums[j] < nums[minIndex] ? j : minIndex;
        }
        mySwap(nums, i, minIndex);
    }
}


void insertSort(vector<int> &nums){


}


void bubbleSort(vector<int> &nums) {


}

void mySwap(vector<int> &nums, int a, int b) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

/*
    配合对数器使用，用于生成随机数组
    maxSize: 随机数组的最大长度
    maxValue: 随机数组上下限的最大绝对值
*/
vector<int> getRandomArray(int maxSize, int maxValue) {
    default_random_engine e;
    uniform_real_distribution<double> u(0.0, 1.0);
    e.seed( time(0) );
    vector<int> nums(0);

    int len = (int)(maxSize + 1)*(u(e));
    for (int i = 0; i < len; i++){
        int temp = (int)((maxValue + 1)*(u(e))) - (int)((maxValue)*(u(e)));
        // int temp = rand() % 100;
        nums.push_back(temp);
    }
    return nums;
}