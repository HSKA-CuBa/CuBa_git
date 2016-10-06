/**
 * @file	CFSMExperiment6.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CFSMEXPERIMENT6_H
#define CFSMEXPERIMENT6_H
#include "CBasicFSM.h"

class CFSMExperiment6 : public CBasicFSM
{
public:
	bool onInitial(CMessage& msg) override;
	bool onIdle(CMessage& msg);
	bool onBalancing(CMessage& msg);
public:
	CFSMExperiment6() = default;
	CFSMExperiment6(const CFSMExperiment6&) = delete;
	CFSMExperiment6& operator=(const CFSMExperiment6&) = delete;
	~CFSMExperiment6() = default;
private:
	static constexpr StatePtr sInitial   = static_cast<StatePtr>(&CFSMExperiment6::onInitial);
	static constexpr StatePtr sIdle 	 = static_cast<StatePtr>(&CFSMExperiment6::onIdle);
	static constexpr StatePtr sBalancing = static_cast<StatePtr>(&CFSMExperiment6::onBalancing);
};

#endif
