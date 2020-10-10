//
// Created by 喻如辰 on 2020/9/27.
// 单向链表的实现
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LIST_H

#include "Node.h"

enum StatusCode {SUCCESS = 0, FAIL, UNDER_FLOW, OVER_FLOW,
        RANGE_ERROR, DUPLICATE_ERROR,NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};
                                                            // 操作状态码

template <class DataType>
class List {
protected:
    Node<DataType>*     head;                               // 头结点指针
    Node<DataType>*     GetNodePtr(int position) const;     // 返回position位置结点指针
    void                Init();                             // 初始化线性表
public:
    List();                                                 // 无参构造函数
    virtual ~List();

    int     Length() const;                                 // 返回链表长度
    bool    Empty() const;                                  // 判断是否为空链表
    void    Clear();                                        // 清空链表
    void    Traverse(int from, int to) const;               // 遍历链表

    List<DataType> &operator = (const List<DataType> &copy);// 重载赋值运算符

    StatusCode GetNode(int position, DataType& d) const;    // 将position的数据域赋值给d
    StatusCode SetNode(int position, DataType& d);          // 将position位置的结点元素赋值为d
    StatusCode Insert(int position, const DataType& d);     // 在position位置前插入元素d
    StatusCode Delete(int position, DataType& d);           // 删除position位置元素，并d被赋值被删除结点下一个结点数据域
};

template <class DataType>
List<DataType>::List() {
    head = nullptr;
    Init();
}

template <class DataType>                               // 添加判断
void List<DataType>::Init() {
    head = new Node<DataType>;
}

template <class DataType>
List<DataType>::~List() {
    Clear();
    delete head;
}

template <class Datatype>
Node<Datatype>* List<Datatype>::GetNodePtr(int position) const {            // head编号为0，head->next为编号为1的结点；
    Node<Datatype>* tmpPtr = head;
    int curPosition = 0;

    while(tmpPtr != nullptr && curPosition < position) {
        tmpPtr = tmpPtr -> next;
        curPosition++;
    }

    if(tmpPtr != nullptr && curPosition == position) {
        return tmpPtr;
    } else {
        return nullptr;
    }
}

template <class DataType>
int List<DataType>::Length() const {
    int count = 0;
    for(Node<DataType>* tmpPtr = head -> next; tmpPtr != nullptr; tmpPtr = tmpPtr->next) {
        count++;
    }
    return count;
}

template <class DataType>
bool List<DataType>::Empty() const {
    return (head -> next == nullptr);
}

template <class DataType>
void List<DataType>::Clear() {                                  // 仅保留head指针
    DataType tmpNode;
    while(Length() > 0) {
        Delete(1, tmpNode);
    }
}

template<class DataType>
void List<DataType>::Traverse(int from, int to) const {
    for(int i = from; i <= to; i++) {
        DataType tmp;
        GetNode(i, tmp);
        std::cout << tmp << " ";
    }
    std::cout << std::endl;
}

template<class DataType>
List<DataType> &List<DataType>::operator=(const List<DataType> &copy) {
    if(&copy != this) {
        int copyLength = copy.Length();
        Clear();

        for(int curPosition = 1; curPosition <= copyLength; curPosition++) {
            DataType tmp;
            copy(curPosition, tmp);
            Insert(Length() + 1, tmp);
        }
    }
    return *this;
}

template <class DataType>
StatusCode List<DataType>::GetNode(int position, DataType &d) const {   // 借助d作为返回值
    if(position < 1 || position > Length()) {
        return RANGE_ERROR;
    } else {
        Node<DataType>* tmpPtr;
        tmpPtr = GetNodePtr(position);
        d = tmpPtr -> data;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode List<DataType>::SetNode(int position, DataType &d) {
    if(position < 1 || position > Length()) {
        return RANGE_ERROR;
    } else {
        Node<DataType>* tmpPtr;
        tmpPtr = GetNodePtr(position);
        tmpPtr -> data = d;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode List<DataType>::Insert(int position, const DataType &d) {
    if(position < 1 || position > Length() + 1) {
        return RANGE_ERROR;
    } else {
        Node<DataType>* tmpPtr;
        tmpPtr = GetNodePtr(position - 1);

        Node<DataType>* newNode;
        newNode = new Node<DataType>(d, tmpPtr -> next);
        tmpPtr -> next = newNode;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode List<DataType>::Delete(int position, DataType &d) {
    if(position < 1 || position > Length()) {
        return RANGE_ERROR;
    } else {
        Node<DataType>* tmpPtr;
        tmpPtr = GetNodePtr(position - 1);
        Node<DataType>* nextPtr = tmpPtr -> next;                       // nextPtr所指向结点为准备被删除结点
        tmpPtr -> next = nextPtr -> next;
        d = nextPtr -> data;
        delete nextPtr;
        return SUCCESS;
    }
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LIST_H
