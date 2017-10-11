#include <iostream>
#include <vector>

#include "BucketSort.h"
#include "common.h"

using namespace std;

int main()
{
	const int64_t size = 100000;
	const int64_t max = 1000000;
	vector<int> v;
	getRandomVector(v, size, 0, max);

	//printVector(v);

	CPUTimer clk;
	clk.Start();
	bucketSort(v, max);
	clk.Stop();
	//printVector(v);

	cout << "BucketSort time: " << clk.microsecond() << " us." << endl;
}