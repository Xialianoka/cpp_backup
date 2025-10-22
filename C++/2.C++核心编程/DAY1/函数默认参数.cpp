#include<iostream>
using namespace std;

int func(int a, int b = 20, int c = 30){//左边第一个开始后面每个都必须有默认值
    return a + b + c;
}

//如果函数声明有默认参数，则实现不能有默认参数
//声明和实现只能有一个有默认参数
int func1(int a = 10);

int main()
{
    int ans = func(10, 30);
    cout << ans;
    return 0;
}

int func1(int a){
    return a;
}