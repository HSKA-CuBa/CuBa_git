/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GyroskopAuswertung.c
 *
 * Code generated for Simulink model 'GyroskopAuswertung'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sat Aug 27 12:41:29 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GyroskopAuswertung.h"
#include "GyroskopAuswertung_private.h"
#include "GyroskopAuswertung_dt.h"

/* Block signals (auto storage) */
B_GyroskopAuswertung_T GyroskopAuswertung_B;

/* Block states (auto storage) */
DW_GyroskopAuswertung_T GyroskopAuswertung_DW;

/* Real-time model */
RT_MODEL_GyroskopAuswertung_T GyroskopAuswertung_M_;
RT_MODEL_GyroskopAuswertung_T *const GyroskopAuswertung_M =
  &GyroskopAuswertung_M_;

/* Model step function */
void GyroskopAuswertung_step(void)
{
  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor1' */
  MPU6050_CustomBlock_Outputs_wrapper( &GyroskopAuswertung_B.Sensor1_o1,
    &GyroskopAuswertung_B.Sensor1_o2, &GyroskopAuswertung_B.Sensor1_o3,
    &GyroskopAuswertung_B.Sensor1_o4, &GyroskopAuswertung_B.Sensor1_o5,
    &GyroskopAuswertung_B.Sensor1_o6, &GyroskopAuswertung_DW.Sensor1_DSTATE,
    &GyroskopAuswertung_P.Sensor1_P1, 1, &GyroskopAuswertung_P.Sensor1_P2, 1);

  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor2' */
  MPU6050_CustomBlock_Outputs_wrapper( &GyroskopAuswertung_B.Sensor2_o1,
    &GyroskopAuswertung_B.Sensor2_o2, &GyroskopAuswertung_B.Sensor2_o3,
    &GyroskopAuswertung_B.Sensor2_o4, &GyroskopAuswertung_B.Sensor2_o5,
    &GyroskopAuswertung_B.Sensor2_o6, &GyroskopAuswertung_DW.Sensor2_DSTATE,
    &GyroskopAuswertung_P.Sensor2_P1, 1, &GyroskopAuswertung_P.Sensor2_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor1 */
  MPU6050_CustomBlock_Update_wrapper( &GyroskopAuswertung_B.Sensor1_o1,
    &GyroskopAuswertung_B.Sensor1_o2, &GyroskopAuswertung_B.Sensor1_o3,
    &GyroskopAuswertung_B.Sensor1_o4, &GyroskopAuswertung_B.Sensor1_o5,
    &GyroskopAuswertung_B.Sensor1_o6, &GyroskopAuswertung_DW.Sensor1_DSTATE,
    &GyroskopAuswertung_P.Sensor1_P1, 1, &GyroskopAuswertung_P.Sensor1_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor2 */
  MPU6050_CustomBlock_Update_wrapper( &GyroskopAuswertung_B.Sensor2_o1,
    &GyroskopAuswertung_B.Sensor2_o2, &GyroskopAuswertung_B.Sensor2_o3,
    &GyroskopAuswertung_B.Sensor2_o4, &GyroskopAuswertung_B.Sensor2_o5,
    &GyroskopAuswertung_B.Sensor2_o6, &GyroskopAuswertung_DW.Sensor2_DSTATE,
    &GyroskopAuswertung_P.Sensor2_P1, 1, &GyroskopAuswertung_P.Sensor2_P2, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, GyroskopAuswertung_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(GyroskopAuswertung_M)!=-1) &&
        !((rtmGetTFinal(GyroskopAuswertung_M)-
           GyroskopAuswertung_M->Timing.taskTime0) >
          GyroskopAuswertung_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(GyroskopAuswertung_M, "Simulation finished");
    }

    if (rtmGetStopRequested(GyroskopAuswertung_M)) {
      rtmSetErrorStatus(GyroskopAuswertung_M, "Simulation finished");
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
  if (!(++GyroskopAuswertung_M->Timing.clockTick0)) {
    ++GyroskopAuswertung_M->Timing.clockTickH0;
  }

  GyroskopAuswertung_M->Timing.taskTime0 =
    GyroskopAuswertung_M->Timing.clockTick0 *
    GyroskopAuswertung_M->Timing.stepSize0 +
    GyroskopAuswertung_M->Timing.clockTickH0 *
    GyroskopAuswertung_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void GyroskopAuswertung_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)GyroskopAuswertung_M, 0,
                sizeof(RT_MODEL_GyroskopAuswertung_T));
  rtmSetTFinal(GyroskopAuswertung_M, 10.0);
  GyroskopAuswertung_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  GyroskopAuswertung_M->Sizes.checksums[0] = (1941814335U);
  GyroskopAuswertung_M->Sizes.checksums[1] = (4017032776U);
  GyroskopAuswertung_M->Sizes.checksums[2] = (2489100557U);
  GyroskopAuswertung_M->Sizes.checksums[3] = (945044384U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    GyroskopAuswertung_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GyroskopAuswertung_M->extModeInfo,
      &GyroskopAuswertung_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GyroskopAuswertung_M->extModeInfo,
                        GyroskopAuswertung_M->Sizes.checksums);
    rteiSetTPtr(GyroskopAuswertung_M->extModeInfo, rtmGetTPtr
                (GyroskopAuswertung_M));
  }

  /* block I/O */
  (void) memset(((void *) &GyroskopAuswertung_B), 0,
                sizeof(B_GyroskopAuswertung_T));

  /* states (dwork) */
  (void) memset((void *)&GyroskopAuswertung_DW, 0,
                sizeof(DW_GyroskopAuswertung_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    GyroskopAuswertung_M->SpecialInfo.mappingInfo = (&dtInfo);
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
        GyroskopAuswertung_DW.Sensor1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <Root>/Sensor2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        GyroskopAuswertung_DW.Sensor2_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void GyroskopAuswertung_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
