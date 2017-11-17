#ifndef _NODE_H_
#define _NODE_H_

#include "basic.h"

#include <iostream>
#include <string>
#include <type_traits>

using COLOR = bool;
const COLOR RED = false;
const COLOR BLACK = true;

template<typename T>
class node
{
public:
	using pNode = node<T>*;
	
	node();
	node(COLOR _color, T _key);
	explicit node(COLOR _color);
	explicit node(T _key);
	//~node();

	COLOR color() { return color_; }
	void setColor(COLOR _color);
	T key() { return key_; }
	void setKey(T _key);

	pNode left() { return left_; }
	pNode right() { return right_; }
	pNode parent() { return parent_; }
	void setLeft(pNode _newleft);
	void setRight(pNode _newright);
	void setParent(pNode _newparent);
private:
	COLOR color_;
	T key_;
	pNode left_;
	pNode right_;
	pNode parent_;
	DISABLE_COPY_AND_ASSIGN(node);
};


#endif


