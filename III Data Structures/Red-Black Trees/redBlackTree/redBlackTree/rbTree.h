#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "basic.h"
#include "node.h"

#include <string>
#include <vector>
#include <iostream>
#include <initializer_list>

template<typename T>
class rbTree
{
public:
    /*using RED = node<T>::RED;
    using BLACK = node<T>::BLACK;
    using NIL = node<T>::NIL;
    using COLOR = node<T>::iro;*/
//#define RED node<T>::RED
//#define BLACK node<T>::BLACK
//#define NIL node<T>::NIL
    using pNode = node<T>*;
    rbTree();
    rbTree(std::initializer_list<T> il);
    explicit rbTree(std::vector<T>& v);
    ~rbTree();
    /*typename node<T>::COLOR RED() { return node<T>::RED; }
    typename node<T>::COLOR BLACK() { return node<T>::BLACK; }
    typename node<T>::COLOR NIL() { return node<T>::NIL; }*/
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
    pNode nil_;

    pNode treeMaximum(pNode x);
    pNode treeMinimum(pNode x);
    pNode treeSearch(pNode x, T key);
    pNode iterativeTreeSearch(pNode x, T key);
    pNode rbSuccessor(pNode x);
    pNode rbPreSuccessor(pNode x);
    void rbInsert(pNode z);
    void rbDelete(pNode z);

    void leftRotate(pNode x);
    void rightRotate(pNode y);
    void rbInsertFixup(pNode z);
    void rbTransplant(pNode u, pNode v);
    void rbDeleteFixup(pNode x);
    void rbFree(pNode x);
    DISABLE_COPY_AND_ASSIGN(rbTree);
};

#endif

