#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <vector>

using namespace std;

void swap(int& i, int& j);
void quickSort(vector<int>& A, int p, int r);
int partition(vector<int>& A, int p, int r);

#endif
