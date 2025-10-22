#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Person
{
public:
    Person(string name, int age) {
        m_Name = name;
        m_Age = age;
    }

    bool operator== (const Person &p) {
        return this->m_Age == p.m_Age;
    }

    string m_Name;
    int m_Age;
};

int main()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    int num1 = count(v1.begin(), v1.end(), 5);

    cout << "5的个数为：" << num1 << endl;

    vector<Person> v;
    Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
    Person p("诸葛亮", 35);

    int num2 = count(v.begin(), v.end(), p);
    cout << "num2 = " << num2 << endl;

    return 0;

}