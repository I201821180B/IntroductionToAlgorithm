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

matrix<int> matrixMultiply(const matrix<int32_t>& a, const matrix<int32_t>& b);
void matrixChainOrder(const vector<int32_t>& p, vector<vector<int32_t>>& m, vector<vector<int32_t>>& s);
void printOptimalParens(const vector<vector<int32_t>>& s, size_t i, size_t j);

#endif // !_MATRIX_CHAIN_MULTIPLICATION_H_

