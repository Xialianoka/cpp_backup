#include <iostream>
using namespace std;
#include <fstream>

class Person
{
public:
    char m_Name[20];
    int m_Age;
};

void test01()
{
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);

    Person p;
    ifs.read((char *)&p, sizeof(p));

    cout << "name:" << p.m_Name << "age:" << p.m_Age << endl;

    ifs.close();
}

int main()
{
    test01();
    return 0;
}