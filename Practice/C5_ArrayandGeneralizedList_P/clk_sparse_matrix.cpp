//
// Created by 喻如辰 on 2020/10/29.
// 1、用十字链表法实现稀疏矩阵的表示 utility of clk_sparse_matrix.h
//

#include <iostream>
#include "../../Header&Library/clk_sparse_matrix.h"
using namespace std;

int main () {
    CLkSparseMatrix<int> m1(3, 3);

    m1.SetNode(1, 1, 12);
    m1.SetNode(1, 2, 30);
    m1.SetNode(1, 3, 8);

    m1.SetNode(3, 1, 30);
    m1.SetNode(3, 2, 18);

    m1.Traverse();

    return 0;
}