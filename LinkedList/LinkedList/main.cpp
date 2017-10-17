
#include "linkedList.h"


int main()
{
	linkedList<int> l = { 2, 4, 7, 9, 1, 8 };
	l.print();

	node<int>* n1 = new node<int>(99);
	node<int>* n2 = new node<int>(9);
	
	l.insert(n1);
	l.print();

	l.del(n2);
	l.print();
}