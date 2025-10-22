#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> ivec;
    int i = 0;
    while (std::cin >> i)
        ivec.push_back(i);
    auto beg = ivec.cbegin(), end = ivec.cend();
    for (auto it = beg, eit = end - 1; it <= beg + (end - beg) / 2; ++it, --eit) {
        std::cout << (*it) + (*eit)<< std::endl;
    }

    return 0;
}