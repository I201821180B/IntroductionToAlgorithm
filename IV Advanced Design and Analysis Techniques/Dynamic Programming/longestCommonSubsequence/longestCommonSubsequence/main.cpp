#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

#include "longestCommonSubsequence.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<string> x{"A","B","C","B","D","A","B"};
	vector<string> y{"B","D","C","A","B","A"};

	vector<vector<int32_t>> b;
	vector<vector<int32_t>> c;

	lcsLength(x, y, b, c);
	printLcs(b, x, b[0].size() - 1, b[1].size() - 1);
}