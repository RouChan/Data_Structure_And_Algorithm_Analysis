//
// Created by 喻如辰 on 2020/10/15.
// 第三章 栈与队列
// 2. 用栈实现表达式中括号匹配算法
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_PARENTHESEMATCH_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_PARENTHESEMATCH_H

#include <iostream>
#include "../../Header&Library/LkStack.h"

class Expression : public LinkStack<char> {
protected:
    char    *expr;                                                  // 保存表达式
    int     count;                                                  // 保存表达式字符数
    bool    trueValue;                                              // 是否表达式括号合法特征值

    // 辅助函数
    bool    Legal();                                                // 判断表达式括号合法
public:
    Expression (char a[], int to);                                  // 初始化
    virtual ~Expression();                                          // 虚构函数

    bool GetTrueValue() const;                                      // 取表达式真值
};

Expression::Expression (char *a, int to) {
    expr = new char[to + 1];                                        // 初始化表达式
    for(int i = 0; i <= to; ++i) {
        expr[i] = a[i];
    }
    count = to + 1;
    Init();
    trueValue = Legal();
}

Expression::~Expression ()  {
    delete []expr;
}

bool Expression::Legal () {
    bool trueValue = true;
    for(int i = 0; i < count; ++i) {
        if(isdigit(expr[i]) || expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            continue;
        } else if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            Push(expr[i]);
        } else if (expr[i] == ')' && !Empty()) {
            char tmp = 0;
            Top(tmp);
            if(tmp == '(') {
                Pop(tmp);
                continue;;
            } else{
                trueValue = false;
                break;
            }
        } else if (expr[i] == ']' && !Empty()) {
            char tmp = 0;
            Top(tmp);
            if(tmp == '[') {
                Pop(tmp);
                continue;;
            } else{
                trueValue = false;
                break;
            }
        } else if (expr[i] == '}' && !Empty()) {
            char tmp = 0;
            Top(tmp);
            if(tmp == '{') {
                Pop(tmp);
                continue;;
            } else{
                trueValue = false;
                break;
            }
        } else {
            trueValue = false;
            break;
        }
    }

    if(!Empty()) trueValue = false;
    RETURN_POINT:
    return trueValue;
}

bool Expression::GetTrueValue () const {
    return trueValue;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_PARENTHESEMATCH_H
