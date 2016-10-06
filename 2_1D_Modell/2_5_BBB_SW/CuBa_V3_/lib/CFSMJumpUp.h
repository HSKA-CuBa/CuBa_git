/**
 * @file	CFSMJumpUp.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef CFSMJUMPUP_H
#define CFSMJUMPUP_H
#include "CBasicFSM.h"

class CFSMJumpUp : public CBasicFSM
{
private:
	bool onInitial(CMessage& msg) override;
	bool onWaiting(CMessage& msg);
	bool onAccelerating(CMessage& msg);
	bool onBraking(CMessage& msg);
public:
	CFSMJumpUp() = default;
	CFSMJumpUp(const CFSMJumpUp&) = delete;
	CFSMJumpUp& operator=(const CFSMJumpUp&) = delete;
	~CFSMJumpUp() = default;
private:
	static constexpr StatePtr sInitial		= static_cast<StatePtr>(&CFSMJumpUp::onInitial);
	static constexpr StatePtr sWaiting		= static_cast<StatePtr>(&CFSMJumpUp::onWaiting);
	static constexpr StatePtr sAccelerating	= static_cast<StatePtr>(&CFSMJumpUp::onAccelerating);
	static constexpr StatePtr sBraking		= static_cast<StatePtr>(&CFSMJumpUp::onBraking);
};

#endif
