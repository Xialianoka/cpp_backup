#include <iostream>
#include <string>

using namespace std;

int main()
{
    int score = 100;
    string lv;
    lv = (score < 60) ? "fail" : (score > 90) ? "high pass" : (score > 75) ? "pass" : "low pass";
    cout << lv << endl;

    return 0;
}