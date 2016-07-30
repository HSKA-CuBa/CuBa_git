/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SingleBlockSensoren_private.h
 *
 * Code generated for Simulink model 'SingleBlockSensoren'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sat Jul 30 09:46:21 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SingleBlockSensoren_private_h_
#define RTW_HEADER_SingleBlockSensoren_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void Sensoren_CustomBlock_Outputs_wrapper(int16_T *XAcceleration,
  int16_T *ZAngularVelocity,
  const real_T *xD,
  const uint32_T *LPBW, const int_T p_width0);
extern void Sensoren_CustomBlock_Update_wrapper(int16_T *XAcceleration,
  int16_T *ZAngularVelocity,
  real_T *xD,
  const uint32_T *LPBW, const int_T p_width0);

#endif                                 /* RTW_HEADER_SingleBlockSensoren_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
