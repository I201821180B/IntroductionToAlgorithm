#ifndef _LONGEST_COMMON_SUBSEQUENCE_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using std::vector;
using std::string;
using std::cout;
using std::endl;

template<typename T>
void lcsLength(const vector<T>& _x, const vector<T>& _y, vector<vector<int32_t>>& _b, vector<vector<int32_t>>& _c);

template<typename T>
void printLcs(const vector<vector<int32_t>>& _b, const vector<T>& _x, int _i, int _j);

#endif // !_LONGEST_COMMON_SUBSEQUENCE_H_

