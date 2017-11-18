#include <iostream>

#include "cutRod.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> p{ 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int length = 4;
	size_t res1 = memorizedCutRod(p, length);
	size_t res2 = bottomMemorizedCutRod(p, length);
	cout << length << " inches rod cutting: " << res1 << " and " << res2 << endl;
}