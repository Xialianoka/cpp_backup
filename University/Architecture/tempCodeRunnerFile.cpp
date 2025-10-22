#include <windows.h>
#include <iostream>
#include <process.h>
#include <fstream>
#include <vector>
#include <string>
#include <io.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

HANDLE evGetAllFiles, evRead1, evRead2; //三个Event信号
const string path = "D:\\programming\\C_C++\\C_C++ in VSCode\\University\\Architecture\\testdir\\";   //查找路径
const string str = "abc";
vector<string> filename;    //文件索引

//包装信息，好像可以用全局变量替代
class Dirinfo{

public:
    Dirinfo(){
        m_path = path;
        m_filetype = "\\*.txt";
        m_filename = &filename;
    }
public:
    string m_path;
    string m_filetype;
    vector<string> *m_filename;
} info;

void ReadThread1(LPVOID param){
    WaitForSingleObject(evGetAllFiles, INFINITE);   //阻塞等待GetAllFiles运行结束
    char temp[100];  //获取文件内容
    int rows;   //获取行号
    string ipath;    //获取路径
    string s;   //存储获取的内容
    cout<<"ReadThread1 is reading file"<<endl;
    for (int i = 0; i < filename.size(); i += 2) {
        ipath.assign(path + filename[i]);
        cout << "The file" << ipath << " includes the string" << temp << "is : " << endl;
        rows = 0;
        ifstream ifs(ipath);

        while (!ifs.eof()) {
            ++rows;
            ifs.getline(temp, 100);
            s = temp;
            if (s.find(str) < s.length()) {
                cout << "line " << rows << " : " << s << endl; 
            }
        }
        cout << endl;
    }

    SetEvent(evRead1);
}

void ReadThread2(LPVOID param){
    WaitForSingleObject(evRead1, INFINITE);
    char temp[100];  //获取文件内容
    int rows;   //获取行号
    string ipath;    //获取路径
    string s;   //存储获取的内容
    cout<<"ReadThread2 is reading file"<<endl;
    for (int i = 1; i < filename.size(); i += 2) {
        ipath.assign(path + filename[i]);
        cout << "The file" << ipath << " includes the string" << temp << "is : " << endl;
        rows = 0;
        ifstream ifs(ipath);

        while (!ifs.eof()) {
            ++rows;
            ifs.getline(temp, 100);
            s = temp;
            if (s.find(str) < s.length()) {
                cout << "line " << rows << " : " << s << endl; 
            }
        }
        cout << endl;
    }
    SetEvent(evRead2);
}

void GetAllFiles(LPVOID param){
    Dirinfo *info = (Dirinfo *)param;
    struct _finddata_t fileinfo{};
    long long handler;
    string p;
    cout << "GetAllFiles is reading all files" << endl;
    p = info->m_path + info->m_filetype;    //"D:\\programming\\C_C++\\C_C++ in VSCode\\University\\Architecture\\testdir\\ + *.txt"
    char path[100];
    strcpy(path, p.c_str());    //_findfirst不支持string，转成C风格字符串
    handler = _findfirst(path, &fileinfo);
    if (handler != -1) {
        do {
            info->m_filename->emplace_back(fileinfo.name);
        } while (_findnext(handler, &fileinfo) == 0);
        
        _findclose(handler);
    }

    cout << "GetAllFiles have read all files." << endl;
    // cout << *info->m_filename->begin() << endl;
    SetEvent(evGetAllFiles);
    cout << endl;
}


int main()
{
    evGetAllFiles = CreateEvent(NULL, FALSE, FALSE, NULL);
    evRead1 = CreateEvent(NULL, FALSE, FALSE, NULL);
    evRead2 = CreateEvent(NULL, FALSE, FALSE, NULL);

    _beginthread(GetAllFiles, 0, (void *)&info);
    _beginthread(ReadThread1, 0, NULL);
    _beginthread(ReadThread2, 0, NULL);

    WaitForSingleObject(evRead2, INFINITE);
    cout << "The program is end." << endl;
    return 0;
}