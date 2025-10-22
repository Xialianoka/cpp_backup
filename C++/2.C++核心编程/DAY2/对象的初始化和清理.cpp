#include<iostream>

class Person{
    public:
    Person(){
        std::cout << "Person构造函数的调用" << std::endl;
    }
    ~Person(){
        std::cout << "Person析构函数的调用" << std::endl;
    }
};

void test01(){
    Person p = Person();
}

int main()
{
    test01();

    return 0;
}