#include "longestCommonSubsequence.h"

template<typename T>
void lcsLength(const vector<T>& x, const vector<T>& y, vector<vector<int32_t>>& b, vector<vector<int32_t>>& c)
{
    const int32_t oblique = 0;
    const int32_t up = 1;
    const int32_t left = -1;
    size_t xlen = x.size();
    size_t ylen = y.size();
    b.resize(xlen, vector<int32_t>(ylen, 0));
    c.resize(xlen+1, vector<int32_t>(ylen + 1, 0));


    // 计算X的前缀Xi在Y的前缀Yj中的最长公共子序列
    for (size_t i = 0; i < xlen; ++i)
    {
        for (size_t j = 0; j < ylen; ++j)
        {
            // 前缀末尾相等
            if (x[i] == y[j])
            {
                // 公共子序列长度加1
                c[i+1][j+1] = c[i][j] + 1;
                // 标记方向
                b[i][j] = oblique;
            }
            // Xi和Yj+1的公共子序列长度大于Xi+1和Yj的公共子序列长度
            else if (c[i][j+1] >= c[i+1][j])
            {
                c[i+1][j+1] = c[i][j+1];
                b[i][j] = up;
            }
            else
            {
                c[i+1][j+1] = c[i+1][j];
                b[i][j] = left;
            }
        }
    }
}

template<typename T>
void printLcs(const vector<vector<int32_t>>& b, const vector<T>& x, int i, int j)
{
    const int32_t oblique = 0;
    const int32_t up = 1;
    if (i < 0 || j < 0)
    {
        return;
    }
    if (b[i][j] == oblique)
    {
        printLcs(b, x, i - 1, j - 1);
        cout << x[i] << " ";
    }
    else if (b[i][j] == up)
    {
        printLcs(b, x, i - 1, j);
    }
    else
    {
        printLcs(b, x, i, j - 1);
    }
}

template void lcsLength<string>(const vector<string>& x, 
    const vector<string>& y, vector<vector<int32_t>>& b, vector<vector<int32_t>>& c);

template void printLcs<string>(const vector<vector<int32_t>>& b,
    const vector<string>& x, int i, int j);