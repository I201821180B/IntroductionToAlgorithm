#ifndef _STACK_H_
#define _STACK_H_

#include <cstdint>

using namespace std;

template<typename T>
class stack
{
public:
	stack();
	stack(uint32_t size);
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

