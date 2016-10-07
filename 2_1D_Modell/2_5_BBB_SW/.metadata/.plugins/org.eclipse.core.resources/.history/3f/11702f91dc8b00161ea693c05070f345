/**
 * @file	CFSMCuBa.h
 * @author	Michael Meindl
 * @date	4.10.2016
 */
#ifndef CFSMCUBA_H
#define CFSMCUBA_H
#include "CBasicFSM.h"
#include "CFSMJumpUp.h"

class CFSMCuBa : public CBasicFSM
{
private:
	bool onInitial(CMessage& msg) override;
	bool onIdle(CMessage& msg);
	bool onBalancing(CMessage& msg);
	bool onJumpUp(CMessage& msg);
public:
	CFSMCuBa() = default;
	CFSMCuBa(const CFSMCuBa&) = delete;
	CFSMCuBa& operator=(const CFSMCuBa&) = delete;
	~CFSMCuBa() = default;
private:
	static constexpr StatePtr sInitial 		= static_cast<StatePtr>(&CFSMCuBa::onInitial);
	static constexpr StatePtr sIdle 		= static_cast<StatePtr>(&CFSMCuBa::onIdle);
	static constexpr StatePtr sBalancing	= static_cast<StatePtr>(&CFSMCuBa::onBalancing);
	static constexpr StatePtr sJumpUp		= static_cast<StatePtr>(&CFSMCuBa::onJumpUp);
	CFSMJumpUp mSuperStateJumpUp;
};

#endif
