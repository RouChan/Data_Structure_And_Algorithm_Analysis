//
// Created by 喻如辰 on 2020/10/13.
// 顺序队列头文件调用 utility of SeqQueue.h
//

#include <iostream>
#include "../Header&Library/SeqQueue.h"
using namespace std;

int main () {
    SeqQueue<int> s(4);
    cout << s.Length() << endl;
    s.Push(1);
    s.Push(2);
    s.Push(10);

    s.Traverse();
    int tmp = 0;
    s.Front(tmp);
    cout << tmp << endl;

    return 0;
}