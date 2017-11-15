#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "basic.h"
#include "node.h"

#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

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
	void inorderTreeWalk(pNode _x);
	void print();
	pNode treeSearch(pNode _x, T _key);	
	pNode iterativeTreeSearch(pNode _x, T _key);
	pNode search(T _key);
	pNode treeMinimum(pNode _x);
	pNode min();
	pNode treeMaximum(pNode _x);
	pNode max();
	pNode treeSuccessor(pNode _x);
	void treeInsert(pNode _z);
	void treeDelete(pNode _z);
private:
	pNode root_;
	void transplant(pNode _u, pNode _v);
	void treeFree(pNode _x);
};

#endif




