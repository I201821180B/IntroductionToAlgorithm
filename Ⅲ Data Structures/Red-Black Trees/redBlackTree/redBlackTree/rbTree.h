#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "node.h"

template<typename T>
class rbTree
{
public:
	rbTree();
	~rbTree();
private:
	node<T>* root;
};

#endif