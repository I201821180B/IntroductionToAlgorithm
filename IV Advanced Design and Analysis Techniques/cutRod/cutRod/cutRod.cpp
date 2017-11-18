#include "cutRod.h"

/**
 * 动态规划方法要求仔细安排求解顺序，对每个子问题只求解一次，并将结果保存起来
 * 下次使用时只需查找保存的结果
 */

size_t memorizedCutRod(const vector<int>& p, size_t n)
{
	vector<int> r(n+1, numeric_limits<int>::min());
	return memorizedCutRodAux(p, n, r);
}

size_t memorizedCutRodAux(const vector<int>& p, size_t n, vector<int>& r)
{
	int q = 0;
	/*如果所求的值已知，直接返回这个值*/
	if (r[n] >= 0)
	{
		return r[n];
	}
	/**/
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		q = numeric_limits<int>::min();
		
		for (int i = 1; i <= n; i++)
		{
			/*钢管截下i寸，求剩下n-i寸的最优解*/
			int aux = p[i - 1] + memorizedCutRodAux(p, n - i, r);
			q = max(q, aux);
		}
	}
	/*n英寸钢管最优解为q*/
	r[n] = q;
	return q;
}

size_t bottomMemorizedCutRod(const vector<int>& p, size_t n)
{
	vector<int> r(n + 1, 0);
	/*r[0]*是一个边界*/
	r[0] = 0;

	/*求1~n英寸钢管的最优解*/
	for (int i = 1; i <= n; ++i)
	{
		/*求1~i英寸钢管的最优解*/
		int q = numeric_limits<int>::min();
		for (int j = 1; j <= i; ++j)
		{
			/*钢管截下j寸，求剩下n-j寸的最优解*/
			int temp = p[j - 1] + r[i - j];
			q = max(q, temp);
		}
		r[i] = q;
	}
	return r[n];
}
