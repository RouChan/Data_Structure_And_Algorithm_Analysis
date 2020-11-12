//
// Created by 喻如辰 on 2020/11/8.
// 二叉树类 binary_tree.h
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_BINARY_TREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_BINARY_TREE_H

#include "global.h"
#include "bin_tree_node.h"
#include "LkQueue.h"
#include "LkStack.h"
#include <iostream>

template <class DataType>
class BinaryTree{
private:
    BinTreeNode<DataType> *root;                                            // 根结点

    // 辅助函数
    void    PreOrderHelp(BinTreeNode<DataType> *r) const;                   // 先序遍历辅助函数
    void    InOrderHelp(BinTreeNode<DataType> *r) const;                    // 中序遍历辅助函数
    void    PostOrderHelp(BinTreeNode<DataType> *r) const;                  // 后序遍历辅助函数
    int     NodeCountHelp(BinTreeNode<DataType> *r) const;                  // 结点个数辅助函数
    void    DeleteHelp(BinaryTree<DataType> *&node);                        // 删除结点辅助函数
    int     HeightHelp(BinTreeNode<DataType> *node) const;                  // 求深度辅助函数
public:
    BinaryTree();											                // 无参构造函数
    explicit BinaryTree(const DataType& d);                                          // 以d为根结点元素的构造函数
    ~BinaryTree();

    bool    Empty() const;							                        // 判断二叉树是否为空
    void    PreOrderTraverse() const;	                                    // 先序遍历
    void    InOrderTraverse() const;	                                    // 中序遍历
    void    PostOrderTraverse() const;	                                    // 后序遍历
    void    LevelOrderTraverse() const;	                                    // 层次遍历
    int     NodeCount() const;									            // 结点个数
    void    InsertLeftChild(BinTreeNode<DataType> *pos, const DataType &d); // 插入左孩子
    void    InsertRightChild(BinTreeNode<DataType> *pos, const DataType &d);// 插入右孩子
    void    DeleteLeftChild(BinTreeNode<DataType> *pos);		            // 删除左子树
    void    DeleteRightChild(BinTreeNode<DataType> *pos);		            // 删除右子树
    int     Height() const;                                                 // 求深度

    StatusCode GetRootPtr(BinTreeNode<DataType> *&r) const;				    // 返回根
    StatusCode GetElemPtr(int num, BinTreeNode<DataType> *&node) const;     // 以满二叉树排号方式、返回编号为num的结点地址
    StatusCode GetElem(BinTreeNode<DataType> *pos, DataType &d) const;      // 取特定位置元素
    StatusCode SetElem(BinTreeNode<DataType> *pos, const DataType &d);      // 设置特定位置元素
    StatusCode GetLeftChild(BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const;
                                                                            // 返回pos结点的左子结点
    StatusCode GetRightChild(BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const;
                                                                            // 返回pos结点的右子结点
    StatusCode GetParent(BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const;
                                                                            // 返回pos结点的双亲结点
};

template <class DataType>
BinaryTree<DataType>::BinaryTree () {
    root = nullptr;
}

template <class DataType>
BinaryTree<DataType>::BinaryTree (const DataType& d) {
    root = new BinTreeNode<DataType>(d);
}

template <class DataType>
BinaryTree<DataType>::~BinaryTree () {
    DeleteHelp(root);
}

template <class DataType>
void BinaryTree<DataType>::PreOrderHelp (BinTreeNode<DataType> *r) const {
    if(r == nullptr) return;
    else {
        std::cout << r -> data << " ";
        PreOrderHelp(r -> leftChild);
        PreOrderHelp(r -> rightChild);
    }
}

template <class DataType>
void BinaryTree<DataType>::InOrderHelp (BinTreeNode<DataType> *r) const {
    if(r == nullptr) return;
    else {
        InOrderHelp(r -> leftChild);
        std::cout << r -> data << " ";
        InOrderHelp(r -> rightChild);
    }
}

template <class DataType>
void BinaryTree<DataType>::PostOrderHelp (BinTreeNode<DataType> *r) const {
    if(r == nullptr) return;
    else {
        PostOrderHelp(r -> leftChild);
        PostOrderHelp(r -> rightChild);
        std::cout << r -> data << " ";
    }
}

template <class DataType>
int BinaryTree<DataType>::NodeCountHelp (BinTreeNode<DataType> *r) const {
    if(r == nullptr)    return 0;
    else                return (NodeCountHelp(r -> leftChild) + NodeCountHelp(r -> rightChild) + 1);
}

template <class DataType>
void BinaryTree<DataType>::DeleteHelp (BinaryTree<DataType> *&node) {
    if(node == nullptr) return;
    else {
        DeleteHelp(node -> leftChild);
        DeleteHelp(node -> rightChild);
        delete node;
        node = nullptr;
    }
}

template <class DataType>
int BinaryTree<DataType>::HeightHelp (BinTreeNode<DataType> *node) const {
    if(node == 0) return 0;
    else {
        int leftHeight = HeightHelp(node -> leftChild), rightHeight = HeightHelp(node -> rightChild);
        return (1 + (leftHeight > rightHeight ? leftHeight : rightHeight));
    }
}

template <class DataType>
bool BinaryTree<DataType>::Empty () const {
    return (root == nullptr);
}

template <class DataType>
void BinaryTree<DataType>::PreOrderTraverse () const {
    PreOrderHelp(root);
    std::cout << std::endl;
}

template <class DataType>
void BinaryTree<DataType>::InOrderTraverse () const {
    InOrderHelp(root);
    std::cout << std::endl;
}

template <class DataType>
void BinaryTree<DataType>::PostOrderTraverse () const {
    PostOrderHelp(root);
    std::cout << std::endl;
}

template <class DataType>
void BinaryTree<DataType>::LevelOrderTraverse () const {
    LinkQueue<BinTreeNode<DataType> *> nodes;
    nodes.Push(root);

    while(!nodes.Empty()) {
        BinTreeNode<DataType> *tmpPtr;
        nodes.Front(tmpPtr);
        if(tmpPtr == nullptr) {
            nodes.Pop(tmpPtr);
        } else {
            std::cout << tmpPtr -> data << " ";
            nodes.Push(tmpPtr -> leftChild);
            nodes.Push(tmpPtr -> rightChild);
            nodes.Pop(tmpPtr);
        }
    }

    std::cout << std::endl;
}

template <class DataType>
int BinaryTree<DataType>::NodeCount () const {
    return NodeCountHelp(root);
}

template <class DataType>
void BinaryTree<DataType>::InsertLeftChild (BinTreeNode<DataType> *pos, const DataType& d) {
    if(pos == nullptr) {
        return;
    } else {
        pos -> leftChild = new BinTreeNode<DataType>(d, pos, nullptr, nullptr);
        return;
    }
}

template <class DataType>
void BinaryTree<DataType>::InsertRightChild (BinTreeNode<DataType> *pos, const DataType& d) {
    if(pos == nullptr) {
        return ;
    } else {
        pos -> rightChild = new BinTreeNode<DataType>(d, pos, nullptr, nullptr);
        return;
    }
}

template <class DataType>
void BinaryTree<DataType>::DeleteLeftChild (BinTreeNode<DataType> *pos) {
    if(pos == nullptr) return;
    else {
        DeleteHelp(pos -> leftChild);
    }
}

template <class DataType>
void BinaryTree<DataType>::DeleteRightChild (BinTreeNode<DataType> *pos) {
    if(pos == nullptr) return;
    else {
        DeleteHelp(pos -> rightChild);
    }
}

template <class DataType>
int BinaryTree<DataType>::Height () const {
    return HeightHelp(root);
}

template <class DataType>
StatusCode BinaryTree<DataType>::GetRootPtr (BinTreeNode<DataType> *&r) const {
    if(Empty()) {
        return FAIL;
    } else {
        r = root;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode BinaryTree<DataType>::GetElemPtr (int num, BinTreeNode<DataType> *& node) const {
    LinkStack<char> lor;
    while(num != 1) {
        lor.Push(num % 2);
        num /= 2;
    }
    BinTreeNode<DataType> *tmpPtr = root;
    while(!lor.Empty()){
        char t = 0;
        lor.Top(t);
        if(tmpPtr == nullptr) {
            return FAIL;
        } else {
            if (t) tmpPtr = tmpPtr -> rightChild;
            else tmpPtr = tmpPtr -> leftChild;
        }
        lor.Pop(t);
    }
    node = tmpPtr;
    return SUCCESS;
}

template <class DataType>
StatusCode BinaryTree<DataType>::GetElem (BinTreeNode<DataType> *pos, DataType& d) const {
    if(pos == nullptr) {
        return FAIL;
    } else {
        d = pos -> data;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode BinaryTree<DataType>::SetElem (BinTreeNode<DataType> *pos, const DataType& d) {
    if(pos == nullptr) {
        return FAIL;
    } else {
        pos -> data = d;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode BinaryTree<DataType>::GetLeftChild (BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const {
    if(pos == nullptr) return FAIL;
    else {
        n = pos -> leftChild;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode BinaryTree<DataType>::GetRightChild (BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const {
    if(pos == nullptr) return FAIL;
    else {
        n = pos -> rightChildChild;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode BinaryTree<DataType>::GetParent (BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const {
    if(pos == nullptr) return FAIL;
    else {
        n = pos -> parent;
        return SUCCESS;
    }
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_BINARY_TREE_H
