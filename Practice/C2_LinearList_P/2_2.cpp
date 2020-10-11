//
// Created by 喻如辰 on 2020/10/10.
// 第二章线性表
// 2. 实现一元多项式的表示与运算
//

#include <iostream>
#include "Polynomial.h"
using namespace std;

int main () {
    Polynomial p1, p2, p3;

    p1.Plus(PolyItem(4, 0));
    p1.Plus(PolyItem(0, 1));

    p2.Plus(PolyItem(-13.2, 2));
    p2.Plus(PolyItem(0, 1));
    p2.Plus(PolyItem(-2, 10));

    p3 = p1 * p2;

    p1.Traverse(1, p1.Length());
    p2.Traverse(1, p2.Length());
    p3.Traverse(1, p3.Length());

    return 0;
}