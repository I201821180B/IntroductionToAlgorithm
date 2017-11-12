#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <memory>

using std::shared_ptr;
using std::string;

template<typename T>
class node
{
public:
	static enum iro { RED, BLACK, NIL };
	explicit node(iro _color, T _key);
	explicit node(iro _color);
	//~node();
	iro color() { return color_; }
	void setColor(iro _color);
	T& key() { return key_; }
	void setKey(T _key);
	node<T>* left() { return left_; }
	node<T>* right() { return right_; }
	node<T>* parent() { return parent_; }
	void setLeft(node<T>* _newleft);
	void setRight(node<T>* _newright);
	void setParent(node<T>* _newparent);
private:
	iro color_;
	T key_;
	node<T>* left_;
	node<T>* right_;
	node<T>* parent_;
};

#endif


