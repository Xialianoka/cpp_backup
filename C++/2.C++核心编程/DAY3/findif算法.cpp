#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class GreaterFive
{
public:
    bool operator() (int val) {

        return val > 5;
    }

};

class Person
{
public:

    Person(string name, int age) {
        m_Name = name;
        m_Age = age;
    }

    int m_Age;
    string m_Name;
};

class GreaterTwenty
{
public:
    bool operator() (Person &p) {
        return p.m_Age > 20;
    }

};

int main()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i << 2);
    }
    vector<int>::iterator it1 = find_if(v1.begin(), v1.end(), GreaterFive());
    if(it1 == v1.end())
        cout << "没有找到大于5的数" << endl;
    else
        cout << "找到大于5的第一个数为： " << *it1 << endl;

    vector<Person> v2;
    Person p1("aaa", 20);
    Person p2("bbb", 21);
    Person p3("ccc", 20);
    Person p4("ddd", 20);

    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    vector<Person>::iterator it2 = find_if(v2.begin(), v2.end(), GreaterTwenty());
    if(it2 == v2.end())
        cout << "没有找到大于20岁的人" << endl;
    else 
        cout << "找到大于20岁的人：" << it2->m_Name << " " << it2->m_Age << "岁" << endl;



    return 0;
}