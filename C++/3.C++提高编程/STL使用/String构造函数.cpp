#include <iostream>
#include <string>

using namespace std;

int main()
{
	string st1;
	const char* str = "Hello World";
	string st2(str);

	string st3(st2);
	
	string st4(10, 'c');

	cout << st1 << endl << st2 << endl << st3 << endl << st4 << endl;

	return 0;
}