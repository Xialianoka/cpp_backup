#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
 {
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<string> v2{"Beijing", "Chongqing", "Tianjing", "Shanghai"};
    int value[]{1, 2, 3, 4, 5};

    for (int i : v1) {
        cout << i << " ";
    }
    cout << endl;

    for (string s : v2) {
        cout << s << " ";
    }
    cout << endl;

    for (int i : value) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
 }