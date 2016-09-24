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

	if(fork() == 0)
	{
		CCommComponent commComp(*commQueue, *controlQueue);
		commComp.init();
		//commComp.run_V1_AusgleichsPolynomAccelerometer();
		//commComp.run_V2_OffsetGyroscope();
		//commComp.run_V3_AusgleichsPolynomMotorADC();
		//commComp.run_V4_FilterTest();
		//commComp.run_V5_BestimmungC_psi();
		//commComp.run_V6_BestimmungC_phi();
		commComp.run_V7_RegelungTest();
	}
	else
	{
		CControlComponent controlComp(*controlQueue, *commQueue);
		controlComp.init();
		//controlComp.run_V1_AusgleichsPolynomAccelerometer();
		//controlComp.run_V2_OffsetGyroscope();
		//controlComp.run_V3_AusgleichsPolynomMotorADC();
		//controlComp.run_V4_FilterTest();
		//controlComp.run_V5_BestimmungC_psi();
		//controlComp.run_V6_BestimmungC_phi();
		controlComp.run_V7_RegelungTest();
	}
	return 0;
}
