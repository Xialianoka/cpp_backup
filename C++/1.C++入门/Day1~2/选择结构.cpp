#include <iostream>
using namespace std;

int main()
{
    int score = 0;
    cout << "请输入您的分数：" << endl;
    cin >> score;
    // 选择结构，if后面不能加“；”
    if (score > 600)
    {
        cout << "恭喜您考上了一本大学";
    }
    else
    {
        cout << "很可惜您落榜了" << endl;
    }
    //

    system("pause");
    return 0;
}