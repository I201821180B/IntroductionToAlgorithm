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
	size_ = 0;
}

template<typename T>
linkedList<T>::linkedList(initializer_list<T> il)
	: linkedList()
{
	for (auto& item : il)
	{
		//node<T>* newnode = new node<T>(item);
		insert(item);
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

//template<typename T>
//void linkedList<T>::insertToTail(node<T> * x)
//{
//	/*x->next = nil->next;
//	nil->next = x;
//	x->prev = nil;
//	x->next->prev = x;
//	size_++;*/
//	insertAfter(x, nil); // £¿£¿£¿
//}
//
//template<typename T>
//void linkedList<T>::insertToTail(T x)
//{
//	node<T>* newnode = new node<T>(x);
//	insertToTail(newnode); // £¿£¿£¿
//}

template<typename T>
void linkedList<T>::insertAfter(node<T>* x, node<T>* n)
{
	x->next = n->next;
	n->next = x;
	x->prev = n;
	x->next->prev = x;
	size_++;
}

template<typename T>
void linkedList<T>::insertNode(node<T>* x, const uint32_t idx)
{
	//cout << "linkedList<T>::insertNode(node<T>* x, const uint32_t idx)" << endl;
	node<T>* res = locate(idx);
	insertAfter(x, res); // £¿£¿£¿
}

template<typename T>
void linkedList<T>::insertNode(node<T>* x)
{
	//cout << "linkedList<T>::insertNode(node<T>* x)" << endl;
	insertAfter(x, nil);
}

template<typename T>
void linkedList<T>::insert(T x, const uint32_t idx)
{
	//idx = axis(idx);
	//cout << "linkedList<T>::insert(T x, const uint32_t idx)" << endl;
	node<T>* newnode = new node<T>(x);
	insertNode(newnode, idx); // £¿£¿£¿
}

template<typename T>
void linkedList<T>::insert(T x)
{
	//cout << "linkedList<T>::insert(T x)" << endl;
	node<T>* newnode = new node<T>(x);
	insertNode(newnode);
}

template<typename T>
node<T>* linkedList<T>::searchNode(node<T> * k)
{
	/*node<T>* cursor = nil->next;
	while (cursor != nil && cursor->data != k->data)
	{
		cursor = cursor->next;
	}
	return cursor;*/
	return search(k->data);
}

template<typename T>
node<T>* linkedList<T>::search(T k)
{
	node<T>* cursor = nil->next;
	while (cursor != nil && cursor->data != k)
	{
		cursor = cursor->next;
	}
	return cursor;
}

template<typename T>
void linkedList<T>::removeNode(node<T> * k)
{
	remove(k->data); // £¿£¿£¿
}

template<typename T>
void linkedList<T>::remove(T x)
{
	//node<T>* newnode = new node<T>(x);
	node<T>* res = search(x);
	del(res);
}

template<typename T>
void linkedList<T>::removeFrom(const uint32_t idx)
{
	node<T>* res = locate(idx);
	removeNode(res);
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

//template<typename T>
//void linkedList<T>::print(const uint32_t idx)
//{
//	node<T>* res = locate(idx);
//	cout << res->data << endl;
//}

template<typename T>
T linkedList<T>::operator[](const uint32_t idx)
{
	return locate(idx)->data;
}

//template<typename T>
//uint32_t linkedList<T>::axis(int idx)
//{
//	if (idx < 0)
//	{
//		return (-idx) - 1;
//	}
//	return idx;
//}

//template<typename T>
//node<T>* linkedList<T>::locate(const uint32_t idx)
//{
//	
//}

template<typename T>
node<T>* linkedList<T>::locate(const uint32_t idx)
{
	//uint32_t idx = axis(i);
	assert(idx < size_);
	if (idx == size_ - 1)
	{
		return nil->prev;
	}
	node<T>* cursor = nil->next;
	uint32_t iter = 0;
	while (iter != idx)
	{
		cursor = cursor->next;
		++iter;
	}
	return cursor;
}

template<typename T>
uint32_t linkedList<T>::size()
{
	return size_;
}

template<typename T>
void linkedList<T>::del(node<T>* x)
{
	if (!size_) 
		return;
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
	size_--;
}

/**
* wrong wording
* template<> class linkedList<int>
*/
template class linkedList<int>;
template class linkedList<string>;

