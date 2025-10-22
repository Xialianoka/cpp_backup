#include<iostream>
using namespace std;

int main()
{
    //int temp = 10; int &ref = temp;
    const int &ref = 10;

    cout << ref;
    return 0;
}