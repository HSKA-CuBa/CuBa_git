/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V4_Ermittlung_C_phi.c
 *
 * Code generated for Simulink model 'V4_Ermittlung_C_phi'.
 *
 * Model version                  : 1.89
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Aug 22 14:26:01 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "V4_Ermittlung_C_phi.h"
#include "V4_Ermittlung_C_phi_private.h"
#include "V4_Ermittlung_C_phi_dt.h"

/* Block signals (auto storage) */
B_V4_Ermittlung_C_phi_T V4_Ermittlung_C_phi_B;

/* Block states (auto storage) */
DW_V4_Ermittlung_C_phi_T V4_Ermittlung_C_phi_DW;

/* Real-time model */
RT_MODEL_V4_Ermittlung_C_phi_T V4_Ermittlung_C_phi_M_;
RT_MODEL_V4_Ermittlung_C_phi_T *const V4_Ermittlung_C_phi_M =
  &V4_Ermittlung_C_phi_M_;

/* Model step function */
void V4_Ermittlung_C_phi_step(void)
{
  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor1' */
  MPU6050_CustomBlock_Outputs_wrapper( &V4_Ermittlung_C_phi_B.Sensor1_o1,
    &V4_Ermittlung_C_phi_B.Sensor1_o2, &V4_Ermittlung_C_phi_B.Sensor1_o3,
    &V4_Ermittlung_C_phi_B.Sensor1_o4, &V4_Ermittlung_C_phi_B.Sensor1_o5,
    &V4_Ermittlung_C_phi_B.Sensor1_o6, &V4_Ermittlung_C_phi_DW.Sensor1_DSTATE,
    &V4_Ermittlung_C_phi_P.Sensor1_P1, 1, &V4_Ermittlung_C_phi_P.Sensor1_P2, 1);

  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor2' */
  MPU6050_CustomBlock_Outputs_wrapper( &V4_Ermittlung_C_phi_B.Sensor2_o1,
    &V4_Ermittlung_C_phi_B.Sensor2_o2, &V4_Ermittlung_C_phi_B.Sensor2_o3,
    &V4_Ermittlung_C_phi_B.Sensor2_o4, &V4_Ermittlung_C_phi_B.Sensor2_o5,
    &V4_Ermittlung_C_phi_B.Sensor2_o6, &V4_Ermittlung_C_phi_DW.Sensor2_DSTATE,
    &V4_Ermittlung_C_phi_P.Sensor2_P1, 1, &V4_Ermittlung_C_phi_P.Sensor2_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor1 */
  MPU6050_CustomBlock_Update_wrapper( &V4_Ermittlung_C_phi_B.Sensor1_o1,
    &V4_Ermittlung_C_phi_B.Sensor1_o2, &V4_Ermittlung_C_phi_B.Sensor1_o3,
    &V4_Ermittlung_C_phi_B.Sensor1_o4, &V4_Ermittlung_C_phi_B.Sensor1_o5,
    &V4_Ermittlung_C_phi_B.Sensor1_o6, &V4_Ermittlung_C_phi_DW.Sensor1_DSTATE,
    &V4_Ermittlung_C_phi_P.Sensor1_P1, 1, &V4_Ermittlung_C_phi_P.Sensor1_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor2 */
  MPU6050_CustomBlock_Update_wrapper( &V4_Ermittlung_C_phi_B.Sensor2_o1,
    &V4_Ermittlung_C_phi_B.Sensor2_o2, &V4_Ermittlung_C_phi_B.Sensor2_o3,
    &V4_Ermittlung_C_phi_B.Sensor2_o4, &V4_Ermittlung_C_phi_B.Sensor2_o5,
    &V4_Ermittlung_C_phi_B.Sensor2_o6, &V4_Ermittlung_C_phi_DW.Sensor2_DSTATE,
    &V4_Ermittlung_C_phi_P.Sensor2_P1, 1, &V4_Ermittlung_C_phi_P.Sensor2_P2, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, V4_Ermittlung_C_phi_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(V4_Ermittlung_C_phi_M)!=-1) &&
        !((rtmGetTFinal(V4_Ermittlung_C_phi_M)-
           V4_Ermittlung_C_phi_M->Timing.taskTime0) >
          V4_Ermittlung_C_phi_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(V4_Ermittlung_C_phi_M, "Simulation finished");
    }

    if (rtmGetStopRequested(V4_Ermittlung_C_phi_M)) {
      rtmSetErrorStatus(V4_Ermittlung_C_phi_M, "Simulation finished");
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
  if (!(++V4_Ermittlung_C_phi_M->Timing.clockTick0)) {
    ++V4_Ermittlung_C_phi_M->Timing.clockTickH0;
  }

  V4_Ermittlung_C_phi_M->Timing.taskTime0 =
    V4_Ermittlung_C_phi_M->Timing.clockTick0 *
    V4_Ermittlung_C_phi_M->Timing.stepSize0 +
    V4_Ermittlung_C_phi_M->Timing.clockTickH0 *
    V4_Ermittlung_C_phi_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void V4_Ermittlung_C_phi_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)V4_Ermittlung_C_phi_M, 0,
                sizeof(RT_MODEL_V4_Ermittlung_C_phi_T));
  rtmSetTFinal(V4_Ermittlung_C_phi_M, -1);
  V4_Ermittlung_C_phi_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  V4_Ermittlung_C_phi_M->Sizes.checksums[0] = (3176365128U);
  V4_Ermittlung_C_phi_M->Sizes.checksums[1] = (2478406900U);
  V4_Ermittlung_C_phi_M->Sizes.checksums[2] = (3706884886U);
  V4_Ermittlung_C_phi_M->Sizes.checksums[3] = (1024789914U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    V4_Ermittlung_C_phi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(V4_Ermittlung_C_phi_M->extModeInfo,
      &V4_Ermittlung_C_phi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(V4_Ermittlung_C_phi_M->extModeInfo,
                        V4_Ermittlung_C_phi_M->Sizes.checksums);
    rteiSetTPtr(V4_Ermittlung_C_phi_M->extModeInfo, rtmGetTPtr
                (V4_Ermittlung_C_phi_M));
  }

  /* block I/O */
  (void) memset(((void *) &V4_Ermittlung_C_phi_B), 0,
                sizeof(B_V4_Ermittlung_C_phi_T));

  /* states (dwork) */
  (void) memset((void *)&V4_Ermittlung_C_phi_DW, 0,
                sizeof(DW_V4_Ermittlung_C_phi_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    V4_Ermittlung_C_phi_M->SpecialInfo.mappingInfo = (&dtInfo);
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
        V4_Ermittlung_C_phi_DW.Sensor1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <Root>/Sensor2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        V4_Ermittlung_C_phi_DW.Sensor2_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void V4_Ermittlung_C_phi_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
