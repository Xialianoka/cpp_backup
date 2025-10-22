#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

int main()
{
    string str1("Hello World!!!");
    string str2("nihao shijie");
    for(string::size_type index = 0; index < str1.size(); index++)
        str1[index] = 'x';
    decltype(str1.size()) i = 0;
    while(str2[i] != '\0') {
        str2[i] = 'x';
        i++;
    }
    cout << str1 << std::endl;
    cout << str2 << std::endl;

    return 0;
}