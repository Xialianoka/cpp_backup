#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &v) {
    
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVec(v1);

    vector<int> v2;
    for (int i = 10; i > 0 ;i--) {
        v2.push_back(i);
    }
    printVec(v2);

    v2.swap(v1);
    printVec(v1);
    printVec(v2);

    for(int i = 0; i < 100000; i++) {
        v2.push_back(i);
    }

    cout << "v2的大小为：" << v2.size() << endl;
    cout << "v2的容量为：" << v2.capacity() << endl;

    v2.resize(3);
    cout << "v2的大小为：" << v2.size() << endl;
    cout << "v2的容量为：" << v2.capacity() << endl;


    //利用swap函数实现内存收缩
    vector<int>(v2).swap(v2);
    cout << "v2的大小为：" << v2.size() << endl;
    cout << "v2的容量为：" << v2.capacity() << endl;


    return 0;
}