#include <iostream>
#include <set>

using namespace std;

int main()
{

    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(10);//不允许重复的元素

    //查找
    set<int>::iterator pos = s1.find(20);

    if (pos != s1.end()) {
        cout << "找到了元素" << *pos << endl;
    }
    else {
        cout << "未找到元素" << endl;
    }

    //统计
    int num = s1.count(10);
    cout << num << endl;

    return 0;
}

