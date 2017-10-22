#ifndef _STACK_H_
#define _STACK_H_

#include "linkedList.h"

#include <cstdint>
#include <initializer_list>

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
	bool push(T x);
	T pop();
	uint32_t size();
private:
	linkedList<T> s;
	//uint32_t top;
	//uint32_t size;
};

#endif

