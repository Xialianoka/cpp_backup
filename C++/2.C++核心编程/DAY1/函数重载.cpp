#include<iostream>

//函数重载
//同一个作用域
//函数名称相同
//函数参数类型不同，或者个数不同，或者顺序不同
//函数返回值无法作为重载条件

void func(){
    std::cout << "func的调用" << std::endl;
}

void func(int a){
    std::cout << "func(int a)的调用" << std::endl;
}

void func(double a){
    std::cout << "func(double a)的调用" << std::endl;
}

int main()
{

    func(10.13);

    system("pause");
    return 0;
}
