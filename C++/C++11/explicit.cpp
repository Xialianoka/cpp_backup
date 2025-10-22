#include <iostream>

using namespace std;

class P
{
public:
    P(int a, int b) {
        cout << "P(int a, int b)" << endl;
    }
    P(initializer_list<int>) {
        cout << "P(initializer_list<int>)" << endl;
    }

    explicit
    P(int a, int b, int c) {
        cout << "explicit P" << endl;
    }
};


int main()
{
    P p1(5, 4);
    P p2{5, 4};
    P p3(1, 2, 3);
    P p4{1, 2, 3};
    P p5 = {1, 2, 3};

    return 0;
}