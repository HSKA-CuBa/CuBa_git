/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SingleBlockSensoren.h
 *
 * Code generated for Simulink model 'SingleBlockSensoren'.
 *
 * Model version                  : 1.56
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sat Jul 30 09:46:21 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SingleBlockSensoren_h_
#define RTW_HEADER_SingleBlockSensoren_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef SingleBlockSensoren_COMMON_INCLUDES_
# define SingleBlockSensoren_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* SingleBlockSensoren_COMMON_INCLUDES_ */

#include "SingleBlockSensoren_types.h"

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
  int16_T SFunctionBuilder2_o1;        /* '<Root>/S-Function Builder2' */
  int16_T SFunctionBuilder2_o2;        /* '<Root>/S-Function Builder2' */
} B_SingleBlockSensoren_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder2_DSTATE;     /* '<Root>/S-Function Builder2' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_SingleBlockSensoren_T;

/* Parameters (auto storage) */
struct P_SingleBlockSensoren_T_ {
  uint32_T SFunctionBuilder2_P1;       /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/S-Function Builder2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SingleBlockSensoren_T {
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
extern P_SingleBlockSensoren_T SingleBlockSensoren_P;

/* Block signals (auto storage) */
extern B_SingleBlockSensoren_T SingleBlockSensoren_B;

/* Block states (auto storage) */
extern DW_SingleBlockSensoren_T SingleBlockSensoren_DW;

/* Model entry point functions */
extern void SingleBlockSensoren_initialize(void);
extern void SingleBlockSensoren_step(void);
extern void SingleBlockSensoren_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SingleBlockSensoren_T *const SingleBlockSensoren_M;

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
 * '<Root>' : 'SingleBlockSensoren'
 */
#endif                                 /* RTW_HEADER_SingleBlockSensoren_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
