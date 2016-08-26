//26.8.2016, Michael Meindl
//Class-Deklaration to calculate the current motor torque
#ifndef CLQR_H
#define CLQR_H
#include "Global.h"

class CLQR
{
public:
	float controlIteration(const float phi, const float phi__d, const float psi__d);
public:
	CLQR() = default;
	CLQR(const CLQR&) = delete;
	CLQR& operator=(const CLQR&) = delete;
	~CLQR() = default;
};

#endif
