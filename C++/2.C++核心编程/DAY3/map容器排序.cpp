#include <iostream>
#include <map>

using namespace std;

class MyCompare
{
	public:
		bool operator()(int n1, int n2) {
			return n1 > n2;
		}
};



int main()
{
	map<int, int, MyCompare> mp1;
	mp1.insert(make_pair(1, 10));
	mp1.insert(make_pair(2, 20));
	mp1.insert(make_pair(3, 30));
	mp1.insert(make_pair(4, 40));
	mp1.insert(make_pair(5, 50));
	mp1.insert(make_pair(6, 60));
	mp1.insert(make_pair(7, 70));
	mp1.insert(make_pair(8, 80));

	for(map<int, int, MyCompare>::iterator it = mp1.begin(); it != mp1.end(); it++) {
		cout << "Key: " << it->first << ' ' << "Value: " << it->second << ' ' ;
	}


	return 0;
}
