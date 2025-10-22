#include <iostream>

using namespace std;

using int_array = int[3];
typedef int int_array_[3];

int main()
{
    //版本1
    int ia[2][3] = {{1, 1, 1}, {2, 2, 2}};
    for (int (&a)[3] : ia) {
        for (int b : a)
            cout << b << ' ';
        cout << endl;
    }
    //版本2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            cout << ia[i][j] << ' ';
        cout << endl;
    }
    //版本3
    for (int (*p)[3] = ia; p != ia + 2; p++) {
        for (int *q = *p; q != *p + 3; q++)
            cout << *q << ' ';
        cout << endl;
    }

    for (int_array *p = ia; p != ia + 2; p++) {
        for (int *q = *p; q != *p + 3; q++)
            cout << *q << ' ';
        cout << endl;
    }

    for (auto p = begin(ia); p != end(ia); p++) {
        for (auto q = begin(*p); q != end(*p); q++)
            cout << *q << ' ';
        cout << endl;
    }

    return 0;
}