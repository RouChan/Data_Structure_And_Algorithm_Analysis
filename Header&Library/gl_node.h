//
// Created by 喻如辰 on 2020/11/1.
// 广义表结点类
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_GL_NODE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_GL_NODE_H

enum NodeType {HEAD, ATOM, LIST};

template <class DataType>
struct GenListNode {
    NodeType tag;
    union {
        int                     ref;                                                    // 头结点->引用次数
        DataType                value;                                                  // 原子结点->数据
        GenListNode<DataType>   *subLink;                                               // 表结点->子表
    };
    GenListNode<DataType> *nextNode;                                                    // 下一个元素

    GenListNode(NodeType tag = HEAD, GenListNode<DataType> *next = nullptr);            // 构造函数
};

template <class DataType>
GenListNode<DataType>::GenListNode (NodeType tag, GenListNode<DataType> *next) {
    this -> tag = tag;
    nextNode = next;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_GL_NODE_H
