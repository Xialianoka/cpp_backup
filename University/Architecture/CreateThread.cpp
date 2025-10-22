#include<windows.h>
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

DWORD WINAPI FunOne(LPVOID param){
// 具体工作内容
    while(true){
        Sleep(1000); 
        cout<<"hello 1!"<<endl;
    }
    return 0;
}

DWORD WINAPI FunTwo(LPVOID param){
    // 具体工作内容
    while(true){
        Sleep(1000);
        cout<<"hello 2!"<<endl;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int input = 0;
    HANDLE hand1=CreateThread(NULL, 0, FunOne, (void*)&input, CREATE_SUSPENDED, NULL);
    HANDLE hand2=CreateThread(NULL, 0, FunTwo, (void*)&input, CREATE_SUSPENDED, NULL);

    while (true) {
        cin >> input;
        switch(input) {
            case 1:
                ResumeThread(hand1);
                cout << "Thread1 running..." << endl;
                break;
            case 2:
                SuspendThread(hand1);
                cout << "Thread1 suspended..." << endl;
                break;
            case 3:
                TerminateThread(hand1, 1);
                cout << "Thread1 terminated..." << endl;
                break;
            case 5:
                ResumeThread(hand2);
                cout << "Thread2 running..." << endl;
                break;
            case 6:
                SuspendThread(hand2);
                cout << "Thread2 suspended..." << endl;
                break;
            case 7:
                TerminateThread(hand2, 1);
                cout << "Thread2 terminated..." << endl;
                break;
            default:
                cout << "Input 1~3or5~6" << endl;
                break;
                
        }
    }
    return 0;
}
