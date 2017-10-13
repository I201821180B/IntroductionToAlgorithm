#include <iostream>
#include <vector>
//#include <ctime>
//#include <random>
//#include <functional>
#include "Heap.h"
#include "common.h"
#include "PriorityQueue.h"
using namespace std;


int main()
{
	vector<int> v;
	getRandomVector(v, 10, 0, 100);
	printVector(v);
	//cout << endl;
	priorityQueue pq(v);
	pq.print();

	cout << "pq.maximum(): " << pq.maximum() << endl;
	cout << "pq.extractMax(): " << pq.extractMax() << endl;

	cout << "before increase key: ";
	pq.print();
	pq.increaseKey(5, 486);
	cout << "after increase key: ";
	pq.print();

	pq.insert(78);
	cout << "after insert: ";
	pq.print();
}