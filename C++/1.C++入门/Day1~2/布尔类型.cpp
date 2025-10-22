#include <iostream>
using namespace std;

int main()
{
    //1、创建布尔类型（非零的值都是真）
    bool flag = true;   //flag为真
    cout << flag << endl;

    flag = false;   //flag为假
    cout << flag << endl;
    // 2、查看bool类型所占内存空间
    cout << "bool类型占用的内存空间：" << sizeof(bool) << endl;

    system("pause");
    return 0;
}