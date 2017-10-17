#include <iostream>
#include <vector>

#include "CountingSort.h"
#include "common.h"

using namespace std;

int main()
{
	const int size = 100000;
	const int max = 1000000;

	vector<int> v;
	getRandomVector(v, size, 0, max);
	vector<int> vec(v.size(), 0);

	//printVector(v);
	CPUTimer clk;
	clk.Start();
	countSort(v, vec, max);
	clk.Stop();
	cout << "CountingSort time: " << clk.microsecond() << " us." << endl;
	//printVector(vec);
	//getchar();
}