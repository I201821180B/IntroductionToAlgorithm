#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "node.h"


template<typename T>
class rbTree
{
public:
	using RED = node<T>::RED;
	using BLACK = node<T>::BLACK;
	using NIL = node<T>::NIL;
	using pNode = node<T>*;
	explicit rbTree();
	~rbTree();
	void rbInsert(pNode _z);
	void rbDelete(pNode _z);
private:
	pNode root_;
	pNode nil_;
	void leftRotate(pNode _x);
	void rightRotate(pNode _y);
	void rbInsertFixup(pNode _z);
	void rbTransplant(pNode _u, pNode _v);
	void rbDeleteFixup(pNode _x);
};

#endif