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

	T search(T _key);
	
	T min();	
	T max();

	T successor(T _key);
	T preSuccessor(T _key);

	void insert(T _key);
	void remove(T _key);
private:
	pNode root_;

	pNode treeSearch(pNode _x, T _key);
	pNode iterativeTreeSearch(pNode _x, T _key);
	pNode treeMinimum(pNode _x);
	pNode treeMaximum(pNode _x);
	pNode treeSuccessor(pNode _x);
	pNode treePreSuccessor(pNode _x);
	void treeInsert(pNode _z);
	void treeDelete(pNode _z);

	void transplant(pNode _u, pNode _v);
	void treeFree(pNode _x);
	DISABLE_COPY_AND_ASSIGN(binaryTree);
};

#endif




