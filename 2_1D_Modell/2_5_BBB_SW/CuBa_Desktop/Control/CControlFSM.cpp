/**
 * @file	CControlFSM.cpp
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#include "CControlFSM.h"
#include "CMessage.h"

bool CControlFSM::dispatch(CMessage& msg)
{
	bool consumed = CControlBase::dispatch(msg);

	if(sQueueSize != 0)
	{
		CMessage internalMsg = sInternalQueue;
		sQueueSize 			 = 0;
		consumed             = CControlBase::dispatch(internalMsg);
	}
	return consumed;
}
bool CControlFSM::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sStandby;
		sAction.entryStandby();
		return true;
	}
	return false;
}
bool CControlFSM::onStandby(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitStandby();
		mState = sInitial;
		return true;
	}
	if(EEvent::RUN_SENSOR_MEASUREMENT == event)
	{
		sAction.exitStandby();
		mState = sSensorMeasurement;
		sAction.entrySensorMeasurement();
		return true;
	}
	if(EEvent::RUN_ADC_MEASUREMENT == event)
	{
		sAction.exitStandby();
		mState = sADCMeasurement;
		sAction.entryADCMeasurement();
		return true;
	}
	if(EEvent::RUN_CPSI_IDENTIFICATION == event)
	{
		sAction.exitStandby();
		mState = sCPsiIdentification;
		sAction.entryCPsiIdentification();
		return true;
	}
	if(EEvent::RUN_CPHI_IDENTIFICATION == event)
	{
		sAction.exitStandby();
		mState = sCPhiIdentification;
		sAction.entryCPhiIdentification();
		return true;
	}
	if(EEvent::RUN_CONTROL_TEST == event)
	{
		sAction.exitStandby();
		mState = sControlTest;
		sAction.entryControlTest();
		mSuperstateControlTest.entry();
		return true;
	}
	if(EEvent::RUN_JUMP_TEST == event)
	{
		sAction.exitStandby();
		mState = sJumpTest;
		sAction.entryJumpTest();
		mSuperstateJump.entry();
		return true;
	}
	return false;
}
bool CControlFSM::onSensorMeasurement(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitSensorMeasurement();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleSensors();
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.exitSensorMeasurement();
		mState = sStandby;
		sAction.entryStandby();
		return true;
	}
	return false;
}
bool CControlFSM::onADCMeasurement(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitADCMeasurement();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleADC();
		return true;
	}
	if(EEvent::SET_TORQUE == event)
	{
		sAction.setTorque(msg.getTorque());
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.exitADCMeasurement();
		mState = sStandby;
		sAction.entryStandby();
		return true;
	}
	return false;
}
bool CControlFSM::onCPsiIdentification(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitCPsiIdentification();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleCPsiIdentification();
		return true;
	}
	if(EEvent::SET_TORQUE == event)
	{
		sAction.setTorque(msg.getTorque());
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.exitCPsiIdentification();
		mState = sStandby;
		sAction.entryStandby();
		return true;
	}
	return false;
}
bool CControlFSM::onCPhiIdentification(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		sAction.exitCPhiIdentification();
		mState = sInitial;
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		sAction.sampleCPhiIdentification();
		return true;
	}
	if(EEvent::CLIENT_DISCONNECT == event)
	{
		sAction.exitCPhiIdentification();
		mState = sStandby;
		sAction.entryStandby();
		return true;
	}
	return false;
}
bool CControlFSM::onControlTest(CMessage& msg)
{
	bool consumed = mSuperstateControlTest.dispatch(msg);

	if(consumed == false)
	{
		EEvent event = msg.getEvent();
		if(EEvent::CLIENT_DISCONNECT == event)
		{
			sAction.exitControlTest();
			mSuperstateControlTest.exit();
			mState = sStandby;
			sAction.entryStandby();
			return true;
		}
	}
	return consumed;
}
bool CControlFSM::onJumpTest(CMessage& msg)
{
	bool consumed = mSuperstateJump.dispatch(msg);

	if(consumed == false)
	{
		EEvent event = msg.getEvent();
		if(EEvent::CLIENT_DISCONNECT == event)
		{
			sAction.exitJumpTest();
			mSuperstateJump.exit();
			mState = sStandby;
			sAction.entryStandby();
			return true;
		}
		if(EEvent::BRAKING_FINISHED == event)
		{
			mSuperstateJump.exit();
			sAction.exitJumpTest();
			mState = sStandby;
			sAction.entryStandby();
			return true;
		}
	}
	return consumed;
}
