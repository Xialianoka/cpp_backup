#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 10; i++) {

        v.push_back(i << 2);
    }

    int total = accumulate(v.begin(), v.end(), 0);

    cout << "总和为：" << total << endl;

    return 0;
}