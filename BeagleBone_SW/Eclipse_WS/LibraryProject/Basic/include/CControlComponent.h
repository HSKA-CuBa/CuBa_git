//12.9.16, Michael Meindl
#ifndef CCONTROLCOMPONENT_H
#define CCONTROLCOMPONENT_H
#include "AComponentBase.h"
#include "CBBBHardware.h"

class CControlComponent : public AComponentBase
{
public:
	void init() override;
	void run() override;
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
};

#endif
