//28.8.9, Michael Meindl
#include "ControlConfig.h"
#include "CLQR.h"

float CLQR::controlIteration(const float phi, const float phi__d, const float psi__d)
{
	return (ControlConfig::K_phi * (phi - ControlConfig::PhiBalanceOffset)) +
		   (ControlConfig::K_phi__d * phi__d) +
		   (ControlConfig::K_psi__d * psi__d);
}
