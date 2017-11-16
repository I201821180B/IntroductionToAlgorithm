#ifndef _NODE_H_
#define _NODE_H_

#include "basic.h"

#include <string>
#include <iostream>
//#include <memory>

//using std::shared_ptr;

template<typename T>
class node
{
public:
	using pNode = node<T>*;
	//static enum iro { RED, BLACK, NIL };
	explicit node(T _key);
	//node(const node<T>& _node);
	//explicit node(iro _color);
	//~node();
	//iro color() { return color_; }
	//void setColor(iro _color);
	T key() { return key_; }
	void setKey(T _key);
	pNode left() { return left_; }
	pNode right() { return right_; }
	pNode parent() { return parent_; }
	void setLeft(pNode _newleft);
	void setRight(pNode _newright);
	void setParent(pNode _newparent);
private:
	//iro color_;
	T key_;
	pNode left_;
	pNode right_;
	pNode parent_;
	DISABLE_COPY_AND_ASSIGN(node);
};

#endif


