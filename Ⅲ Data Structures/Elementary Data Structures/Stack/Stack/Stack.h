#ifndef _STACK_H_
#define _STACK_H_

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
	~stack();
	bool stackEmpty();
	bool push();
	T pop();
private:
	T* s;
	uint32_t top;
	uint32_t size;
};

#endif

