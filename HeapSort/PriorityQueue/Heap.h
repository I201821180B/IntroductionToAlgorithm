#ifndef _HEAP_H_
#define _HEAP_H_

#include <vector>
#include <iostream>

#define _PARENT(x) ((x)>>1)
#define _LEFT(x)   ((x)<<1)
#define _RIGHT(x)  (((x)<<1)+1)

#define PARENT(x) (_PARENT(x+1)-1)
#define LEFT(x)   (_LEFT(x+1)-1)
#define RIGHT(x)  (_RIGHT(x+1)-1)

using namespace std;

class heap
{
public:
	heap(const vector<int>& v);
	void heapSort();
	void print();
protected:
	void MaxHeapify(const int i);
	void BuildMaxHeap();
	void swap(const int i, const int j);
	vector<int> A;
	size_t heapSize;
};


#endif

