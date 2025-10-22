#include <iostream>
#include <vector>

using namespace std;

#include "getRandomArray.cpp"
#include "printVec.cpp"

void countSort(std::vector<int> &nums) {
    if (nums.size() < 2) {
        return;
    }
    vector<int> counter(200, 0);
    for (const int i : nums) {
        counter[i]++;
    }
    int j = 0;
    int temp = 0;
    while (j < nums.size()) {
        while (counter[temp] > 0) {
            nums[j++] = temp;
            --counter[temp];
        }
        temp++;
    }
}

int main()
{
    std::vector<int> ages {18, 20, 21, 20, 19, 35, 23, 18, 26, 22};
    
    std::cout << "原始员工年龄：" << std::endl;
    printVec(ages);
    std::cout << std::endl;

    countSort(ages);
    std::cout << "排序后的员工年龄：" << std::endl;
    printVec(ages);

    return 0;
}