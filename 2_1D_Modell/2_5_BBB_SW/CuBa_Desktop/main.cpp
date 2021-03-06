#include "CProxy.h"
#include "CControlComponent.h"
#include "CCommComponent.h"
#include "CThread.h"
#include "CMessage.h"
#include <iostream>
#include <unistd.h>

#define LINE std::cout<<"---------------------------------------"<<std::endl;

void testExperimentLogic();
void testControlTest();
void testJump();

int main()
{
	CControlComponent mControl;
	CThread mControlThread(&mControl);
	CCommComponent mComm;
	CThread mCommThread(&mComm);
	CProxy& proxy = CProxy::getInstance();
	proxy.registerCommComponent(&mComm);
	proxy.registerControlComponent(&mControl);

	mControlThread.start();
	mCommThread.start();

	mControlThread.join();
	mCommThread.join();
	return 0;
}
void testJump()
{
	CControlComponent myComponent;
	CProxy::getInstance().registerControlComponent(&myComponent);
	CThread myThread(&myComponent);
	myThread.start();

	sleep(1);
	CProxy& proxy = CProxy::getInstance();
	LINE;
	CMessage msg(EEvent::INIT);
	proxy.routeMATLABMessage(msg, true);
	msg = CMessage(EEvent::RUN_JUMP_TEST);
	proxy.routeMATLABMessage(msg, true);
	CMessage timer(EEvent::TIMER_TICK);
	sleep(3);
	msg = CMessage(EEvent::CLIENT_DISCONNECT);
	proxy.routeMATLABMessage(msg, true);
	LINE
	myThread.join();
}
void testControlTest()
{
	CControlFSM myFSM;
	LINE;
	CMessage msg(EEvent::INIT);
	myFSM.dispatch(msg);
	CMessage timer(EEvent::TIMER_TICK);
	msg = CMessage(EEvent::RUN_CONTROL_TEST);
	myFSM.dispatch(msg);
	myFSM.dispatch(timer);
	myFSM.dispatch(timer);
	myFSM.dispatch(timer);
	msg = CMessage(EEvent::CLIENT_DISCONNECT);
	myFSM.dispatch(msg);
}
void testExperimentLogic()
{
	CControlFSM myFSM;
	LINE;
	CMessage msg(EEvent::INIT);
	CMessage timer(EEvent::TIMER_TICK);
	myFSM.dispatch(msg);
	msg = CMessage(EEvent::RUN_SENSOR_MEASUREMENT);
	myFSM.dispatch(msg);
	myFSM.dispatch(timer);
	CMessage clientDC = CMessage(EEvent::CLIENT_DISCONNECT);
	myFSM.dispatch(clientDC);

	LINE

	msg = CMessage(EEvent::RUN_ADC_MEASUREMENT);
	myFSM.dispatch(msg);
	msg = CMessage(EEvent::SET_TORQUE);
	myFSM.dispatch(msg);
	myFSM.dispatch(timer);
	myFSM.dispatch(clientDC);

	LINE

	msg = CMessage(EEvent::RUN_CPSI_IDENTIFICATION);
	myFSM.dispatch(msg);
	msg = CMessage(EEvent::SET_TORQUE);
	myFSM.dispatch(msg);
	myFSM.dispatch(timer);
	myFSM.dispatch(clientDC);

	LINE

	msg = CMessage(EEvent::RUN_CPHI_IDENTIFICATION);
	myFSM.dispatch(msg);
	myFSM.dispatch(timer);
	myFSM.dispatch(clientDC);
}
