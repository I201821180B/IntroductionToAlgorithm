#include <iostream>
#include <algorithm>

#include "RandomQuickSort.h"
#include "common.h"

using namespace std;

int main()
{
	vector<int> v;
	getRandomVector(v, 100000, 0, 1000000);

	//printVector(v);
	CPUTimer clk;
	clk.Start();
	randomizedQuickSort(v, 0, v.size() - 1);
	clk.Stop();
	//printVector(v);
	cout << "QuickSort time: " << clk.microsecond() << " us." << endl;

	vector<int> vec;
	getRandomVector(vec, 100000, 0, 1000000);
	CPUTimer c;
	c.Start();
	sort(vec.begin(), vec.end());
	c.Stop();
	//printVector(vec);
	cout << "sort time: " << c.microsecond() << " us." << endl;
}