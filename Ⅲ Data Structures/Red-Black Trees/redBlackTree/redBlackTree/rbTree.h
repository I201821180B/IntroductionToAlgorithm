#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "node.h"


template<typename T>
class rbTree
{
public:
	typedef node<T>::RED RED;
	typedef node<T>::BLACK BLACK;
	typedef node<T>::NIL NIL;
	typedef node<T>* pNode;
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