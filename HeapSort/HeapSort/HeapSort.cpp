#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <functional>

#include "benchmark.h"

#include "Heap.h"

using namespace std;

int main()
{
	vector<int> v = { 9,8,7,6,5,4,3,2,1,0 };
	heap h1(v);
	h1.heapSort();
	h1.print();

	std::default_random_engine generator(time(NULL));
	std::uniform_int_distribution<int> dis(0, 1000000);
	auto dice = std::bind(dis, generator);

	v.resize(0);
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(dice());
		cout << v.back() << " ";
	}

	cout << endl;
	heap h2(v);
	CPUTimer clk;
	clk.Start();
	h2.heapSort();
	clk.Stop();
	h2.print();
	cout << "HeapSort time : " << clk.microsecond() << " us." << endl;
}