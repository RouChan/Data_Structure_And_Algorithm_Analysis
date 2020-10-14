//
// Created by 喻如辰 on 2020/10/11.
// 顺序栈头文件的调用 utility of SeqStack.h
//

#include <iostream>
#include "../Header&Library/SeqStack.h"
using namespace std;

int main () {
    int a[] = {1, 4, 6, 2, 8, 10};
    SeqStack<int> s(10, a, 1, 6);
    s.Traverse(1, s.Length());                              // 初始化

    int tmp = 0;
    s.Top(tmp);
    cout << tmp << endl;                                        // 栈顶

    s.Push(13);
    s.Traverse(1, s.Length());                              // 入栈

    s.Pop(tmp);
    s.Traverse(1, s.Length());                              // 出栈

    return 0;
}