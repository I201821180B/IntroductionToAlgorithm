#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_

#include "Heap.h"

class priorityQueue : public heap
{
public:
	priorityQueue(const vector<int>& v);
	void insert(int x);
	int maximum();
	int extractMax();
	void increaseKey(int x, int k);
};

#endif
