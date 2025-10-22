#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;
        return -1;
    }

    // char chr[1024];
    // while( ifs >> chr){
    //     cout << chr << endl;
    // }

    // char buf[1024] = { 0 };
    // while (ifs.getline(buf, sizeof(buf))){
    //     cout << buf << endl;
    // }

    // string buf;
    // while (getline(ifs, buf)){
    //     cout << buf << endl;
    // }

    char c;
    while ((c = ifs.get()) != EOF){
        cout << c;
    }

    ifs.close();

    return 0;

}