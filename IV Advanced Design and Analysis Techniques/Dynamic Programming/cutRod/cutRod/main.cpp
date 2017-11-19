#include <iostream>

#include "cutRod.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> price{ 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int length = 10;
	size_t res1 = memorizedCutRod(price, length);
	size_t res2 = bottomUpCutRod(price, length);
	cout << length << " inches rod cutting price is: " << res1 << " and " << res2 << endl;

	printCutRodSolution(price, length);
}