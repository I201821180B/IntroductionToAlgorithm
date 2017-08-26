#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <ctime>
#include <limits>

#include "benchmark.h"
//#include "../../common/benchmark.h"
//#include "../../common/benchmark.cpp"

#define SIZE 1000

using namespace std;

void print(const vector<int>& arr)
{
	for (const int& val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
}

void merge(vector<int>& a, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	/*int* L = new int[n1+1];
	int* R = new int[n2+1];*/
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	L[n1] = numeric_limits<int>::max();
	R[n2] = numeric_limits<int>::max();
	for (int i = 0; i < n1; ++i)
	{
		L[i] = a[p + i];
	}
	for (int j = 0; j < n2; ++j)
	{
		R[j] = a[q + j + 1];
	}
	int i = 0;
	int j = 0;
	for (int k = p; k < r + 1; ++k)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i += 1;
		}
		else
		{
			a[k] = R[j];
			j += 1;
		}
	}
}

void MergeSort(vector<int>& a, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(a, p, q);
		MergeSort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

int main()
{
	std::default_random_engine generator(time(NULL));
	std::uniform_int_distribution<int> dis(0, 1000);
	auto dice = std::bind(dis, generator);

	vector<int> arr;
	for (int i = 0; i < SIZE; ++i)
	{
		arr.push_back(dice());
	}
	print(arr);
	cout << endl;

	CPUTimer clk;
	clk.Start();
	MergeSort(arr, 0, arr.size() - 1);
	clk.Stop();
	print(arr);
	cout << "MergeSort : " << clk.microsecond() << " us." << endl;
}