/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V7___Aufspringen.c
 *
 * Code generated for Simulink model 'V7___Aufspringen'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sun Aug 28 14:40:47 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "V7___Aufspringen.h"
#include "V7___Aufspringen_private.h"
#include "V7___Aufspringen_dt.h"

/* Block signals (auto storage) */
B_V7___Aufspringen_T V7___Aufspringen_B;

/* Real-time model */
RT_MODEL_V7___Aufspringen_T V7___Aufspringen_M_;
RT_MODEL_V7___Aufspringen_T *const V7___Aufspringen_M = &V7___Aufspringen_M_;

/* Model step function */
void V7___Aufspringen_step(void)
{
  /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  if ((int32_T)V7___Aufspringen_P.Constant3_Value == 1) {
    V7___Aufspringen_B.MultiportSwitch1 = V7___Aufspringen_P.Constant4_Value;
  } else {
    V7___Aufspringen_B.MultiportSwitch1 = V7___Aufspringen_P.Constant5_Value;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch1' */

  /* S-Function (ServoBremse): '<Root>/S-Function Builder' */
  ServoBremse_Outputs_wrapper(&V7___Aufspringen_B.MultiportSwitch1 );

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   */
  if ((int32_T)V7___Aufspringen_P.Constant3_Value == 1) {
    V7___Aufspringen_B.MultiportSwitch = V7___Aufspringen_P.Constant_Value;
  } else {
    V7___Aufspringen_B.MultiportSwitch = V7___Aufspringen_P.Constant1_Value;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* S-Function (Motor): '<Root>/S-Function Builder1' */
  Motor_Outputs_wrapper(&V7___Aufspringen_B.MultiportSwitch,
                        &V7___Aufspringen_P.Constant2_Value );

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, V7___Aufspringen_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(V7___Aufspringen_M)!=-1) &&
        !((rtmGetTFinal(V7___Aufspringen_M)-V7___Aufspringen_M->Timing.taskTime0)
          > V7___Aufspringen_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(V7___Aufspringen_M, "Simulation finished");
    }

    if (rtmGetStopRequested(V7___Aufspringen_M)) {
      rtmSetErrorStatus(V7___Aufspringen_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++V7___Aufspringen_M->Timing.clockTick0)) {
    ++V7___Aufspringen_M->Timing.clockTickH0;
  }

  V7___Aufspringen_M->Timing.taskTime0 = V7___Aufspringen_M->Timing.clockTick0 *
    V7___Aufspringen_M->Timing.stepSize0 +
    V7___Aufspringen_M->Timing.clockTickH0 *
    V7___Aufspringen_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void V7___Aufspringen_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)V7___Aufspringen_M, 0,
                sizeof(RT_MODEL_V7___Aufspringen_T));
  rtmSetTFinal(V7___Aufspringen_M, -1);
  V7___Aufspringen_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  V7___Aufspringen_M->Sizes.checksums[0] = (591538933U);
  V7___Aufspringen_M->Sizes.checksums[1] = (3768879274U);
  V7___Aufspringen_M->Sizes.checksums[2] = (928544881U);
  V7___Aufspringen_M->Sizes.checksums[3] = (4121094942U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    V7___Aufspringen_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(V7___Aufspringen_M->extModeInfo,
      &V7___Aufspringen_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(V7___Aufspringen_M->extModeInfo,
                        V7___Aufspringen_M->Sizes.checksums);
    rteiSetTPtr(V7___Aufspringen_M->extModeInfo, rtmGetTPtr(V7___Aufspringen_M));
  }

  /* block I/O */
  (void) memset(((void *) &V7___Aufspringen_B), 0,
                sizeof(B_V7___Aufspringen_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    V7___Aufspringen_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }
}

/* Model terminate function */
void V7___Aufspringen_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
