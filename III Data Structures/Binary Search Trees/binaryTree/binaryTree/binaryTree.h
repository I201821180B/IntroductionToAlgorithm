#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "basic.h"
#include "node.h"

#include <iostream>
#include <initializer_list>
#include <string>
#include <vector>
#include <memory>

template<typename T>
class binaryTree
{
public:
    //using pNode = node<T>::pNode;
    using pNode = node<T>*;
    binaryTree();
    binaryTree(std::initializer_list<T> il);/*复制列表初始化构造函数不能标记为explicit*/
    explicit binaryTree(std::vector<T>& v);
    ~binaryTree();
    pNode root() { return root_; }

    void preOrderTreeWalk(pNode x);
    void inOrderTreeWalk(pNode x);
    void postOrderTreeWalk(pNode x);
    void print();

    T search(T key);
    
    T min();	
    T max();

    T successor(T key);
    T preSuccessor(T key);

    void insert(T key);
    void remove(T key);
private:
    pNode root_;

    pNode treeSearch(pNode x, T key);
    pNode iterativeTreeSearch(pNode x, T key);
    pNode treeMinimum(pNode x);
    pNode treeMaximum(pNode x);
    pNode treeSuccessor(pNode x);
    pNode treePreSuccessor(pNode x);
    void treeInsert(pNode z);
    void treeDelete(pNode z);

    void transplant(pNode u, pNode v);
    void treeFree(pNode x);
    DISABLE_COPY_AND_ASSIGN(binaryTree);
};

#endif




