/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V6___LQR_Regelung.c
 *
 * Code generated for Simulink model 'V6___LQR_Regelung'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Sep 02 13:21:06 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "V6___LQR_Regelung.h"
#include "V6___LQR_Regelung_private.h"
#include "V6___LQR_Regelung_dt.h"

/* Block signals (auto storage) */
B_V6___LQR_Regelung_T V6___LQR_Regelung_B;

/* Block states (auto storage) */
DW_V6___LQR_Regelung_T V6___LQR_Regelung_DW;

/* Real-time model */
RT_MODEL_V6___LQR_Regelung_T V6___LQR_Regelung_M_;
RT_MODEL_V6___LQR_Regelung_T *const V6___LQR_Regelung_M = &V6___LQR_Regelung_M_;

/* Model step function */
void V6___LQR_Regelung_step(void)
{
  real32_T rtb_WinkelOffset;

  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor1' */
  MPU6050_CustomBlock_Outputs_wrapper( &V6___LQR_Regelung_B.Sensor1_o1,
    &V6___LQR_Regelung_B.Sensor1_o2, &V6___LQR_Regelung_B.Sensor1_o3,
    &V6___LQR_Regelung_B.Sensor1_o4, &V6___LQR_Regelung_B.Sensor1_o5,
    &V6___LQR_Regelung_B.Sensor1_o6, &V6___LQR_Regelung_DW.Sensor1_DSTATE,
    &V6___LQR_Regelung_P.Sensor1_P1, 1, &V6___LQR_Regelung_P.Sensor1_P2, 1);

  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor2' */
  MPU6050_CustomBlock_Outputs_wrapper( &V6___LQR_Regelung_B.Sensor2_o1,
    &V6___LQR_Regelung_B.Sensor2_o2, &V6___LQR_Regelung_B.Sensor2_o3,
    &V6___LQR_Regelung_B.Sensor2_o4, &V6___LQR_Regelung_B.Sensor2_o5,
    &V6___LQR_Regelung_B.Sensor2_o6, &V6___LQR_Regelung_DW.Sensor2_DSTATE,
    &V6___LQR_Regelung_P.Sensor2_P1, 1, &V6___LQR_Regelung_P.Sensor2_P2, 1);

  /* S-Function (SensorenFilter_Block): '<Root>/S-Function Builder2' */
  SensorenFilter_Block_Outputs_wrapper(&V6___LQR_Regelung_B.Sensor1_o1,
    &V6___LQR_Regelung_B.Sensor1_o2, &V6___LQR_Regelung_B.Sensor1_o6,
    &V6___LQR_Regelung_B.Sensor2_o1, &V6___LQR_Regelung_B.Sensor2_o2,
    &V6___LQR_Regelung_B.Sensor2_o6, &V6___LQR_Regelung_B.SFunctionBuilder2_o1,
    &V6___LQR_Regelung_B.SFunctionBuilder2_o2,
    &V6___LQR_Regelung_B.SFunctionBuilder2_o3,
    &V6___LQR_Regelung_B.SFunctionBuilder2_o4,
    &V6___LQR_Regelung_DW.SFunctionBuilder2_DSTATE,
    &V6___LQR_Regelung_P.SFunctionBuilder2_P1, 1);

  /* Sum: '<Root>/WinkelOffset' incorporates:
   *  Constant: '<Root>/phi_COG_Offset'
   */
  rtb_WinkelOffset = V6___LQR_Regelung_B.SFunctionBuilder2_o3 -
    V6___LQR_Regelung_P.phi_COG_Offset_Value;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Abs: '<Root>/Abs'
   *  Constant: '<S1>/Constant'
   */
  V6___LQR_Regelung_B.Compare = ((real32_T)fabs(rtb_WinkelOffset) <=
    V6___LQR_Regelung_P.BalanceArea_const);

  /* S-Function (MotorADC): '<Root>/S-Function Builder1' */
  MotorADC_Outputs_wrapper( &V6___LQR_Regelung_B.SFunctionBuilder1 );

  /* Sum: '<Root>/WinkelOffset1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/phi_COG_Offset1'
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Add'
   */
  V6___LQR_Regelung_B.WinkelOffset1 = (V6___LQR_Regelung_P.Constant2_Value -
    (real_T)((uint32_T)V6___LQR_Regelung_P.Gain_Gain *
             V6___LQR_Regelung_B.SFunctionBuilder1) * 1.52587890625E-5) -
    V6___LQR_Regelung_P.phi_COG_Offset1_Value;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   */
  V6___LQR_Regelung_B.T_M = (real32_T)(((0.0 - (real_T)
    V6___LQR_Regelung_P.Gain1_Gain * rtb_WinkelOffset) -
    V6___LQR_Regelung_P.Gain2_Gain * V6___LQR_Regelung_B.SFunctionBuilder2_o4) -
    V6___LQR_Regelung_P.Kd[2] * V6___LQR_Regelung_B.WinkelOffset1);

  /* S-Function (Motor): '<Root>/S-Function Builder' */
  Motor_Outputs_wrapper(&V6___LQR_Regelung_B.Compare, &V6___LQR_Regelung_B.T_M );

  /* Gain: '<Root>/radtodeg3' */
  V6___LQR_Regelung_B.phi_acc_deg = V6___LQR_Regelung_P.radtodeg3_Gain *
    V6___LQR_Regelung_B.SFunctionBuilder2_o1;

  /* Gain: '<Root>/radtodeg2' */
  V6___LQR_Regelung_B.phi_komp_deg = V6___LQR_Regelung_P.radtodeg2_Gain *
    V6___LQR_Regelung_B.SFunctionBuilder2_o2;

  /* Gain: '<Root>/radtodeg1' */
  V6___LQR_Regelung_B.phi_kalman__deg = V6___LQR_Regelung_P.radtodeg1_Gain *
    V6___LQR_Regelung_B.SFunctionBuilder2_o3;

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor1 */
  MPU6050_CustomBlock_Update_wrapper( &V6___LQR_Regelung_B.Sensor1_o1,
    &V6___LQR_Regelung_B.Sensor1_o2, &V6___LQR_Regelung_B.Sensor1_o3,
    &V6___LQR_Regelung_B.Sensor1_o4, &V6___LQR_Regelung_B.Sensor1_o5,
    &V6___LQR_Regelung_B.Sensor1_o6, &V6___LQR_Regelung_DW.Sensor1_DSTATE,
    &V6___LQR_Regelung_P.Sensor1_P1, 1, &V6___LQR_Regelung_P.Sensor1_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor2 */
  MPU6050_CustomBlock_Update_wrapper( &V6___LQR_Regelung_B.Sensor2_o1,
    &V6___LQR_Regelung_B.Sensor2_o2, &V6___LQR_Regelung_B.Sensor2_o3,
    &V6___LQR_Regelung_B.Sensor2_o4, &V6___LQR_Regelung_B.Sensor2_o5,
    &V6___LQR_Regelung_B.Sensor2_o6, &V6___LQR_Regelung_DW.Sensor2_DSTATE,
    &V6___LQR_Regelung_P.Sensor2_P1, 1, &V6___LQR_Regelung_P.Sensor2_P2, 1);

  /* S-Function "SensorenFilter_Block_wrapper" Block: <Root>/S-Function Builder2 */
  SensorenFilter_Block_Update_wrapper(&V6___LQR_Regelung_B.Sensor1_o1,
    &V6___LQR_Regelung_B.Sensor1_o2, &V6___LQR_Regelung_B.Sensor1_o6,
    &V6___LQR_Regelung_B.Sensor2_o1, &V6___LQR_Regelung_B.Sensor2_o2,
    &V6___LQR_Regelung_B.Sensor2_o6, &V6___LQR_Regelung_B.SFunctionBuilder2_o1,
    &V6___LQR_Regelung_B.SFunctionBuilder2_o2,
    &V6___LQR_Regelung_B.SFunctionBuilder2_o3,
    &V6___LQR_Regelung_B.SFunctionBuilder2_o4,
    &V6___LQR_Regelung_DW.SFunctionBuilder2_DSTATE,
    &V6___LQR_Regelung_P.SFunctionBuilder2_P1, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, V6___LQR_Regelung_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(V6___LQR_Regelung_M)!=-1) &&
        !((rtmGetTFinal(V6___LQR_Regelung_M)-
           V6___LQR_Regelung_M->Timing.taskTime0) >
          V6___LQR_Regelung_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(V6___LQR_Regelung_M, "Simulation finished");
    }

    if (rtmGetStopRequested(V6___LQR_Regelung_M)) {
      rtmSetErrorStatus(V6___LQR_Regelung_M, "Simulation finished");
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
  if (!(++V6___LQR_Regelung_M->Timing.clockTick0)) {
    ++V6___LQR_Regelung_M->Timing.clockTickH0;
  }

  V6___LQR_Regelung_M->Timing.taskTime0 = V6___LQR_Regelung_M->Timing.clockTick0
    * V6___LQR_Regelung_M->Timing.stepSize0 +
    V6___LQR_Regelung_M->Timing.clockTickH0 *
    V6___LQR_Regelung_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void V6___LQR_Regelung_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)V6___LQR_Regelung_M, 0,
                sizeof(RT_MODEL_V6___LQR_Regelung_T));
  rtmSetTFinal(V6___LQR_Regelung_M, -1);
  V6___LQR_Regelung_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  V6___LQR_Regelung_M->Sizes.checksums[0] = (1961465426U);
  V6___LQR_Regelung_M->Sizes.checksums[1] = (236356520U);
  V6___LQR_Regelung_M->Sizes.checksums[2] = (2497097983U);
  V6___LQR_Regelung_M->Sizes.checksums[3] = (2666979419U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    V6___LQR_Regelung_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(V6___LQR_Regelung_M->extModeInfo,
      &V6___LQR_Regelung_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(V6___LQR_Regelung_M->extModeInfo,
                        V6___LQR_Regelung_M->Sizes.checksums);
    rteiSetTPtr(V6___LQR_Regelung_M->extModeInfo, rtmGetTPtr(V6___LQR_Regelung_M));
  }

  /* block I/O */
  (void) memset(((void *) &V6___LQR_Regelung_B), 0,
                sizeof(B_V6___LQR_Regelung_T));

  /* states (dwork) */
  (void) memset((void *)&V6___LQR_Regelung_DW, 0,
                sizeof(DW_V6___LQR_Regelung_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    V6___LQR_Regelung_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
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
        V6___LQR_Regelung_DW.Sensor1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <Root>/Sensor2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        V6___LQR_Regelung_DW.Sensor2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <Root>/S-Function Builder2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        V6___LQR_Regelung_DW.SFunctionBuilder2_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void V6___LQR_Regelung_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
