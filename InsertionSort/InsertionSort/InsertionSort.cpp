#include <iostream>
#include <vector>
//#include <string>
#include <random>
#include <functional>
#include <ctime>

#define SIZE 100

using namespace std;

void InsertionSort(vector<int>& arr)
{
	int i = 0;
	int j = 0;
	for (i = 1; i < arr.size(); ++i)
	{
		int key = arr[i];
		j = i - 1;
		/*for (j = i - 1; j >= 0; --j)
		{
			if (key < arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}*/
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void print(vector<int>& arr)
{
	for (const int& val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
}
int main()
{
	std::default_random_engine generator(time(NULL)); // 生成器
	std::uniform_int_distribution<int> dis(0, 1000); // 分布器
	auto dice = std::bind(dis, generator); // 绑定成一个随机数生成函数

	vector<int> arr;
	for (int i = 0; i < SIZE; ++i)
	{
		arr.push_back(dice());
	}
	print(arr);
	cout << endl;
	InsertionSort(arr);
	print(arr);
	//system("pause");
}