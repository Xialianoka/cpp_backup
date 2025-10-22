#include<iostream>
using namespace std;

//占位参数,目前的占位参数用不到
void func(int a, int){
    cout << "This is func" << endl;
}

int main()
{

    func(10,10);
    system("pause");
    return 0;
}