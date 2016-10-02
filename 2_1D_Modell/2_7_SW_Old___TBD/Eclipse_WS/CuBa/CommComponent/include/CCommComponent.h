//12.9.16, Michael Meindl
#ifndef CCOMMCOMPONENT_H
#define CCOMMCOMPOENTN_H
#include "AComponentBase.h"
#include "CServer.h"

class CCommComponent : public AComponentBase
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
public:
	CCommComponent(TQueue<Config::QueueSize>& rxQueue,
				   TQueue<Config::QueueSize>& txQueue);
private:
	CServer mServer;
};

#endif
