#include <iostream>
using namespace std;
#include <string>

class Animal
{
public:
    Animal(){
        cout << "父类构造" << endl;
    }
    virtual void speak() = 0;
    virtual ~Animal() = 0;

};
Animal::~Animal(){
    cout << "父类析构" << endl;
}

class Cat :public Animal
{
public:

    Cat(string name){
        cout << "子类构造" << endl;
        m_Name = new string(name);
    }
    virtual void speak(){
        cout << "小猫在说话" << endl;
    }

    ~Cat()
    {
        cout << "子类析构" << endl;
        if(!m_Name){
            delete m_Name;
            m_Name = nullptr;
        }
    }

    string *m_Name;
};

void test01()
{
    Animal *abc = new Cat("Tom");
    abc->speak();
    delete abc;
}

int main()
{
    test01();
    return 0;
}