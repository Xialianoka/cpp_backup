/*请声明一个5个元素的数组，并且将元素逆置.

(如原数组元素为：1,3,2,5,4;逆置后输出结果为:4,5,2,3,1);*/
#include <iostream>
using namespace std;
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    cout << "原始数组为：";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < 3; i++){
        int temp = arr[i];
        arr[i] = arr[4 - i];
        arr[4 - i] = temp;
    }
    cout << "倒序数组为：";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    system("pause");
    return 0;
}