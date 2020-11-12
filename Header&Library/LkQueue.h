//
// Created by 喻如辰 on 2020/10/14.
// 链式队列 Linked Queue
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LKQUEUE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LKQUEUE_H

#include "Node.h"
#include "global.h"

template <class DataType>
class LinkQueue {
protected:
    // front -> next.data = a1; rear -> data = an.
    // a1 is the very first element of the list.
    Node<DataType> *front, *rear;                                       // 队头指针、队尾指针。

    // 辅助函数
    void Init();                                                        // 初始化
public:
    LinkQueue();                                                        // 无参构造函数
    LinkQueue(const LinkQueue<DataType>& copy);                         // 复制构造函数
    virtual ~LinkQueue();                                               // 析构函数

    int     Length() const;                                             // 返回队列长度
    bool    Empty() const;                                              // 判断是否为空
    void    Clear();                                                    // 清空队列
    void    Traverse() const;                                           // 遍历

    StatusCode Pop(DataType& d);                                        // 弹出队首元素，并将队首元素保存到d中
    StatusCode Push(const DataType& d);                                 // 压入元素
    StatusCode Front(DataType& d) const;                                // 取队首元素

    LinkQueue<DataType>& operator= (const LinkQueue<DataType>& copy);   // =操作符重载
};

template <class DataType>
void LinkQueue<DataType>::Init () {
    front = rear = new Node<DataType>;
}

template <class DataType>
LinkQueue<DataType>::LinkQueue () {
    front = rear = nullptr;
    Init();
}

template <class DataType>
LinkQueue<DataType>::LinkQueue (const LinkQueue<DataType>& copy) {
    Clear();
    for(Node<DataType> *tmpPtr = copy.front -> next; tmpPtr != nullptr; tmpPtr = tmpPtr -> next) {
        Push(tmpPtr -> data);
    }
}

template <class DataType>
LinkQueue<DataType>::~LinkQueue () {
    Clear();
}

template <class DataType>
int LinkQueue<DataType>::Length () const {
    int count = 0;
    for(Node<DataType> *tmpPtr = front -> next; tmpPtr != nullptr; tmpPtr = tmpPtr ->next) {
        ++count;
    }
    return count;
}

template <class DataType>
bool LinkQueue<DataType>::Empty () const {
    return (front == rear);
}

template <class DataType>
void LinkQueue<DataType>::Clear () {
    DataType tmpNode;
    while (Length() > 0) {
        Pop(tmpNode);
    }
}

template <class DataType>
void LinkQueue<DataType>::Traverse () const {
    for(Node<DataType> *tmpPtr = front -> next; tmpPtr != nullptr; tmpPtr = tmpPtr -> next) {
        std::cout << tmpPtr -> data << " ";
    }
    std::cout << std::endl;
}

template <class DataType>
StatusCode LinkQueue<DataType>::Pop (DataType& d) {
    if(!Empty()) {
        Node<DataType> *tmpPtr = front -> next;                                 // tmpPtr指向a1;
        d = tmpPtr -> data;
        front -> next = tmpPtr -> next;
        if(tmpPtr == rear) {                                                    // 删除的元素即唯一的元素（队尾元素）
            rear = front;
        }
        delete tmpPtr;
        return SUCCESS;
    } else {
        return UNDER_FLOW;
    }
}

template <class DataType>
StatusCode LinkQueue<DataType>::Push (const DataType& d) {
    Node<DataType> *tmpPtr = new Node<DataType>(d);
    if(tmpPtr != nullptr) {
        rear -> next = tmpPtr;
        rear = tmpPtr;
        return SUCCESS;
    } else {
        return OVER_FLOW;
    }
}

template <class DataType>
StatusCode LinkQueue<DataType>::Front (DataType& d) const {
    if(!Empty()) {
        d = front -> next -> data;
        return SUCCESS;
    } else {
        return UNDER_FLOW;
    }
}

template <class DataType>
LinkQueue<DataType>& LinkQueue<DataType>::operator= (const LinkQueue<DataType>& copy) {
    if(&copy != this) {
        Clear();
        for(Node<DataType> *tmpPtr = copy.front -> next; tmpPtr != nullptr; tmpPtr = tmpPtr -> next) {
            Push(tmpPtr -> data);
        }
    }
    return *this;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LKQUEUE_H
