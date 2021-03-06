//26.8.2016, Michael Meindl
//Definitions in order to calculate the current motor torque
#include "CLQR.h"
#include "Config.h"

float CLQR::controlIteration(const float phi, const float phi__d, const float psi__d)
{
	return (Config::K_phi * (phi - Config::PhiBalanceOffset)) +
		   (Config::K_phi__d * phi__d) +
		   (Config::K_psi__d * psi__d);
}
