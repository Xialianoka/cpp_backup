//1. 如果函数模板和普通函数都可以实现，优先调用普通函数
//2. 可以通过空模板参数列表来强制调用函数模板
//3. 函数模板也可以发生重载
//4. 如果函数模板可以产生更好的匹配, 优先调用函数模板

#include <iostream>
using namespace std;

void myprint(int a, int b) {
	cout << "普通函数调用" << endl;
}

template <typename T>
void myprint(T a, T b) {
	cout << "模板函数调用" << endl;
}

template <typename T>
void myprint(T a, T b, T c) {
	cout << "模板函数重载调用" << endl;
}

void test01()
{
	int a = 0, b = 0;
	myprint(a, b);

	myprint<>(a, b);

	int a1 = 0, b1 = 0, c = 0;
	myprint(a1, b1, c);

	char c1 = '1', c2 = '2';
	myprint(c1, c2);
}

int main()
{
	test01();

	return 0;

}