/**
 * @file	CFSMExperiment7.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CFSMEXPERIMENT7
#define CFSMEXPERIMENT7
#include "CBasicFSM.h"

class CFSMExperiment7 : public CBasicFSM
{
public:
	bool onInitial(CMessage& msg) override;
	bool onWaiting(CMessage& msg);
	bool onAccelerating(CMessage& msg);
	bool onBraking(CMessage& msg);
public:
	CFSMExperiment7() = default;
	CFSMExperiment7(const CFSMExperiment7&) = delete;
	CFSMExperiment7& operator=(const CFSMExperiment7&) = delete;
	~CFSMExperiment7() = default;
private:
	static constexpr StatePtr sInitial 		= static_cast<StatePtr>(&CFSMExperiment7::onInitial);
	static constexpr StatePtr sWaiting		= static_cast<StatePtr>(&CFSMExperiment7::onWaiting);
	static constexpr StatePtr sAccelerating = static_cast<StatePtr>(&CFSMExperiment7::onAccelerating);
	static constexpr StatePtr sBraking 		= static_cast<StatePtr>(&CFSMExperiment7::onBraking);
};

#endif
