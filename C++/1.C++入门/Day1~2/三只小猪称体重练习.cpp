// 有三只小猪ABC，请分别输入三只小猪的体重，并且判断哪只小猪最重？
#include <iostream>
using namespace std;

int main()
{
    float pig1, pig2, pig3 = 0.0;
    float max = 0.0;
    cout << "请输入三只小猪的体重" << endl;
    cin >> pig1 >> pig2 >> pig3;
    max = pig1;
    if (pig1 < pig2)
    {
        max = pig1;
    }
    if (max < pig3){
        max = pig3;
    }
    cout << "三只小猪最重的有：" << max << "斤" << endl;
    system("pause");
    return 0;
}