#include <iostream>
#include <vector>
#include <cstdint>

#include "common.h"

#include "RandomizedSelect.h"

using namespace std;

int main()
{
	const int32_t size = 10;
	const int32_t min = 0;
	const int32_t max = 100;
	vector<int32_t> v;
	getRandomVector(v, size, min, max);
	printVector(v);

	int res = randomizedSelect(v, 0, v.size()-1, 6);
	cout << "res = " << res << endl;
	quickSort(v, 0, v.size()-1);
	printVector(v);
}