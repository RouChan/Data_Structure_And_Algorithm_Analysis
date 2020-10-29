//
// Created by 喻如辰 on 2020/10/29.
// 十字链表稀疏矩阵头文件调用 utility of clk_sparse_matrix.h
//

#include <iostream>
#include "../Header&Library/clk_sparse_matrix.h"
using namespace std;

int main () {
    CLkSparseMatrix<int> m1(3, 3);

//    cout << m1.GetNum() << endl;

    m1.SetNode(1, 1, 12);
    m1.SetNode(1, 2, 30);
    m1.SetNode(1, 3, 8);
//    cout << m1.GetNum() << endl;

    int tmp = 0;
    m1.GetNode(1, 2, tmp);
    cout << tmp << endl;

    cout << m1.GetNum() << endl;

    return 0;
}