//
// Created by 喻如辰 on 2020/10/29.
// 十字链表结点
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CLK_TRI_NODE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CLK_TRI_NODE_H

template <class DataType>
struct CLkTriNode{
    int row, col;
    DataType value;
    CLkTriNode<DataType> *right,*down;                      // 分别表示同行/同列下一个元素

    CLkTriNode();
    CLkTriNode(const int row, const int col, const DataType& value, CLkTriNode<DataType> *rLink = nullptr, CLkTriNode<DataType> *dLink = nullptr);
};

template <class DataType>
CLkTriNode<DataType>::CLkTriNode () {
    row = col = 0;
    right = down = nullptr;
}

template <class DataType>
CLkTriNode<DataType>::CLkTriNode (const int row, const int col, const DataType& value, CLkTriNode<DataType> *rLink, CLkTriNode<DataType> *dLink) {
    this -> row     = row;
    this -> col     = col;
    this -> value   = value;
    right           = rLink;
    down            = dLink;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CLK_TRI_NODE_H
