#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    for(int i = 0 ; i < 10; i++) {
        cout << v1[i] << ' ' ;
    }
    cout << endl;

    for(int i = 0 ; i < 10; i++) {
        cout << v1.at(i) << ' ' ;
    }
    cout << endl;

    cout << "V1的第一个元素为：" << v1.front() << endl;
    cout << "v1的最后一个元素为：" << v1.back() << endl;


    return 0;
}