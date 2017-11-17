#ifndef _RANDOMQUICKSORT_H_
#define _RANDOMQUICKSORT_H_

#include <iostream>
#include <vector>
//#include <random>
#include <ctime>
#include <cstdlib>

#include "QuickSort.h"

using namespace std;

void randomizedQuickSort(vector<int>& v, int p, int r);
int randomizedPartition(vector<int>& v, int p, int r);

#endif

