/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestSTMSupportPackage_private.h
 *
 * Code generated for Simulink model 'TestSTMSupportPackage'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Jul 29 09:42:40 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestSTMSupportPackage_private_h_
#define RTW_HEADER_TestSTMSupportPackage_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void LED_CustomBlock_Outputs_wrapper(const boolean_T *ledState,
  const real_T *xD);
extern void LED_CustomBlock_Update_wrapper(const boolean_T *ledState,
  real_T *xD);

#endif                                 /* RTW_HEADER_TestSTMSupportPackage_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
