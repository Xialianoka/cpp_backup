#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> ivec(10, 2);
    for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
        std::cout << (*it) * 2 << std::endl;

    return 0;
}