//
// Created by 喻如辰 on 2020/10/14.
// 链式队列调用 utility of LkQueue.h
//

#include <iostream>
#include "../Header&Library/LkQueue.h"
using namespace std;

int main () {
    LinkQueue<int> q;
    cout << q.Length() << endl;
    q.Push(1);
    q.Push(10);
    q.Push(233);
    q.Traverse();
    int tmp = 0;
    cout << q.Length() << endl;
    q.Pop(tmp);
    q.Traverse();

    cout << q.Length() << endl;
    return 0;
}