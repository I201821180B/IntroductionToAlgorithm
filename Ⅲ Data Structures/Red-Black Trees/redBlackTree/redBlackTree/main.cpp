#include <iostream>
#include <vector>

#include "basic.h"
#include "rbTree.h"

int main()
{
	/*只用加这一句就可以检测内存泄露了*/
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	rbTree<int> rb{ 4, 1, 3, 2, 7, 5, 6, 9 };
	rb.print();

	std::vector<int> v1{ 46,143,25,32,15,65,57 };
	rbTree<int>* prb = new rbTree<int>(v1);
	prb->print();

	int key = 32;
	auto res = prb->search(key);
	std::cout << "tree search " << key << ", result: " << res->key() << std::endl;

	std::cout << "tree min: " << prb->min()->key() << ", tree max: " << prb->max()->key() << std::endl;

	auto res1 = prb->successor(res);
	std::cout << "tree Successor: " << key << "'s successor is " << res1->key() << std::endl;

	auto res2 = prb->preSuccessor(res);
	std::cout << "tree preSuccessor: " << key << "'s presuccessor is " << res2->key() << std::endl;

	delete prb;
}