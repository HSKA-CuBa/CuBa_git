/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BeschleunigungsAuswertung.c
 *
 * Code generated for Simulink model 'BeschleunigungsAuswertung'.
 *
 * Model version                  : 1.79
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Aug 08 17:04:04 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BeschleunigungsAuswertung.h"
#include "BeschleunigungsAuswertung_private.h"
#include "BeschleunigungsAuswertung_dt.h"

/* Block signals (auto storage) */
B_BeschleunigungsAuswertung_T BeschleunigungsAuswertung_B;

/* Block states (auto storage) */
DW_BeschleunigungsAuswertung_T BeschleunigungsAuswertung_DW;

/* Real-time model */
RT_MODEL_BeschleunigungsAuswe_T BeschleunigungsAuswertung_M_;
RT_MODEL_BeschleunigungsAuswe_T *const BeschleunigungsAuswertung_M =
  &BeschleunigungsAuswertung_M_;

/* Model step function */
void BeschleunigungsAuswertung_step(void)
{
  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor1' */
  MPU6050_CustomBlock_Outputs_wrapper( &BeschleunigungsAuswertung_B.Sensor1_o1,
    &BeschleunigungsAuswertung_B.Sensor1_o2,
    &BeschleunigungsAuswertung_B.Sensor1_o3,
    &BeschleunigungsAuswertung_B.Sensor1_o4,
    &BeschleunigungsAuswertung_B.Sensor1_o5,
    &BeschleunigungsAuswertung_B.Sensor1_o6,
    &BeschleunigungsAuswertung_DW.Sensor1_DSTATE,
    &BeschleunigungsAuswertung_P.Sensor1_P1, 1,
    &BeschleunigungsAuswertung_P.Sensor1_P2, 1);

  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor2' */
  MPU6050_CustomBlock_Outputs_wrapper( &BeschleunigungsAuswertung_B.Sensor2_o1,
    &BeschleunigungsAuswertung_B.Sensor2_o2,
    &BeschleunigungsAuswertung_B.Sensor2_o3,
    &BeschleunigungsAuswertung_B.Sensor2_o4,
    &BeschleunigungsAuswertung_B.Sensor2_o5,
    &BeschleunigungsAuswertung_B.Sensor2_o6,
    &BeschleunigungsAuswertung_DW.Sensor2_DSTATE,
    &BeschleunigungsAuswertung_P.Sensor2_P1, 1,
    &BeschleunigungsAuswertung_P.Sensor2_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor1 */
  MPU6050_CustomBlock_Update_wrapper( &BeschleunigungsAuswertung_B.Sensor1_o1,
    &BeschleunigungsAuswertung_B.Sensor1_o2,
    &BeschleunigungsAuswertung_B.Sensor1_o3,
    &BeschleunigungsAuswertung_B.Sensor1_o4,
    &BeschleunigungsAuswertung_B.Sensor1_o5,
    &BeschleunigungsAuswertung_B.Sensor1_o6,
    &BeschleunigungsAuswertung_DW.Sensor1_DSTATE,
    &BeschleunigungsAuswertung_P.Sensor1_P1, 1,
    &BeschleunigungsAuswertung_P.Sensor1_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor2 */
  MPU6050_CustomBlock_Update_wrapper( &BeschleunigungsAuswertung_B.Sensor2_o1,
    &BeschleunigungsAuswertung_B.Sensor2_o2,
    &BeschleunigungsAuswertung_B.Sensor2_o3,
    &BeschleunigungsAuswertung_B.Sensor2_o4,
    &BeschleunigungsAuswertung_B.Sensor2_o5,
    &BeschleunigungsAuswertung_B.Sensor2_o6,
    &BeschleunigungsAuswertung_DW.Sensor2_DSTATE,
    &BeschleunigungsAuswertung_P.Sensor2_P1, 1,
    &BeschleunigungsAuswertung_P.Sensor2_P2, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, BeschleunigungsAuswertung_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(BeschleunigungsAuswertung_M)!=-1) &&
        !((rtmGetTFinal(BeschleunigungsAuswertung_M)-
           BeschleunigungsAuswertung_M->Timing.taskTime0) >
          BeschleunigungsAuswertung_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(BeschleunigungsAuswertung_M, "Simulation finished");
    }

    if (rtmGetStopRequested(BeschleunigungsAuswertung_M)) {
      rtmSetErrorStatus(BeschleunigungsAuswertung_M, "Simulation finished");
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
  if (!(++BeschleunigungsAuswertung_M->Timing.clockTick0)) {
    ++BeschleunigungsAuswertung_M->Timing.clockTickH0;
  }

  BeschleunigungsAuswertung_M->Timing.taskTime0 =
    BeschleunigungsAuswertung_M->Timing.clockTick0 *
    BeschleunigungsAuswertung_M->Timing.stepSize0 +
    BeschleunigungsAuswertung_M->Timing.clockTickH0 *
    BeschleunigungsAuswertung_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void BeschleunigungsAuswertung_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BeschleunigungsAuswertung_M, 0,
                sizeof(RT_MODEL_BeschleunigungsAuswe_T));
  rtmSetTFinal(BeschleunigungsAuswertung_M, 10.0);
  BeschleunigungsAuswertung_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  BeschleunigungsAuswertung_M->Sizes.checksums[0] = (1433181656U);
  BeschleunigungsAuswertung_M->Sizes.checksums[1] = (3867704793U);
  BeschleunigungsAuswertung_M->Sizes.checksums[2] = (3435414682U);
  BeschleunigungsAuswertung_M->Sizes.checksums[3] = (3218394539U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    BeschleunigungsAuswertung_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BeschleunigungsAuswertung_M->extModeInfo,
      &BeschleunigungsAuswertung_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BeschleunigungsAuswertung_M->extModeInfo,
                        BeschleunigungsAuswertung_M->Sizes.checksums);
    rteiSetTPtr(BeschleunigungsAuswertung_M->extModeInfo, rtmGetTPtr
                (BeschleunigungsAuswertung_M));
  }

  /* block I/O */
  (void) memset(((void *) &BeschleunigungsAuswertung_B), 0,
                sizeof(B_BeschleunigungsAuswertung_T));

  /* states (dwork) */
  (void) memset((void *)&BeschleunigungsAuswertung_DW, 0,
                sizeof(DW_BeschleunigungsAuswertung_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BeschleunigungsAuswertung_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* S-Function Block: <Root>/Sensor1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BeschleunigungsAuswertung_DW.Sensor1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <Root>/Sensor2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        BeschleunigungsAuswertung_DW.Sensor2_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void BeschleunigungsAuswertung_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
