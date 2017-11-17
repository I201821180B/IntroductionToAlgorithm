#ifndef _NODE_H_
#define _NODE_H_

#include "basic.h"

#include <string>
#include <iostream>
#include <type_traits>
#include <memory>

template<typename T>
class node
{
public:
	using pNode = node<T>*;
	explicit node(T _key);
	//~node();

	T key() { return key_; }
	void setKey(T _key);

	pNode left() { return left_; }
	pNode right() { return right_; }
	pNode parent() { return parent_; }
	void setLeft(pNode _newleft);
	void setRight(pNode _newright);
	void setParent(pNode _newparent);
private:
	T key_;
	pNode left_;
	pNode right_;
	pNode parent_;
	
	DISABLE_COPY_AND_ASSIGN(node);
};

#endif


