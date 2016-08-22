/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'GyroskopAuswertung'.
 *
 * Model version                  : 1.84
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Aug 22 13:44:50 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GyroskopAuswertung.h"
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
  GyroskopAuswertung_step();

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
  rtmSetErrorStatus(GyroskopAuswertung_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  GyroskopAuswertung_initialize();
  __enable_irq();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(GyroskopAuswertung_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(GyroskopAuswertung_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(GyroskopAuswertung_M, true);
    }
  }

  rtERTExtModeStartMsg();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    (rtmGetErrorStatus(GyroskopAuswertung_M) == (NULL)) && !rtmGetStopRequested
    (GyroskopAuswertung_M);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(GyroskopAuswertung_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(GyroskopAuswertung_M, true);
      }
    }

    runModel =
      (rtmGetErrorStatus(GyroskopAuswertung_M) == (NULL)) &&
      !rtmGetStopRequested(GyroskopAuswertung_M);
  }

  rtExtModeShutdown(1);

#ifndef USE_RTX

  (void)systemClock;

#endif

  ;

  /* Disable rt_OneStep() here */

  /* Terminate model */
  GyroskopAuswertung_terminate();
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
