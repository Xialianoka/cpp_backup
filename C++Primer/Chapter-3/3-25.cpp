#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> index(11, 0);
    auto it = index.begin();
    int score;
    while (std::cin >> score) {
        auto it = index.begin();
        it += score / 10;
        (*it)++;
    }
    for (auto temp = index.cbegin(); temp != index.cend(); ++temp)
        std::cout << *temp << ' ';
    std::cout << std::endl;

    return 0;
}