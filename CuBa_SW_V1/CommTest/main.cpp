#include "CThread.h"
#include "CProxy.h"
#include "CCommComponent.h"


int main()
{
	CProxy proxy;
	CCommComponent comm(proxy);
	CThread commThread(&comm);
	proxy.setCommPtr(&comm);
	commThread.start();
	commThread.join();
	return 0;
}
