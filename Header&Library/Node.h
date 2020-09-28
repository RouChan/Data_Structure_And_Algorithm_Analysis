//
// Created by 喻如辰 on 2020/9/28.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_NODE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_NODE_H

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

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_NODE_H
