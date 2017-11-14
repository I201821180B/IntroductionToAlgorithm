#ifndef _NODE_H_
#define _NODE_H_

#include <string>
//#include <memory>

//using std::shared_ptr;
using std::string;

template<typename T>
class node
{
public:
	using pNode = node<T>*;
	static enum iro { RED, BLACK, NIL };
	node(iro _color, T _key);
	explicit node(iro _color);
	//~node();
	iro color() { return color_; }
	void setColor(iro _color);
	T key() { return key_; }
	void setKey(T _key);
	pNode left() { return left_; }
	pNode right() { return right_; }
	pNode parent() { return parent_; }
	void setLeft(pNode _newleft);
	void setRight(pNode _newright);
	void setParent(pNode _newparent);
private:
	iro color_;
	T key_;
	pNode left_;
	pNode right_;
	pNode parent_;
};

#endif


