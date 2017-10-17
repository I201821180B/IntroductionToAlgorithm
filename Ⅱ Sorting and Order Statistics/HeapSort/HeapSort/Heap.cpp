#include "Heap.h"

heap::heap(const vector<int>& v)
{
	A.assign(v.begin(), v.end());
	heapSize = A.size();
	BuildMaxHeap();
}

void heap::swap(const int i, const int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void heap::BuildMaxHeap()
{
	for (int i = A.size() / 2; i >= 0; --i)
	{
		MaxHeapify(i);
	}
}

void heap::MaxHeapify(const int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = 0;
	if (l < heapSize && A[l] > A[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r < heapSize && A[r] > A[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(i, largest);
		MaxHeapify(largest);
	}
}



void heap::heapSort()
{
	//BuildMaxHeap();
	
	for (int i = A.size() - 1; i >= 0; --i)
	{
		swap(i, 0);
		--heapSize;
		MaxHeapify(0);
	}
	heapSize = A.size();
}

void heap::print()
{
	for (const int var : A)
	{
		cout << var << " ";
	}
	cout << endl;
}
