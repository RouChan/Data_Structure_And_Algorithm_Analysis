//
// Created by 喻如辰 on 2020/11/8.
// 二叉树结点类
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_BIN_TREE_NODE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_BIN_TREE_NODE_H

template <class DataType>
struct BinTreeNode{
    DataType data;                                      // 数据域
    BinTreeNode<DataType>   *parent;                    // 双亲结点
    BinTreeNode<DataType>   *leftChild;                 // 左子结点
    BinTreeNode<DataType>   *rightChild;                // 右子结点

    // 构造函数
    BinTreeNode();
    BinTreeNode(const DataType& val, BinTreeNode<DataType> *parent = nullptr, BinTreeNode<DataType> *lChild = nullptr, BinTreeNode<DataType> *rChild = nullptr);
};

template <class DataType>
BinTreeNode<DataType>::BinTreeNode () {
    parent = leftChild = rightChild = nullptr;
}

template <class DataType>
BinTreeNode<DataType>::BinTreeNode(const DataType& val, BinTreeNode<DataType> *parent, BinTreeNode<DataType> *lChild, BinTreeNode<DataType> *rChild) {
    data        = val;
    parent      = parent;
    leftChild   = lChild;
    rightChild  = rChild;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_BIN_TREE_NODE_H
