#ifndef _MATRIX_CHAIN_MULTIPLICATION_H_
#define _MATRIX_CHAIN_MULTIPLICATION_H_

#include <iostream>
#include <vector>
#include <cassert>
#include <utility>
#include <cstdint>
#include <limits>

#include "matrix.h"

using std::vector;
using std::cerr;
using std::endl;
using std::numeric_limits;

matrix<int> matrixMultiply(const matrix<int32_t>& _a, const matrix<int32_t>& _b);
void matrixChainOrder(const vector<int32_t>& _p, vector<vector<int32_t>>& _m, vector<vector<int32_t>>& _s);
void printOptimalParens(const vector<vector<int32_t>>& _s, size_t _i, size_t _j);

#endif // !_MATRIX_CHAIN_MULTIPLICATION_H_

