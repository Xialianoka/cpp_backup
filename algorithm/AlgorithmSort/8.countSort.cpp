#include <iostream>
#include <vector>

using namespace std;

#include "getRandomArray.cpp"
#include "printVec.cpp"

/**
 * 计数排序
 * 1）使用一个count数组，统计原数组nums中的各个元素值的数量
 * 2）遍历count数组，将nums中的数重排
 * 需提前知道数据范围
 */

void countSort(std::vector<int>& nums) {
  if (nums.size() < 2) {
    return;
  }
  vector<int> count(200, 0);
  for (int num : nums) {
    count[num]++;
  }

  int i = 0;
  int index = 0;
  while (i < nums.size()) {
    while (count[index] > 0) {
      nums[i++] = index;
      count[index]--;
    }
    index++;
  }
  return;
}

int main() {
  std::vector<int> ages{18, 20, 21, 20, 19, 35, 23, 18, 26, 22};

  std::cout << "原始员工年龄：" << std::endl;
  printVec(ages);
  std::cout << std::endl;

  countSort(ages);
  std::cout << "排序后的员工年龄：" << std::endl;
  printVec(ages);

  return 0;
}