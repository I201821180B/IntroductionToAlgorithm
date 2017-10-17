#include <iostream>
#include <vector>

#include "common.h"
#include "QuickSort.h"

using namespace std;

int main()
{
	vector<int> v;
	getRandomVector(v, 100000, 0, 1000000);

	//printVector(v);

	CPUTimer clk;
	clk.Start();
	quickSort(v, 0, v.size() - 1);
	clk.Stop();
	//printVector(v);
	cout << "QuickSort time: " << clk.microsecond() << " us." << endl;
}
