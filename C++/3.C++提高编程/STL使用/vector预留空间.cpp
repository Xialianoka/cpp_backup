#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    // v1.reserve(100000);
    int *p = nullptr;
    int num = 0;    //统计扩容次数

    for(int i = 0; i < 100000; i++) {
        v1.push_back(i);
        if(p != &v1[0]){
            p = &v1[0];
            num++;
        }
    }

    cout << num << endl;

    return 0;

}