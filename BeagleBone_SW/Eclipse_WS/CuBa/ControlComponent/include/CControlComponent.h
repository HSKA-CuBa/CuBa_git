//12.9.16, Michael Meindl
#ifndef CCONTROLCOMPONENT_H
#define CCONTROLCOMPONENT_H
#include "AComponentBase.h"
#include "CBBBHardware.h"
#include "CSensorEvaluation.h"
#include "CComplementaryFilter.h"
#include "TKalmanFilter.h"
#include "CLQR.h"

class CControlComponent : public AComponentBase
{
public:
	void init() override;
	void run_V1_AusgleichsPolynomAccelerometer() override;
	void run_V2_OffsetGyroscope() override;
	void run_V3_AusgleichsPolynomMotorADC() override;
	void run_V4_FilterTest() override;
	void run_V5_BestimmungC_psi() override;
	void run_V6_BestimmungC_phi() override;
	void run_V7_RegelungTest() override;
private:
	void V1_AusgleichsPolynomAccelerometer();
	void V2_AusgleichsPolynomGyroscope();
public:
	CControlComponent(TQueue<Config::QueueSize>& rxQueue,
					  TQueue<Config::QueueSize>& txQueue);
	CControlComponent(const CControlComponent&) = delete;
	CControlComponent& operator=(const CControlComponent&) = delete;
	~CControlComponent() = default;
private:
	CBBBHardware mHardware;
	CSensorEvaluation mSensorEvaluation;
	CComplementaryFilter mComplementaryFilter;
	TKalmanFilter<ControlConfig::KalmanVarianceSize> mKalmanFilter;
	CLQR mLQR;
};

#endif
