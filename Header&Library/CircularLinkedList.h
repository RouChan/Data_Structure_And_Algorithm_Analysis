//
// Created by 喻如辰 on 2020/9/27.
// 单向循环链表的实现
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CIRCULARLINKEDLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CIRCULARLINKEDLIST_H

#include "Node.h"

enum StatusCode {SUCCESS = 0, RANGE_ERROR};

template <class DataType>
class CList {
protected:
    Node<DataType>* head;
    Node<DataType>* GetNodePtr(int position) const;
    void Init();                                            // 初始化线性表
public:
    CList();                                                // 无参构造函数
//    virtual ~CList();                                       // 析构函数

    int     Length() const;                                 // 求线性表长度
    bool    Empty() const;                                  // 判断线性表是否为空
//    void    Clear();                                        // 将线性表清空

//    StatusCode Delete(int position, DataType& d);           // 删除position位置元素，并将后一个位置数据域赋值给d
};

template <class DataType>
CList<DataType>::CList() {
    head = nullptr;
    Init();
}

template <class DataType>
void CList<DataType>::Init() {
    head = new Node<DataType>;
    head -> next = head;                                    // 构造循环链表
}

template <class DataType>
int CList<DataType>::Length() const {
    int count = 0;
    for(Node<DataType>* tmpPtr = head -> next; tmpPtr != head; tmpPtr = tmpPtr -> next) {
        count++;
    }
    return count;
}

template <class DataType>
bool CList<DataType>::Empty() const {
    return (head -> next == head);
}

//template <class DataType>
//void CList<DataType>::Clear() {
//
//}

//template <class DataType>
//StatusCode CList<DataType>::Delete(int position, DataType &d) {
//
//}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CIRCULARLINKEDLIST_H
