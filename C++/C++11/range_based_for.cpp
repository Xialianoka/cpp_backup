#include <iostream>
#include <vector>

using namespace std;

int main()
{

    for (int a : {1, 2, 3, 4, 5, 6}) {
        cout << a << endl;
    }
    vector<int> vec{1, 2, 3, 4, 5};
    for (auto elem : vec) {
        cout << elem << endl;
    }



    return 0;
}