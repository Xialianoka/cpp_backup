#include <iostream>
#include <functional>

using namespace std;

int main()
{
    plus<int> p;
    cout << p(10, 20) << endl;

    negate<int> n;
    cout << n(40) << endl;

    return 0;

}