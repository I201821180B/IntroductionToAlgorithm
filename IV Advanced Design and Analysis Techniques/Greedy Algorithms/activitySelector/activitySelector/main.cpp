#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

#include "activitySelector.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    const int32_t n = 11;
    vector<int32_t> s{ 0,1,3,0,5,3,5,6,8,8,2,12 };
    vector<int32_t> f{ 0,4,5,6,7,9,9,10,11,12,14,16 };

    vector<int32_t> a;
    recursiveActivitySelector(a, s, f, 0, n);
    cout << "recursiveActivitySelector: ";
    for (auto elem : a)
    {
        cout << elem << " ";
    }
    cout << endl;

    a.clear();
    greedyActivitySelector(a, s, f);
    cout << "greedyActivitySelector: ";
    for (auto elem : a)
    {
        cout << elem << " ";
    }
    cout << endl;
}