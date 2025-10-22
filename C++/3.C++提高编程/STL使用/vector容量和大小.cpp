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

    if(v1.empty())
        cout << "v1为空" << endl;
    else {
        cout << "v1不为空"  << endl;
        cout << "v1的容量为：" << v1.capacity() << endl;
        cout << "v1的大小为：" << v1.size() << endl;
    }
    printVec(v1);

    v1.resize(15,1);
    printVec(v1);

    v1.resize(5);
    printVec(v1);

    return 0;

}