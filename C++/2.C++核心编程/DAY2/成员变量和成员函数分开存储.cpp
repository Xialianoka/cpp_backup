#include<iostream>
using namespace std;

class Student
{
public:
    int age;

    static int name;

    void showAge(){
        cout << "age:" << endl;
    }

    static void showClass()
    {
        cout << "class" << endl;
    }
    
};

void test01()
{
    Student stu;
    
    cout << "Size of stu：" << sizeof(stu) << endl;
}

int main()
{
    test01();

    return 0;
}