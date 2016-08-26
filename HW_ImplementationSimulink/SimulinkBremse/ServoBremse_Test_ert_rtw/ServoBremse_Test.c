/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ServoBremse_Test.c
 *
 * Code generated for Simulink model 'ServoBremse_Test'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Aug 24 16:33:55 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ServoBremse_Test.h"
#include "ServoBremse_Test_private.h"
#include "ServoBremse_Test_dt.h"

/* Real-time model */
RT_MODEL_ServoBremse_Test_T ServoBremse_Test_M_;
RT_MODEL_ServoBremse_Test_T *const ServoBremse_Test_M = &ServoBremse_Test_M_;

/* Model step function */
void ServoBremse_Test_step(void)
{
  /* S-Function (ServoBremse): '<Root>/S-Function Builder' */
  ServoBremse_Outputs_wrapper(&ServoBremse_Test_P.Constant_Value );

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, ServoBremse_Test_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(ServoBremse_Test_M)!=-1) &&
        !((rtmGetTFinal(ServoBremse_Test_M)-ServoBremse_Test_M->Timing.taskTime0)
          > ServoBremse_Test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ServoBremse_Test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ServoBremse_Test_M)) {
      rtmSetErrorStatus(ServoBremse_Test_M, "Simulation finished");
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
  if (!(++ServoBremse_Test_M->Timing.clockTick0)) {
    ++ServoBremse_Test_M->Timing.clockTickH0;
  }

  ServoBremse_Test_M->Timing.taskTime0 = ServoBremse_Test_M->Timing.clockTick0 *
    ServoBremse_Test_M->Timing.stepSize0 +
    ServoBremse_Test_M->Timing.clockTickH0 *
    ServoBremse_Test_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void ServoBremse_Test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ServoBremse_Test_M, 0,
                sizeof(RT_MODEL_ServoBremse_Test_T));
  rtmSetTFinal(ServoBremse_Test_M, -1);
  ServoBremse_Test_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ServoBremse_Test_M->Sizes.checksums[0] = (3874650348U);
  ServoBremse_Test_M->Sizes.checksums[1] = (2683463414U);
  ServoBremse_Test_M->Sizes.checksums[2] = (3817676167U);
  ServoBremse_Test_M->Sizes.checksums[3] = (159563753U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ServoBremse_Test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ServoBremse_Test_M->extModeInfo,
      &ServoBremse_Test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ServoBremse_Test_M->extModeInfo,
                        ServoBremse_Test_M->Sizes.checksums);
    rteiSetTPtr(ServoBremse_Test_M->extModeInfo, rtmGetTPtr(ServoBremse_Test_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ServoBremse_Test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }
}

/* Model terminate function */
void ServoBremse_Test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
