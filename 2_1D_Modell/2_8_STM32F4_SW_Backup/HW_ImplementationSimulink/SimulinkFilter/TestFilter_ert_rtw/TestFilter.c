/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestFilter.c
 *
 * Code generated for Simulink model 'TestFilter'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sat Aug 27 13:43:35 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestFilter.h"
#include "TestFilter_private.h"
#include "TestFilter_dt.h"

/* Block signals (auto storage) */
B_TestFilter_T TestFilter_B;

/* Block states (auto storage) */
DW_TestFilter_T TestFilter_DW;

/* Real-time model */
RT_MODEL_TestFilter_T TestFilter_M_;
RT_MODEL_TestFilter_T *const TestFilter_M = &TestFilter_M_;

/* Model step function */
void TestFilter_step(void)
{
  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor1' */
  MPU6050_CustomBlock_Outputs_wrapper( &TestFilter_B.Sensor1_o1,
    &TestFilter_B.Sensor1_o2, &TestFilter_B.Sensor1_o3, &TestFilter_B.Sensor1_o4,
    &TestFilter_B.Sensor1_o5, &TestFilter_B.Sensor1_o6,
    &TestFilter_DW.Sensor1_DSTATE, &TestFilter_P.Sensor1_P1, 1,
    &TestFilter_P.Sensor1_P2, 1);

  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor2' */
  MPU6050_CustomBlock_Outputs_wrapper( &TestFilter_B.Sensor2_o1,
    &TestFilter_B.Sensor2_o2, &TestFilter_B.Sensor2_o3, &TestFilter_B.Sensor2_o4,
    &TestFilter_B.Sensor2_o5, &TestFilter_B.Sensor2_o6,
    &TestFilter_DW.Sensor2_DSTATE, &TestFilter_P.Sensor2_P1, 1,
    &TestFilter_P.Sensor2_P2, 1);

  /* S-Function (SensorenFilter_Block): '<Root>/S-Function Builder' */
  SensorenFilter_Block_Outputs_wrapper(&TestFilter_B.Sensor1_o1,
    &TestFilter_B.Sensor1_o6, &TestFilter_B.Sensor2_o6, &TestFilter_B.Sensor1_o2,
    &TestFilter_B.Sensor2_o2, &TestFilter_B.Sensor2_o1,
    &TestFilter_B.SFunctionBuilder_o1, &TestFilter_B.SFunctionBuilder_o2,
    &TestFilter_B.SFunctionBuilder_o3, &TestFilter_B.SFunctionBuilder_o4,
    &TestFilter_DW.SFunctionBuilder_DSTATE, &TestFilter_P.SFunctionBuilder_P1, 1);

  /* Gain: '<Root>/radtodeg' */
  TestFilter_B.radtodeg = TestFilter_P.radtodeg_Gain *
    TestFilter_B.SFunctionBuilder_o1;

  /* Gain: '<Root>/radtodeg1' */
  TestFilter_B.radtodeg1 = TestFilter_P.radtodeg1_Gain *
    TestFilter_B.SFunctionBuilder_o2;

  /* Gain: '<Root>/radtodeg2' */
  TestFilter_B.radtodeg2 = TestFilter_P.radtodeg2_Gain *
    TestFilter_B.SFunctionBuilder_o3;

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor1 */
  MPU6050_CustomBlock_Update_wrapper( &TestFilter_B.Sensor1_o1,
    &TestFilter_B.Sensor1_o2, &TestFilter_B.Sensor1_o3, &TestFilter_B.Sensor1_o4,
    &TestFilter_B.Sensor1_o5, &TestFilter_B.Sensor1_o6,
    &TestFilter_DW.Sensor1_DSTATE, &TestFilter_P.Sensor1_P1, 1,
    &TestFilter_P.Sensor1_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor2 */
  MPU6050_CustomBlock_Update_wrapper( &TestFilter_B.Sensor2_o1,
    &TestFilter_B.Sensor2_o2, &TestFilter_B.Sensor2_o3, &TestFilter_B.Sensor2_o4,
    &TestFilter_B.Sensor2_o5, &TestFilter_B.Sensor2_o6,
    &TestFilter_DW.Sensor2_DSTATE, &TestFilter_P.Sensor2_P1, 1,
    &TestFilter_P.Sensor2_P2, 1);

  /* S-Function "SensorenFilter_Block_wrapper" Block: <Root>/S-Function Builder */
  SensorenFilter_Block_Update_wrapper(&TestFilter_B.Sensor1_o1,
    &TestFilter_B.Sensor1_o6, &TestFilter_B.Sensor2_o6, &TestFilter_B.Sensor1_o2,
    &TestFilter_B.Sensor2_o2, &TestFilter_B.Sensor2_o1,
    &TestFilter_B.SFunctionBuilder_o1, &TestFilter_B.SFunctionBuilder_o2,
    &TestFilter_B.SFunctionBuilder_o3, &TestFilter_B.SFunctionBuilder_o4,
    &TestFilter_DW.SFunctionBuilder_DSTATE, &TestFilter_P.SFunctionBuilder_P1, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, TestFilter_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(TestFilter_M)!=-1) &&
        !((rtmGetTFinal(TestFilter_M)-TestFilter_M->Timing.taskTime0) >
          TestFilter_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(TestFilter_M, "Simulation finished");
    }

    if (rtmGetStopRequested(TestFilter_M)) {
      rtmSetErrorStatus(TestFilter_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  TestFilter_M->Timing.taskTime0 =
    (++TestFilter_M->Timing.clockTick0) * TestFilter_M->Timing.stepSize0;
}

/* Model initialize function */
void TestFilter_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)TestFilter_M, 0,
                sizeof(RT_MODEL_TestFilter_T));
  rtmSetTFinal(TestFilter_M, -1);
  TestFilter_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  TestFilter_M->Sizes.checksums[0] = (2046822630U);
  TestFilter_M->Sizes.checksums[1] = (1117202071U);
  TestFilter_M->Sizes.checksums[2] = (2108673156U);
  TestFilter_M->Sizes.checksums[3] = (1228462439U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    TestFilter_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TestFilter_M->extModeInfo,
      &TestFilter_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TestFilter_M->extModeInfo, TestFilter_M->Sizes.checksums);
    rteiSetTPtr(TestFilter_M->extModeInfo, rtmGetTPtr(TestFilter_M));
  }

  /* block I/O */
  (void) memset(((void *) &TestFilter_B), 0,
                sizeof(B_TestFilter_T));

  /* states (dwork) */
  (void) memset((void *)&TestFilter_DW, 0,
                sizeof(DW_TestFilter_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TestFilter_M->SpecialInfo.mappingInfo = (&dtInfo);
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
        TestFilter_DW.Sensor1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <Root>/Sensor2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        TestFilter_DW.Sensor2_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        TestFilter_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void TestFilter_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
