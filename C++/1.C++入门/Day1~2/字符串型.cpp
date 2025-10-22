#include <iostream>
#include <string>   //用C++风格字符串时要包含这个头文件
using namespace std;

int main()
{
    //1、C风格的字符串
    char str[] = "Hello World";
    cout << str << endl;

    //2、C++风格的字符串
    //注意事项：使用C++风格字符串时要包含string头文件
    string str2 = "Hello World";
    cout << str2 << endl;

    system("pause");
    return 0;
}
