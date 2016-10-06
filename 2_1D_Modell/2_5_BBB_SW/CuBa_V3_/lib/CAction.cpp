/**
 * @file	CAction.cpp
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#include "CAction.h"
#include <iostream>

CAction::CAction() : mBalanceFlag(false)
{

}
void CAction::setBalanceFlag(bool flag)
{
	mBalanceFlag = flag;
}
void CAction::sampleE1()
{
	std::cout << "[Control-Component] Sampling Experiment1" << std::endl;
	//TODO E1
}
void CAction::sampleE2()
{
	std::cout << "[Control-Component] Sampling Experiment2" << std::endl;
	//TODO E2
}
void CAction::sampleE3()
{
	std::cout << "[Control-Component] Sampling Experiment3" << std::endl;
	//TODO E3
}
void CAction::sampleE4()
{
	std::cout << "[Control-Component] Sampling Experiment4" << std::endl;
	//TODO E4
}
void CAction::sampleE5()
{
	std::cout << "[Control-Component] Sampling Experiment5" << std::endl;
	//TODO E5
}
void CAction::controlIteration()
{
	std::cout << "[Control-Component] Control Iteration" << std::endl;
	//TODO Control
}
bool CAction::inBalanceArea()
{
	return true;
	//TODO Area check
}
void CAction::onEntryAccelerating()
{
	std::cout << "[Control-Component] Entering Accelerating" << std::endl;
	//TODO Set Torque
}
void CAction::onExitAccelerating()
{
	std::cout << "[Control-Component] Exiting Accelerating" << std::endl;
	//TODO Set Torque
}
void CAction::onEntryWaiting()
{
	std::cout << "[Control-Component] Entering Waiting" << std::endl;
	//TODO Nothing?
}
void CAction::onExitWaiting()
{
	std::cout << "[Control-Component] Exiting Waiting" << std::endl;
}
void CAction::onEntryBraking()
{
	std::cout << "[Control-Component] Entering Braking" << std::endl;
	//TODO Close Brake
}
void CAction::onExitBraking()
{
	std::cout << "[Control-Component] Exiting Braking" << std::endl;
	//TODO Open Brake
}
void CAction::onEntryBalancing()
{
	std::cout << "[Control-Component] Entering Balancing" << std::endl;
	//TODO Enable Motor, zero torque
}
void CAction::onExitBalancing()
{
	std::cout << "[Control-Component] Exiting Balancing" << std::endl;
	//TODO Disable Motor
}
void CAction::onEntryIdle()
{
	std::cout << "[Control-Component] Entering Idle" << std::endl;
	//TODO Nothing?
}
void CAction::onExitIdle()
{
	std::cout << "[Control-Compoennt] Exiting Idle" << std::endl;
	//TODO Nothing?
}
void CAction::onEntryStandby()
{
	std::cout << "[Control-Component] Entering Standby" << std::endl;
	//TODO Entry-Action Standby
}
void CAction::onExitStandby()
{
	std::cout << "[Control-Component] Exiting Standby" << std::endl;
	//TODO Exit-Aciton Standby
}
void CAction::onEntryExperiment1()
{
	std::cout << "[Control-Component] Entering Experiment1" << std::endl;
	//TODO Start Timer
}
void CAction::onExitExperiment1()
{
	std::cout << "[Control-Component] Exiting Experiment1" << std::endl;
	//TODO Stop Timer
}
void CAction::onEntryExperiment2()
{
	std::cout << "[Control-Component] Entering Experiment2" << std::endl;
	//TODO Start Timer
}
void CAction::onExitExperiment2()
{
	std::cout << "[Control-Component] Exiting Experiment2" << std::endl;
	//TODO Stop Timer
}
void CAction::onEntryExperiment3()
{
	std::cout << "[Control-Component] Entering Experiment3" << std::endl;
	//TODO Start Timer
}
void CAction::onExitExperiment3()
{
	std::cout << "[Control-Component] Exiting Experiment3" << std::endl;
	//TODO Stop Timer
}
void CAction::onEntryExperiment4()
{
	std::cout << "[Control-Component] Entering Experiment4" << std::endl;
	//TODO Start Timer
}
void CAction::onExitExperiment4()
{
	std::cout << "[Control-Component] Exiting Experiment4" << std::endl;
	//TODO Stop Timer
}
void CAction::onEntryExperiment5()
{
	std::cout << "[Control-Component] Entering Experiment5" << std::endl;
	//TODO Start Timer
}
void CAction::onExitExperiment5()
{
	std::cout << "[Control-Component] Exiting Experiment5" << std::endl;
	//TODO Stop Timer
}
void CAction::onEntryExperiment6()
{
	std::cout << "[Control-Component] Entering Experiment6" << std::endl;
	//TODO Start Timer
}
void CAction::onExitExperiment6()
{
	std::cout << "[Control-Component] Exiting Experiment6" << std::endl;
	//TODO Stop Timer
}
void CAction::onEntryExperiment7()
{
	std::cout << "[Control-Component] Entering Experiment7" << std::endl;
	//TODO Start Timer
}
void CAction::onExitExperiment7()
{
	std::cout << "[Control-Component] Exiting Experiment7" << std::endl;
	//TODO Stop Timer
}
void CAction::onEntryCuBa()
{
	std::cout << "[Control-Component] Entering CuBa" << std::endl;
	//TODO Start Timer
}
void CAction::onExitCuBa()
{
	std::cout << "[Control-Component] Exiting CuBa" << std::endl;
	//TODO Stop Timer
}
void CAction::setTorque(Float32 torque)
{
	//TODO Set Torque
}
