#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "node.h"

template<typename T>
class binaryTree
{
public:
	typedef node<T>* pNode;
	binaryTree();
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
};

#endif