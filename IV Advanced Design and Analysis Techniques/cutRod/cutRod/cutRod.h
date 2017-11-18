#ifndef _CUTROD_H_
#define _CUTROD_H_

#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::numeric_limits;
using std::max;

size_t memorizedCutRod(const vector<int>& p, size_t n);
size_t memorizedCutRodAux(const vector<int>& p, size_t n, vector<int>& r);
size_t bottomMemorizedCutRod(const vector<int>& p, size_t n);


#endif // !_CURROD_H_
