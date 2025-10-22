#include <iostream>
using namespace std;

int main()
{

    //1、应用必须初始化
    int a = 10;
    int &b = a;
    // int &b;//错误，必须初始化
    int c = 20;
    b = c;//赋值操作，不是更改引用

    cout << b << ' ' << a << ' ' << c << endl;
    system("pause");
    return 0;
}