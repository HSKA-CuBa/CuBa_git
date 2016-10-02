/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestMPU6050.c
 *
 * Code generated for Simulink model 'TestMPU6050'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Aug 24 11:10:07 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestMPU6050.h"
#include "TestMPU6050_private.h"
#include "TestMPU6050_dt.h"

/* Block signals (auto storage) */
B_TestMPU6050_T TestMPU6050_B;

/* Block states (auto storage) */
DW_TestMPU6050_T TestMPU6050_DW;

/* Real-time model */
RT_MODEL_TestMPU6050_T TestMPU6050_M_;
RT_MODEL_TestMPU6050_T *const TestMPU6050_M = &TestMPU6050_M_;

/* Model step function */
void TestMPU6050_step(void)
{
  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor1' */
  MPU6050_CustomBlock_Outputs_wrapper( &TestMPU6050_B.Sensor1_o1,
    &TestMPU6050_B.Sensor1_o2, &TestMPU6050_B.Sensor1_o3,
    &TestMPU6050_B.Sensor1_o4, &TestMPU6050_B.Sensor1_o5,
    &TestMPU6050_B.Sensor1_o6, &TestMPU6050_DW.Sensor1_DSTATE,
    &TestMPU6050_P.Sensor1_P1, 1, &TestMPU6050_P.Sensor1_P2, 1);

  /* S-Function (MPU6050_CustomBlock): '<Root>/Sensor2' */
  MPU6050_CustomBlock_Outputs_wrapper( &TestMPU6050_B.Sensor2_o1,
    &TestMPU6050_B.Sensor2_o2, &TestMPU6050_B.Sensor2_o3,
    &TestMPU6050_B.Sensor2_o4, &TestMPU6050_B.Sensor2_o5,
    &TestMPU6050_B.Sensor2_o6, &TestMPU6050_DW.Sensor2_DSTATE,
    &TestMPU6050_P.Sensor2_P1, 1, &TestMPU6050_P.Sensor2_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor1 */
  MPU6050_CustomBlock_Update_wrapper( &TestMPU6050_B.Sensor1_o1,
    &TestMPU6050_B.Sensor1_o2, &TestMPU6050_B.Sensor1_o3,
    &TestMPU6050_B.Sensor1_o4, &TestMPU6050_B.Sensor1_o5,
    &TestMPU6050_B.Sensor1_o6, &TestMPU6050_DW.Sensor1_DSTATE,
    &TestMPU6050_P.Sensor1_P1, 1, &TestMPU6050_P.Sensor1_P2, 1);

  /* S-Function "MPU6050_CustomBlock_wrapper" Block: <Root>/Sensor2 */
  MPU6050_CustomBlock_Update_wrapper( &TestMPU6050_B.Sensor2_o1,
    &TestMPU6050_B.Sensor2_o2, &TestMPU6050_B.Sensor2_o3,
    &TestMPU6050_B.Sensor2_o4, &TestMPU6050_B.Sensor2_o5,
    &TestMPU6050_B.Sensor2_o6, &TestMPU6050_DW.Sensor2_DSTATE,
    &TestMPU6050_P.Sensor2_P1, 1, &TestMPU6050_P.Sensor2_P2, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, TestMPU6050_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(TestMPU6050_M)!=-1) &&
        !((rtmGetTFinal(TestMPU6050_M)-TestMPU6050_M->Timing.taskTime0) >
          TestMPU6050_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(TestMPU6050_M, "Simulation finished");
    }

    if (rtmGetStopRequested(TestMPU6050_M)) {
      rtmSetErrorStatus(TestMPU6050_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  TestMPU6050_M->Timing.taskTime0 =
    (++TestMPU6050_M->Timing.clockTick0) * TestMPU6050_M->Timing.stepSize0;
}

/* Model initialize function */
void TestMPU6050_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)TestMPU6050_M, 0,
                sizeof(RT_MODEL_TestMPU6050_T));
  rtmSetTFinal(TestMPU6050_M, -1);
  TestMPU6050_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  TestMPU6050_M->Sizes.checksums[0] = (1409208171U);
  TestMPU6050_M->Sizes.checksums[1] = (40314041U);
  TestMPU6050_M->Sizes.checksums[2] = (1872515678U);
  TestMPU6050_M->Sizes.checksums[3] = (1460890587U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    TestMPU6050_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TestMPU6050_M->extModeInfo,
      &TestMPU6050_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TestMPU6050_M->extModeInfo,
                        TestMPU6050_M->Sizes.checksums);
    rteiSetTPtr(TestMPU6050_M->extModeInfo, rtmGetTPtr(TestMPU6050_M));
  }

  /* block I/O */
  (void) memset(((void *) &TestMPU6050_B), 0,
                sizeof(B_TestMPU6050_T));

  /* states (dwork) */
  (void) memset((void *)&TestMPU6050_DW, 0,
                sizeof(DW_TestMPU6050_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TestMPU6050_M->SpecialInfo.mappingInfo = (&dtInfo);
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
        TestMPU6050_DW.Sensor1_DSTATE = initVector[0];
      }
    }
  }

  /* S-Function Block: <Root>/Sensor2 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        TestMPU6050_DW.Sensor2_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void TestMPU6050_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
