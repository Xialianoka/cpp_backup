#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;


// #include "LogarithmicDevice.h"

void getRandomNum(vector<int> &nums, int maxSize, int maxValue) {
    default_random_engine e;
    uniform_real_distribution<double> u(0.0, 1.0);
    e.seed( time(0) );

    nums.clear();
    int len = (int)(maxSize + 1)*(u(e));
    for (int i = 0; i < len; i++){
        int temp = (int)((maxValue + 1)*(u(e))) - (int)((maxValue)*(u(e)));
        // int temp = rand() % 100;
        nums.push_back(temp);
    }
    return;
}

// int main()
// {

//     vector<int> nums;
//     getRandomNum(nums,100,100);

//     for(int i = 0; i < nums.size(); i++) {
//         cout << nums[i] << " ";
//     }

//     cout << endl;

//     return 0;
// }

