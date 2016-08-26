/*
 * V6___LQR_Regelung_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "V6___LQR_Regelung".
 *
 * Model version              : 1.15
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Fri Aug 26 09:20:35 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(uint16_T),
  sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "uint16_T",
  "uint32_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&V6___LQR_Regelung_B.SFunctionBuilder2_o1), 1, 0, 6 },

  { (char_T *)(&V6___LQR_Regelung_B.Sensor1_o1), 4, 0, 12 },

  { (char_T *)(&V6___LQR_Regelung_B.SFunctionBuilder1), 5, 0, 1 }
  ,

  { (char_T *)(&V6___LQR_Regelung_DW.Sensor1_DSTATE), 0, 0, 3 },

  { (char_T *)(&V6___LQR_Regelung_DW.Scope1_PWORK.LoggedData), 11, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&V6___LQR_Regelung_P.Kd[0]), 0, 0, 4 },

  { (char_T *)(&V6___LQR_Regelung_P.SFunctionBuilder2_P1), 1, 0, 5 },

  { (char_T *)(&V6___LQR_Regelung_P.Sensor1_P2), 7, 0, 2 },

  { (char_T *)(&V6___LQR_Regelung_P.Gain_Gain), 14, 0, 1 },

  { (char_T *)(&V6___LQR_Regelung_P.Constant_Value), 8, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] V6___LQR_Regelung_dt.h */
