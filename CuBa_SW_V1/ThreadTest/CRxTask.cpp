#include "CRxTask.h"

int counter = 0;
CRxTask::CRxTask() : mRunningSem(false, true)
{

}
void CRxTask::pause()
{
	mRunningSem.take(true);
}
void CRxTask::resume()
{
	mRunningSem.give();
	counter = 0;
}
void CRxTask::init()
{
	std::cout << "[RxTask] Init" << std::endl;
}
void CRxTask::run()
{
	while(true)
	{
		counter ++;
		if(counter > 2)
		{
			mRunningSem.take(true);
		}
		mRunningSem.take(true);
		mRunningSem.give();
		std::cout << "[RxTask] Run-Iteration" << std::endl;
		sleep(1);
	}
}
