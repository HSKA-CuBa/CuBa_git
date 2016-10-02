/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: V6___LQR_Regelung.h
 *
 * Code generated for Simulink model 'V6___LQR_Regelung'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Sep 05 11:52:48 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_V6___LQR_Regelung_h_
#define RTW_HEADER_V6___LQR_Regelung_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef V6___LQR_Regelung_COMMON_INCLUDES_
# define V6___LQR_Regelung_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* V6___LQR_Regelung_COMMON_INCLUDES_ */

#include "V6___LQR_Regelung_types.h"

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
  real_T WinkelOffset1;                /* '<Root>/WinkelOffset1' */
  real_T DiscreteFIRFilter;            /* '<Root>/Discrete FIR Filter' */
  real32_T SFunctionBuilder2_o1;       /* '<Root>/S-Function Builder2' */
  real32_T SFunctionBuilder2_o2;       /* '<Root>/S-Function Builder2' */
  real32_T SFunctionBuilder2_o3;       /* '<Root>/S-Function Builder2' */
  real32_T SFunctionBuilder2_o4;       /* '<Root>/S-Function Builder2' */
  real32_T DiscreteFIRFilter1;         /* '<Root>/Discrete FIR Filter1' */
  real32_T T_M;                        /* '<Root>/Sum' */
  real32_T phi_acc_deg;                /* '<Root>/radtodeg3' */
  real32_T phi_komp_deg;               /* '<Root>/radtodeg2' */
  real32_T phi_kalman__deg;            /* '<Root>/radtodeg1' */
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
  uint16_T SFunctionBuilder1;          /* '<Root>/S-Function Builder1' */
  boolean_T Compare;                   /* '<S1>/Compare' */
} B_V6___LQR_Regelung_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Sensor1_DSTATE;               /* '<Root>/Sensor1' */
  real_T Sensor2_DSTATE;               /* '<Root>/Sensor2' */
  real_T SFunctionBuilder2_DSTATE;     /* '<Root>/S-Function Builder2' */
  real_T DiscreteFIRFilter_states[3];  /* '<Root>/Discrete FIR Filter' */
  struct {
    void *LoggedData[2];
  } phi__d_scope_PWORK;                /* '<Root>/phi__d_scope' */

  struct {
    void *LoggedData[3];
  } phi_scope_PWORK;                   /* '<Root>/phi_scope' */

  struct {
    void *LoggedData[2];
  } psi__d_scope_PWORK;                /* '<Root>/psi__d_scope' */

  real32_T DiscreteFIRFilter1_states[3];/* '<Root>/Discrete FIR Filter1' */
  int32_T DiscreteFIRFilter1_circBuf;  /* '<Root>/Discrete FIR Filter1' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<Root>/Discrete FIR Filter' */
} DW_V6___LQR_Regelung_T;

/* Parameters (auto storage) */
struct P_V6___LQR_Regelung_T_ {
  real_T Kd[3];                        /* Variable: Kd
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real32_T BalanceArea_const;          /* Mask Parameter: BalanceArea_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 1017
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T phi_COG_Offset1_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/phi_COG_Offset1'
                                        */
  real_T DiscreteFIRFilter_InitialStates;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete FIR Filter'
                                          */
  real_T DiscreteFIRFilter_Coefficients[4];/* Expression: [0.25 0.25 0.25 0.25]
                                            * Referenced by: '<Root>/Discrete FIR Filter'
                                            */
  real32_T phi_COG_Offset_Value;       /* Computed Parameter: phi_COG_Offset_Value
                                        * Referenced by: '<Root>/phi_COG_Offset'
                                        */
  real32_T SFunctionBuilder2_P1;       /* Expression: single(0.02)
                                        * Referenced by: '<Root>/S-Function Builder2'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T DiscreteFIRFilter1_InitialState;/* Computed Parameter: DiscreteFIRFilter1_InitialState
                                            * Referenced by: '<Root>/Discrete FIR Filter1'
                                            */
  real32_T DiscreteFIRFilter1_Coefficients[4];/* Computed Parameter: DiscreteFIRFilter1_Coefficients
                                               * Referenced by: '<Root>/Discrete FIR Filter1'
                                               */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real32_T radtodeg3_Gain;             /* Computed Parameter: radtodeg3_Gain
                                        * Referenced by: '<Root>/radtodeg3'
                                        */
  real32_T radtodeg2_Gain;             /* Computed Parameter: radtodeg2_Gain
                                        * Referenced by: '<Root>/radtodeg2'
                                        */
  real32_T radtodeg1_Gain;             /* Computed Parameter: radtodeg1_Gain
                                        * Referenced by: '<Root>/radtodeg1'
                                        */
  uint32_T Sensor1_P2;                 /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/Sensor1'
                                        */
  uint32_T Sensor2_P2;                 /* Expression: uint32(LowPassBW)
                                        * Referenced by: '<Root>/Sensor2'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  boolean_T Sensor1_P1;                /* Expression: boolean(AD0PinLevel)
                                        * Referenced by: '<Root>/Sensor1'
                                        */
  boolean_T Sensor2_P1;                /* Expression: boolean(AD0PinLevel)
                                        * Referenced by: '<Root>/Sensor2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_V6___LQR_Regelung_T {
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
extern P_V6___LQR_Regelung_T V6___LQR_Regelung_P;

/* Block signals (auto storage) */
extern B_V6___LQR_Regelung_T V6___LQR_Regelung_B;

/* Block states (auto storage) */
extern DW_V6___LQR_Regelung_T V6___LQR_Regelung_DW;

/* Model entry point functions */
extern void V6___LQR_Regelung_initialize(void);
extern void V6___LQR_Regelung_step(void);
extern void V6___LQR_Regelung_terminate(void);

/* Real-time Model object */
extern RT_MODEL_V6___LQR_Regelung_T *const V6___LQR_Regelung_M;

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
 * '<Root>' : 'V6___LQR_Regelung'
 * '<S1>'   : 'V6___LQR_Regelung/BalanceArea'
 */
#endif                                 /* RTW_HEADER_V6___LQR_Regelung_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
