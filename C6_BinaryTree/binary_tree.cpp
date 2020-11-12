//
// Created by 喻如辰 on 2020/11/8.
// 二叉树头文件调用 utility of binary_tree.h
//

#include <iostream>
#include "../Header&Library/binary_tree.h"
using namespace std;

int main () {
    BinaryTree<char> test('1');

    BinTreeNode<char> *tmp;

    test.GetRootPtr(tmp);
    test.InsertLeftChild(tmp, '2');

    test.GetElemPtr(2, tmp);
    test.InsertLeftChild(tmp, '4');

    test.GetRootPtr(tmp);
    test.InsertRightChild(tmp, '3');

    test.GetElemPtr(3, tmp);
    test.InsertLeftChild(tmp, '9');

    test.PreOrderTraverse();

    return 0;
}
