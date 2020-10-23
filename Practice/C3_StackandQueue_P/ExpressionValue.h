//
// Created by 喻如辰 on 2020/10/22.
// 表达式求值：利用栈完成四则表达式优先级判断并求值
//
#pragma once
#include <iostream>
#include "../../Header&Library/LkStack.h"

// 判断两个操作符的优先级，LESS表示operator1 < operator2
enum OptrCmp {WRONG = -1, LESS, GREATER};

// 操作符优先级表，0表示<，1表示>，-1表示错误
// [0]表示+-，[1]表示*/，[2]表示(，[3]表示)，[4]表示=
int priority[5][5] = {{1, 0, 0, 1, 1},
                      {1, 1, 0, 1, 1},
                      {0, 0, 0, 1, -1},
                      {1, 1, -1, 1, 1},
                      {0, 0, 0, -1, 1}};

class Expression {
protected:
    LinkStack<char>     optr;
    LinkStack<double>   opnd;

    int         GetPos(const char& a) const;                    // 返回运算符下标
    double      GetNumber() const;                              // 读取一个数
    OptrCmp     Priority(const char& a, const char& b) const;   // 判断运算符优先级
public:
    // todo 构造函数析构函数
    double      ExpressionValue();                              // 求值函数
};

int Expression::GetPos (const char& a) const {
    switch (a) {
        case '+' : return 0;
        case '-' : return 0;
        case '*' : return 1;
        case '/' : return 1;
        case '(' : return 2;
        case ')' : return 3;
        case '=' : return 4;
    }
    return -1;
}

double Expression::GetNumber () const {
    char c = 0;
    double number = 0;
    while (std::cin >> c) {
        if(isdigit(c)) {
            int digit = c - '0';
            number = number * 10 + digit;
        } else if(c == '.') {
            double fraction = 0;
            int count = 0;
            while (std::cin >> c) {
                if(isdigit(c)) {
                    count++;
                    double digit = c - '0';
                    fraction = fraction * 10 + digit;
                } else {
                    number = number + pow(10.0, (-1.0) * count) * fraction;
                    std::cin.putback(c);
                    break;
                }
            }
        } else {
            std::cin.putback(c);
            break;
        }
    }
    return number;
}

OptrCmp Expression::Priority(const char& a, const char& b) const {
    int aPos = GetPos(a), bPos = GetPos(b);
    if(aPos < 0 || bPos < 0) {
        return WRONG;
    } else {
        OptrCmp cmp = OptrCmp(priority[aPos][bPos]);
        return cmp;
    }
}

double Expression::ExpressionValue () {
    optr.Clear();
    opnd.Clear();

    optr.Push('=');
    fflush(stdin);
    char c = 0;

    //todo: for double type.
    while (std::cin >> c) {
        if(c == EOF || c == '\n') {
            break;
        } else if(c >= '0' && c <= '9') {
            // 下一个读取的是一个数
            std::cin.putback(c);
            double tmp = GetNumber();
            opnd.Push(tmp);
        } else if(GetPos(c) >= 0 && GetPos(c) <= 4) {
            // 下一个字符是符号
            char top = 0;
            optr.Top(top);

            if(top == '(' && c == ')') {
                optr.Pop(top);
                continue;
            } else if (top == '=' && c == '='){
                break;
            } else if (Priority(top, c) == GREATER) {
                // 出栈并计算
                std::cin.putback((c));

                double opnd1 = 0, opnd2 = 0;
                opnd.Pop(opnd1);
                opnd.Pop(opnd2);

                if(top == '+')      opnd.Push(opnd1 + opnd2);
                else if(top == '-') opnd.Push(opnd2 - opnd1);
                else if(top == '*') opnd.Push(opnd1 * opnd2);
                else if(top == '/') opnd.Push(opnd2 / opnd1);

                optr.Pop(top);

                continue;
            } else if (Priority(top, c) == LESS) {
                optr.Push(c);
            }
        }
    }

    fflush(stdin);

    double result = 0;
    opnd.Top(result);
    return result;
}