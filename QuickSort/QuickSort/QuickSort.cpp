#include "QuickSort.h"

void swap(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}

void quickSort(vector<int>& A, int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int partition(vector<int>& A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j)
	{
		if (A[j] <= x)
		{
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}
