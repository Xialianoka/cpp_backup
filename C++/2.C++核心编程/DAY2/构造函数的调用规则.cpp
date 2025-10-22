#include<iostream>
using namespace std;

class Person{
public:
    Person(){
        cout << "默认" << endl;
    }

    Person(int age){
        cout << "有参" << endl;
    }

    Person(const int &age){
        this->age = age;
    }

    ~Person(){
        cout << "析构" << endl;
    }

private:
    int age;

};

int main()
{

    return 0;
}