//
// Created by 喻如辰 on 2020/10/29.
// 使用十字链表
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CLK_SPARSE_MATRIX_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CLK_SPARSE_MATRIX_H
#define DEFAULT_SIZE 5

#include "clk_tri_node.h"

enum StatusCode {SUCCESS = 0, FAIL, UNDER_FLOW, OVER_FLOW,
    RANGE_ERROR, DUPLICATE_ERROR,NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

template <class DataType>
class CLkSparseMatrix{
protected:
    CLkTriNode<DataType> **rowHead, **colHead;                                          // 存储行头、列头
    int rows, cols, num;                                                                // 稀疏矩阵行数、列数、非零元素个数
public:
    CLkSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE);                      // 构造函数
    ~CLkSparseMatrix();                                                                 // 析构函数

    void    Clear();                                                                    // 清空矩阵
    int     GetRows() const;                                                            // 返回矩阵行数
    int     GetCols() const;                                                            // 返回矩阵列数
    int     GetNum()  const;                                                            // 返回矩阵非零元素个数

    StatusCode GetNode(int r, int c, DataType& d) const;                                // 取元素
    StatusCode SetNode(int r, int c, const DataType& d);                                // 设置矩阵元素d在(r, c)
};

template <class DataType>
CLkSparseMatrix<DataType>::CLkSparseMatrix (int rs, int cs) {
    rows = rs;
    cols = cs;
    num = 0;

    rowHead = new CLkTriNode<DataType> *[rows + 1];
    colHead = new CLkTriNode<DataType> *[cols + 1];
    for(int i = 1; i <= rows; ++i) {
        rowHead[i] = new CLkTriNode<DataType>;
    }
    for(int j = 1; j <= cols; ++j) {
        colHead[j] = new CLkTriNode<DataType>;
    }
}

template <class DataType>
CLkSparseMatrix<DataType>::~CLkSparseMatrix () {
    Clear();
}

template <class DataType>
void CLkSparseMatrix<DataType>::Clear () {
    for(int i = 1; i <= rows; ++i) {
        if(rowHead[i] != nullptr) {
            CLkTriNode<DataType> *tmpPtr = rowHead[i];
            rowHead[i] = tmpPtr -> right;                                               // 指向下一个（右边一个）非零元素
            delete tmpPtr;
        }
    }
    delete []rowHead;
    delete []colHead;
    rows = cols = num = 0;
}

template <class DataType>
int CLkSparseMatrix<DataType>::GetRows () const {
    return rows;
}

template <class DataType>
int CLkSparseMatrix<DataType>::GetCols () const {
    return cols;
}

template <class DataType>
int CLkSparseMatrix<DataType>::GetNum () const {
    return num;
}

template <class DataType>
StatusCode CLkSparseMatrix<DataType>::GetNode (int r, int c, DataType& d) const {
    if(r > rows || c > cols) {
        return RANGE_ERROR;
    } else {
        d = 0;
        for(CLkTriNode<DataType> *tmpPtr = rowHead[r]; tmpPtr != nullptr; tmpPtr = tmpPtr -> right) {
            if(tmpPtr -> col == c) {
                d = tmpPtr -> value;
                break;
            }
        }
        return SUCCESS;
    }
}

template <class DataType>
StatusCode CLkSparseMatrix<DataType>::SetNode (int r, int c, const DataType& d) {
    if(r > rows || c > cols) {
        return RANGE_ERROR;
    } else {
        CLkTriNode<DataType> *tmpPtr = rowHead[r];

        while(tmpPtr -> right != nullptr && tmpPtr -> right -> col <= c) {
            tmpPtr = tmpPtr -> right;
        }
        if(tmpPtr -> col == c) {                                                            // 该位置结点存在
            tmpPtr -> value = d;
        } else {                                                                            // 该位置结点不存在
            CLkTriNode<DataType> *newNode = new CLkTriNode<DataType>;
            newNode -> value = d;
            newNode -> row = r;
            newNode -> col = c;

            newNode -> right = tmpPtr -> right;                                             // 横向链接
            tmpPtr -> right = newNode;

            tmpPtr = colHead[c];                                                            // 纵向链接
            while(tmpPtr -> down != nullptr && tmpPtr ->  down -> row <= r) {
                tmpPtr = tmpPtr -> down;
            }
            newNode -> down = tmpPtr -> down;
            tmpPtr -> down = newNode;
            num++;
        }


    }
    return SUCCESS;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_CLK_SPARSE_MATRIX_H
