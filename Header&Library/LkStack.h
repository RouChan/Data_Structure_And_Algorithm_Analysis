//
// Created by 喻如辰 on 2020/10/11.
// 链式栈 Linked Stack
//

#include "Node.h"

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LKSTACK_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LKSTACK_H

#define DEFAULT_SIZE 10

enum StatusCode {SUCCESS = 0, FAIL, UNDER_FLOW, OVER_FLOW,
    RANGE_ERROR, DUPLICATE_ERROR,NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

template <class DataType>
class LinkStack {
protected:
    Node<DataType>* top;
    // 辅助函数
    void Init();
public:
    LinkStack();                                                            // 无参数构造函数
    LinkStack(const LinkStack<DataType>& copy);                             // 复制构造函数
    virtual ~LinkStack();                                                   // 析构函数

    int     Length() const;                                                 // 求栈长度
    bool    Empty() const;                                                  // 判断是否为空
    void    Clear();                                                        // 清空栈
    void    Traverse() const;                                               // 遍历

    StatusCode Push (const DataType& d);                                    // 压入栈
    StatusCode Top (DataType& d) const;                                     // 将栈顶元素保存到d中
    StatusCode Pop (DataType& d);                                           // 出栈

    LinkStack<DataType>& operator= (const LinkStack<DataType>& copy);       // =操作符重载
};

template <class DataType>
void LinkStack<DataType>::Init () {
    top = nullptr;
}

template <class DataType>
LinkStack<DataType>::LinkStack () {
    Init();
}

template <class DataType>
LinkStack<DataType>::LinkStack (const LinkStack<DataType>& copy) {
    if(copy.Empty()) {
        Init();
    } else {
        top = new Node<DataType>((copy.top)->data);                         // 栈顶
        Node<DataType>* bottomPtr = top;
        for(Node<DataType>* tmpPtr = copy.top -> next; tmpPtr != nullptr; tmpPtr = tmpPtr -> next) {
            bottomPtr -> next = new Node<DataType>(tmpPtr -> data);
            bottomPtr = bottomPtr -> next;
        }
    }
}

template <class DataType>
LinkStack<DataType>::~LinkStack<DataType> () {
    Clear();
}

template <class DataType>
void LinkStack<DataType>::Clear () {
    DataType tmp;
    while(!Empty()) {
        Pop(tmp);
    }
}

template <class DataType>
int LinkStack<DataType>::Length () const {
    int count = 0;
    for(Node<DataType>* tmpPtr = top; tmpPtr != nullptr; tmpPtr = tmpPtr -> next) {
        count++;
    }
    return count;
}

template <class DataType>
bool LinkStack<DataType>::Empty () const {
    return (top == nullptr);
}

template <class DataType>
void LinkStack<DataType>::Traverse () const {
    Node<DataType>* tmpNPtr;
    LinkStack<DataType> tmpS;
    for(tmpNPtr = top; tmpNPtr != nullptr; tmpNPtr = tmpNPtr -> next) {
        tmpS.Push(tmpNPtr -> data);
    }

    for(tmpNPtr = tmpS.top; tmpNPtr != nullptr; tmpNPtr = tmpNPtr -> next) {
        std::cout << tmpNPtr -> data << " ";
    }
    std::cout << std::endl;
}

template <class DataType>
StatusCode LinkStack<DataType>::Push (const DataType& d) {
    Node<DataType>* newTop = new Node<DataType>(d, top);
    if(newTop == nullptr) {
        return OVER_FLOW;
    } else {
        this -> top = newTop;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode LinkStack<DataType>::Top (DataType& d) const {
    if(Empty()) {
        return RANGE_ERROR;
    } else {
        d = top -> data;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode LinkStack<DataType>::Pop (DataType& d) {
    if(Empty()) {
        return UNDER_FLOW;
    } else {
        Node<DataType>* oldTop = top;
        d = oldTop -> data;
        top = top -> next;
        delete oldTop;
        return SUCCESS;
    }
}

template <class DataType>
LinkStack<DataType>& LinkStack<DataType>::operator= (const LinkStack<DataType>& copy) {
    if(&copy != this) {
        if(copy.Empty()) {
            Init();
        } else {
            Clear();
            top = new Node<DataType>((copy.top) -> data);
            Node<DataType>* bottomPtr = top;
            for(Node<DataType>* tmpPtr = copy.top -> next; tmpPtr != nullptr; tmpPtr = tmpPtr -> next) {
                bottomPtr -> next = new Node<DataType>(tmpPtr -> data);
                bottomPtr = bottomPtr -> next;
            }
        }
    }
    return *this;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LKSTACK_H
