#ifndef _NODE_H_
#define _NODE_H_

template<typename T>
struct node
{
	node() = default;
	node(T t) : data(t) {}
	T data;
	node* prev;
	node* next;
};

#endif