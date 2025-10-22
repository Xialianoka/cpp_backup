#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person
{
	public:


		Person(string name, int age) {
			m_Name = name;
			m_Age = age;
		}

		bool operator==(const Person &p) {
			if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
				return true;
			return false;
		}



		int m_Age;
		string m_Name;


};


int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
		cout << "没有找到" << endl;
	else
		cout << "找到" << *it << endl;
	
	vector<Person> v1;
	Person p1("张三", 21);
	Person p2("李四", 22);
	Person p3("王五", 21);
	Person p4("你好", 01);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);

	vector<Person>::iterator it1 = find(v1.begin(), v1.end(), p2);
	if(it1 == v1.end())
		cout << "没有找到" << endl;
	else
		cout << "找到" << it1->m_Name << "的年龄" << it1->m_Age << endl;


	return 0;

}
