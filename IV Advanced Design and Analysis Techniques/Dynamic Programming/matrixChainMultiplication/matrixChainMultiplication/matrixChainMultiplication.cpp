#include "matrixChainMultiplication.h"

matrix<int> matrixMultiply(const matrix<int32_t>& a, const matrix<int32_t>& b)
{
    assert(a.col_ == b.row_);
    matrix<int32_t> c(a.row_, b.col_);
    for (size_t i = 0; i < a.row_; ++i)
    {
        for (size_t j = 0; j < b.col_; ++j)
        {
            for (size_t k = 0; k < a.col_; ++k)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

void matrixChainOrder(const vector<int32_t>& p, vector<vector<int32_t>>& m, vector<vector<int32_t>>& s)
{
    // 初始化辅助表
    size_t n = p.size() - 1;
    m.resize(n, vector<int32_t>(n, 0));
    s.resize(n - 1, vector<int32_t>(n, 0));

    // 选取子链的长度
    for (int32_t chainLength = 2; chainLength <= n; ++chainLength)
    {
        // i和j分别是子链的起点和终点，长度为chainLength
        for (int32_t i = 0; i < n - chainLength + 1; ++i)
        {
            int32_t j = i + chainLength - 1;
            m[i][j] = numeric_limits<int32_t>::max();
            // 分割ij链
            for (int32_t k = i; k < j; ++k)
            {
                // 计算最优值
                int32_t q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j])
                {
                    // 更新最优值
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}



void printOptimalParens(const vector<vector<int32_t>>& s, size_t _i, size_t _j)
{
    if (_i == _j)
    {
        cout << "A" << _i;
    }
    else
    {
        cout << "(";
        printOptimalParens(s, _i, s[_i][_j]);
        printOptimalParens(s, s[_i][_j]+1, _j);
        cout << ")";
    }
}
