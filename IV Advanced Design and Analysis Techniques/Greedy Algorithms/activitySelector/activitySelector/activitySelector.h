#ifndef _ACTIVITY_SELECTOR_H_
#define _ACTIVITY_SELECTOR_H_

#include <iostream>
#include <vector>
#include <cstdint>

using std::vector;
using std::cout;
using std::endl;

void recursiveActivitySelector(const vector<int32_t>& a, const vector<int32_t>& s, const vector<int32_t>& f, size_t k, size_t n);
void greedyActivitySelector();

#endif // !_ACTIVITY_SELECTOR_H_

