#include "../include/Lexer.h"

Lexer::Lexer() {
    tk = TK_UNDEF;
    curCh = ' ';
    word = "";
    row = 1;
}

Lexer::~Lexer() {}

void Lexer::print(){
    if (tk == TK_UNDEF) {
        /*未识别*/
        cout << "(" << tk << ", " <<  word << ")" << "未识别" << "--位于文件第" << row << "行" <<  endl;
        return;
    }
    cout << "(" << tk << ", " <<  word << ")" << endl;
}

bool Lexer::isKeyWords(){
    if (keyWords.count(word))
        return true;
    return false;
}

bool Lexer::isLetter(){
    if ((curCh >= 'a' && curCh <= 'z') || (curCh >= 'A' && curCh <= 'Z'))
        return true;
    return false;
}

bool Lexer::isDigit(){
    if (curCh >= '0' && curCh <= '9')
        return true;
    return false;
}


void Lexer::LexicalAnalysis(){
    ofs.open("Token.txt", ios::out|ios::trunc);
    while ((curCh = ifs.get()) != EOF) {
        tk = TK_UNDEF;
        /*遇到空格，tab，换行跳过*/
        if (curCh == ' ' || curCh == '\t' || curCh == '\n'){
            if (curCh == '\n')
                row++;
            continue;
        }
        /*判断标识符*/
        else if (isLetter()) {
            while (isLetter() || isDigit()) {
                word += curCh;
                curCh = ifs.get();
            }
            ifs.seekg(-1, ios::cur);  //指针回退一个字节，为了不会漏掉下一单词的开头
            if (isKeyWords())
                tk = KW;
            else
                tk = TK_IDEN;
        }
        /*判断数字*/
        else if (isDigit()) {
                bool flag = false;   //标记是否为浮点数
                while (isDigit()) {
                    word += curCh;
                    curCh = ifs.get();
                    if (curCh == '.' && flag == 0) {
                        char temp = curCh;
                        curCh = ifs.get();  //超前搜索
                        if (isDigit()) {
                            flag = true;
                            ifs.seekg(-1, ios::cur);
                            word += temp;
                            curCh = ifs.get();
                        }
                    }
                }
                ifs.seekg(-1, ios::cur);
                if (flag)
                    tk = TK_DOUB;
                else
                    tk = TK_UINT;
        }
        else switch(curCh) {
            /*运算符*/
            case '+':
            case '-':
            case '*':
            case '/':
            {
                word += curCh;
                tk = TK_OPER;
            }
            break;
            case '=':
            {
                word += curCh;
                curCh = ifs.get();
                if (curCh == '=') {
                    word += curCh;
                    tk = TK_OPER;
                }
                else {
                    tk = TK_DELI;
                    ifs.seekg(-1, ios::cur);
                }
            }
            break;
            case '<':
            case '>':
            {
                word += curCh;
                curCh = ifs.get();
                if (curCh == '=') {
                    word += curCh;
                    tk = TK_OPER;
                }
                else{
                    tk = TK_OPER;
                    ifs.seekg(-1, ios::cur);
                }
            }
            break;
            /*分隔符*/
            case '(':
            case ')':
            case '{':
            case '}':
            case ';':
            case ',':
            {
                word += curCh;
                tk = TK_DELI;
            }
            break;
            default:
            {
                while (curCh != ' ' && curCh != '\t' && curCh != '\n' && !isLetter() && !isDigit()) {
                    word += curCh;
                    curCh = ifs.get();
                }
                ifs.seekg(-1, ios::cur);
            }
            break;
        }
        saveTokenToFile();
        print();
        word.clear();
    }
    ofs.close();
}

void Lexer::saveTokenToFile() {
    ofs << '(' << this->tk << ',' << this->word << ')' << endl;
}