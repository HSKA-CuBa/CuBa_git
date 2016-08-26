/*
 * TestFilter_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TestFilter".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Wed Aug 24 18:27:22 2016
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
  2*sizeof(uint32_T)
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
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&TestFilter_B.SFunctionBuilder_o1), 1, 0, 7 },

  { (char_T *)(&TestFilter_B.Sensor1_o1), 4, 0, 12 }
  ,

  { (char_T *)(&TestFilter_DW.Sensor1_DSTATE), 0, 0, 3 },

  { (char_T *)(&TestFilter_DW.Scope1_PWORK.LoggedData[0]), 11, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&TestFilter_P.SFunctionBuilder_P1), 1, 0, 4 },

  { (char_T *)(&TestFilter_P.Sensor1_P2), 7, 0, 2 },

  { (char_T *)(&TestFilter_P.Sensor1_P1), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] TestFilter_dt.h */
