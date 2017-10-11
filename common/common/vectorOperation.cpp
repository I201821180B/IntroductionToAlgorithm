#include "vectorOperation.h"

void getRandomVector(vector<int>& v, size_t size, int from, int to)
{
	v.resize(0);
	std::default_random_engine generator(time(NULL));
	std::uniform_int_distribution<int> dis(from, to);
	auto dice = std::bind(dis, generator);

	for (int i = 0; i < size; ++i)
	{
		v.push_back(dice());
		//cout << v.back() << " ";
	}
}

template<typename T>
void printVector(vector<T>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}