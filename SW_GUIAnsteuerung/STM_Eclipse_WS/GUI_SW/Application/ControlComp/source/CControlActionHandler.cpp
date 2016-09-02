/************************************************
 * Author: Michael Meindl
 * Datum : 17.04.2016
 ***********************************************/
#include "SProxy.h"
#include "CControlActionHandler.h"
#include "Config.h"
#include <cmath>

CControlActionHandler::CControlActionHandler() : mJumpFlag(false),
												 mBalanceFlag(false),
												 mTransmitFlag(false),
												 mPhiK(0.0F),
												 mPhiK_d(0.0F),
												 mPhiR_d(0.0F),
												 mSoftTimer(SSoftTimer::getInstance()) {}
void CControlActionHandler::onEntryConfiguration()
{
	if(mTransmitFlag == true)
	{
		SProxy::getInstance().transmitStateEntry(EComponentID::CONTROL_COMP,
												 EState::STATE_CONFIFURATION);
	}
}
void CControlActionHandler::onExitConfiguration()
{
	;
}
void CControlActionHandler::onEntryRunning()
{
	mSoftTimer.setPeriod(EConfig::TIMERPERIOD_IDLE);
	mSoftTimer.start();
	if(mTransmitFlag == true)
	{
		SProxy::getInstance().transmitStateEntry(EComponentID::CONTROL_COMP,
												 EState::STATE_RUNNING);
	}
}
void CControlActionHandler::onExitRunning()
{
	mSoftTimer.stop();
}
void CControlActionHandler::onEntryIdle()
{
	if(mTransmitFlag == true)
	{
		SProxy::getInstance().transmitStateEntry(EComponentID::CONTROL_COMP,
												 EState::STATE_IDLE);
	}
}
void CControlActionHandler::onEntryBalance()
{
	mSoftTimer.setPeriod(EConfig::TIMERPERIOD_BALANCE);
	mHardware.setTorque(0.0F);
	mHardware.enableMotor();
	if(mTransmitFlag == true)
	{
		SProxy::getInstance().transmitStateEntry(EComponentID::CONTROL_COMP,
												 EState::STATE_BALANCE);
	}
}
void CControlActionHandler::onExitBalance()
{
	mHardware.disableMotor();
	mHardware.setTorque(0.0F);
}
void CControlActionHandler::onEntryJump()
{
	mSoftTimer.setPeriod(EConfig::TIMERPERIOD_JUMP);
	if(mTransmitFlag == true)
	{
		SProxy::getInstance().transmitStateEntry(EComponentID::CONTROL_COMP,
												 EState::STATE_JUMP);
	}
}
void CControlActionHandler::onExitJump()
{
	;
}
void CControlActionHandler::onEntryWaiting()
{
	if(mTransmitFlag == true)
	{
		SProxy::getInstance().transmitStateEntry(EComponentID::CONTROL_COMP,
												 EState::STATE_WAITING);
	}
}
void CControlActionHandler::onExitWaiting()
{
	;
}
void CControlActionHandler::onEntryAccelerate()
{
	//mHardware.setTorque(Config::Torque_JumpUp);
	if(mTransmitFlag == true)
	{
		SProxy::getInstance().transmitStateEntry(EComponentID::CONTROL_COMP,
												 EState::STATE_ACCELERATE);
	}
}
void CControlActionHandler::onExitIdle()
{
	//TODO;
}
bool CControlActionHandler::getJumpFlag()
{
	return mJumpFlag;
}
bool CControlActionHandler::getBalanceFlag()
{
	return mBalanceFlag;
}
bool CControlActionHandler::getTransmitFlag()
{
	return mTransmitFlag;
}
void CControlActionHandler::setBalanceFlag(UInt8 balanceFlag)
{
	mBalanceFlag = balanceFlag > 0U;
}
void CControlActionHandler::setJumpFlag(UInt8 jumpFlag)
{
	mJumpFlag = jumpFlag > 0U;
}
void CControlActionHandler::setTransmitFlag(UInt8 transmitFlag)
{
	mTransmitFlag = transmitFlag > 0U;
}
void CControlActionHandler::onEntryBrake()
{
	mHardware.closeBrake();
	if(mTransmitFlag == true)
	{
		SProxy::getInstance().transmitStateEntry(EComponentID::CONTROL_COMP,
												 EState::STATE_BRAKE);
	}
}
void CControlActionHandler::onExitBrake()
{
	mHardware.openBrake();
}
void CControlActionHandler::onExitAccelerate()
{
	mHardware.setTorque(0.0F);
}
bool CControlActionHandler::breakingFinished()
{
	mPhiK 		= mSensorEval.calcPhi(mHardware.getX1__dd_raw(),
							      mHardware.getX2__dd_raw(),
								  mHardware.getY1__dd_raw(),
								  mHardware.getY2__dd_raw());
	mPhiK_d		= mSensorEval.calcPhi__d(mHardware.getPhi1__d_raw(),
										 mHardware.getPhi2__d_raw());
	mPhiR_d		= mSensorEval.calcPsi__d(mHardware.getPsi__d_raw());
	mPhiK 		= mCompFilter.calculatePhi(mPhiK, mPhiK_d);

	//TODO Eventuell warten oder Grenze für Bremse fertig festlegen
	return mPhiR_d == 0U;				//Realdata needs to be evaluated with more care/should be done in the Hardware-Class
}
bool CControlActionHandler::cubeIsResting()
{
	mPhiK 		= mSensorEval.calcPhi(mHardware.getX1__dd_raw(),
							      mHardware.getX2__dd_raw(),
								  mHardware.getY1__dd_raw(),
								  mHardware.getY2__dd_raw());
	mPhiK_d		= mSensorEval.calcPhi__d(mHardware.getPhi1__d_raw(),
										 mHardware.getPhi2__d_raw());
	mPhiR_d		= mSensorEval.calcPsi__d(mHardware.getPsi__d_raw());
	mPhiK 		= mCompFilter.calculatePhi(mPhiK, mPhiK_d);
	return (std::abs(mPhiK) > Config::PhiResting);					//Realdata needs to be evaluated with more care/should be done in the Hardware-Class
}
bool CControlActionHandler::jumpVelocityReached()
{
	//TODO Richtugn überprüfen
	return std::abs(mPhiR_d) > Config::Psi__d_JumpValue;
}
bool CControlActionHandler::phiK_inBalanceArea()
{
	mPhiK 		= mSensorEval.calcPhi(mHardware.getX1__dd_raw(),
							      mHardware.getX2__dd_raw(),
								  mHardware.getY1__dd_raw(),
								  mHardware.getY2__dd_raw());
	mPhiK_d		= mSensorEval.calcPhi__d(mHardware.getPhi1__d_raw(),
										 mHardware.getPhi2__d_raw());
	mPhiR_d		= mSensorEval.calcPsi__d(mHardware.getPsi__d_raw());
	mPhiK 		= mCompFilter.calculatePhi(mPhiK, mPhiK_d);
	return std::abs(mPhiK) < Config::PhiBalanceMax;
}
void CControlActionHandler::controlIteration()
{
	mHardware.setTorque(mLQR.controlIteration(mPhiK, mPhiK_d, mPhiR_d));
}

void CControlActionHandler::getLogData()
{
	SProxy::getInstance().transmitVelocity(EComponentID::CONTROL_COMP, mPhiR_d);
	SProxy::getInstance().transmitAngle(EComponentID::CONTROL_COMP, mPhiK);
}

