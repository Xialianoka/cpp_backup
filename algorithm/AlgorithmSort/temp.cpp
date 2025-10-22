#include <iostream>
#include <ctime>
#include <random>
#include <vector>

#include "getRandomArray.cpp"
#include "printVec.cpp"

using namespace std;

void mySwap(vector<int> &nums, int i, int r) {
    int temp = nums[i];
    nums[i] = nums[r];
    nums[r] = temp;
}

void quickSort() {
    
}

int main()
{
    vector<int> nums;
    getRandomNum(nums, 1000, 10000);
    cout << "原数组：" << endl;
    printVec(nums);
    cout << endl;


    quickSort(nums,0,nums.size()-1);
    cout << "排序后的数组：" << endl;
    printVec(nums);

    return 0;

}