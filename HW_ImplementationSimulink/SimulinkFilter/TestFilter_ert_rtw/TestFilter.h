/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestFilter.h
 *
 * Code generated for Simulink model 'TestFilter'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Aug 24 18:27:22 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestFilter_h_
#define RTW_HEADER_TestFilter_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef TestFilter_COMMON_INCLUDES_
# define TestFilter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* TestFilter_COMMON_INCLUDES_ */

#include "TestFilter_types.h"

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
  real32_T SFunctionBuilder_o1;        /* '<Root>/S-Function Builder' */
  real32_T SFunctionBuilder_o2;        /* '<Root>/S-Function Builder' */
  real32_T SFunctionBuilder_o3;        /* '<Root>/S-Function Builder' */
  real32_T SFunctionBuilder_o4;        /* '<Root>/S-Function Builder' */
  real32_T radtodeg;                   /* '<Root>/radtodeg' */
  real32_T radtodeg1;                  /* '<Root>/radtodeg1' */
  real32_T radtodeg2;                  /* '<Root>/radtodeg2' */
  int16_T Sensor1_o1;                  /* '<Root>/Sensor1' */
  int16_T Sensor1_o2;                  /* '<Root>/Sensor1' */
  int16_T Sensor1_o3;                  /* '<Root>/Sensor1' */
  int16_T Sensor1_o4;                  /* '<Root>/Sensor1' */
  int16_T Sensor1_o5;                  /* '<Root>/Sensor1' */
  int16_T Sensor1_o6;                  /* '<Root>/Sensor1' */
  int16_T Sensor2_o1;                  /* '<Root>/Sensor2' */
  int16_T Sensor2_o2;                  /* '<Root>/Sensor2' */
  int16_T Sensor2_o3;                  /* '<Root>/Sensor2' */
  int16_T Sensor2_o4;                  /* '<Root>/Sensor2' */
  int16_T Sensor2_o5;                  /* '<Root>/Sensor2' */
  int16_T Sensor2_o6;                  /* '<Root>/Sensor2' */
} B_TestFilter_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Sensor1_DSTATE;               /* '<Root>/Sensor1' */
  real_T Sensor2_DSTATE;               /* '<Root>/Sensor2' */
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
  struct {
    void *LoggedData[4];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_TestFilter_T;

/* Parameters (auto storage) */
struct P_TestFilter_T_ {
  real32_T SFunctionBuilder_P1;        /* Expression: single(0.02)
                                        * Referenced by: '<Root>/S-Function Builder'
                                        */
  real32_T radtodeg_Gain;              /* Computed Parameter: radtodeg_Gain
                                        * Referenced by: '<Root>/radtodeg'
                                        */
  real32_T radtodeg1_Gain;             /* Computed Parameter: radtodeg1_Gain
                                        * Referenced by: '<Root>/radtodeg1'
                                        */
  real32_T radtodeg2_Gain;             /* Computed Parameter: radtodeg2_Gain
                                        * Referenced by: '<Root>/radtodeg2'
                                        */
  uint32_T Sensor1_P2;                 /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/Sensor1'
                                        */
  uint32_T Sensor2_P2;                 /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/Sensor2'
                                        */
  boolean_T Sensor1_P1;                /* Expression: boolean(AD0PinLevel)
                                        * Referenced by: '<Root>/Sensor1'
                                        */
  boolean_T Sensor2_P1;                /* Expression: boolean(AD0PinLevel)
                                        * Referenced by: '<Root>/Sensor2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TestFilter_T {
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
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_TestFilter_T TestFilter_P;

/* Block signals (auto storage) */
extern B_TestFilter_T TestFilter_B;

/* Block states (auto storage) */
extern DW_TestFilter_T TestFilter_DW;

/* Model entry point functions */
extern void TestFilter_initialize(void);
extern void TestFilter_step(void);
extern void TestFilter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestFilter_T *const TestFilter_M;

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
 * '<Root>' : 'TestFilter'
 */
#endif                                 /* RTW_HEADER_TestFilter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
