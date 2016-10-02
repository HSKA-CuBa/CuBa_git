//8.9.2016, Michael Meindl
#include "Assertion.h"
#include <cstdlib>
#include <iostream>

void sAssertion(bool assertion, const char* errMsg)
{
	if(false == assertion)
	{
		std::cerr << errMsg << std::endl;
		exit(1);
	}
}
