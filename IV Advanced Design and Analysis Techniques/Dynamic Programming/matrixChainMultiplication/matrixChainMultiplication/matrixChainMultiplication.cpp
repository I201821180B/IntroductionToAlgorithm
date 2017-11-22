#include "matrixChainMultiplication.h"

matrix<int> matrixMultiply(const matrix<int>& _a, const matrix<int>& _b)
{
	assert(_a.col_ == _b.row_);
	matrix<int> c(_a.row_, _b.col_);
	for (size_t i = 0; i < _a.row_; ++i)
	{
		for (size_t j = 0; j < _b.col_; ++j)
		{
			for (size_t k = 0; k < _a.col_; ++k)
			{
				c[i][j] = c[i][j] + _a[i][k] * _b[k][j];
			}
		}
	}
	return c;
}

void matrixChainOrder(const vector<int>& _p, vector<vector<int>>& _m, vector<vector<int>>& _s)
{
}

void printOptimalParens(const vector<vector<int>>& _s, size_t _i, size_t _j)
{
}
