#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    for (decltype(v1.size()) index = 0; index < v1.size(); index++) {
        std::cout << v1[index] << std::endl;
    }

    for (decltype(v2.size()) index = 0; index < v2.size(); index++) {
        std::cout << v2[index] << std::endl;
    }

    for (decltype(v3.size()) index = 0; index < v3.size(); index++) {
        std::cout << v3[index] << std::endl;
    }

    for (decltype(v4.size()) index = 0; index < v4.size(); index++) {
        std::cout << v4[index] << std::endl;
    }

    for (decltype(v5.size()) index = 0; index < v5.size(); index++) {
        std::cout << v5[index] << std::endl;
    }

    for (decltype(v6.size()) index = 0; index < v6.size(); index++) {
        std::cout << v6[index] << std::endl;
    }

    for (decltype(v7.size()) index = 0; index < v7.size(); index++) {
        std::cout << v7[index] << std::endl;
    }

}