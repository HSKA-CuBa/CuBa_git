/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V6___LQR_Regelung_data.c
 *
 * Code generated for Simulink model 'V6___LQR_Regelung'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Aug 26 09:20:35 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "V6___LQR_Regelung.h"
#include "V6___LQR_Regelung_private.h"

/* Block parameters (auto storage) */
P_V6___LQR_Regelung_T V6___LQR_Regelung_P = {
  /*  Variable: Kd
   * Referenced by: '<Root>/Gain3'
   */
  { -1.2143007872722522, -0.14984487258542348, -0.000412288804367589 },
  1017.0,                              /* Expression: 1017
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.02F,                               /* Expression: single(0.02)
                                        * Referenced by: '<Root>/S-Function Builder2'
                                        */
  0.11F,                               /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  -1.21430075F,                        /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -0.14984487F,                        /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  57.2958F,                            /* Computed Parameter: radtodeg1_Gain
                                        * Referenced by: '<Root>/radtodeg1'
                                        */
  1U,                                  /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/Sensor1'
                                        */
  1U,                                  /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/Sensor2'
                                        */
  33882U,                              /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  0,                                   /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
  0,                                   /* Expression: boolean(AD0PinLevel)
                                        * Referenced by: '<Root>/Sensor1'
                                        */
  1                                    /* Expression: boolean(AD0PinLevel)
                                        * Referenced by: '<Root>/Sensor2'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
