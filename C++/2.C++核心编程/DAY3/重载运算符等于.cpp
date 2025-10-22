#include <iostream>
using namespace std;

class Person
{
public:
    Person(int a)
    {
        m_A = new int(a);
    }
    Person& operator=(Person &p)
    {
        if(m_A != NULL){
            delete m_A;
            m_A = NULL;
        }

        m_A = new int(*p.m_A);
    }

private:
    int *m_A;
}


