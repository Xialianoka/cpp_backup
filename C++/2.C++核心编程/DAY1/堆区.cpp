#include <iostream>
using namespace std;

int *func() //堆区开辟数据
{
    int *a = new int(10);
    return a;
}

int main()
{
    //在堆区开辟数据
    //指针 本质也是局部变量，放在栈上
    int *p = func();

    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;



    system("pause");
    return 0;
}