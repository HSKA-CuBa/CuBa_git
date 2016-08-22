/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestMotorBlock_private.h
 *
 * Code generated for Simulink model 'TestMotorBlock'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Aug 22 12:56:36 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestMotorBlock_private_h_
#define RTW_HEADER_TestMotorBlock_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void Motor_Outputs_wrapper(const boolean_T *EnableState,
  const real32_T *Torque,
  uint16_T *VelocityADCValue);

#endif                                 /* RTW_HEADER_TestMotorBlock_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
