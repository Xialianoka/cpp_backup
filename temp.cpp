#include <stdio.h>

int main() {
    float pi, r, s;
    pi = 3.1415926;
    printf("请输入圆的半径：");
    scanf("%f", &r);
    s = pi * r * r;
    printf("%f\n", s);
    return 0;
}