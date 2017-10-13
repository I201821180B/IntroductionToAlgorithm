#include "CountingSort.h"

void countSort(const vector<int>& A, vector<int>& B, const int k)
{
	vector<int> C(k + 1, 0);
	for (const int& val : A)
	{
		C[val]++;
	}
	for (int i = 1; i <= k; ++i)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (int j = A.size() - 1; j >= 0; --j)
	{
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}
}
