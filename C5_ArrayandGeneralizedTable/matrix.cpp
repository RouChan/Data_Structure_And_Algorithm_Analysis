//
// Created by 喻如辰 on 2020/10/26.
// 特殊矩阵了类的调用 utility of Matrix.h
//

#include "../Header&Library/Matrix.h"
using namespace std;

int main () {
    // 对称矩阵
    SymmetryMatrix<int> tmpS(4);
    tmpS(1, 2) = 3;
    tmpS(3, 2) = 6;
    tmpS(1, 3) = 10;
    tmpS(2, 2) = 20;
    tmpS(4, 3) = 19;
    tmpS.Traverse();

    cout << endl;

    // 三角矩阵
    TriDiagonalMatrix<int> tmpT(4, 1);
    tmpT(4, 0) = 12;
    tmpT(1, 1) = 10;
    tmpT(2, 2) = 15;
    tmpT(3, 4) = 8;
    tmpT(2, 4) = 100;
    tmpT.Traverse();

    return 0;
}