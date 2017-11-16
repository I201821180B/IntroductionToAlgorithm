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
	binaryTree(std::initializer_list<T> _il);/*复制列表初始化构造函数不能标记为explicit*/
	explicit binaryTree(std::vector<T>& _v);
	~binaryTree();
	pNode root() { return root_; }

	void preOrderTreeWalk(pNode _x);
	void inOrderTreeWalk(pNode _x);
	void postOrderTreeWalk(pNode _x);
	void print();

	pNode treeSearch(pNode _x, T _key);	
	pNode iterativeTreeSearch(pNode _x, T _key);
	pNode search(T _key);

	pNode treeMinimum(pNode _x);
	pNode min();
	pNode treeMaximum(pNode _x);
	pNode max();

	pNode successor(pNode _x);
	pNode preSuccessor(pNode _x);

	void insert(pNode _z);
	void remove(pNode _z);
private:
	pNode root_;
	void transplant(pNode _u, pNode _v);
	void treeFree(pNode _x);
	DISABLE_COPY_AND_ASSIGN(binaryTree);
};

#endif




