#include "LogarithmicDevice.h"
#include <vector>

void getRandomNum(vector<int> &nums, int maxSize, int maxValue) {
    default_random_engine e;
    uniform_real_distribution<double> u(0.0, 1.0);
    e.seed( time(0) );

    int len = (int)(maxSize + 1)*(u(e));
    for (int i = 0; i < len; i++){
        int temp = (int)((maxValue + 1)*(u(e))) - (int)((maxValue)*(u(e)));
        nums.push_back(temp);
    }
    return;
}