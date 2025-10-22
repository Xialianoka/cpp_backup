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
    Student st1 = {"张三", 18, 100};
    Student *p = &st1;

    cout << " 姓名: " << p->name << " 年龄: " << p->age << " 分数: " << p->score;

    return 0;
}