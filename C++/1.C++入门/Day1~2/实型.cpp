#include <iostream>
using namespace std;
int main()
{
    cout << "float类型占用内存空间：" << sizeof(float) << endl;
    cout << "double类型占用内存空间：" << sizeof(double) << endl;

    //科学计数法
    float f = 3e2;  //3*10^2
    cout << "f=" << f << endl;
    float f1 = 3e-2;    //3*0.1^2
    cout << "f1=" << f1 << endl;

    system("pause");
    return 0;
}