#include <iostream>
#include <vector>

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  float a = 1, b = 2;
  double mid = float((a++ + b) / 2);
  printf("mid = %lf\n", mid);
  return 0;
}