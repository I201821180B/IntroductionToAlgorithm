#include "linkedList.h"

#include <iostream>

using std::cout;
using std::endl;

template<typename T>
linkedList<T>::linkedList()
{
	//head = new node();
	nil = new node<T>();
	nil->next = nil;
	nil->prev = nil;
}

template<typename T>
linkedList<T>::linkedList(initializer_list<T> il)
	: linkedList()
{
	for (auto& item : il)
	{
		node<T>* newnode = new node<T>(item);
		insert(newnode);
	}
}

template<typename T>
linkedList<T>::~linkedList()
{
	node<T>* cursor = nil->next;
	node<T>* nxt = cursor->next;
	while (cursor != nil)
	{
		del(cursor);
		cursor = nxt;
		nxt = cursor->next;
	}
}

template<typename T>
void linkedList<T>::insert(node<T> * x)
{
	x->next = nil->next;
	nil->next = x;
	x->prev = nil;
	x->next->prev = x;
}

template<typename T>
node<T>* linkedList<T>::search(node<T> * k)
{
	node<T>* cursor = nil->next;
	while (cursor != nil && cursor->data != k->data)
	{
		cursor = cursor->next;
	}
	return cursor;
}

template<typename T>
void linkedList<T>::del(node<T> * k)
{
	node<T>* x = search(k);
	x->prev->next = x->next;
	x->next->prev = x->prev;
	x->~node();
}

template<typename T>
void linkedList<T>::print()
{
	node<T>* cursor = nil->next;
	while (cursor != nil)
	{
		cout << cursor->data << " ";
		cursor = cursor->next;
	}
	cout << endl;
}

/**
* wrong wording
* template<> class linkedList<int>
*/
template class linkedList<int>;
template class linkedList<string>;
