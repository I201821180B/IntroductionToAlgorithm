#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "LinkedList.h"

#include <initializer_list>
#include <cstdint>

using std::initializer_list;
using std::int32_t;

template<typename T>
class queue
{
public:
	queue();
	queue(initializer_list<T> il);
	~queue();
private:
	linkedList l;
	int32_t size;
};

#endif