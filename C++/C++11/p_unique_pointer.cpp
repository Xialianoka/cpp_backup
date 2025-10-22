#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Cat {

public:
    Cat() {
        m_name = "Mimi";
    }

    Cat(string name) {
        cout << "构造函数" << endl;
        m_name = name;
    }

    ~Cat() {
        cout << "析构函数" << endl;
    }

    void printInfo() {
        cout << "name is " << m_name << endl;;
    }

public:
    string m_name;
};

int main() {
    // Cat cat("yy");
    // cat.printInfo();

    // Cat *c_p2 = new Cat("zz");
    // c_p2->printInfo();
    // {
    //     c_p2 = new Cat("aa");
    //     c_p2->printInfo();
    //     delete c_p2;
    // }

    // delete c_p2;
    // c_p2 = nullptr;

    Cat *c_p2 = new Cat("HH");
    unique_ptr<Cat> u_c_p1{c_p2};
    // c_p2->printInfo();
    // u_c_p1->printInfo();
    delete c_p2;
    c_p2 = nullptr;
    // u_c_p1->printInfo();

    unique_ptr<Cat> u_c_p2(new Cat("dd"));
    u_c_p2->printInfo();

    unique_ptr<Cat> u_c_p3 = make_unique<Cat>();
    u_c_p3->printInfo();

    cout << "----结束----" << endl;
    return 0;
}