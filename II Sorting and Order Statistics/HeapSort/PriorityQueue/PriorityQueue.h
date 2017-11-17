#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_

#include "Heap.h"
#include <limits>
class priorityQueue : public heap
{
public:
	priorityQueue(const vector<int>& v);
	void insert(int key);
	int maximum();
	int extractMax();
	void increaseKey(int i, int key);
};

#endif
