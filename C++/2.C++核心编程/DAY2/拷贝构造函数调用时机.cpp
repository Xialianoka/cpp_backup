#include <iostream>

class Person{
    public:
    int age;
    std::string sex;
    
    public:
    Person(){
        std::cout << "默认构造" << std::endl;
    }

    Person(int age, std::string sex){
        this->age = age;
        this->sex = sex;
        std::cout << "带参构造" << std::endl;
    }

    Person(const Person &p){
        this->age = p.age;
        this->sex = p.sex;
        std::cout << "拷贝构造" << std::endl;
    }

    ~Person(){
        std::cout << "析构构造" << std::endl;
    }
};

void test01(){
    Person p1 = Person(20, "nan");
    Person p2 = Person(p1);
    
    std::cout << p2.age << std::endl;
}

void doWork (Person p){}    //拷贝临时对象

void test02(){
    Person p;
    doWork(p);
}

int main()
{

    test02();
    return 0;
}