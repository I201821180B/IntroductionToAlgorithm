#include "matrixChainMultiplication.h"

matrix<int> matrixMultiply(const matrix<int32_t>& _a, const matrix<int32_t>& _b)
{
	assert(_a.col_ == _b.row_);
	matrix<int32_t> c(_a.row_, _b.col_);
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

void matrixChainOrder(const vector<int32_t>& _p, vector<vector<int32_t>>& _m, vector<vector<int32_t>>& _s)
{
	// 初始化辅助表
	size_t n = _p.size() - 1;
	_m.resize(n, vector<int32_t>(n, 0));
	_s.resize(n - 1, vector<int32_t>(n, 0));

	// 选取子链的长度
	for (int32_t chainLength = 2; chainLength <= n; ++chainLength)
	{
		// i和j分别是子链的起点和终点，长度为chainLength
		for (int32_t i = 0; i < n - chainLength + 1; ++i)
		{
			int32_t j = i + chainLength - 1;
			_m[i][j] = numeric_limits<int32_t>::max();
			// 分割ij链
			for (int32_t k = i; k < j; ++k)
			{
				// 计算最优值
				int32_t q = _m[i][k] + _m[k + 1][j] + _p[i] * _p[k + 1] * _p[j + 1];
				if (q < _m[i][j])
				{
					// 更新最优值
					_m[i][j] = q;
					_s[i][j] = k;
				}
			}
		}
	}
}



void printOptimalParens(const vector<vector<int32_t>>& _s, size_t _i, size_t _j)
{
	if (_i == _j)
	{
		cout << "A" << _i;
	}
	else
	{
		cout << "(";
		printOptimalParens(_s, _i, _s[_i][_j]);
		printOptimalParens(_s, _s[_i][_j]+1, _j);
		cout << ")";
	}
}
