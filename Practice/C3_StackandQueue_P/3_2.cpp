//
// Created by 喻如辰 on 2020/10/15.
// 第三章 栈与队列
// 2. 用栈实现表达式中括号匹配算法
//

#include "ParentheseMatch.h"
#include <string>
using namespace std;

int main () {
    // check whether each parentheses in the expression match its respective one.
    string str;
    while (cin >> str) {
        char *a = new char[str.length()];
        for(int i = 0; i < str.length(); ++i) {
            a[i] = str[i];
        }

        Expression e(a, str.length() - 1);
        if(e.GetTrueValue()) {
            cout << "LEGAL!" << endl;
        } else {
            cout << "ILLEGAL!" << endl;
        }
    }

    return 0;
}
