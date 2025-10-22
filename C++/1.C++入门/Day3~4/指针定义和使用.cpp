#include <iostream>
using namespace std;

int main() {
  int a = 10;

  int *p = &a;  // 记录a的地址
  cout << "a的地址：" << &a << endl;
  cout << "p的内容：" << p << endl;

  // 使用指针，解引用
  cout << "指针p指向地址的内容为：" << *p << endl;

  system("pause");
  return 0;
}
