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
	node(iro _color, T _key);
	node(iro _color);
	//~node();
	iro color() { return color_; }
	void setColor(iro _color);
	T& key() { return key_; }
	void setKey(T _key);
	shared_ptr<node<T>> left() { return left_; }
	shared_ptr<node<T>> right() { return right_; }
	shared_ptr<node<T>> parent() { return parent_; }
	void setLeft(const shared_ptr<node<T>>& _newleft);
	void setRight(const shared_ptr<node<T>>& _newright);
	void setParent(const shared_ptr<node<T>>& _newparent);
private:
	iro color_;
	T key_;
	shared_ptr<node<T>> left_;
	shared_ptr<node<T>> right_;
	shared_ptr<node<T>> parent_;
};

#endif


