#include <algorithm>
#include <iostream>
#include <vector>

#include "getRandomArray.cpp"

using namespace std;

void shellSort(vector<int>& nums, int len) {
  int gap, i, j;
  int temp;
  for (gap = len >> 1; gap > 0; gap >>= 1) {
    for (i = gap; i < len; ++i) {
      temp = nums[i];
      for (j = i - gap; j >= 0 && nums[j] > temp; j -= gap) {
        nums[j + gap] = nums[j];
      }
      nums[j + gap] = temp;
    }
  }
}

int main() {
  int maxtimes = 10000;  // 测试次数
  int maxsize = 1000;    // 数组最大长度
  int maxvalue = 1000;   // 数组最大绝对值

  vector<int> nums1;
  vector<int> nums2;
  for (int i = 0; i < maxtimes; ++i) {
    getRandomNum(nums1, maxsize, maxvalue);
    nums2 = nums1;
    shellSort(nums1, nums1.size());
    sort(nums2.begin(), nums2.end());
    if (nums2 != nums1) {
      cout << "No!!!" << endl;
      return 0;
    }
  }
  cout << "Nice!!!" << endl;
  return 0;
}