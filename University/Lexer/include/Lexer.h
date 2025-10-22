#pragma once
#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>

#include "TokenCode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::ios;

/*关键词*/
const unordered_set<string> keyWords = {"main", "const", "if", "else", "while",
                                        "int", "for", "auto", "return", "double",
                                        "unsigned"};

class Lexer
{
public:
    Lexer();

    void print();
    bool isKeyWords();
    bool isLetter();
    bool isDigit();
    void LexicalAnalysis();
    void saveTokenToFile();

    ~Lexer();

    std::ifstream ifs;
private:
    TokenCode tk;   //种别码
    char curCh;     //单个字符
    string word;    //单词
    int row;    //记录单词行号
    std::ofstream ofs;
};