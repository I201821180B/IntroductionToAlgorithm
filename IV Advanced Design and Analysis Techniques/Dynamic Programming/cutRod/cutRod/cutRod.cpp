#include "cutRod.h"

/**
 * 动态规划方法要求仔细安排求解顺序，对每个子问题只求解一次，并将结果保存起来
 * 下次使用时只需查找保存的结果
 */

size_t memorizedCutRod(const vector<int>& price, const size_t length)
{
    vector<int> r(length + 1, numeric_limits<int>::min());
    return memorizedCutRodAux(price, length, r);
}

size_t memorizedCutRodAux(const vector<int>& price, const size_t length, vector<int>& r)
{
    int _max = 0;
    /*如果所求的值已知，直接返回这个值*/
    if (r[length] >= 0)
    {
        return r[length];
    }
    /**/
    if (length == 0)
    {
        _max = 0;
    }
    else
    {
        _max = INT_MIN;// numeric_limits<int>::min();
        
        for (int i = 1; i <= length; i++)
        {
            /*钢管截下i寸，求剩下n-i寸的最优解*/
            int aux = price[i - 1] + memorizedCutRodAux(price, length - i, r);
            _max = max(_max, aux);
        }
    }
    /*n英寸钢管最优解为q*/
    r[length] = _max;
    return _max;
}

size_t bottomUpCutRod(const vector<int>& price, const size_t length)
{
    vector<int> r(length + 1, 0);
    /*r[0]*是一个边界*/
    r[0] = 0;

    /*求1~n英寸钢管的最优解*/
    for (int i = 1; i <= length; ++i)
    {
        /*求1~i英寸钢管的最优解*/
        int _max = INT_MIN; // numeric_limits<int>::min();
        for (int j = 1; j <= i; ++j)
        {
            /*钢管截下j寸，求剩下n-j寸的最优解*/
            int temp = price[j - 1] + r[i - j];
            _max = max(_max, temp);
        }
        r[i] = _max;
    }
    return r[length];
}

void extendedBottomUpCutRod(const vector<int>& price, const size_t length, vector<int>& optimal, vector<int>& s)
{
    
    optimal[0] = 0;
    /*求1~n英寸钢管的最优解*/
    for (int i = 1; i <= length; ++i)
    {
        /*求1~i英寸钢管的最优解*/
        int _max = INT_MAX; // numeric_limits<int>::min();
        for (int j = 1; j <= i; ++j)
        {
            if (_max < price[j - 1] + optimal[i - j])
            {
                _max = price[j - 1] + optimal[i - j];
                s[i] = j;
            }
        }
        optimal[i] = _max;
    }
    //return optimal[length];
}

void printCutRodSolution(const vector<int>& price, const size_t length)
{
    vector<int> firstCut(length + 1, 0);
    vector<int> optimal(length + 1, 0);
    extendedBottomUpCutRod(price, length, optimal, firstCut);
    cout << "best cutting is ";
    int restLength = length;
    while (restLength > 0)
    {
        cout << firstCut[restLength] << " ";
        restLength = restLength - firstCut[restLength];	
    }
    cout << endl << "price is " << optimal[length] << endl;
}
