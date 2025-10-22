#include <iostream>

class Base {
 public:
  int base_data;
  Base() {
    std::cout << "base构造地址：" << this << std::endl;
    std::cout << "Base." << std::endl;
  }
};

class Derived : public Base {
 public:
  int derived_data;
  Derived() {
    std::cout << "derived构造地址：" << this << std::endl;
    std::cout << "Derived." << std::endl;
  }
};

int main() {
  Derived d;
  std::cout << "d地址：" << &d << std::endl;
  std::cout << "d.base_data地址：" << &d.base_data << std::endl;
  std::cout << "d.derived_data地址：" << &d.derived_data << std::endl;
  return 0;
}