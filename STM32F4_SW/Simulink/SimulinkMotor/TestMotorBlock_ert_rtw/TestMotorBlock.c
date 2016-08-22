/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestMotorBlock.c
 *
 * Code generated for Simulink model 'TestMotorBlock'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Aug 22 12:56:36 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestMotorBlock.h"
#include "TestMotorBlock_private.h"
#include "TestMotorBlock_dt.h"

/* Block signals (auto storage) */
B_TestMotorBlock_T TestMotorBlock_B;

/* Block states (auto storage) */
DW_TestMotorBlock_T TestMotorBlock_DW;

/* Real-time model */
RT_MODEL_TestMotorBlock_T TestMotorBlock_M_;
RT_MODEL_TestMotorBlock_T *const TestMotorBlock_M = &TestMotorBlock_M_;

/* Model step function */
void TestMotorBlock_step(void)
{
  /* S-Function (Motor): '<Root>/S-Function Builder' */
  Motor_Outputs_wrapper(&TestMotorBlock_P.Constant_Value,
                        &TestMotorBlock_P.Constant1_Value,
                        &TestMotorBlock_B.SFunctionBuilder );

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, TestMotorBlock_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(TestMotorBlock_M)!=-1) &&
        !((rtmGetTFinal(TestMotorBlock_M)-TestMotorBlock_M->Timing.taskTime0) >
          TestMotorBlock_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(TestMotorBlock_M, "Simulation finished");
    }

    if (rtmGetStopRequested(TestMotorBlock_M)) {
      rtmSetErrorStatus(TestMotorBlock_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  TestMotorBlock_M->Timing.taskTime0 =
    (++TestMotorBlock_M->Timing.clockTick0) * TestMotorBlock_M->Timing.stepSize0;
}

/* Model initialize function */
void TestMotorBlock_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)TestMotorBlock_M, 0,
                sizeof(RT_MODEL_TestMotorBlock_T));
  rtmSetTFinal(TestMotorBlock_M, -1);
  TestMotorBlock_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  TestMotorBlock_M->Sizes.checksums[0] = (2436832317U);
  TestMotorBlock_M->Sizes.checksums[1] = (3608607758U);
  TestMotorBlock_M->Sizes.checksums[2] = (3686247111U);
  TestMotorBlock_M->Sizes.checksums[3] = (2167492531U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    TestMotorBlock_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TestMotorBlock_M->extModeInfo,
      &TestMotorBlock_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TestMotorBlock_M->extModeInfo,
                        TestMotorBlock_M->Sizes.checksums);
    rteiSetTPtr(TestMotorBlock_M->extModeInfo, rtmGetTPtr(TestMotorBlock_M));
  }

  /* block I/O */
  (void) memset(((void *) &TestMotorBlock_B), 0,
                sizeof(B_TestMotorBlock_T));

  /* states (dwork) */
  (void) memset((void *)&TestMotorBlock_DW, 0,
                sizeof(DW_TestMotorBlock_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TestMotorBlock_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void TestMotorBlock_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
