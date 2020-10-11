//
// Created by 喻如辰 on 2020/10/11.
// 链式栈头文件的调用 utility of LkStack.h
//

#include <iostream>
#include "../Header&Library/LkStack.h"
using namespace std;

int main () {
    LinkStack<int> s;
    int a[] = {10, 2, 3, 1, 7, 8, 99};
    for(int i = 0; i < sizeof(a)/sizeof(int); i++) {
        s.Push(a[i]);
    }

    s.Traverse();

    return 0;
}

