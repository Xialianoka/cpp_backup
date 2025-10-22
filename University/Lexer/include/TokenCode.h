#pragma once
#include <iostream>

enum TokenCode
{
    TK_UNDEF = 0,   //未定义
    KW,     //保留字
    TK_IDEN,    //标识符
    TK_UINT,    //无符号整数
    TK_OPER,    //运算符
    TK_DELI,    //分隔符
    TK_DOUB,    //浮点数
};