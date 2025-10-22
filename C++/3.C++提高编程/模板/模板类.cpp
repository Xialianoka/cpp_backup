#include <iostream>
using namespace std;
#include <string>

template <class T>
class Person
{

public:
    T name;
    Person(T n)
    {
        this->name = n;
    }
};

int main()
{
    Person p1("nihao");
    cout << p1.name;

    Person<int> p2(10);
    cout << p2.name;
    return 0;
}