#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "node.h"

#include <memory>

using std::shared_ptr;
using std::make_shared;

template<typename T>
class rbTree
{
public:
	explicit rbTree();
	~rbTree();
	void rbInsert(node<T>* z);
private:
	node<T>* root_;
	node<T>* nil_;
	void leftRotate(node<T>* x);
	void rightRotate(node<T>* y);
	void rbInsertFixup(node<T>* z);
};

#endif