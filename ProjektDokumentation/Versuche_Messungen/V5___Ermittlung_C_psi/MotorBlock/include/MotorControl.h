// Michael Meindl, 8.8.2016
// Funktionen zum An- bzw. Ausschalten des Mtoors und setzten des Drehmoments
#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H
#include "Global.h"

void motorIteration(bool motorState, float* torquePtr);
UInt16 getMotorADCValue();

#endif
