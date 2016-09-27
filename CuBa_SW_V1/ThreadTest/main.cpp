#include "CThread.h"
#include "CRxTask.h"
#include "CComponent.h"

int main()
{
	CComponent comp;
	CThread compThread(&comp);
	compThread.start();

	compThread.join();

	return 0;
}
