#include <iostream>
using namespace std;

class Student
{
public:
    int m_Age;
    int m_Id;

    void showAge()
    {
        cout << "age" << endl;
    }

    void showId()
    {
        if(this == NULL) return;
        cout << "id:" << m_Id << endl;
    }

};

void test01()
{
    Student * stu = NULL;
    stu->showAge();
    stu->showId();
}

int main()
{
    test01();

    return 0;
}