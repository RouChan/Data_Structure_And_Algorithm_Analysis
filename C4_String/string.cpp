//
// Created by 喻如辰 on 2020/10/16.
// 串 utility of string.h
//

#include <iostream>
#include "../Header&Library/string.h"
using namespace std;

int main () {
    char a[] = "Hello World!\0";

    String s(a, 0, 18);
    cout << s;

    return 0;
}
