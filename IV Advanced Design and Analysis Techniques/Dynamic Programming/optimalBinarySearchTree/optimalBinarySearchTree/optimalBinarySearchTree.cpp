#include "optimalBinarySearchTree.h"

#define RANGE(_i, _from, _to) \
	for(int32_t _i = _from; _i < _to +1; ++_i)


void optimalBst(const vector<float>& _p, const vector<float>& _q, size_t _n, 
	vector<vector<float>>& _e, vector<vector<size_t>>& _r)
{
	// 初始化
	_e.resize(_n + 2, vector<float>(_n + 1, 0));
	vector<vector<float>> w(_n + 2, vector<float>(_n + 1, 0));
	_r.resize(_n + 1, vector<size_t>(_n + 1, 0));

	// 为只包含关键字di的子树设置边界内容
	for (int32_t i = 1; i < _n + 2; ++i)
	{
		_e[i][i-1] = _q[i-1];
		w[i][i-1] = _q[i-1];
	}

	// len是ki到kj子树的“长度”
	//for (int32_t len = 1; len < _n + 1; ++len)
	RANGE(len, 1, _n)
	{
		//for (int32_t i = 1; i < _n - len + 2; ++i)
		RANGE(i, 1, _n - len + 1)
		{
			int32_t j = i + len - 1;
			_e[i][j] = FLT_MAX;//numeric_limits<int32_t>::max();

			// ki到kj+1子树的期望代价 = ki到kj的子树期望代价 + kj+1节点的搜索成功频率 + kj+1节点的搜索失败频率
			w[i][j] = w[i][j - 1] + _p[j - 1] + _q[j];
			// 选取根节点，
			for (int32_t r = i; r < j + 1; ++r)
			{
				float t = _e[i][r - 1] + _e[r + 1][j] + w[i][j];
				if (t < _e[i][j])
				{
					_e[i][j] = t;
					_r[i][j] = r;
				}
			}
		}
	}
}

// 去掉e和r中未使用的空间
void optimalBstRe(const vector<float>& _p, const vector<float>& _q, size_t _n,
	vector<vector<float>>& _e, vector<vector<size_t>>& _r)
{
	// 初始化
	_e.resize(_n + 1, vector<float>(_n + 1, 0));
	vector<vector<float>> w(_n + 1, vector<float>(_n + 1, 0));
	_r.resize(_n, vector<size_t>(_n, 0));

	// 为只包含关键字di的子树设置边界内容
	for (int32_t i = 0; i < _n + 1; ++i)
	{
		_e[i][i] = _q[i];
		w[i][i] = _q[i];
	}

	// len是ki到kj子树的“长度”
	//for (int32_t len = 1; len < _n + 1; ++len)
	RANGE(len, 1, _n)
	{
		//for (int32_t i = 1; i < _n - len + 2; ++i)
		RANGE(i, 0, _n - len)
		{
			int32_t j = i + len;
			_e[i][j] = FLT_MAX;//numeric_limits<int32_t>::max();

			// ki到kj+1子树的期望代价 = ki到kj的子树期望代价 + kj+1节点的搜索成功频率 + kj+1节点的搜索失败频率
			w[i][j] = w[i][j - 1] + _p[j - 1] + _q[j];
			// 选取根节点，
			for (int32_t r = i + 1; r < j + 1; ++r)
			{
				float t = _e[i][r - 1] + _e[r][j] + w[i][j];
				if (t < _e[i][j])
				{
					_e[i][j] = t;
					_r[i][j - 1] = r;
				}
			}
		}
	}
}
