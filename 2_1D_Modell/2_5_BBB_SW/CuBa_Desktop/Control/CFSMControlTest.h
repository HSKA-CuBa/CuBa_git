/**
 * @file	CFSMControlTest.h
 * @author	Michael Meindl
 * @date	5.10.2016
 */
#ifndef CFSMCONTROLTEST_H
#define CFSMCONTROLTEST_H
#include "TFSMBase.h"
#include "CControlAction.h"

using CControlBase = TFSMBase<CControlAction>;

class CFSMControlTest : public CControlBase
{
protected:
	bool onInitial(CMessage& msg) override;
	bool onIdle(CMessage& msg);
	bool onBalancing(CMessage& msg);
public:
	CFSMControlTest() = default;
	CFSMControlTest(const CFSMControlTest&) = delete;
	CFSMControlTest& operator=(const CFSMControlTest&) = delete;
	~CFSMControlTest() = default;
private:
	static constexpr StatePtr sIdle =
			static_cast<StatePtr>(&CFSMControlTest::onIdle);
	static constexpr StatePtr sBalancing =
			static_cast<StatePtr>(&CFSMControlTest::onBalancing);
};

#endif
