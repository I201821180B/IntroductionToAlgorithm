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
	void rbInsert(pNode z);
	void rbDelete(pNode z);
private:
	pNode root_;
	pNode nil_;
	void leftRotate(pNode x);
	void rightRotate(pNode y);
	void rbInsertFixup(pNode z);
	void rbTransplant(pNode u, pNode v);
	void rbDeleteFixup(pNode x);
};

#endif