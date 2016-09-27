#include <iostream>
#include "CComponent.h"

CComponent::CComponent() : mRxTask(),
						   mRxThread(&mRxTask)
{

}
void CComponent::init()
{
	std::cout << "[Component] Init" << std::endl;
	mRxThread.start();
}
void CComponent::run()
{
	while(true)
	{
		std::cout << "Resuming Rx-Thread" << std::endl;
		mRxTask.resume();
		for(Int32 i = 0; i < 5; i++)
		{
			std::cout << "[Component] Run-Iteration" << std::endl;
			sleep(1);
		}
		std::cout << "Pausing Rx-Thread" << std::endl;
		for(Int32 i = 0; i < 5; i++)
		{
			std::cout << "[Component] Run-Iteration" << std::endl;
			sleep(1);
		}
	}
}
void CComponent::pause()
{

}
void CComponent::resume()
{

}
