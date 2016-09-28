/**
 * @file	main.cpp
 * @author	Michael Meindl
 * @date	28.9.2016
 * @brief	File containing the main routing, creates the componentes and runs them.
 */
#include "CThread.h"
#include "CProxy.h"
#include "CControlComponent.h"
#include "CCommComponent.h"

int main()
{
	CProxy proxy;
	CControlComponent controlComponent(proxy);
	CCommComponent commComponent(proxy);
	proxy.setCommPtr(&commComponent);
	proxy.setControlPtr(&controlComponent);

	CThread controlThread(&controlComponent);
	CThread commThread(&commComponent);

	controlThread.start();
	commThread.start();

	controlThread.join();
	commThread.join();
	return 0;
}
