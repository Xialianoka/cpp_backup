#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <stack>

#include "getRandomArray.cpp"
#include "printVec.cpp"

using namespace std;

void mySwap(vector<int> &nums, int i, int r) {
    int temp = nums[i];
    nums[i] = nums[r];
    nums[r] = temp;
}

vector<int> partition(vector<int>& nums, int l, int r) {
    int less = l - 1;
    int more = r;
    while (l < more) {
        if (nums[l] < nums[r]) {
            mySwap(nums, ++less, l++);
        } else if (nums[l] > nums[r]) {
            mySwap(nums, --more, l);
        } else {
            ++l;
        }
    }
    mySwap(nums, r, more);
    return {less + 1, more};
}

void quickSort(vector<int>& nums, int l, int r) {
    if (l < r) {
        int index = l + rand() % (r - l + 1);
        mySwap(nums, index, r);
        vector<int> p = partition(nums, l, r);
        quickSort(nums, l, p[0] - 1);
        quickSort(nums, p[1] + 1, r);
    }
}

void quickSort1(vector<int>& nums) {
    if (nums.size() < 2) {
        return;
    }
    stack<pair<int, int>> st;
    st.push({0, nums.size() - 1});

    while (!st.empty()) {
        int l = st.top().first;
        int r = st.top().second;
        st.pop();

        if (l < r) {
            int index = l + rand() % (r - l + 1);
            mySwap(nums, index, r);
            vector<int> p = partition(nums, l, r);
            st.push({l, p[0] - 1});
            st.push({p[1] + 1, r});
        }
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
        quickSort(nums1, 0, nums1.size() - 1);
        sort(nums2.begin(), nums2.end());
        if (nums2 != nums1) {
            cout << "No!!!" << endl;
            return 0;
        }
    }
    cout << "Nice!!!" << endl;
    return 0;
}