#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "Hello World";
    int len = str1.length();

    for(int i = 0; i < len; i++){
        cout << str1[i];
    }
    cout << endl;

    for(int i = 0; i < len; i++) {
        cout <<str1.at(i);
    }
    cout << endl;

    str1[0] = 'X';
    str1.at(1) = 'Y';
    cout << str1 << endl;

    str1.erase(0,2);
    cout << str1 << endl;

    str1.insert(0,"He");
    cout << str1 << endl;

    str1.insert(str1.length(), str1);
    cout << str1 << endl;


    string str2 = str1.substr(1,5);
    cout << str2 << endl;

    return 0;
}