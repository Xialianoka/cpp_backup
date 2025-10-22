#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &v) {
    
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
}

int main()
{

    vector<int> v1;
    for(int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVec(v1);

    vector<int> v2;
    v2 = v1;
    printVec(v2);

    vector<int> v3;
    v3.assign(v2.begin(), v2.end());
    printVec(v3);

    vector<int> v4;
    v4.assign(10, 10);
    printVec(v4);

    return 0;
}

