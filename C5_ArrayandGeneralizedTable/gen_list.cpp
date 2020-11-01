//
// Created by 喻如辰 on 2020/11/1.
// 广义表头文件的调用 utility of gen_list.h
//

#include <iostream>
#include "../Header&Library/gen_list.h"
using namespace std;

int main () {
    GenList<int> a;
    a.PushFront(12);
    a.PushFront(100);
    a.PushFront(78);

    GenList<int> b;
    b.PushFront(a);
    b.PushFront(2);
    b.Traverse();
    return 0;
}