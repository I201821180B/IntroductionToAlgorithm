#include <iostream>
#include <vector>
#include <cstdint>


#include "matrix.h"
#include "matrixChainMultiplication.h"

using std::cout;
using std::endl;
using std::vector;

template<typename T>
void print(vector<vector<T>>& _v)
{
	cout << endl;
	for (const vector<T>& item : _v)
	{
		for (const T& elem : item)
		{
			cout << elem << "\t\t";
		}
		cout << endl;
	}
}

int main()
{
	vector<int32_t> v1{ 1,2,3,1,2,3 };
	vector<int32_t> v2{ 1,1,2,2,3,3 };
	matrix<int32_t> m1(v1, 2, 3);
	matrix<int32_t> m2(v2, 3, 2);
	m1.print();
	m2.print();

	// 这里调用移动构造函数
	matrix<int32_t> c = matrixMultiply(m1, m2);
	c.print();

	vector<int32_t> p{ 30, 35, 15, 5, 10, 20, 25 };
	vector<vector<int32_t>> m;
	vector<vector<int32_t>> s;
	matrixChainOrder(p, m, s);
	
	print(m);
	print(s);
	printOptimalParens(s, 0, p.size() - 2);
}