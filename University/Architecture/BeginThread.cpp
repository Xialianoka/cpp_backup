#include<windows.h>
#include<iostream>
#include<process.h>

using std::cin;
using std::cout;
using std::endl;

HANDLE evRead, evFinish;

void ReadThread(LPVOID param){
    WaitForSingleObject(evRead, INFINITE);  //等待WriteThread()结束
    cout<<"Reading"<<endl;
    SetEvent(evFinish);
}

void WriteThread(LPVOID param){
    cout<<"Writing"<<endl;
    SetEvent(evRead);
}


int main()
 {
    evRead = CreateEvent(NULL, FALSE, FALSE, NULL);
    evFinish = CreateEvent(NULL, FALSE, FALSE, NULL);

    _beginthread(ReadThread, 0, NULL);
    _beginthread(WriteThread, 0, NULL);

    WaitForSingleObject(evFinish, INFINITE);    //等待ReadThread()结束
    cout << "The Program is End" << endl;

    return 0;
 }