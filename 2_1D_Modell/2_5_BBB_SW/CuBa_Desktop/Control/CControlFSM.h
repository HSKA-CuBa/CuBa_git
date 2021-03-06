/**
 * @file	CControlFSM.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CCONTROLFSM_H
#define CCONTROLFSM_H
#include "TFSMBase.h"
#include "CControlAction.h"
#include "CFSMControlTest.h"
#include "CFSMJump.h"

using CControlBase = TFSMBase<CControlAction>;

class CControlFSM : public CControlBase
{
public:
	bool dispatch(CMessage& msg);
	bool onInitial(CMessage& msg) override;
	bool onStandby(CMessage& msg);
	bool onSensorMeasurement(CMessage& msg);
	bool onADCMeasurement(CMessage& msg);
	bool onCPsiIdentification(CMessage& msg);
	bool onCPhiIdentification(CMessage& msg);
	bool onControlTest(CMessage& msg);
	bool onJumpTest(CMessage& msg);
public:
	CControlFSM() = default;
	CControlFSM(const CControlFSM&) = delete;
	CControlFSM& operator&(const CControlFSM&) = delete;
	~CControlFSM() = default;
private:
	static constexpr StatePtr sStandby =
			static_cast<StatePtr>(&CControlFSM::onStandby);
	static constexpr StatePtr sSensorMeasurement =
			static_cast<StatePtr>(&CControlFSM::onSensorMeasurement);
	static constexpr StatePtr sADCMeasurement =
			static_cast<StatePtr>(&CControlFSM::onADCMeasurement);
	static constexpr StatePtr sCPsiIdentification =
			static_cast<StatePtr>(&CControlFSM::onCPsiIdentification);
	static constexpr StatePtr sCPhiIdentification =
			static_cast<StatePtr>(&CControlFSM::onCPhiIdentification);
	static constexpr StatePtr sControlTest =
			static_cast<StatePtr>(&CControlFSM::onControlTest);
	static constexpr StatePtr sJumpTest =
			static_cast<StatePtr>(&CControlFSM::onJumpTest);
	CFSMControlTest mSuperstateControlTest;
	CFSMJump mSuperstateJump;
};

#endif
