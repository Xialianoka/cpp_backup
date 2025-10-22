#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "Hello World";
    string str2 = "or";
    
    int pos = str1.find("ll");
    cout << pos << endl;

    pos = str1.find(str2);
    cout << pos << endl;

    
    cout << pos << endl;

    return 0;

}