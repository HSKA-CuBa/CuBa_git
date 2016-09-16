//13.9.2016, Michael Meindl
#ifndef CONTROLCONFIG_H
#define CONTROLCONFIG_H
#include "Global.h"

///Namespace to hold defines required for the control system.
namespace ControlConfig
{
	constexpr Float32 T_a				= 0.02F;
	constexpr Float32 K_phi				= 1.0F;		//TODO: K_phi
	constexpr Float32 K_phi__d			= 1.0F;		//TODO: K_phi__d
	constexpr Float32 K_psi__d			= 1.0F; 	//TODO: K_psi__d
	constexpr Float32 CompAlpha			= 0.98F;
	constexpr Float32 X1__dd_P1			= 1.0F;		//TODO: X1__dd_P1
	constexpr Float32 X1__dd_P2 		= 1.0F;		//TODO: X1__dd_P2
	constexpr Float32 X2__dd_P1			= 1.0F;		//TODO: X2__dd_P1
	constexpr Float32 X2__dd_P2			= 1.0F;		//TODO: X2__dd_P2
	constexpr Float32 Y1__dd_P1			= 1.0F; 	//TODO: Y1__dd_P1
	constexpr Float32 Y1__dd_P2			= 1.0F; 	//TODO: Y1__dd_P2
	constexpr Float32 Y2__dd_P1 		= 1.0F; 	//TODO: Y2__dd_P1
	constexpr Float32 Y2__dd_P2			= 1.0F; 	//TODO: Y2__dd_P2
	constexpr Float32 Phi1__d_P1		= 1.0F; 	//TODO: Phi1__d_P1
	constexpr Float32 Phi1__d_P2		= 1.0F; 	//TODO: Phi1__d_P2
	constexpr Float32 Phi2__d_P1		= 1.0F; 	//TODO: Phi2__d_P1
	constexpr Float32 Phi2__d_P2		= 1.0F;		//TODO: Phi2__d_P2
	constexpr Float32 Psi__d_P1			= 1.0F; 	//TODO: Psi__d_P1
	constexpr Float32 Psi__d_P2			= 1.0F; 	//TODO: Psi__d_P2
	constexpr Float32 R_S1				= 5.0F; 	//TODO: R_S1
	constexpr Float32 R_S2				= 1.0F; 	//TODO: R_S2
	constexpr Float32 SensorAlpha		= R_S1 / R_S2;
	constexpr UInt32 KalmanVarianceSize = 7U;
	constexpr Float32 PhiBalanceOffset	= 0.1F;
	constexpr Float32 PhiBalanceMax		= 0.3F;
	constexpr Float32 Psi__d_JumpValue  = 380.0F;
	constexpr Float32 Psi__d_Resting	= 20.0F;
	constexpr Float32 Torque_JumpUp		= 0.01F;
	constexpr Float32 DegToRad			= 0.0175F;
	constexpr Float32 RadtoDeg 			= 1/DegToRad;
}

#endif
