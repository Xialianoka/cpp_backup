#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string a = "aabb";
    string b = "aabb";
    if (a == b)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
    char c[] = {'a', 'b', 'c'};
    char d[] = "abc";   //有空字符'\0'
    if (strcmp(c, d) == 0)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}