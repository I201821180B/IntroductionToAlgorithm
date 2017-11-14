#ifndef _BASIC_H_
#define _BASIC_H_

#define CHECK_MEMORY_LEAKS

#ifdef CHECK_MEMORY_LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define CHECK_MEMORY_LEAKS_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new CHECK_MEMORY_LEAKS_NEW
#endif

#endif

/*
作者：vczh
链接：https ://www.zhihu.com/question/63946754/answer/215606096
来源：知乎
著作权归作者所有，转载请联系作者获得授权。
*/