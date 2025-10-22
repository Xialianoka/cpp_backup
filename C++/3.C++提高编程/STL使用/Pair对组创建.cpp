#include <iostream>
#include <string>

using namespace std;

int main()
{
    pair<string, int> p1(string("Tom"), 20);
    cout << p1.first << ' ' << p1.second << endl;

    pair<string, int> p2 = make_pair("Jhon", 21);
    cout << p2.first << ' ' << p2.second << endl;

    return 0;
}