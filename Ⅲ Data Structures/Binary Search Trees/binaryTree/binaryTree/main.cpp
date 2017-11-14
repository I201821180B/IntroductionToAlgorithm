#include <iostream>
#include <vector>


#include "basic.h"
#include "binaryTree.h"

int main()
{
	/*只用加这一句就可以检测内存泄露了*/
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(215);
	//_CrtDumpMemoryLeaks();

	std::vector<int> v = { 4,1,2,3,5,6,7 };
	binaryTree<int> bt(v);
	bt.inorderTreeWalk(bt.root());

	std::vector<int> v1 = { 46,143,25,32,15,65,57 };
	binaryTree<int>* pbt = new binaryTree<int>(v1);
	pbt->inorderTreeWalk(pbt->root());
	delete pbt;
	//_CrtDumpMemoryLeaks();
}