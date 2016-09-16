#include <pthread.h>
#include <unistd.h>

#include "CSharedMemory.h"
#include "AComponentBase.h"
#include "CControlComponent.h"
#include "CCommComponent.h"
#include "Global.h"
#include "TQueue.h"


int main(void)
{
	CSharedMemory shm;
	TQueue<Config::QueueSize>* controlQueue = shm.createQueue();
	TQueue<Config::QueueSize>* commQueue	= shm.createQueue();

	CCommComponent commComp(*commQueue, *controlQueue);
	CControlComponent controlComp(*controlQueue, *commQueue);
	if(fork() == 0)
	{
		commComp.init();
		//commComp.run_V1_AusgleichsPolynomAccelerometer();
		//commComp.run_V2_OffsetGyroscope();
		commComp.run_V3_AusgleichsPolynomMotorADC();
		//commComp.run_V4_FilterTest();
	}
	else
	{
		controlComp.init();
		//controlComp.run_V1_AusgleichsPolynomAccelerometer();
		//controlComp.run_V2_OffsetGyroscope();
		controlComp.run_V3_AusgleichsPolynomMotorADC();
		//controlComp.run_V4_FilterTest();
	}
	return 0;
}
