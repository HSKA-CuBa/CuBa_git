/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V5_C_psi.c
 *
 * Code generated for Simulink model 'V5_C_psi'.
 *
 * Model version                  : 1.46
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Aug 22 14:58:28 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "V5_C_psi.h"
#include "V5_C_psi_private.h"
#include "V5_C_psi_dt.h"

/* Block signals (auto storage) */
B_V5_C_psi_T V5_C_psi_B;

/* Block states (auto storage) */
DW_V5_C_psi_T V5_C_psi_DW;

/* Real-time model */
RT_MODEL_V5_C_psi_T V5_C_psi_M_;
RT_MODEL_V5_C_psi_T *const V5_C_psi_M = &V5_C_psi_M_;

/* Model step function */
void V5_C_psi_step(void)
{
  /* S-Function (Motor): '<Root>/S-Function Builder' */
  Motor_Outputs_wrapper(&V5_C_psi_P.Constant_Value, &V5_C_psi_P.Constant1_Value,
                        &V5_C_psi_B.SFunctionBuilder );

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, V5_C_psi_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(V5_C_psi_M)!=-1) &&
        !((rtmGetTFinal(V5_C_psi_M)-V5_C_psi_M->Timing.taskTime0) >
          V5_C_psi_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(V5_C_psi_M, "Simulation finished");
    }

    if (rtmGetStopRequested(V5_C_psi_M)) {
      rtmSetErrorStatus(V5_C_psi_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  V5_C_psi_M->Timing.taskTime0 =
    (++V5_C_psi_M->Timing.clockTick0) * V5_C_psi_M->Timing.stepSize0;
}

/* Model initialize function */
void V5_C_psi_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)V5_C_psi_M, 0,
                sizeof(RT_MODEL_V5_C_psi_T));
  rtmSetTFinal(V5_C_psi_M, -1);
  V5_C_psi_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  V5_C_psi_M->Sizes.checksums[0] = (1326540792U);
  V5_C_psi_M->Sizes.checksums[1] = (1457656267U);
  V5_C_psi_M->Sizes.checksums[2] = (1430955655U);
  V5_C_psi_M->Sizes.checksums[3] = (2248274108U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    V5_C_psi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(V5_C_psi_M->extModeInfo,
      &V5_C_psi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(V5_C_psi_M->extModeInfo, V5_C_psi_M->Sizes.checksums);
    rteiSetTPtr(V5_C_psi_M->extModeInfo, rtmGetTPtr(V5_C_psi_M));
  }

  /* block I/O */
  (void) memset(((void *) &V5_C_psi_B), 0,
                sizeof(B_V5_C_psi_T));

  /* states (dwork) */
  (void) memset((void *)&V5_C_psi_DW, 0,
                sizeof(DW_V5_C_psi_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    V5_C_psi_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void V5_C_psi_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
