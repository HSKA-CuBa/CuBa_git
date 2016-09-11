/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V3_AusgleichsPolynomPsi__d.c
 *
 * Code generated for Simulink model 'V3_AusgleichsPolynomPsi__d'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Sep 05 17:01:56 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "V3_AusgleichsPolynomPsi__d.h"
#include "V3_AusgleichsPolynomPsi__d_private.h"
#include "V3_AusgleichsPolynomPsi__d_dt.h"

/* Block signals (auto storage) */
B_V3_AusgleichsPolynomPsi__d_T V3_AusgleichsPolynomPsi__d_B;

/* Block states (auto storage) */
DW_V3_AusgleichsPolynomPsi__d_T V3_AusgleichsPolynomPsi__d_DW;

/* Real-time model */
RT_MODEL_V3_AusgleichsPolynom_T V3_AusgleichsPolynomPsi__d_M_;
RT_MODEL_V3_AusgleichsPolynom_T *const V3_AusgleichsPolynomPsi__d_M =
  &V3_AusgleichsPolynomPsi__d_M_;

/* Model step function */
void V3_AusgleichsPolynomPsi__d_step(void)
{
  /* S-Function (Motor): '<Root>/S-Function Builder' */
  Motor_Outputs_wrapper(&V3_AusgleichsPolynomPsi__d_P.Constant_Value,
                        &V3_AusgleichsPolynomPsi__d_P.Constant1_Value );

  /* S-Function (MotorADC): '<Root>/S-Function Builder1' */
  MotorADC_Outputs_wrapper( &V3_AusgleichsPolynomPsi__d_B.SFunctionBuilder1 );

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, V3_AusgleichsPolynomPsi__d_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(V3_AusgleichsPolynomPsi__d_M)!=-1) &&
        !((rtmGetTFinal(V3_AusgleichsPolynomPsi__d_M)-
           V3_AusgleichsPolynomPsi__d_M->Timing.taskTime0) >
          V3_AusgleichsPolynomPsi__d_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(V3_AusgleichsPolynomPsi__d_M, "Simulation finished");
    }

    if (rtmGetStopRequested(V3_AusgleichsPolynomPsi__d_M)) {
      rtmSetErrorStatus(V3_AusgleichsPolynomPsi__d_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  V3_AusgleichsPolynomPsi__d_M->Timing.taskTime0 =
    (++V3_AusgleichsPolynomPsi__d_M->Timing.clockTick0) *
    V3_AusgleichsPolynomPsi__d_M->Timing.stepSize0;
}

/* Model initialize function */
void V3_AusgleichsPolynomPsi__d_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)V3_AusgleichsPolynomPsi__d_M, 0,
                sizeof(RT_MODEL_V3_AusgleichsPolynom_T));
  rtmSetTFinal(V3_AusgleichsPolynomPsi__d_M, 10.0);
  V3_AusgleichsPolynomPsi__d_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  V3_AusgleichsPolynomPsi__d_M->Sizes.checksums[0] = (53785334U);
  V3_AusgleichsPolynomPsi__d_M->Sizes.checksums[1] = (2788412469U);
  V3_AusgleichsPolynomPsi__d_M->Sizes.checksums[2] = (2347852118U);
  V3_AusgleichsPolynomPsi__d_M->Sizes.checksums[3] = (2233727977U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    V3_AusgleichsPolynomPsi__d_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(V3_AusgleichsPolynomPsi__d_M->extModeInfo,
      &V3_AusgleichsPolynomPsi__d_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(V3_AusgleichsPolynomPsi__d_M->extModeInfo,
                        V3_AusgleichsPolynomPsi__d_M->Sizes.checksums);
    rteiSetTPtr(V3_AusgleichsPolynomPsi__d_M->extModeInfo, rtmGetTPtr
                (V3_AusgleichsPolynomPsi__d_M));
  }

  /* block I/O */
  (void) memset(((void *) &V3_AusgleichsPolynomPsi__d_B), 0,
                sizeof(B_V3_AusgleichsPolynomPsi__d_T));

  /* states (dwork) */
  (void) memset((void *)&V3_AusgleichsPolynomPsi__d_DW, 0,
                sizeof(DW_V3_AusgleichsPolynomPsi__d_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    V3_AusgleichsPolynomPsi__d_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void V3_AusgleichsPolynomPsi__d_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
