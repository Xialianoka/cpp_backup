#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    for (int &x : v) {
        if (x & 1) {
            cout << x << endl;
            x *= 2;
        }
    }
    return 0;
}