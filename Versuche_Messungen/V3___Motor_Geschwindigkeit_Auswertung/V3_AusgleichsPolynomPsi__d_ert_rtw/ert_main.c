/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'V3_AusgleichsPolynomPsi__d'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Aug 22 14:03:57 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "V3_AusgleichsPolynomPsi__d.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  __enable_irq();
  V3_AusgleichsPolynomPsi__d_step();

  /* Get model outputs here */
  __disable_irq();
  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.01;
  float systemClock = 168;

#ifndef USE_RTX

  __disable_irq();

#endif

  ;
  stm32f4xx_init_board();
  SystemCoreClockUpdate();
  bootloaderInit();
  rtmSetErrorStatus(V3_AusgleichsPolynomPsi__d_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  V3_AusgleichsPolynomPsi__d_initialize();
  __enable_irq();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(V3_AusgleichsPolynomPsi__d_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(V3_AusgleichsPolynomPsi__d_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(V3_AusgleichsPolynomPsi__d_M, true);
    }
  }

  rtERTExtModeStartMsg();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    (rtmGetErrorStatus(V3_AusgleichsPolynomPsi__d_M) == (NULL)) &&
    !rtmGetStopRequested(V3_AusgleichsPolynomPsi__d_M);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(V3_AusgleichsPolynomPsi__d_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(V3_AusgleichsPolynomPsi__d_M, true);
      }
    }

    runModel =
      (rtmGetErrorStatus(V3_AusgleichsPolynomPsi__d_M) == (NULL)) &&
      !rtmGetStopRequested(V3_AusgleichsPolynomPsi__d_M);
  }

  rtExtModeShutdown(1);

#ifndef USE_RTX

  (void)systemClock;

#endif

  ;

  /* Disable rt_OneStep() here */

  /* Terminate model */
  V3_AusgleichsPolynomPsi__d_terminate();
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
