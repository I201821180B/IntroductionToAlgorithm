#ifndef _NODE_H_
#define _NODE_H_

#include <string>

using std::string;

template<typename T>
class node
{
public:
	static enum iro { RED, BLACK, NIL };
	node(iro _color, T _key);
	//~node();
	iro& color() { return color_; }
	T& key() { return key_; }
	node<T>* left() { return left_; }
	node<T>* right() { return right_; }
	node<T>* parent() { return parent_; }
private:
	iro color_;
	T key_;
	node<T>* left_;
	node<T>* right_;
	node<T>* parent_;
};

#endif


