#include <vector>
#include <iostream>

using namespace std;

void printVec(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }

    cout << endl;
}