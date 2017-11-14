#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "node.h"
#include <initializer_list>

template<typename T>
class binaryTree
{
public:
	//using pNode = node<T>::pNode;
	using pNode = node<T>*;
	binaryTree();
	explicit binaryTree(std::initializer_list<T> il);
	~binaryTree();
private:
	pNode root_;
	void inorderTreeWalk(pNode _x);
	pNode treeSearch(pNode _x, T _key);
	pNode iterativeTreeSearch(pNode _x, T _key);
	pNode treeMinimum(pNode _x);
	pNode treeMaximum(pNode _x);
	pNode treeSuccessor(pNode _x);
	void treeInsert(pNode _z);
	void transplant(pNode _u, pNode _v);
	void treeDelete(pNode _z);
	void treeFree(pNode _x);
};

#endif