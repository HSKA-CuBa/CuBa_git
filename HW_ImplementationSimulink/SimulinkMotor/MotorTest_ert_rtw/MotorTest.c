/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MotorTest.c
 *
 * Code generated for Simulink model 'MotorTest'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Aug 29 09:57:17 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorTest.h"
#include "MotorTest_private.h"
#include "MotorTest_dt.h"

/* Block signals (auto storage) */
B_MotorTest_T MotorTest_B;

/* Block states (auto storage) */
DW_MotorTest_T MotorTest_DW;

/* Real-time model */
RT_MODEL_MotorTest_T MotorTest_M_;
RT_MODEL_MotorTest_T *const MotorTest_M = &MotorTest_M_;

/* Model step function */
void MotorTest_step(void)
{
  /* S-Function (MotorADC): '<Root>/S-Function Builder1' */
  MotorADC_Outputs_wrapper( &MotorTest_B.SFunctionBuilder1 );

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Gain: '<Root>/Gain'
   */
  MotorTest_B.Add = MotorTest_P.Constant2_Value - (real_T)((uint32_T)
    MotorTest_P.Gain_Gain * MotorTest_B.SFunctionBuilder1) * 1.52587890625E-5;

  /* S-Function (Motor): '<Root>/S-Function Builder' */
  Motor_Outputs_wrapper(&MotorTest_P.Constant_Value,
                        &MotorTest_P.Constant1_Value );

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, MotorTest_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(MotorTest_M)!=-1) &&
        !((rtmGetTFinal(MotorTest_M)-MotorTest_M->Timing.taskTime0) >
          MotorTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(MotorTest_M, "Simulation finished");
    }

    if (rtmGetStopRequested(MotorTest_M)) {
      rtmSetErrorStatus(MotorTest_M, "Simulation finished");
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
  if (!(++MotorTest_M->Timing.clockTick0)) {
    ++MotorTest_M->Timing.clockTickH0;
  }

  MotorTest_M->Timing.taskTime0 = MotorTest_M->Timing.clockTick0 *
    MotorTest_M->Timing.stepSize0 + MotorTest_M->Timing.clockTickH0 *
    MotorTest_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void MotorTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)MotorTest_M, 0,
                sizeof(RT_MODEL_MotorTest_T));
  rtmSetTFinal(MotorTest_M, -1);
  MotorTest_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  MotorTest_M->Sizes.checksums[0] = (923569970U);
  MotorTest_M->Sizes.checksums[1] = (529230976U);
  MotorTest_M->Sizes.checksums[2] = (1293867602U);
  MotorTest_M->Sizes.checksums[3] = (2484971821U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    MotorTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MotorTest_M->extModeInfo,
      &MotorTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MotorTest_M->extModeInfo, MotorTest_M->Sizes.checksums);
    rteiSetTPtr(MotorTest_M->extModeInfo, rtmGetTPtr(MotorTest_M));
  }

  /* block I/O */
  (void) memset(((void *) &MotorTest_B), 0,
                sizeof(B_MotorTest_T));

  /* states (dwork) */
  (void) memset((void *)&MotorTest_DW, 0,
                sizeof(DW_MotorTest_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    MotorTest_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }
}

/* Model terminate function */
void MotorTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
