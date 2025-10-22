#include <iostream>
using namespace std;

class AbstractDrinking
{
public:
    virtual void boil() = 0;
    virtual void brew() = 0;
    virtual void pourInCup() = 0;
    virtual void putSomething() = 0;

    void makeDrink(){
        boil();
        brew();
        pourInCup();
        putSomething();
    }
};

class Coffee :public AbstractDrinking
{
public:
    virtual void boil(){
        cout << "煮矿泉水" << endl;
    }
    virtual void brew(){
        cout << "冲泡咖啡" << endl;
    }
    virtual void pourInCup(){
        cout << "倒入杯中" << endl;
    }
    virtual void putSomething(){
        cout << "加入牛奶和糖" << endl;
    }
};

class Tea :public AbstractDrinking
{
public:
    virtual void boil(){
        cout << "煮矿泉水" << endl;
    }
    virtual void brew(){
        cout << "冲泡茶叶" << endl;
    }
    virtual void pourInCup(){
        cout << "倒入杯中" << endl;
    }
    virtual void putSomething(){
        cout << "加入枸杞" << endl;
    }
};

void doWork(AbstractDrinking *abc){
    abc->makeDrink();
    delete abc;
}

void test01(){
    doWork(new Coffee);
    doWork(new Tea);
}


int main()
{
    test01();
    return 0;
}