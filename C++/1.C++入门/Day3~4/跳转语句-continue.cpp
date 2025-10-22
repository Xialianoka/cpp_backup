#include <iostream>
using namespace std;

int main()
{
    //奇数输出，偶数不输出
    for (int n = 0; n <= 100;n++)
    {
        if(n % 2 == 0)
            continue;
        cout << n << endl;
    }
    system("pause");
    return 0;
}