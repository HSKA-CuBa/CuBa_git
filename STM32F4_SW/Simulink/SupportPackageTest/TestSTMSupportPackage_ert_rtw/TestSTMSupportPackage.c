/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestSTMSupportPackage.c
 *
 * Code generated for Simulink model 'TestSTMSupportPackage'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Jul 29 09:42:40 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestSTMSupportPackage.h"
#include "TestSTMSupportPackage_private.h"
#include "TestSTMSupportPackage_dt.h"

/* Block states (auto storage) */
DW_TestSTMSupportPackage_T TestSTMSupportPackage_DW;

/* Real-time model */
RT_MODEL_TestSTMSupportPackag_T TestSTMSupportPackage_M_;
RT_MODEL_TestSTMSupportPackag_T *const TestSTMSupportPackage_M =
  &TestSTMSupportPackage_M_;

/* Model step function */
void TestSTMSupportPackage_step(void)
{
  /* S-Function (stm32f4_do_write): '<Root>/GPIO Write' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_GPIO_WriteBit(3U, 13U, TestSTMSupportPackage_P.Constant_Value);

  /* S-Function (LED_CustomBlock): '<Root>/S-Function Builder' */
  LED_CustomBlock_Outputs_wrapper(&TestSTMSupportPackage_P.Constant_Value,
    &TestSTMSupportPackage_DW.SFunctionBuilder_DSTATE);

  /* S-Function "LED_CustomBlock_wrapper" Block: <Root>/S-Function Builder */
  LED_CustomBlock_Update_wrapper(&TestSTMSupportPackage_P.Constant_Value,
    &TestSTMSupportPackage_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(0, TestSTMSupportPackage_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(TestSTMSupportPackage_M)!=-1) &&
        !((rtmGetTFinal(TestSTMSupportPackage_M)-
           TestSTMSupportPackage_M->Timing.taskTime0) >
          TestSTMSupportPackage_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(TestSTMSupportPackage_M, "Simulation finished");
    }

    if (rtmGetStopRequested(TestSTMSupportPackage_M)) {
      rtmSetErrorStatus(TestSTMSupportPackage_M, "Simulation finished");
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
  if (!(++TestSTMSupportPackage_M->Timing.clockTick0)) {
    ++TestSTMSupportPackage_M->Timing.clockTickH0;
  }

  TestSTMSupportPackage_M->Timing.taskTime0 =
    TestSTMSupportPackage_M->Timing.clockTick0 *
    TestSTMSupportPackage_M->Timing.stepSize0 +
    TestSTMSupportPackage_M->Timing.clockTickH0 *
    TestSTMSupportPackage_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void TestSTMSupportPackage_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)TestSTMSupportPackage_M, 0,
                sizeof(RT_MODEL_TestSTMSupportPackag_T));
  rtmSetTFinal(TestSTMSupportPackage_M, -1);
  TestSTMSupportPackage_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  TestSTMSupportPackage_M->Sizes.checksums[0] = (3189477022U);
  TestSTMSupportPackage_M->Sizes.checksums[1] = (786592663U);
  TestSTMSupportPackage_M->Sizes.checksums[2] = (1290981471U);
  TestSTMSupportPackage_M->Sizes.checksums[3] = (2455615455U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    TestSTMSupportPackage_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TestSTMSupportPackage_M->extModeInfo,
      &TestSTMSupportPackage_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TestSTMSupportPackage_M->extModeInfo,
                        TestSTMSupportPackage_M->Sizes.checksums);
    rteiSetTPtr(TestSTMSupportPackage_M->extModeInfo, rtmGetTPtr
                (TestSTMSupportPackage_M));
  }

  /* states (dwork) */
  (void) memset((void *)&TestSTMSupportPackage_DW, 0,
                sizeof(DW_TestSTMSupportPackage_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TestSTMSupportPackage_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (stm32f4_do_write): '<Root>/GPIO Write' */
  MW_GpioInit(3U, 8192U, 1U, 2U, 0U, 1U);
  MW_GPIO_WriteBit(3U, 13U, 1U);

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        TestSTMSupportPackage_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void TestSTMSupportPackage_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
