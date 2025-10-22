#include <iostream>
#include <string>

using std::string;

int main()
{
    string str1, str2;
    // getline(std::cin, str);
    std::cin >> str1;
    std::cin >> str2;
    // if (str1 > str2)
    //     std::cout << str1;
    // else
    //     std::cout << str2;

    if (str1.size() != str2.size()){
        if(str1.size() > str2.size())
            std::cout << str1 << std::endl;
        else
            std::cout << str2 << std::endl;
    }

    return 0;
}