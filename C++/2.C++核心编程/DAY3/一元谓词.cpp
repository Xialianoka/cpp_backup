#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct GreaterFive
{
    bool operator()(int val) {
        return val > 5;
    }

};

int main()
{
    vector<int> nums;
    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
    }

    vector<int>::iterator it = find_if(nums.begin(), nums.end(), GreaterFive());
    if(it == nums.end()) {
        cout << "未找到大于5的数组" << endl;
    }
    else
        cout << "找到大于5的数字为: "  << *it << endl;

    return 0;

}