#include <iostream>
#include <bitset>

// void print() {
//     std::cout << "print()" << std::endl;
// }

template<typename T, typename... Types>
void print(const T& first, const Types&... args) {
    std::cout << first << std::endl;
    print(args...);
}

template<typename... T>
void print(const T&... args) {
    std::cout << "T&... args" << std::endl;
}

int main()
{
    print(4.2, "Hello", std::bitset<16>(377), 4);   //调用到第一个
    return 0;
}
