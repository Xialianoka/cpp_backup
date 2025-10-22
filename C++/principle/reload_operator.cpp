#include <iostream>

class Complex {
 public:
  Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

  // 重载+
  Complex operator+(const Complex& c) {
    return Complex(real + c.real, imag + c.imag);
  }

  double real, imag;
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "(" << c.real << ", " << c.imag << ")";
  return os;
}

int main() {
  Complex c1(1, 2), c2(3, 4);
  Complex c3 = c1 + c2;
  std::cout << c3 << std::endl;
  return 0;
}