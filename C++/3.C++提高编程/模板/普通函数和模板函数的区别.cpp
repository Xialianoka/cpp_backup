//普通函数调用时可以发生自动类型转换(隐式类型转换)
//函数模板调用时，如果利用自动类型推导，不会发生隐式类型转
//如果利用显示指定类型的方式，可以发生隐式类型转换

#include <iostream>
using namespace std;

int add01(int a, int b) {
	return a + b;
}

template<typename T>
T add02(T a, T b) {
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 10;
	char c = 'a';
	cout << add01(a, c) << endl;
	//cout << add02(a, c);
	cout << add02(a, b) << endl;
	cout << add02<int>(a, c) << endl;
}

int main()
{
	test01();
	return 0;
}
