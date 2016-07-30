/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SingleBlockSensoren.c
 *
 * Code generated for Simulink model 'SingleBlockSensoren'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sat Jul 30 09:46:21 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SingleBlockSensoren.h"
#include "SingleBlockSensoren_private.h"
#include "SingleBlockSensoren_dt.h"

/* Block signals (auto storage) */
B_SingleBlockSensoren_T SingleBlockSensoren_B;

/* Block states (auto storage) */
DW_SingleBlockSensoren_T SingleBlockSensoren_DW;

/* Real-time model */
RT_MODEL_SingleBlockSensoren_T SingleBlockSensoren_M_;
RT_MODEL_SingleBlockSensoren_T *const SingleBlockSensoren_M =
  &SingleBlockSensoren_M_;

/* Model step function */
void SingleBlockSensoren_step(void)
{
  /* S-Function (Sensoren_CustomBlock): '<Root>/S-Function Builder2' */
  Sensoren_CustomBlock_Outputs_wrapper
    ( &SingleBlockSensoren_B.SFunctionBuilder2_o1,
     &SingleBlockSensoren_B.SFunctionBuilder2_o2,
     &SingleBlockSensoren_DW.SFunctionBuilder2_DSTATE,
     &SingleBlockSensoren_P.SFunctionBuilder2_P1, 1);

  /* S-Function "Sensoren_CustomBlock_wrapper" Block: <Root>/S-Function Builder2 */
  Sensoren_CustomBlock_Update_wrapper
    ( &SingleBlockSensoren_B.SFunctionBuilder2_o1,
     &SingleBlockSensoren_B.SFunctionBuilder2_o2,
     &SingleBlockSensoren_DW.SFunctionBuilder2_DSTATE,
     &SingleBlockSensoren_P.SFunctionBuilder2_P1, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(0, SingleBlockSensoren_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(SingleBlockSensoren_M)!=-1) &&
        !((rtmGetTFinal(SingleBlockSensoren_M)-
           SingleBlockSensoren_M->Timing.taskTime0) >
          SingleBlockSensoren_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(SingleBlockSensoren_M, "Simulation finished");
    }

    if (rtmGetStopRequested(SingleBlockSensoren_M)) {
      rtmSetErrorStatus(SingleBlockSensoren_M, "Simulation finished");
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
  if (!(++SingleBlockSensoren_M->Timing.clockTick0)) {
    ++SingleBlockSensoren_M->Timing.clockTickH0;
  }

  SingleBlockSensoren_M->Timing.taskTime0 =
    SingleBlockSensoren_M->Timing.clockTick0 *
    SingleBlockSensoren_M->Timing.stepSize0 +
    SingleBlockSensoren_M->Timing.clockTickH0 *
    SingleBlockSensoren_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void SingleBlockSensoren_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)SingleBlockSensoren_M, 0,
                sizeof(RT_MODEL_SingleBlockSensoren_T));
  rtmSetTFinal(SingleBlockSensoren_M, -1);
  SingleBlockSensoren_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  SingleBlockSensoren_M->Sizes.checksums[0] = (3181172925U);
  SingleBlockSensoren_M->Sizes.checksums[1] = (4189816070U);
  SingleBlockSensoren_M->Sizes.checksums[2] = (716536122U);
  SingleBlockSensoren_M->Sizes.checksums[3] = (1809506437U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    SingleBlockSensoren_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SingleBlockSensoren_M->extModeInfo,
      &SingleBlockSensoren_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SingleBlockSensoren_M->extModeInfo,
                        SingleBlockSensoren_M->Sizes.checksums);
    rteiSetTPtr(SingleBlockSensoren_M->extModeInfo, rtmGetTPtr
                (SingleBlockSensoren_M));
  }

  /* block I/O */
  (void) memset(((void *) &SingleBlockSensoren_B), 0,
                sizeof(B_SingleBlockSensoren_T));

  /* states (dwork) */
  (void) memset((void *)&SingleBlockSensoren_DW, 0,
                sizeof(DW_SingleBlockSensoren_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SingleBlockSensoren_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* S-Function Block: <Root>/S-Function Builder2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        SingleBlockSensoren_DW.SFunctionBuilder2_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void SingleBlockSensoren_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
