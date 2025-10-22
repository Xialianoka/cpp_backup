#include <iostream>
using namespace std;

int main()
{
    char ch = 'a';
    cout << ch << endl;

    cout << "char字符型变量所占内存：" << sizeof(char) << endl;

    // char ch2="b";//创建字符型变量要用单引号
    // char ch2='abc';//创建字符型变量，单引号只能有一个字符
    
    //字符型变量对应ASCII码
    cout << (int)ch << endl;

    system("pause");
    return 0;
}