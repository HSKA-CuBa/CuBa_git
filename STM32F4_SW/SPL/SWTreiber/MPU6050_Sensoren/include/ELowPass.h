// Autor: Michael Meindl
// Datum: 28.07.2016
// Enumeration fuer die moeglichen Tiefpass-Einstellungen der MPU6050 Sensoren
#ifndef ELOWPASS_H
#define ELOWPASS_H
#include "Global.h"

typedef enum UInt8
{
	BANDWIDTH_260 = 0,
	BANDWIDTH_184 = 1,
	BANDWIDTH_94  = 2,
	BANDWIDTH_44  = 3,
	BANDWIDTH_21  = 4,
	BANDWIDTH_10  = 5,
	BANDWIDTH_5   = 6
} ELowPass;


#endif
