#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "node.h"

#include <vector>
#include <initializer_list>

using std::vector;
using std::initializer_list;

template<typename T>
class linkedList
{
public:
	//linkedList(const vector<T>& v);
	linkedList(initializer_list<T> il);
	bool push(T x);
	bool insert(T x);
	bool search(T k);
private:
	node* head;
	node* nil;
};

#endif


