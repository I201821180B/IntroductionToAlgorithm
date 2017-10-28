#include <iostream>
#include <vector>

#include "Queue.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	queue<int> q = { 7, 8, 6 ,5, 2, 4, 4, 1, 3 };
	q.print();

	q.enqueue(78);
	cout << "after push stack size: " << q.size() << endl;
	q.enqueue(6767);
	cout << "after push stack size: " << q.size() << endl;
	q.enqueue(4321);
	cout << "after push stack size: " << q.size() << endl;
	q.print();

	if (q.isEmpty())
	{
		cout << " stack is empty!!!" << endl;
	}
	else
	{
		cout << " stack is not empty!!!" << endl;
	}

	q.dequeue();
	cout << "after pop stack size: " << q.size() << endl;
	q.dequeue();
	cout << "after pop stack size: " << q.size() << endl;
	q.dequeue();
	cout << "after pop stack size: " << q.size() << endl;
	q.dequeue();
	cout << "after pop stack size: " << q.size() << endl;
	q.dequeue();
	cout << "after pop stack size: " << q.size() << endl;
	q.dequeue();
	cout << "after pop stack size: " << q.size() << endl;
	q.dequeue();
	cout << "after pop stack size: " << q.size() << endl;

	q.print();
}