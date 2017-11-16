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
	rbTree(std::initializer_list<T> _il);
	explicit rbTree(std::vector<T>& _v);
	~rbTree();
	/*typename node<T>::COLOR RED() { return node<T>::RED; }
	typename node<T>::COLOR BLACK() { return node<T>::BLACK; }
	typename node<T>::COLOR NIL() { return node<T>::NIL; }*/
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
	pNode nil_;
	void leftRotate(pNode _x);
	void rightRotate(pNode _y);
	void rbInsertFixup(pNode _z);
	void rbTransplant(pNode _u, pNode _v);
	void rbDeleteFixup(pNode _x);
	void rbFree(pNode _x);
	DISABLE_COPY_AND_ASSIGN(rbTree);
};

#endif
/*未解决边界条件问题*/

