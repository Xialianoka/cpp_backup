#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40};
    vector<int> vec(begin(arr), end(arr));
    for (int a : vec) {
        cout << a << ' ' << endl;
    }
    return 0;
}