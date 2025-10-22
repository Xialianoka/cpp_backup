#include <iostream>
using namespace std;
//1、new的基本语法
int *func()
{
    //在堆区创建整形数据
    //在new返回的是该数据类型的指针
    int *a = new int(10);
    return a;
}

void test01()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    //堆区的数据由程序员管理开辟、释放
    //如果想释放，利用关键字delete
    delete p;

    //cout << *p << endl; //内存已经释放，再次访问就是非法操作。
}
//2、在堆区利用new开辟数组
void test02()
{
    //创建10个整型数据的数组
    int *arr = new int[10];//10代表10个元素
    for(int i = 0; i < 10; i++){
        arr[i] = i + 100;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }

    //释放堆区数组
    //要加[]才可以
    delete[] arr;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}