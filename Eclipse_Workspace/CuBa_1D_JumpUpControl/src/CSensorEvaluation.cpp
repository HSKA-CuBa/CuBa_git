//26.8.2016, Michael Meindl
//Definitions to process the raw sensorvalues
#include "CSensorEvaluation.h"
#include "Config.h"
#include <cmath>

float CSensorEvaluation::calcPhi(Int16 x1__dd_raw, Int16 x2__dd_raw,
								 Int16 y1__dd_raw, Int16 y2__dd_raw)
{
	float x1__dd = static_cast<float>(x1__dd_raw) * Config::X1__dd_P1 + Config::X1__dd_P2;
	float x2__dd = static_cast<float>(x2__dd_raw) * Config::X2__dd_P1 + Config::X2__dd_P2;
	float y1__dd = static_cast<float>(y1__dd_raw) * Config::Y1__dd_P1 + Config::Y1__dd_P2;
	float y2__dd = static_cast<float>(y2__dd_raw) * Config::Y2__dd_P1 + Config::Y2__dd_P2;
	return -atan2f(x1__dd - (Config::SensorAlpha * x2__dd),
				   y1__dd - (Config::SensorAlpha * y2__dd));
}
float CSensorEvaluation::calcPhi__d(Int16 phi1__d_raw, Int16 phi2__d_raw)
{
	float phi1__d = Config::Phi1__d_P1 * (static_cast<float>(phi1__d_raw + Config::Phi1__d_P2));
	float phi2__d = Config::Phi2__d_P1 * (static_cast<float>(phi2__d_raw + Config::Phi2__d_P2));
	return (phi1__d + phi2__d) / 2.0F;
}
float CSensorEvaluation::calcPsi__d(Int16 psi__d_raw)
{
	return static_cast<float>(psi__d_raw) * Config::Psi__d_P1 + Config::Psi__d_P2;
}
