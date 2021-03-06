//26.8.2016, Michael Meindl
//Class-declaration to calculate the current motor torque
#ifndef CLQR_H
#define CLQR_H
#include "Global.h"

class CLQR
{
public:
	Float32 controlIteration(const Float32 phi, const Float32 phi__d, const Float32 psi__d);
public:
	CLQR() = default;
	CLQR(const CLQR&) = delete;
	CLQR& operator=(const CLQR&) = delete;
	~CLQR() = default;
};

#endif
