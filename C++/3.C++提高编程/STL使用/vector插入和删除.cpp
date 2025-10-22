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
    //尾插
    v1.push_back(50);
    v1.push_back(50);
    v1.push_back(50);
    v1.push_back(50);
    v1.push_back(50);
    printVec(v1);

    //尾删
    v1.pop_back();
    printVec(v1);

    //插入
    v1.insert(v1.begin(),100);
    printVec(v1);

    v1.insert(v1.begin(), 2, 200);
    printVec(v1);

    //删除
    v1.erase(v1.begin());
    printVec(v1);

    //清空
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVec(v1);

    return 0;

}