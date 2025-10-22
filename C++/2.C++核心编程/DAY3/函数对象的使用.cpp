#include <iostream>
#include <string>

using namespace std;

class myAdd
{
public:
    int operator() (int a, int b) {

        return a + b;
    }

};

class myPrint
{
public:
    myPrint(){
        this->count = 0;
    }
    void operator() (string str) {

        cout << str << endl;
        this->count++;
    }
    
    int count;
};

void doPrint(myPrint &mp, string test) {

    mp(test);

}

int main()
{
    myAdd add;
    cout << add(10, 10) << endl;

    myPrint mp;
    mp("Hello World");
    mp("Hello World");
    mp("Hello World");
    mp("Hello World");
    cout << mp.count << endl;

    doPrint(mp, "Hello C++");

    return 0;
}