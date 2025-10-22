#include <iostream>

class Singleton {
 private:
  // 唯一实例的指针
  static Singleton* instance;

  Singleton() = default;
  ~Singleton() = default;
  Singleton(const Singleton&) = delete;             // 禁止拷贝构造
  Singleton& operator=(const Singleton&) = delete;  // 禁止赋值操作

 public:
  static Singleton* getInstance() { return instance; }
  void print() {
    std::cout << "Singleton instance address: " << this << std::endl;
  }
};

// 饿汉初始化
Singleton* Singleton::instance = new Singleton();

int main() {
  Singleton* s1 = Singleton::getInstance();
  s1->print();

  return 0;
}