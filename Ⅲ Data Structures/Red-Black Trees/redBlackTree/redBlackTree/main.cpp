#include <iostream>
#include <vector>

#include "basic.h"
#include "rbTree.h"

int main()
{
	/*只用加这一句就可以检测内存泄露了*/
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	rbTree<int> rb{ 4, 1, 3, 2, 7, 5, 6, 9 };//
	rb.print();

	std::vector<int> v1{ 46,143,25,32,15,65,57,67,120,23,45 };
	rbTree<int>* prb = new rbTree<int>(v1);
	prb->print();

	int key = 32;
	int res = prb->search(key);
	std::cout << "tree search " << key << ", result: " << res << std::endl;

	std::cout << "tree min: " << prb->min() << ", tree max: " << prb->max() << std::endl;

	int suc = prb->successor(res);
	std::cout << "tree Successor: " << key << "'s successor is " << suc << std::endl;

	int preSuc = prb->preSuccessor(res);
	std::cout << "tree preSuccessor: " << key << "'s presuccessor is " << preSuc << std::endl;

	prb->insert(78);
	prb->print();
	prb->remove(65);
	prb->print();
	delete prb;
}