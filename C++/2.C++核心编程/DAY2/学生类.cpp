#include<iostream>
using namespace std;

class Student{
    public:
    int id;
    string name;

    public:
    void setName(string name){
        this->name = name;
    }
    void setID(int id){
        this->id = id;
    }
    void showStudent(){
        cout << "name: " << name << " " << "id: " << id << endl;
    }

};

int main()
{
    Student stu;
    stu.setName("zhangsan1");
    stu.setID(2021011047);
    stu.showStudent();

    return 0;
}