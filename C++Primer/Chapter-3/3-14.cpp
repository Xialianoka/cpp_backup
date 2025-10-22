#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    vector<string> ivec;
    string temp;
    while (cin >> temp)
        ivec.push_back(temp);
    for (decltype(ivec.size()) i = 0; i < ivec.size(); i++) {
        cout << ivec[i] << endl;
    }

    return 0;
}