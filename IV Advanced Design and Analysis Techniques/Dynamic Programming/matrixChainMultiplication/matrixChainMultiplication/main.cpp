#include <iostream>
#include <vector>

#include "matrix.h"
#include "matrixChainMultiplication.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> v1{ 1,2,3,1,2,3 };
	vector<int> v2{ 1,1,2,2,3,3 };
	matrix<int> m1(v1, 2, 3);
	matrix<int> m2(v2, 3, 2);
	m1.print();
	m2.print();

	// 这里调用移动构造函数
	matrix<int> c = matrixMultiply(m1, m2);
	c.print();
}