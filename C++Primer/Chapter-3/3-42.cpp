#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec(3, 2);
    int arr[3];
    for (int i = 0; i < 3; i++)
        arr[i] = vec[i];
    for (int i = 0; i < 3; i++)
        cout << arr[i] << ' ' << endl;

    return 0;
}