#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

#include "src/Lexer.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


void showHelp(char *exe);

int main(int argc, char *argv[])
{

    if (argc < 2) {
        cout << argv[0] << " 待分析程序文件名" << endl;
        cout << "更多信息请使用-h或--help" << endl;
        return 0;
    }
    Lexer lx;

    string argV = argv[1];
    if (argV == "-h" || argV == "--help") {
        showHelp(argv[0]);
        return 0;
    }


    lx.ifs.open(argv[1], std::ios::in);
    int temp = lx.ifs.is_open();
    if (!temp) {
        perror("open");
        return -1;
    }

    cout << "********词法分析********" << endl;
    lx.LexicalAnalysis();
    lx.ifs.close();
    
    return 0;
}

void showHelp(char *exe) {
    cout << "1. 指令格式：" << exe << " filepath(待分析的程序文件)\n2. 结果保存在当前目录下的“Token.txt”中" << endl;
    cout << "3. 语法分析会获取Token.txt中的内容, 请确保访问权限" << endl;
    cout << "4. 产生式定义在\"gproduction.txt\"文件中，有需要的请自行修改, 目前只考虑直接左递归的消除，其他问题请靠自己聪明的头脑人工解决" << endl;
    return;
}
