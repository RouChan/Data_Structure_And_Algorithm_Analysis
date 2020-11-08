//
// Created by 喻如辰 on 2020/11/8.
// 二叉树头文件调用 utility of binary_tree.h
//

#include <iostream>
#include "../Header&Library/binary_tree.h"
using namespace std;

int main () {
    BinaryTree<char> test;

    test.PreOrderTraverse();
    test.InOrderTraverse();
    test.PostOrderTraverse();
    test.LevelOrderTraverse();
    cout << test.NodeCount() << endl;

    return 0;
}
