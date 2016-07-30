/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestMPU6050.h
 *
 * Code generated for Simulink model 'TestMPU6050'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sat Jul 30 20:04:58 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestMPU6050_h_
#define RTW_HEADER_TestMPU6050_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef TestMPU6050_COMMON_INCLUDES_
# define TestMPU6050_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* TestMPU6050_COMMON_INCLUDES_ */

#include "TestMPU6050_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  int16_T SFunctionBuilder1_o1;        /* '<Root>/S-Function Builder1' */
  int16_T SFunctionBuilder1_o2;        /* '<Root>/S-Function Builder1' */
  int16_T SFunctionBuilder1_o3;        /* '<Root>/S-Function Builder1' */
  int16_T SFunctionBuilder1_o4;        /* '<Root>/S-Function Builder1' */
  int16_T SFunctionBuilder1_o5;        /* '<Root>/S-Function Builder1' */
  int16_T SFunctionBuilder1_o6;        /* '<Root>/S-Function Builder1' */
  int16_T SFunctionBuilder2_o1;        /* '<Root>/S-Function Builder2' */
  int16_T SFunctionBuilder2_o2;        /* '<Root>/S-Function Builder2' */
  int16_T SFunctionBuilder2_o3;        /* '<Root>/S-Function Builder2' */
  int16_T SFunctionBuilder2_o4;        /* '<Root>/S-Function Builder2' */
  int16_T SFunctionBuilder2_o5;        /* '<Root>/S-Function Builder2' */
  int16_T SFunctionBuilder2_o6;        /* '<Root>/S-Function Builder2' */
} B_TestMPU6050_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder1_DSTATE;     /* '<Root>/S-Function Builder1' */
  real_T SFunctionBuilder2_DSTATE;     /* '<Root>/S-Function Builder2' */
  struct {
    void *LoggedData[6];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[6];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_TestMPU6050_T;

/* Parameters (auto storage) */
struct P_TestMPU6050_T_ {
  uint32_T SFunctionBuilder1_P2;       /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/S-Function Builder1'
                                        */
  uint32_T SFunctionBuilder2_P2;       /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/S-Function Builder2'
                                        */
  boolean_T SFunctionBuilder1_P1;      /* Expression: boolean(AD0PinLevel)
                                        * Referenced by: '<Root>/S-Function Builder1'
                                        */
  boolean_T SFunctionBuilder2_P1;      /* Expression: boolean(AD0PinLevel)
                                        * Referenced by: '<Root>/S-Function Builder2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TestMPU6050_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_TestMPU6050_T TestMPU6050_P;

/* Block signals (auto storage) */
extern B_TestMPU6050_T TestMPU6050_B;

/* Block states (auto storage) */
extern DW_TestMPU6050_T TestMPU6050_DW;

/* Model entry point functions */
extern void TestMPU6050_initialize(void);
extern void TestMPU6050_step(void);
extern void TestMPU6050_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestMPU6050_T *const TestMPU6050_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TestMPU6050'
 */
#endif                                 /* RTW_HEADER_TestMPU6050_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
