//7.9.16, Michael Meindl
//Class-Declarations to control PWM-Outputs, the PWMs have to be enabled via the CapeMgr before execution
#ifndef CPWM_H
#define CPWM_H
#include "Global.h"

class CPWM
{
public:
	void setDutyCycle(float dutyCycle);	//DutyCycle in 0-100%
public:
	CPWM();
	CPWM(const CPWM&) = delete;
	CPWM& operator=(const CPWM&) = delete;
	~CPWM();
private:
	Int32 mFile;
	static constexpr float sPeriod = 20000000.0F;
};

#endif
