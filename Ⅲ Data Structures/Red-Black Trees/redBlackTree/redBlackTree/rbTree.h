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
	rbTree();
	~rbTree();
	void rbInsert(shared_ptr<node<T>>& z);
private:
	shared_ptr<node<T>> root_;
	shared_ptr<node<T>> NIL;
	void leftRotate(shared_ptr<node<T>>& x);
	void rightRotate(shared_ptr<node<T>>& y);
	void rbInsertFixup(shared_ptr<node<T>>& z);
};

#endif