//
// Created by 喻如辰 on 2020/11/8.
// 二叉树类 binary_tree.h
//

#include "bin_tree_node.h"
#include "LkQueue.h"
#include <iostream>

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_BINARY_TREE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_BINARY_TREE_H

template <class DataType>
class BinaryTree{
private:
    BinTreeNode<DataType> *root;                                            // 根结点

    // 辅助函数
    void    PreOrderHelp(BinTreeNode<DataType> *r) const;                   // 先序遍历辅助函数
    void    InOrderHelp(BinTreeNode<DataType> *r) const;                    // 中序遍历辅助函数
    void    PostOrderHelp(BinTreeNode<DataType> *r) const;                  // 后序遍历辅助函数
    int     NodeCountHelp(BinTreeNode<DataType> *r) const;                  // 结点个数辅助函数
public:
    BinaryTree();											                // 无参构造函数

    bool    Empty() const;							                        // 判断二叉树是否为空
    void    PreOrderTraverse() const;	                                    // 先序遍历
    void    InOrderTraverse() const;	                                    // 中序遍历
    void    PostOrderTraverse() const;	                                    // 后序遍历
    void    LevelOrderTraverse() const;	                                    // 层次遍历
    int     NodeCount() const;									            // 结点个数

    StatusCode GetRoot(BinTreeNode<DataType> *r) const;				        // 返回根
    StatusCode GetElem(BinTreeNode<DataType> *pos, DataType &d) const;      // 取特定位置元素
    StatusCode SetElem(BinTreeNode<DataType> *pos, const DataType &d);      // 设置特定位置元素
    StatusCode GetLeftChild(BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const;
                                                                            // 返回pos结点的左子结点
    StatusCode GetRightChild(BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const;
                                                                            // 返回pos结点的右子结点
    StatusCode GetParent(BinTreeNode<DataType> *pos, BinTreeNode<DataType>& n) const;
                                                                            // 返回pos结点的双亲结点
    // todo: 析构函数
    // todo: return the position of the particular node according to a number.
//    virtual ~BinaryTree();									// 析构函数

    void InsertLeftChild(BinTreeNode<DataType> *cur, const DataType &e);// 插入左孩子
    void InsertRightChild(BinTreeNode<DataType> *cur, const DataType &e);// 插入右孩子
    void DeleteLeftChild(BinTreeNode<DataType> *cur);		// 删除左子树
    void DeleteRightChild(BinTreeNode<DataType> *cur);		// 删除右子村
    int	Height() const;										// 求二叉树的高
    BinaryTree(const DataType &e);							// 建立以e为根的二叉树
    BinaryTree(const BinaryTree<DataType> &copy);			// 复制构造函数模板
    BinaryTree(BinTreeNode<DataType> *r);					// 建立以r为根的二叉树
    BinaryTree<DataType> &operator=(const BinaryTree<DataType>& copy);	// 重载赋值运算符
                                                   // 无参数构造函数

};

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
BinaryTree<DataType>::BinaryTree () {
    root = nullptr;
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
StatusCode BinaryTree<DataType>::GetRoot (BinTreeNode<DataType> *r) const {
    if(Empty()) {
        return FAIL;
    } else {
        r = root;
        return SUCCESS;
    }
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
