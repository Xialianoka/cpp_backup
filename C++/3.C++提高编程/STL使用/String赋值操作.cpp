#include <iostream>
#include <string>

using namespace std;

int main()
{
    string st1;
    st1 = "Hello World";

    string st2;
    st2 = st1;

    string st3;
    st3 = 'c';

    string st4;
    st4.assign("Hello World");

    string st5;
    st5.assign("Hello World", 6);

    string st6;
    st6.assign(st5);
    
    string st7;
    st7.assign(10, 'a');

    cout << st1 << endl << st2 << endl << st3 << endl << st4 << endl << st5 << endl << st6 << endl << st7 << endl;



    return 0;
}