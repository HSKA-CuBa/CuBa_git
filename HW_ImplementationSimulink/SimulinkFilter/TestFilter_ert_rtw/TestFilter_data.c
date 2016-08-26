/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestFilter_data.c
 *
 * Code generated for Simulink model 'TestFilter'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Aug 24 18:27:22 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestFilter.h"
#include "TestFilter_private.h"

/* Block parameters (auto storage) */
P_TestFilter_T TestFilter_P = {
  0.02F,                               /* Expression: single(0.02)
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  57.2958F,                            /* Computed Parameter: radtodeg_Gain
                                        * Referenced by: '<Root>/radtodeg'
                                        */
  57.2958F,                            /* Computed Parameter: radtodeg1_Gain
                                        * Referenced by: '<Root>/radtodeg1'
                                        */
  57.2958F,                            /* Computed Parameter: radtodeg2_Gain
                                        * Referenced by: '<Root>/radtodeg2'
                                        */
  1U,                                  /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/Sensor1'
                                        */
  1U,                                  /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/Sensor2'
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
