#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "Hello";
    string str2 = "Hello";

    int ret = str1.compare(str2);
    int ret2 = str1.compare("World");

    if(ret == 0)
        cout << "str1 = str2" << endl;
    else
        cout << "str1 != str2" << endl;

    
    if(ret2  == 0)
        cout << "str1 == World"  << endl;
    else
        cout << "str1 != World" << endl;

    return 0;

}