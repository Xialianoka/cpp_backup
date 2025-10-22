#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
    
}

int main()
{
    vector<int> v1;
    for( int i = 0; i < 5; i++) {
        v1.push_back(i + 1);
    }

    printVec(v1);

    vector<int> v2(v1.begin(), v1.end());
    printVec(v2);

    vector<int> v3(10,1);
    printVec(v3);

    vector<int> v4(v3);
    printVec(v4);

    return 0;

}