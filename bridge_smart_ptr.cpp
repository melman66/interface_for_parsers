
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "ConfigTest.h"

using namespace std;

int main()
{
	unique_ptr<ConfigTest> tst = make_unique<ConfigTest>(ConfigTest());
	tst.reset();

	_CrtDumpMemoryLeaks();

}

