#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TransForm
{
	public:
		int operator() (int val) {
			return val;
		}

};

class MyPrint
{
	public:
		void operator() (int val) {
			cout << val << ' ';
		}

};

int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++ ){
		v.push_back(i);
	}

	vector<int> vTarget;
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), TransForm());

	for_each(vTarget.begin(), vTarget.end(), MyPrint());

	return 0;

}
