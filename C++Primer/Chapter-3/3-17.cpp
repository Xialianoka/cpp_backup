#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::string;

int main()
{
    vector<string> svec;
    string s;
    while (std::cin >> s) {
        svec.push_back(s);
    }
    for (auto &s : svec){
        for (int i = 0; i < s.size(); i++)
            toupper(s[i]);
    }

    for (auto s : svec)
        std::cout << s << std::endl;

    return 0;
}