#include "linkedList.h"

#include <vector>
#include <iostream>

using namespace std;

int main()
{
	
	linkedList<int> l = { 2, 4, 7, 9, 1, 8 };
	l.print();
	cout << l.size() << endl;

	//node<int>* n1 = new node<int>(99);
	//node<int>* n2 = new node<int>(9);
	
	l.insert(99);
	l.print();
	cout << l.size() << endl;

	l.insert(78, 3);
	l.print();
	cout << l.size() << endl;

	l.remove(9);
	l.print();
	cout << l.size() << endl;

	l.print(5);
}