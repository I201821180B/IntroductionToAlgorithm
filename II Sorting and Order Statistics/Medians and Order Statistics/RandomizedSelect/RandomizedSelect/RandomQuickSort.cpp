#include "RandomQuickSort.h"

//std::default_random_engine generator(time(NULL));
//std::uniform_int_distribution<int> dis(0, 100);

#define random(n, m) \
	srand((unsigned)time(0)); \
	int i = (rand() % (m - n + 1) + n); 


void randomizedQuickSort(vector<int>& v, int p, int r)
{
	if (p < r)
	{
		int q = randomizedPartition(v, p, r);
		randomizedQuickSort(v, p, q - 1);
		randomizedQuickSort(v, q + 1, r);
	}
}

int randomizedPartition(vector<int>& v, int p, int r)
{
	random(p, r);
	//cout << "i = " << i << endl;
	swap(v[i], v[r]);
	return partition(v, p, r);
}
