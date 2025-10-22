#include <iostream>
using namespace std;

int main()
{

    //引用基本语法
    //数据类型 &别名 = 原名

    int a = 10;
    int &b = a;

    cout << a << endl;
    cout << b << endl;

    b = 20;
    cout << a << endl;
    cout << b << endl;
    system("pause");
    return 0;
}