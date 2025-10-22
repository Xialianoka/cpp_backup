#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

struct Teacher
{
    int id;
    string name;
    int age;
    Student *stu;
};

int main()
{
    Student arr[3] =
        {
            {"张三", 18, 90},
            {"李四", 19, 100},
            {"王五", 19, 98}};
    Teacher tc = {1, "张老师", 30, arr};

    for (int i = 0; i < 3; i++)
    {
        cout << " 老师姓名：" << tc.name << " 老师职工号：" << tc.id
             << " 老师年龄：" << tc.age << " 老师辅导学生姓名：" << tc.stu[i].name
             << " 老师辅导学生年龄：" << tc.stu[i].age
             << " 老师辅导学生成绩：" << tc.stu[i].score << endl;
    }
    return 0;
}