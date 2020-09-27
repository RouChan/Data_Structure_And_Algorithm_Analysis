//
// Created by 喻如辰 on 2020/9/18.
// 第一章-线性表（单链表实现，包括头插法&尾插法）
//

#include <iostream>
using namespace std;

struct Student {
    string  name;
    int     age;
};

struct Node {
    Student     stu;
    Student*    next;

    Node() : next(nullptr){};           // 无参数构造函数
    Node (Student stu, Student* link);     // 构造一个数据域为stu，指针域为link的结点
};

Node::Node (Student stu, Student* link) {
    this -> stu.name    = stu.name;
    this -> stu.age     = stu.age;
    this -> next        = link;
}

class SimpleLinkList {
protected:
    Node*   head;                   // 头结点
    Node*   p;
public:


};

int main () {

    return 0;
}