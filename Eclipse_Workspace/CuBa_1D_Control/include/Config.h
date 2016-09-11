//26.8.2016, Michael Meindl
//File to define basic values and constants
#ifndef CONFIG_H
#define CONFIG_H
#include "Global.h"

namespace Config
{
	constexpr float T_a						= 0.020F;
	constexpr float K_phi					= 0.8821F;
	constexpr float K_phi__d				= 0.1386F;
	constexpr float K_psi__d				= 0.0002F;
	constexpr float ComplementaryAlpha		= 0.98F;
	constexpr float X1__dd_P1				= -0.0006082F;
	constexpr float X1__dd_P2				= 0.4412F;
	constexpr float X2__dd_P1				= -0.000607F;
	constexpr float X2__dd_P2				= 0.2804F;
	constexpr float Y1__dd_P1				= -0.0006064F;
	constexpr float Y1__dd_P2				= 0.1248F;
	constexpr float Y2__dd_P1			    = -0.0006089F;
	constexpr float Y2__dd_P2				= 0.09182F;
	constexpr float Phi1__d_P1				= -0.0076F;
	constexpr Int16 Phi1__d_P2				= 89;
	constexpr float Phi2__d_P1				= -0.0076F;
	constexpr Int16 Phi2__d_P2				= 889;
	constexpr float Psi__d_P1				= -0.5176F;
	constexpr float Psi__d_P2				= 1017.0F;
	constexpr float R_S1					= 0.14F;
	constexpr float R_S2					= 0.061F;
	constexpr float SensorAlpha				= R_S1 / R_S2;
	constexpr UInt32 KalmanVarianceSize		= 7U;
	constexpr float PhiBalanceOffset		= 0.1F;
	constexpr float PhiBalanceMax			= 0.3F;
	constexpr float PhiResting				= 0.6981F;
	constexpr float Psi__d_JumpValue		= 380.0F;
	constexpr float Psi__d_Resting			= 20.0F;
	constexpr float Torque_JumpUp			= 0.01F;
}

#endif
