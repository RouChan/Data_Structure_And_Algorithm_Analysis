//
// Created by 喻如辰 on 2020/9/27.
// 已知两个链表`la`和`lb`，其元素值递增排序。编程将`la`和`lb`合并成一个递减有序（相同值元素只保留一个）的链表`lc`。
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LIST_H

enum StatusCode {SUCCESS = 0, RANGE_ERROR};                 // 操作状态码

template <class DataType>                                   // 结点类
struct Node {
    DataType data;
    Node<DataType>* next;

    Node() : next(nullptr){};                               // 无参数初始化函数
    Node(DataType d, Node<DataType>* link = nullptr);
};

template <class DataType>
Node<DataType>::Node(DataType d, Node<DataType>* link) {
    data = d;
    next = link;
}

template <class DataType>
class SinglyLinkedList {
protected:
    Node<DataType>*     head;                               // 头结点指针
    Node<DataType>*     GetNodePtr(int position) const;     // 返回position位置结点指针
    void                Init();                             // 初始化线性表
public:
    SinglyLinkedList();                                                 // 无参构造函数
    virtual ~SinglyLinkedList();

    int     Length() const;                                 // 返回链表长度
    bool    Empty() const;                                  // 判断是否为空链表
    void    Clear();                                        // 清空链表
//    void Traverse

    StatusCode GetNode(int position, DataType& d) const;    // 将position的数据域赋值给d
    StatusCode SetNode(int position, DataType& d);          // 将position位置的结点元素赋值为d
    StatusCode Insert(int position, const DataType& d);     // 在position位置前插入元素d
    StatusCode Delete(int position, DataType& d);           // 删除position位置元素，并d被赋值被删除结点下一个结点数据域

    friend void Merge(SinglyLinkedList<DataType>& la, SinglyLinkedList<DataType>& lb, SinglyLinkedList<DataType>& lc);
};

template <class DataType>
SinglyLinkedList<DataType>::SinglyLinkedList() {
    head = nullptr;
    Init();
}

template <class DataType>                               // 添加判断
void SinglyLinkedList<DataType>::Init() {
    head = new Node<DataType>;
}

template <class DataType>
SinglyLinkedList<DataType>::~SinglyLinkedList() {
    Clear();
    delete head;
}

template <class Datatype>
Node<Datatype>* SinglyLinkedList<Datatype>::GetNodePtr(int position) const {            // head编号为0，head->next为编号为1的结点；
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
int SinglyLinkedList<DataType>::Length() const {
    int count = 0;
    for(Node<DataType>* tmpPtr = head -> next; tmpPtr != nullptr; tmpPtr = tmpPtr->next) {
        count++;
    }
    return count;
}

template <class DataType>
bool SinglyLinkedList<DataType>::Empty() const {
    return (head -> next == nullptr);
}

template <class DataType>
void SinglyLinkedList<DataType>::Clear() {
    DataType tmpNode;
    while(Length() > 0) {
        Delete(1, tmpNode);
    }
}

template <class DataType>
StatusCode SinglyLinkedList<DataType>::GetNode(int position, DataType &d) const {   // 借助d作为返回值
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
StatusCode SinglyLinkedList<DataType>::SetNode(int position, DataType &d) {
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
StatusCode SinglyLinkedList<DataType>::Insert(int position, const DataType &d) {
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
StatusCode SinglyLinkedList<DataType>::Delete(int position, DataType &d) {
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

template <class DataType>
void ListMerge(SinglyLinkedList<DataType>& la, SinglyLinkedList<DataType>& lb, SinglyLinkedList<DataType>& lc){
    enum Status {empty = 0, left};
    Status laStatus = left, lbStatus = left;
    int laPos = 0, lbPos = 0;

    while (laStatus + lbStatus) {
        if(laPos == la.Length()) {
            laStatus = empty;
        }
        if(lbPos == lb.Length()) {
            lbStatus = empty;
        }

        if(laStatus == left && lbStatus == left) {
            DataType laTmp, lbTmp;

            la.GetNode(laPos + 1, laTmp);
            lb.GetNode(lbPos + 1, lbTmp);

            if(laTmp <= lbTmp) {
                lc.Insert(1, laTmp);
                laPos++;
                if(laTmp == lbTmp) lbPos++;
            } else {
                lc.Insert(1, lbTmp);
                lbPos++;
            }
        } else if (laStatus == left) {                  // la剩余，lb无
            while(laPos != la.Length()) {
                DataType laTmp;
                la.GetNode(laPos + 1, laTmp);
                lc.Insert(1, laTmp);
                laPos++;
            }
            laStatus = empty;
        } else if (lbStatus == left) {                  // lb剩余，la无
            while(lbPos != lb.Length()) {
                DataType lbTmp;
                lb.GetNode(lbPos + 1, lbTmp);
                lc.Insert(1, lbTmp);
                lbPos++;
            }
            lbStatus = empty;
        }
    }
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_LIST_H
