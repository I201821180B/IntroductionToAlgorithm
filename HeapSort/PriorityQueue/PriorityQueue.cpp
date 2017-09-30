#include "PriorityQueue.h"

priorityQueue::priorityQueue(const vector<int>& v)
	: heap(v)
{
	
}

void priorityQueue::insert(int key)
{
	A.push_back(numeric_limits<int>::min());
	increaseKey(A.size() - 1, key);
}

int priorityQueue::maximum()
{
	return A[0];
}

int priorityQueue::extractMax()
{
	if (A.size() < 1) 
	{
		cerr << "heap underflow";
	}
	int max = A[0];
	A[0] = A[heapSize - 1];
	--heapSize;
	MaxHeapify(0);
	return max;
}

void priorityQueue::increaseKey(int i, int key)
{
	if (key < A[i])
	{
		cerr << "new key is smaller than current key";
	}
	A[i] = key;
	while (i > 1 && A[PARENT(i)] < A[i])
	{
		swap(i, PARENT(i));
		i = PARENT(i);
	}
}
