/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V6___LQR_Regelung_private.h
 *
 * Code generated for Simulink model 'V6___LQR_Regelung'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sun Aug 28 12:47:02 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_V6___LQR_Regelung_private_h_
#define RTW_HEADER_V6___LQR_Regelung_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern void MPU6050_CustomBlock_Outputs_wrapper(int16_T *XAcceleration,
  int16_T *YAcceleration,
  int16_T *ZAcceleration,
  int16_T *XAngularVelocity,
  int16_T *YAngularVelocity,
  int16_T *ZAngularVelocity,
  const real_T *xD,
  const boolean_T *AD0PinLevel, const int_T p_width0,
  const uint32_T *LPBW, const int_T p_width1);
extern void MPU6050_CustomBlock_Update_wrapper(int16_T *XAcceleration,
  int16_T *YAcceleration,
  int16_T *ZAcceleration,
  int16_T *XAngularVelocity,
  int16_T *YAngularVelocity,
  int16_T *ZAngularVelocity,
  real_T *xD,
  const boolean_T *AD0PinLevel, const int_T p_width0,
  const uint32_T *LPBW, const int_T p_width1);
extern void SensorenFilter_Block_Outputs_wrapper(const int16_T *x1__dd,
  const int16_T *y1__dd,
  const int16_T *phi1__d,
  const int16_T *x2__dd,
  const int16_T *y2__dd,
  const int16_T *phi2__d,
  real32_T *phi__raw,
  real32_T *phi__comp,
  real32_T *phi__kalman,
  real32_T *phi__d,
  const real_T *xD,
  const real32_T *T_a, const int_T p_width0);
extern void SensorenFilter_Block_Update_wrapper(const int16_T *x1__dd,
  const int16_T *y1__dd,
  const int16_T *phi1__d,
  const int16_T *x2__dd,
  const int16_T *y2__dd,
  const int16_T *phi2__d,
  real32_T *phi__raw,
  real32_T *phi__comp,
  real32_T *phi__kalman,
  real32_T *phi__d,
  real_T *xD,
  const real32_T *T_a, const int_T p_width0);
extern void MotorADC_Outputs_wrapper(uint16_T *MotorADC);
extern void Motor_Outputs_wrapper(const boolean_T *EnableState,
  const real32_T *Torque);

#endif                                 /* RTW_HEADER_V6___LQR_Regelung_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
