#include<iostream>

class Person{

    public:
    Person(){
        std::cout << "Person构造函数调用" << std::endl;
    }

    Person(int a){
        std::cout << "Person带参构造函数调用" << std::endl;
        this->a = a;
    }

    Person(const Person &p){
        std::cout << "Person拷贝构造函数调用" << std::endl;
        a = p.a;
    }

    ~Person(){
        std::cout << "Person析构函数调用" << std::endl;
    }

    public:
    int a;
};

void test01(){
    Person p;
    Person p1(10);
    Person p2(p1);

    std::cout << p1.a << std::endl;
    std::cout << p2.a << std::endl;
}

int main()
{

    Person p = Person(10);
    Person p1 = Person(p);

    return 0;
}