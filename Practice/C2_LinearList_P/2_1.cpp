//
// Created by 喻如辰 on 2020/10/10.
// 第二章线性表
// 1. 实现带头结点的简单链表，包括创建链表、添加结点、删除结点等基本操作
//

#include <iostream>
#include "/Users/yu_ruchen/Library/Mobile Documents/com~apple~CloudDocs/Programming/Data_Structure_And_Algorithm_Analysis/Header&Library/SinglyLinkedList.h"
using namespace std;

int main () {
    List<int> group;                                    // 创建一个叫做类型为group<int>的链表

    for(int i = 0; i < 8; i++) {                        // 初始化
        group.Insert(group.Length() + 1, i + 1);
    }
    cout << "初始化链表，并插入十个结点：";
    group.Traverse(1, group.Length());

    group.Insert(3, 10);                    // 插入结点
    cout << "三号位置前插入一个值域为10的结点：";
    group.Traverse(1, group.Length());

    int tmp = 0;
    group.Delete(5, tmp);                   // 删除结点
    cout << "删除5号位置的结点：";
    group.Traverse(1, group.Length());

    return 0;
}
