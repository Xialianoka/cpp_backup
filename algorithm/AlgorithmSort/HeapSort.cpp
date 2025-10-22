#include <iostream>
#include <random>
#include <vector>

#include "getRandomArray.cpp"
#include "printVec.cpp"

using namespace std;

void mySwap (vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;

}

void heapInsert(vector<int> &nums, int index) {
    while (nums[index] > nums[(index - 1) >> 1]) {
        mySwap(nums, index, (index - 1) >> 1);
        index = (index - 1) >> 1;
    }
}

void heapify(vector<int> &nums, int index, int heapSize) {
    int left = 2 * index + 1;
    while (left < heapSize) {
        int largest = left + 1 < heapSize && nums[left + 1] > nums[left] ? left + 1 : left;
        largest = nums[largest] > nums[index] ? largest : index;
        if (largest == index)
            break;
        mySwap(nums, largest, index);
        index = largest;
        left = 2 * index + 1;
    }
}

void heapSort(vector<int> &nums) {
    if (nums.size() < 2) {
        return;
    }
    int heapSize = nums.size();
    for (int i = 0; i < heapSize; ++i) {
        heapInsert(nums, i);
    }

    mySwap(nums, 0, --heapSize);
    while (heapSize > 0) {
        heapify(nums, 0, heapSize);
        mySwap(nums, 0, --heapSize);
    }
}

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
        heapSort(nums1);
        sort(nums2.begin(), nums2.end());
        if (nums2 != nums1) {
            cout << "No!!!" << endl;
            return 0;
        }
    }
    cout << "Nice!!!" << endl;
    return 0;
}