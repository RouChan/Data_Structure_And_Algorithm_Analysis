//
// Created by 喻如辰 on 2020/9/27.
// 已知两个链表`la`和`lb`，其元素值递增排序。编程将`la`和`lb`合并成一个递减有序（相同值元素只保留一个）的链表`lc`。
//

#include <iostream>
#include "HW_2_List&Merge.h"
using namespace std;

int main () {
    SinglyLinkedList<int> la, lb, lc;

    for(int i = 0; i < 5; i++) {
        la.Insert(la.Length() + 1, i);
    }

    for(int i = 0; i < 8; i += 2) {
        lb.Insert(lb.Length() + 1, i + 1);
    }

    ListMerge(la, lb, lc);

    for(int i = 0; i < lc.Length(); i++) {
        int x = 0;
        lc.GetNode(i + 1, x);
        cout << x << " ";
    }
    cout << endl;

    return 0;
}