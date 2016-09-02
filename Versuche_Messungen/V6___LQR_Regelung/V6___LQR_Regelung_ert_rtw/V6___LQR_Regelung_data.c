/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V6___LQR_Regelung_data.c
 *
 * Code generated for Simulink model 'V6___LQR_Regelung'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Sep 02 13:21:06 2016
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
  { -0.88214609589243231, -0.13864179610495247, -0.00022760770893999778 },
  0.2618F,                             /* Mask Parameter: BalanceArea_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  1017.0,                              /* Expression: 1017
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/phi_COG_Offset1'
                                        */
  0.127F,                              /* Computed Parameter: phi_COG_Offset_Value
                                        * Referenced by: '<Root>/phi_COG_Offset'
                                        */
  0.02F,                               /* Expression: single(0.02)
                                        * Referenced by: '<Root>/S-Function Builder2'
                                        */
  -0.88214612F,                        /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -0.13864179F,                        /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  57.2958F,                            /* Computed Parameter: radtodeg3_Gain
                                        * Referenced by: '<Root>/radtodeg3'
                                        */
  57.2958F,                            /* Computed Parameter: radtodeg2_Gain
                                        * Referenced by: '<Root>/radtodeg2'
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
