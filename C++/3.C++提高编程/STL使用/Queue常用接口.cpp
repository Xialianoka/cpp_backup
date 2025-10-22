#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

int main()
{

    Person p1("唐僧", 40);
    Person p2("孙悟空", 500);
    Person p3("猪八戒", 200);
    Person p4("沙和尚", 200);

    queue<Person> q;

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    while(!q.empty()) {
        //队列只支持访问队头队尾
        cout << "队首元素：" << q.front().m_Name << " " << q.front().m_Age << endl;
        cout << "队尾元素：" << q.back().m_Name << " " << q.front().m_Age << endl;


        cout << endl;
        q.pop();

    }

    cout << "队列大小为：" << q.size() << endl;

    return 0;

}