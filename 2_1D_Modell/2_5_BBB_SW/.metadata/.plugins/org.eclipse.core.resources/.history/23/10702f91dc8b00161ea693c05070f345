/**
 * @file	CControlFSM.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef CCONTROLFSM_H
#define CCONTROLFSM_H
#include "CBasicFSM.h"
#include "CFSMCuBa.h"
#include "CFSMExperiment6.h"
#include "CFSMExperiment7.h"

class CControlFSM : public CBasicFSM
{
private:
	bool dispatch(CMessage& msg);
	bool onInitial(CMessage& msg) override;
	bool onStandby(CMessage& msg);
	bool onExperiment1(CMessage& msg);
	bool onExperiment2(CMessage& msg);
	bool onExperiment3(CMessage& msg);
	bool onExperiment4(CMessage& msg);
	bool onExperiment5(CMessage& msg);
	bool onExperiment6(CMessage& msg);
	bool onExperiment7(CMessage& msg);
	bool onCuBa(CMessage& msg);
public:
	CControlFSM();
	CControlFSM(const CControlFSM&) = delete;
	CControlFSM& operator=(const CControlFSM) = delete;
	~CControlFSM() = default;
private:
	static constexpr StatePtr sInitial 		= static_cast<StatePtr>(&CControlFSM::onInitial);
	static constexpr StatePtr sStandby		= static_cast<StatePtr>(&CControlFSM::onStandby);
	static constexpr StatePtr sExperiment1	= static_cast<StatePtr>(&CControlFSM::onExperiment1);
	static constexpr StatePtr sExperiment2  = static_cast<StatePtr>(&CControlFSM::onExperiment2);
	static constexpr StatePtr sExperiment3  = static_cast<StatePtr>(&CControlFSM::onExperiment3);
	static constexpr StatePtr sExperiment4  = static_cast<StatePtr>(&CControlFSM::onExperiment4);
	static constexpr StatePtr sExperiment5  = static_cast<StatePtr>(&CControlFSM::onExperiment5);
	static constexpr StatePtr sExperiment6  = static_cast<StatePtr>(&CControlFSM::onExperiment6);
	static constexpr StatePtr sExperiment7 	= static_cast<StatePtr>(&CControlFSM::onExperiment7);
	static constexpr StatePtr sCuBa		  	= static_cast<StatePtr>(&CControlFSM::onCuBa);
	CFSMCuBa mSuperStateCuBa;
	CFSMExperiment6 mSuperStateExperiment6;
	CFSMExperiment7 mSuperStateExperiment7;
};

#endif
