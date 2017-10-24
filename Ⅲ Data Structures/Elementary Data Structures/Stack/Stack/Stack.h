#ifndef _STACK_H_
#define _STACK_H_

#include "linkedList.h"

#include <string>
#include <cstdint>
#include <initializer_list>

using std::string;
using std::uint32_t;
using std::initializer_list;

template<typename T>
class stack
{
public:
	stack();
	stack(initializer_list<T> il);
	//~stack();
	bool isEmpty();
	void push(T x);
	T pop();
	uint32_t size();
	void print();
private:
	linkedList<T> s;
	//uint32_t top;
	//uint32_t size;
};

#endif

