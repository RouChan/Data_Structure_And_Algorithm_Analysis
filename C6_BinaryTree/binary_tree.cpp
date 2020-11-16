//
// Created by 喻如辰 on 2020/11/8.
// 二叉树头文件调用 utility of binary_tree.h
//

#include <iostream>
#include "../Header&Library/binary_tree.h"
using namespace std;

int main () {
    BinaryTree<char> test('a');

    BinTreeNode<char> *tmp;

    test.GetRootPtr(tmp);
    test.InsertLeftChild(tmp, 'b');
    test.InsertRightChild(tmp, 'c');

    test.GetElemPtr(2, tmp);
    test.InsertRightChild(tmp, 'd');

    test.GetElemPtr(3, tmp);
    test.InsertLeftChild(tmp, 'e');

    test.PreOrderTraverse();
    test.DisplayLikeTree();

    return 0;
}
