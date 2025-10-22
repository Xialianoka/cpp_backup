#include <iostream>
#include <map>

using namespace std;

void printMap (map<int, int> mp) {
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
	cout << "Key: " << it->first << ' ' << "Value: " << it->second << ' ';
	}
	cout << endl;

}

int main()
{
	map<int, int> mp;	//默认构造函数
	mp.insert(pair<int, int>(1, 10));
	mp.insert(pair<int, int>(2, 20));
	mp.insert(pair<int, int>(3, 30));
	mp.insert(pair<int, int>(4, 40));
	printMap(mp);

	map<int, int> mp1(mp);	//拷贝构造函数
	printMap(mp1);

	map<int, int> mp2;
	mp2 = mp1;
	printMap(mp2);


	return 0;
}

