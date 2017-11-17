#include "RandomizedSelect.h"

int randomizedSelect(vector<int>& v, int p, int r, int i)
{
	if (p == r)
	{
		return v[p];
	}
	int q = randomizedPartition(v, p, r);
	int k = q - p + 1;
	if (i == k)
	{
		return v[q];
	}
	else if (i < k)
	{
		randomizedSelect(v, p, q - 1, i);
	}
	else if (i > k)
	{
		randomizedSelect(v, q + 1, r, i - k);
	}
}
