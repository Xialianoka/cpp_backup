#include <iostream>
using namespace std;


//抽象类
class Base
{
public:
    virtual void func() = 0;
};

class Son1 :public Base
{
public:
    virtual void func(){
        cout << "func函数调用" << endl;
    }


};

void test01(){
    Son1 *son = new Son1;
    son->func();
    delete son;
    son = nullptr;
}

int main()
{

    test01();
    return 0;
}