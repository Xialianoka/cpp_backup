#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> ivec(10, 0);
    for (int i = 0; i < ivec.size(); i++) {
        ivec[i] = i;
        std::cout << ivec[i] << ' ';
    }
    std::cout << std::endl;
    vector<int> ivec1 = ivec;
    for (auto a : ivec1)
        std::cout << a << ' ';
    
    
    return 0;
}