#include <iostream>
using namespace std;

class Base1
{
	public:
		int m_A;
	protected:
		int m_B;
	private:
		int m_C;

};

class Son1 :public Base1
{
	public :
		void func()
		{
			m_A = 10;
			m_B = 10;	//保护成员到了子类依然是保护
			//m_C = 10;	//父类私有权限成员子类无法访问
		}
};

//保护继承

void test01()
{
	Son1 s1;
	s1.m_A = 100;
	cout << s1.m_A << endl;

}



int main()
{

	test01();
	return 0;
}
