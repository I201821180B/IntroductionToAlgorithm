#include "BucketSort.h"

#include <list>
#include <iostream>
#include <cstdint>

void bucketSort(vector<int>& v, const int max)
{
	const int64_t n = v.size();
	vector<list<int> > temp(n);
	
	for (int i = 0; i < n; ++i)
	{
		const int64_t index = v[i] * n / max;
		temp[index].push_back(v[i]);
	}
	
	for (int j = 0; j < n; ++j)
	{
		temp[j].sort();
	}
	v.clear();
	for (int k = 0; k < n; ++k)
	{
		for (auto iter = temp[k].begin(); iter != temp[k].end(); ++iter)
		{
			v.push_back(*iter);
		}
	}
}