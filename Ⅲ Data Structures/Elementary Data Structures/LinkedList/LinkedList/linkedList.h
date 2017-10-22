#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "node.h"

#include <initializer_list>
#include <string>
#include <cstdint>
#include <cassert>

using std::initializer_list;
using std::string;

template<typename T>
class linkedList
{
public:
	linkedList();
	linkedList(initializer_list<T> il);
	~linkedList();
	/*void insertToTail(node<T>* x);
	void insertToTail(T x);*/
	void insertAfter(node<T>* x, node<T>* n);
	void insertNode(node<T>* x, const uint32_t idx = size_ - 1 );
	void insert(T x, const uint32_t idx = size_ - 1);
	node<T>* searchNode(node<T>* k);
	node<T>* search(T k);
	void removeNode(node<T>* x);
	void removeFrom(const uint32_t idx);
	void remove(T x);
	void print();
	void print(const uint32_t idx);
	node<T>* operator[](const uint32_t idx);
	//node<T>* locate(const uint32_t idx);
	uint32_t size();
private:
	//node* head;
	void del(node<T>* x);
	node<T>* nil;
	uint32_t size_;
};

#endif