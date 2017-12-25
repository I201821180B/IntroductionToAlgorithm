#include "activitySelector.h"

void recursiveActivitySelector(vector<int32_t>& a, const vector<int32_t>& s, const vector<int32_t>& f, size_t k, size_t n)
{
    int32_t m = k + 1;
    for (; m <= n && s[m] < f[k];)
    {
        m = m + 1;
	}
    if (m <= n)
    {
        a.push_back(m);
        recursiveActivitySelector(a, s, f, m, n);
    }
}

void greedyActivitySelector(vector<int32_t>& a, const vector<int32_t>& s, const vector<int32_t>& f)
{
    int32_t n = s.size() - 1;
    a.push_back(1);
    int32_t k = 1;
    for (int32_t m = 2; m <= n; ++m)
    {
        if (s[m] >= f[k])
        {
            a.push_back(m);
            k = m;
        }
    }
}