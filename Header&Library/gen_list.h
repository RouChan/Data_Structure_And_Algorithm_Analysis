//
// Created by 喻如辰 on 2020/11/1.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_GEN_LIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_GEN_LIST_H

#include <iostream>
#include "gl_node.h"

template <class DataType>
class GenList {
protected:
    GenListNode<DataType> *head;                                                            // 头指针

    // 辅助函数
    void    TraverseHelp(GenListNode<DataType> *hd) const;                                // 遍历
    int     DepthHelp(GenListNode<DataType> *hd) const;                                   // 深度
    void    ClearHelp(GenListNode<DataType> *hd);                                         // 清空
public:
    GenList();                                                                              // 构造函数
    ~GenList();                                                                             // 析构函数

    void    Traverse() const;                                                               // 遍历
    int     Depth() const;                                                                  // 深度
    bool    Empty() const;                                                                  // 是否为空
    void    GetFirst(GenListNode<DataType> &d) const;                                       // 取第一个元素
    void    PushFront(const DataType& d);                                                   // 元素放在表头
    void    PushFront(const GenList<DataType>& sl);                                         // 子表放在表头
};

template <class DataType>
GenList<DataType>::GenList () {
    head = new GenListNode<DataType>(HEAD);
    head -> ref = 1;
}

template <class DataType>
GenList<DataType>::~GenList() {
    ClearHelp(head);
}

template <class DataType>
void GenList<DataType>::TraverseHelp (GenListNode<DataType> *hd) const {
    bool first = true;                                                                      // 如果是第一个元素，则前面不需要加逗号
    std::cout << "(";
    for(GenListNode<DataType> *tmpPtr = hd -> nextNode; tmpPtr != nullptr; tmpPtr = tmpPtr -> nextNode) {
        if(first) {
            first = false;
        } else {
            std::cout << ", ";
        }

        if(tmpPtr -> tag == ATOM) {
            std::cout << tmpPtr -> value;
        } else {
            TraverseHelp(tmpPtr -> subLink);
        }
    }
    std::cout << ")";
}

template <class DataType>
int GenList<DataType>::DepthHelp (GenListNode<DataType> *hd) const {
    if(hd -> nextNode == nullptr) return 1;

    int maxDepth = 0;
    for(GenListNode<DataType> *tmpPtr = hd -> nextNode; tmpPtr != nullptr; tmpPtr = tmpPtr -> nextNode) {
        if(tmpPtr -> tag == LIST) {
            int tmp = DepthHelp(tmpPtr -> subLink);
            maxDepth = tmp > maxDepth ? tmp : maxDepth;
        }
    }
    return maxDepth + 1;
}

template <class DataType>
void GenList<DataType>::ClearHelp (GenListNode<DataType> *hd) {
    hd -> ref--;

    if(hd -> ref == 0) {
        GenListNode<DataType> *tmpPre, *tmpPtr;
        for(tmpPre = hd, tmpPtr = hd -> nextNode; tmpPtr != nullptr; tmpPre = tmpPtr, tmpPtr = tmpPtr -> nextNode) {
            delete tmpPre;
            if(tmpPtr -> tag == LIST) {
                tmpPtr -> subLink -> ref--;
            }
        }
    } else {
        std::cerr << "DELETE WRONG!" << std::endl;
    }
}

template <class DataType>
void GenList<DataType>::Traverse () const {
    TraverseHelp(head);
    std::cout << std::endl;
}

template <class DataType>
int GenList<DataType>::Depth () const {
    return DepthHelp(head);
}

template <class DataType>
bool GenList<DataType>::Empty () const {
    return (head -> nextNode == nullptr);
}

template <class DataType>
void GenList<DataType>::GetFirst (GenListNode<DataType>& d) const {
    if(!Empty()) d = head -> nextNode;
}

template <class DataType>
void GenList<DataType>::PushFront (const DataType& d) {
    GenListNode<DataType> *tmpPtr = new GenListNode<DataType>(ATOM, head -> nextNode);
    tmpPtr -> value = d;
    head -> nextNode = tmpPtr;
}

template <class DataType>
void GenList<DataType>::PushFront (const GenList<DataType>& sl) {
    if(&sl == this) {std::cerr << "REFERRED TO ITSELF!" << std::endl;}
    GenListNode<DataType> *tmpPtr = new GenListNode<DataType>(LIST, head -> nextNode);
    tmpPtr -> subLink = sl.head;
    sl.head -> ref++;
    head -> nextNode = tmpPtr;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_GEN_LIST_H
