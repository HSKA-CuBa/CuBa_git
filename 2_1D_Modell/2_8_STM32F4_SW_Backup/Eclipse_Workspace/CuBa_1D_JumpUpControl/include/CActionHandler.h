//27.8.2016, Michael Meindl
//class to carry out the actions of the FSM
#ifndef CACTIONHANDLER_H
#define CACTIONHANDLER_H
#include "Global.h"
#include "IHardware.h"
#include "CSensorEvaluation.h"
#include "CLQR.h"
#include "TKalmanFilter.h"
#include "CComplementaryFilter.h"
#include "EEvent.h"

class CActionHandler
{
public:
	void onEntryIdle();
	void onExitIdle();
	void onEntryJumpUp();
	void onExitJumpUp();
	void onEntryBalance();
	void onExitBalance();
	EEvent onStateJumpUp();
	EEvent onStateIdle();
	EEvent onStateBalance();
public:
	CActionHandler(IHardware& hw);
	CActionHandler(const CActionHandler&) = delete;
	CActionHandler& operator=(const CActionHandler&) = delete;
	~CActionHandler() = default;
private:
	IHardware& mHardware;
	CSensorEvaluation mSensorEval;
	CLQR mLQR;
	CComplementaryFilter mCompFilter;
	TKalmanFilter<Config::KalmanVarianceSize> mKalmanFilter;
};

#endif
