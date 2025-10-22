#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};
int main()
{
    int i;
    Student arr[3] =
        {
            {"张三", 18, 80},
            {"李四", 19, 90},
            {"王五", 19, 95}};

    for (i = 0; i < 3; i++)
    {
        cout << " 姓名: " << arr[i].name 
             << " 年龄: " << arr[i].age 
             << " 分数: " << arr[i].score << endl;
    }
    return 0;
}