#include<iostream>
using namespace std;

const double PI = 3.14;

class Circle{
public:
    int m_r;

    double caculateZC(){
        return 2 * PI * m_r;
    }
};

int main()
{
    Circle cl;
    cl.m_r = 10;

    cout << "圆cl的周长为：" << cl.caculateZC();

    return 0;
}