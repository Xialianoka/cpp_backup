#include <iostream>
using namespace std;

class Student
{
public:
    int m_Age;
    int m_Id;

    Student(int age)
    {
        this->m_Age = age;
    }

    Student &PersonAdd(Student p)
    {
        this->m_Age += p.m_Age;
        return * this;
    }
};

void test01()
{
    Student stu1(10);
    cout << "stu1.age:" << stu1.m_Age << endl;

    Student stu2(10);
    stu2.PersonAdd(stu1).PersonAdd(stu1).PersonAdd(stu1).PersonAdd(stu1);
    cout << "stu2.age" << stu2.m_Age << endl;
}

int main()
{
    test01();

    return 0;
}