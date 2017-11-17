#ifndef _NODE_H_
#define _NODE_H_

template<typename T>
struct node
{
	node() = default;
	node(const T& t);
	~node() = default;
	T data;
	node<T>* prev;
	node<T>* next;
};


#endif