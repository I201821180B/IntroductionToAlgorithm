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
	explicit binaryTree(std::initializer_list<T> il);
	explicit binaryTree(std::vector<T>& v);
	~binaryTree();
	pNode root() { return root_; }
	void inorderTreeWalk(pNode _x);
	pNode treeSearch(pNode _x, T _key);
	pNode iterativeTreeSearch(pNode _x, T _key);
	pNode treeMinimum(pNode _x);
	pNode treeMaximum(pNode _x);
	pNode treeSuccessor(pNode _x);
	void treeInsert(pNode _z);
	void treeDelete(pNode _z);
private:
	pNode root_;
	void transplant(pNode _u, pNode _v);
	void treeFree(pNode _x);
};

#endif




