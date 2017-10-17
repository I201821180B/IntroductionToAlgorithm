#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "node.h"

#include <initializer_list>
#include <string>

using std::initializer_list;
using std::string;

template<typename T>
class linkedList
{
public:
	linkedList();
	linkedList(initializer_list<T> il);
	~linkedList();
	void insert(node<T>* x);
	node<T>* search(node<T>* k);
	void del(node<T>* x);
	void print();
private:
	//node* head;
	node<T>* nil;
};

/** 
 * wrong wording 
 * template<> class linkedList<int>
 */
template class linkedList<int>;
template class linkedList<string>;

#endif