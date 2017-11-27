#ifndef _OPTIMAL_BINARY_SEARCH_TREE_H_
#define _OPTIMAL_BINARY_SEARCH_TREE_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
//#include <limits>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::numeric_limits;

void optimalBst(const vector<float>& _p, const vector<float>& _q, size_t n,
	vector<vector<float>>& _e, vector<vector<size_t>>& _r);

#endif // !_OPTIMAL_BINARY_SEARCH_TREE_H_

