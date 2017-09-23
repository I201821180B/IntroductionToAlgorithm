#include "PriorityQueue.h"

priorityQueue::priorityQueue(const vector<int>& v)
	: heap(v)
{

}

void priorityQueue::insert(int x)
{
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

void priorityQueue::increaseKey(int x, int k)
{

}
