/**
 * @file	CFSMJump.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CFSMJUMP_H
#define CFSMJUMP_H
#include "TFSMBase.h"
#include "CControlAction.h"

using CControlBase = TFSMBase<CControlAction>;

class CFSMJump : public CControlBase
{
public:
	bool onInitial(CMessage& msg) override;
	bool onWaiting(CMessage& msg);
	bool onAccelerating(CMessage& msg);
	bool onBraking(CMessage& msg);
public:
	CFSMJump() = default;
	CFSMJump(const CFSMJump&) = delete;
	CFSMJump& operator=(const CFSMJump&) = delete;
	~CFSMJump() = default;
private:
	static constexpr StatePtr sWaiting =
			static_cast<StatePtr>(&CFSMJump::onWaiting);
	static constexpr StatePtr sAccelerating =
			static_cast<StatePtr>(&CFSMJump::onAccelerating);
	static constexpr StatePtr sBraking =
			static_cast<StatePtr>(&CFSMJump::onBraking);
};

#endif
