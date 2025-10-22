#include <iostream>
using namespace std;


void print(int a, int b);

template<typename T>
void print(T a, T b){
     cout << "Template" << endl;
    cout << a << endl << b;
}

int main()
{
    int a = 10;
    int b= 100;


    char c1= 'a';
    char c2 = 'b';
    print(c1, c2);
    return 0;

}

