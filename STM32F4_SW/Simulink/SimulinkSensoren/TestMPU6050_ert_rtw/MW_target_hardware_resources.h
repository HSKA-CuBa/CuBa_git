#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#include "SysTickScheduler.h"
#include "arm_cortex_m_multitasking.h"
#include "blapp_support.h"
#include "stm32f4discovery_wrapper.h"
#include "system_stm32f4xx.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE STM32F4-Discovery
#define MW_CONNECTIONINFO_SERIAL_BAUDRATE 460800
#define MW_CONNECTIONINFO_SERIAL_COMPORT COM6
#define MW_CONNECTIONINFO_SERIAL_VERBOSE 1
#define MW_EXTMODE_CONFIGURATION Serial
#define MW_EXTMODE_RUNNING on
#define MW_RTOS Baremetal
#define MW_RTOSBASERATETASKPRIORITY 40
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_RUNTIME_BOOTLOADERPROGRAMMINGSUPPORT 0
#define MW_RUNTIME_BOOTLOADERCHOICE 0
#define MW_RUNTIME_BOOTLOADERCOMPORT COM1
#define MW_RUNTIME_BOOTLOADERAPPLICATIONHASCOM 0
#define MW_RUNTIME_BOOTLOADERPROTECTEDTARGET 0
#define MW_RUNTIME_LOADNEWBOOTLOADER 1
#define MW_RUNTIME_BOOTLOADERCOMPATIBLEOS 1
#define MW_RUNTIME_SHOWPROTECTEDOPTIONS 0
#define MW_CLOCKING_CPUCLOCKRATEMHZ 168
#define MW_PIL_INTERFACE 0
#define MW_PIL_COMPORT COM1
#define MW_ADC_PRESCALER 0.000000
#define MW_ADC_DELAYSAMPLEPHASES 0.000000
#define MW_ADC_ENTEMPSENSVREFINT 0
#define MW_ADC_ENVBAT 0
#define MW_ADC_MULTIADC 0.000000
#define MW_ADC_MULTIADCMODE 0.000000
#define MW_ADC_DMAMODE 0.000000
#define MW_ADC_DMAENABLE 0
#define MW_ADC1_CONVRESOLUTION 0.000000
#define MW_ADC1_ENDISCONT 0
#define MW_ADC1_NBOFDISCONTCHL 0.000000
#define MW_ADC1_ENDISCONTINJ 0
#define MW_ADC1_DATAALIGN 0.000000
#define MW_ADC1_ENABLEWATCHDOG 0
#define MW_ADC1_ENABLEWATCHDOGINJ 0
#define MW_ADC1_WATCHDOGONCHANNEL 0.000000
#define MW_ADC1_WATCHDOGLOWTHR 0.000000
#define MW_ADC1_WATCHDOGHIGHTHR 4095.000000
#define MW_ADC1_SAMPLETIMECHL0 0.000000
#define MW_ADC1_SAMPLETIMECHL1 0.000000
#define MW_ADC1_SAMPLETIMECHL2 0.000000
#define MW_ADC1_SAMPLETIMECHL3 0.000000
#define MW_ADC1_SAMPLETIMECHL4 0.000000
#define MW_ADC1_SAMPLETIMECHL5 0.000000
#define MW_ADC1_SAMPLETIMECHL6 0.000000
#define MW_ADC1_SAMPLETIMECHL7 0.000000
#define MW_ADC1_SAMPLETIMECHL8 0.000000
#define MW_ADC1_SAMPLETIMECHL9 0.000000
#define MW_ADC1_SAMPLETIMECHL10 0.000000
#define MW_ADC1_SAMPLETIMECHL11 0.000000
#define MW_ADC1_SAMPLETIMECHL12 0.000000
#define MW_ADC1_SAMPLETIMECHL13 0.000000
#define MW_ADC1_SAMPLETIMECHL14 0.000000
#define MW_ADC1_SAMPLETIMECHL15 0.000000
#define MW_ADC1_SAMPLETIMECHL16 0.000000
#define MW_ADC1_SAMPLETIMECHL17 0.000000
#define MW_ADC1_SAMPLETIMECHL18 0.000000
#define MW_ADC2_CONVRESOLUTION 0.000000
#define MW_ADC2_ENDISCONT 0
#define MW_ADC2_NBOFDISCONTCHL 0.000000
#define MW_ADC2_ENDISCONTINJ 0
#define MW_ADC2_DATAALIGN 0.000000
#define MW_ADC2_ENABLEWATCHDOG 0
#define MW_ADC2_ENABLEWATCHDOGINJ 0
#define MW_ADC2_WATCHDOGONCHANNEL 0.000000
#define MW_ADC2_WATCHDOGLOWTHR 0.000000
#define MW_ADC2_WATCHDOGHIGHTHR 4095.000000
#define MW_ADC2_SAMPLETIMECHL0 0.000000
#define MW_ADC2_SAMPLETIMECHL1 0.000000
#define MW_ADC2_SAMPLETIMECHL2 0.000000
#define MW_ADC2_SAMPLETIMECHL3 0.000000
#define MW_ADC2_SAMPLETIMECHL4 0.000000
#define MW_ADC2_SAMPLETIMECHL5 0.000000
#define MW_ADC2_SAMPLETIMECHL6 0.000000
#define MW_ADC2_SAMPLETIMECHL7 0.000000
#define MW_ADC2_SAMPLETIMECHL8 0.000000
#define MW_ADC2_SAMPLETIMECHL9 0.000000
#define MW_ADC2_SAMPLETIMECHL10 0.000000
#define MW_ADC2_SAMPLETIMECHL11 0.000000
#define MW_ADC2_SAMPLETIMECHL12 0.000000
#define MW_ADC2_SAMPLETIMECHL13 0.000000
#define MW_ADC2_SAMPLETIMECHL14 0.000000
#define MW_ADC2_SAMPLETIMECHL15 0.000000
#define MW_ADC2_SAMPLETIMECHL16 0.000000
#define MW_ADC2_SAMPLETIMECHL17 0.000000
#define MW_ADC2_SAMPLETIMECHL18 0.000000
#define MW_ADC3_CONVRESOLUTION 0.000000
#define MW_ADC3_ENDISCONT 0
#define MW_ADC3_NBOFDISCONTCHL 0.000000
#define MW_ADC3_ENDISCONTINJ 0
#define MW_ADC3_DATAALIGN 0.000000
#define MW_ADC3_ENABLEWATCHDOG 0
#define MW_ADC3_ENABLEWATCHDOGINJ 0
#define MW_ADC3_WATCHDOGONCHANNEL 0.000000
#define MW_ADC3_WATCHDOGLOWTHR 0.000000
#define MW_ADC3_WATCHDOGHIGHTHR 4095.000000
#define MW_ADC3_SAMPLETIMECHL0 0.000000
#define MW_ADC3_SAMPLETIMECHL1 0.000000
#define MW_ADC3_SAMPLETIMECHL2 0.000000
#define MW_ADC3_SAMPLETIMECHL3 0.000000
#define MW_ADC3_SAMPLETIMECHL4 0.000000
#define MW_ADC3_SAMPLETIMECHL5 0.000000
#define MW_ADC3_SAMPLETIMECHL6 0.000000
#define MW_ADC3_SAMPLETIMECHL7 0.000000
#define MW_ADC3_SAMPLETIMECHL8 0.000000
#define MW_ADC3_SAMPLETIMECHL9 0.000000
#define MW_ADC3_SAMPLETIMECHL10 0.000000
#define MW_ADC3_SAMPLETIMECHL11 0.000000
#define MW_ADC3_SAMPLETIMECHL12 0.000000
#define MW_ADC3_SAMPLETIMECHL13 0.000000
#define MW_ADC3_SAMPLETIMECHL14 0.000000
#define MW_ADC3_SAMPLETIMECHL15 0.000000
#define MW_ADC3_SAMPLETIMECHL16 0.000000
#define MW_ADC3_SAMPLETIMECHL17 0.000000
#define MW_ADC3_SAMPLETIMECHL18 0.000000
#define MW_GPIOA_SHOWPINSETTING 0
#define MW_GPIOA_OUTTYPEREGPIN0 0
#define MW_GPIOA_OUTSPEEDREGPIN0 0
#define MW_GPIOA_PUPDREGPIN0 0
#define MW_GPIOA_OUTTYPEREGPIN1 0
#define MW_GPIOA_OUTSPEEDREGPIN1 0
#define MW_GPIOA_PUPDREGPIN1 0
#define MW_GPIOA_OUTTYPEREGPIN2 0
#define MW_GPIOA_OUTSPEEDREGPIN2 0
#define MW_GPIOA_PUPDREGPIN2 0
#define MW_GPIOA_OUTTYPEREGPIN3 0
#define MW_GPIOA_OUTSPEEDREGPIN3 0
#define MW_GPIOA_PUPDREGPIN3 0
#define MW_GPIOA_OUTTYPEREGPIN4 0
#define MW_GPIOA_OUTSPEEDREGPIN4 0
#define MW_GPIOA_PUPDREGPIN4 0
#define MW_GPIOA_OUTTYPEREGPIN5 0
#define MW_GPIOA_OUTSPEEDREGPIN5 0
#define MW_GPIOA_PUPDREGPIN5 0
#define MW_GPIOA_OUTTYPEREGPIN6 0
#define MW_GPIOA_OUTSPEEDREGPIN6 0
#define MW_GPIOA_PUPDREGPIN6 0
#define MW_GPIOA_OUTTYPEREGPIN7 0
#define MW_GPIOA_OUTSPEEDREGPIN7 0
#define MW_GPIOA_PUPDREGPIN7 0
#define MW_GPIOA_OUTTYPEREGPIN8 0
#define MW_GPIOA_OUTSPEEDREGPIN8 0
#define MW_GPIOA_PUPDREGPIN8 0
#define MW_GPIOA_OUTTYPEREGPIN9 0
#define MW_GPIOA_OUTSPEEDREGPIN9 0
#define MW_GPIOA_PUPDREGPIN9 0
#define MW_GPIOA_OUTTYPEREGPIN10 0
#define MW_GPIOA_OUTSPEEDREGPIN10 0
#define MW_GPIOA_PUPDREGPIN10 0
#define MW_GPIOA_OUTTYPEREGPIN11 0
#define MW_GPIOA_OUTSPEEDREGPIN11 0
#define MW_GPIOA_PUPDREGPIN11 0
#define MW_GPIOA_OUTTYPEREGPIN12 0
#define MW_GPIOA_OUTSPEEDREGPIN12 0
#define MW_GPIOA_PUPDREGPIN12 0
#define MW_GPIOA_OUTTYPEREGPIN13 0
#define MW_GPIOA_OUTSPEEDREGPIN13 0
#define MW_GPIOA_PUPDREGPIN13 0
#define MW_GPIOA_OUTTYPEREGPIN14 0
#define MW_GPIOA_OUTSPEEDREGPIN14 0
#define MW_GPIOA_PUPDREGPIN14 0
#define MW_GPIOA_OUTTYPEREGPIN15 0
#define MW_GPIOA_OUTSPEEDREGPIN15 0
#define MW_GPIOA_PUPDREGPIN15 0
#define MW_GPIOB_SHOWPINSETTING 0
#define MW_GPIOB_OUTTYPEREGPIN0 0
#define MW_GPIOB_OUTSPEEDREGPIN0 0
#define MW_GPIOB_PUPDREGPIN0 0
#define MW_GPIOB_OUTTYPEREGPIN1 0
#define MW_GPIOB_OUTSPEEDREGPIN1 0
#define MW_GPIOB_PUPDREGPIN1 0
#define MW_GPIOB_OUTTYPEREGPIN2 0
#define MW_GPIOB_OUTSPEEDREGPIN2 0
#define MW_GPIOB_PUPDREGPIN2 0
#define MW_GPIOB_OUTTYPEREGPIN3 0
#define MW_GPIOB_OUTSPEEDREGPIN3 0
#define MW_GPIOB_PUPDREGPIN3 0
#define MW_GPIOB_OUTTYPEREGPIN4 0
#define MW_GPIOB_OUTSPEEDREGPIN4 0
#define MW_GPIOB_PUPDREGPIN4 0
#define MW_GPIOB_OUTTYPEREGPIN5 0
#define MW_GPIOB_OUTSPEEDREGPIN5 0
#define MW_GPIOB_PUPDREGPIN5 0
#define MW_GPIOB_OUTTYPEREGPIN6 0
#define MW_GPIOB_OUTSPEEDREGPIN6 0
#define MW_GPIOB_PUPDREGPIN6 0
#define MW_GPIOB_OUTTYPEREGPIN7 0
#define MW_GPIOB_OUTSPEEDREGPIN7 0
#define MW_GPIOB_PUPDREGPIN7 0
#define MW_GPIOB_OUTTYPEREGPIN8 0
#define MW_GPIOB_OUTSPEEDREGPIN8 0
#define MW_GPIOB_PUPDREGPIN8 0
#define MW_GPIOB_OUTTYPEREGPIN9 0
#define MW_GPIOB_OUTSPEEDREGPIN9 0
#define MW_GPIOB_PUPDREGPIN9 0
#define MW_GPIOB_OUTTYPEREGPIN10 0
#define MW_GPIOB_OUTSPEEDREGPIN10 0
#define MW_GPIOB_PUPDREGPIN10 0
#define MW_GPIOB_OUTTYPEREGPIN11 0
#define MW_GPIOB_OUTSPEEDREGPIN11 0
#define MW_GPIOB_PUPDREGPIN11 0
#define MW_GPIOB_OUTTYPEREGPIN12 0
#define MW_GPIOB_OUTSPEEDREGPIN12 0
#define MW_GPIOB_PUPDREGPIN12 0
#define MW_GPIOB_OUTTYPEREGPIN13 0
#define MW_GPIOB_OUTSPEEDREGPIN13 0
#define MW_GPIOB_PUPDREGPIN13 0
#define MW_GPIOB_OUTTYPEREGPIN14 0
#define MW_GPIOB_OUTSPEEDREGPIN14 0
#define MW_GPIOB_PUPDREGPIN14 0
#define MW_GPIOB_OUTTYPEREGPIN15 0
#define MW_GPIOB_OUTSPEEDREGPIN15 0
#define MW_GPIOB_PUPDREGPIN15 0
#define MW_GPIOC_SHOWPINSETTING 0
#define MW_GPIOC_OUTTYPEREGPIN0 0
#define MW_GPIOC_OUTSPEEDREGPIN0 0
#define MW_GPIOC_PUPDREGPIN0 0
#define MW_GPIOC_OUTTYPEREGPIN1 0
#define MW_GPIOC_OUTSPEEDREGPIN1 0
#define MW_GPIOC_PUPDREGPIN1 0
#define MW_GPIOC_OUTTYPEREGPIN2 0
#define MW_GPIOC_OUTSPEEDREGPIN2 0
#define MW_GPIOC_PUPDREGPIN2 0
#define MW_GPIOC_OUTTYPEREGPIN3 0
#define MW_GPIOC_OUTSPEEDREGPIN3 0
#define MW_GPIOC_PUPDREGPIN3 0
#define MW_GPIOC_OUTTYPEREGPIN4 0
#define MW_GPIOC_OUTSPEEDREGPIN4 0
#define MW_GPIOC_PUPDREGPIN4 0
#define MW_GPIOC_OUTTYPEREGPIN5 0
#define MW_GPIOC_OUTSPEEDREGPIN5 0
#define MW_GPIOC_PUPDREGPIN5 0
#define MW_GPIOC_OUTTYPEREGPIN6 0
#define MW_GPIOC_OUTSPEEDREGPIN6 0
#define MW_GPIOC_PUPDREGPIN6 0
#define MW_GPIOC_OUTTYPEREGPIN7 0
#define MW_GPIOC_OUTSPEEDREGPIN7 0
#define MW_GPIOC_PUPDREGPIN7 0
#define MW_GPIOC_OUTTYPEREGPIN8 0
#define MW_GPIOC_OUTSPEEDREGPIN8 0
#define MW_GPIOC_PUPDREGPIN8 0
#define MW_GPIOC_OUTTYPEREGPIN9 0
#define MW_GPIOC_OUTSPEEDREGPIN9 0
#define MW_GPIOC_PUPDREGPIN9 0
#define MW_GPIOC_OUTTYPEREGPIN10 0
#define MW_GPIOC_OUTSPEEDREGPIN10 0
#define MW_GPIOC_PUPDREGPIN10 0
#define MW_GPIOC_OUTTYPEREGPIN11 0
#define MW_GPIOC_OUTSPEEDREGPIN11 0
#define MW_GPIOC_PUPDREGPIN11 0
#define MW_GPIOC_OUTTYPEREGPIN12 0
#define MW_GPIOC_OUTSPEEDREGPIN12 0
#define MW_GPIOC_PUPDREGPIN12 0
#define MW_GPIOC_OUTTYPEREGPIN13 0
#define MW_GPIOC_OUTSPEEDREGPIN13 0
#define MW_GPIOC_PUPDREGPIN13 0
#define MW_GPIOC_OUTTYPEREGPIN14 0
#define MW_GPIOC_OUTSPEEDREGPIN14 0
#define MW_GPIOC_PUPDREGPIN14 0
#define MW_GPIOC_OUTTYPEREGPIN15 0
#define MW_GPIOC_OUTSPEEDREGPIN15 0
#define MW_GPIOC_PUPDREGPIN15 0
#define MW_GPIOD_SHOWPINSETTING 0
#define MW_GPIOD_OUTTYPEREGPIN0 0
#define MW_GPIOD_OUTSPEEDREGPIN0 0
#define MW_GPIOD_PUPDREGPIN0 0
#define MW_GPIOD_OUTTYPEREGPIN1 0
#define MW_GPIOD_OUTSPEEDREGPIN1 0
#define MW_GPIOD_PUPDREGPIN1 0
#define MW_GPIOD_OUTTYPEREGPIN2 0
#define MW_GPIOD_OUTSPEEDREGPIN2 0
#define MW_GPIOD_PUPDREGPIN2 0
#define MW_GPIOD_OUTTYPEREGPIN3 0
#define MW_GPIOD_OUTSPEEDREGPIN3 0
#define MW_GPIOD_PUPDREGPIN3 0
#define MW_GPIOD_OUTTYPEREGPIN4 0
#define MW_GPIOD_OUTSPEEDREGPIN4 0
#define MW_GPIOD_PUPDREGPIN4 0
#define MW_GPIOD_OUTTYPEREGPIN5 0
#define MW_GPIOD_OUTSPEEDREGPIN5 0
#define MW_GPIOD_PUPDREGPIN5 0
#define MW_GPIOD_OUTTYPEREGPIN6 0
#define MW_GPIOD_OUTSPEEDREGPIN6 0
#define MW_GPIOD_PUPDREGPIN6 0
#define MW_GPIOD_OUTTYPEREGPIN7 0
#define MW_GPIOD_OUTSPEEDREGPIN7 0
#define MW_GPIOD_PUPDREGPIN7 0
#define MW_GPIOD_OUTTYPEREGPIN8 0
#define MW_GPIOD_OUTSPEEDREGPIN8 0
#define MW_GPIOD_PUPDREGPIN8 0
#define MW_GPIOD_OUTTYPEREGPIN9 0
#define MW_GPIOD_OUTSPEEDREGPIN9 0
#define MW_GPIOD_PUPDREGPIN9 0
#define MW_GPIOD_OUTTYPEREGPIN10 0
#define MW_GPIOD_OUTSPEEDREGPIN10 0
#define MW_GPIOD_PUPDREGPIN10 0
#define MW_GPIOD_OUTTYPEREGPIN11 0
#define MW_GPIOD_OUTSPEEDREGPIN11 0
#define MW_GPIOD_PUPDREGPIN11 0
#define MW_GPIOD_OUTTYPEREGPIN12 0
#define MW_GPIOD_OUTSPEEDREGPIN12 0
#define MW_GPIOD_PUPDREGPIN12 0
#define MW_GPIOD_OUTTYPEREGPIN13 0
#define MW_GPIOD_OUTSPEEDREGPIN13 0
#define MW_GPIOD_PUPDREGPIN13 0
#define MW_GPIOD_OUTTYPEREGPIN14 0
#define MW_GPIOD_OUTSPEEDREGPIN14 0
#define MW_GPIOD_PUPDREGPIN14 0
#define MW_GPIOD_OUTTYPEREGPIN15 0
#define MW_GPIOD_OUTSPEEDREGPIN15 0
#define MW_GPIOD_PUPDREGPIN15 0
#define MW_GPIOE_SHOWPINSETTING 0
#define MW_GPIOE_OUTTYPEREGPIN0 0
#define MW_GPIOE_OUTSPEEDREGPIN0 0
#define MW_GPIOE_PUPDREGPIN0 0
#define MW_GPIOE_OUTTYPEREGPIN1 0
#define MW_GPIOE_OUTSPEEDREGPIN1 0
#define MW_GPIOE_PUPDREGPIN1 0
#define MW_GPIOE_OUTTYPEREGPIN2 0
#define MW_GPIOE_OUTSPEEDREGPIN2 0
#define MW_GPIOE_PUPDREGPIN2 0
#define MW_GPIOE_OUTTYPEREGPIN3 0
#define MW_GPIOE_OUTSPEEDREGPIN3 0
#define MW_GPIOE_PUPDREGPIN3 0
#define MW_GPIOE_OUTTYPEREGPIN4 0
#define MW_GPIOE_OUTSPEEDREGPIN4 0
#define MW_GPIOE_PUPDREGPIN4 0
#define MW_GPIOE_OUTTYPEREGPIN5 0
#define MW_GPIOE_OUTSPEEDREGPIN5 0
#define MW_GPIOE_PUPDREGPIN5 0
#define MW_GPIOE_OUTTYPEREGPIN6 0
#define MW_GPIOE_OUTSPEEDREGPIN6 0
#define MW_GPIOE_PUPDREGPIN6 0
#define MW_GPIOE_OUTTYPEREGPIN7 0
#define MW_GPIOE_OUTSPEEDREGPIN7 0
#define MW_GPIOE_PUPDREGPIN7 0
#define MW_GPIOE_OUTTYPEREGPIN8 0
#define MW_GPIOE_OUTSPEEDREGPIN8 0
#define MW_GPIOE_PUPDREGPIN8 0
#define MW_GPIOE_OUTTYPEREGPIN9 0
#define MW_GPIOE_OUTSPEEDREGPIN9 0
#define MW_GPIOE_PUPDREGPIN9 0
#define MW_GPIOE_OUTTYPEREGPIN10 0
#define MW_GPIOE_OUTSPEEDREGPIN10 0
#define MW_GPIOE_PUPDREGPIN10 0
#define MW_GPIOE_OUTTYPEREGPIN11 0
#define MW_GPIOE_OUTSPEEDREGPIN11 0
#define MW_GPIOE_PUPDREGPIN11 0
#define MW_GPIOE_OUTTYPEREGPIN12 0
#define MW_GPIOE_OUTSPEEDREGPIN12 0
#define MW_GPIOE_PUPDREGPIN12 0
#define MW_GPIOE_OUTTYPEREGPIN13 0
#define MW_GPIOE_OUTSPEEDREGPIN13 0
#define MW_GPIOE_PUPDREGPIN13 0
#define MW_GPIOE_OUTTYPEREGPIN14 0
#define MW_GPIOE_OUTSPEEDREGPIN14 0
#define MW_GPIOE_PUPDREGPIN14 0
#define MW_GPIOE_OUTTYPEREGPIN15 0
#define MW_GPIOE_OUTSPEEDREGPIN15 0
#define MW_GPIOE_PUPDREGPIN15 0
#define MW_GPIOF_SHOWPINSETTING 0
#define MW_GPIOF_OUTTYPEREGPIN0 0
#define MW_GPIOF_OUTSPEEDREGPIN0 0
#define MW_GPIOF_PUPDREGPIN0 0
#define MW_GPIOF_OUTTYPEREGPIN1 0
#define MW_GPIOF_OUTSPEEDREGPIN1 0
#define MW_GPIOF_PUPDREGPIN1 0
#define MW_GPIOF_OUTTYPEREGPIN2 0
#define MW_GPIOF_OUTSPEEDREGPIN2 0
#define MW_GPIOF_PUPDREGPIN2 0
#define MW_GPIOF_OUTTYPEREGPIN3 0
#define MW_GPIOF_OUTSPEEDREGPIN3 0
#define MW_GPIOF_PUPDREGPIN3 0
#define MW_GPIOF_OUTTYPEREGPIN4 0
#define MW_GPIOF_OUTSPEEDREGPIN4 0
#define MW_GPIOF_PUPDREGPIN4 0
#define MW_GPIOF_OUTTYPEREGPIN5 0
#define MW_GPIOF_OUTSPEEDREGPIN5 0
#define MW_GPIOF_PUPDREGPIN5 0
#define MW_GPIOF_OUTTYPEREGPIN6 0
#define MW_GPIOF_OUTSPEEDREGPIN6 0
#define MW_GPIOF_PUPDREGPIN6 0
#define MW_GPIOF_OUTTYPEREGPIN7 0
#define MW_GPIOF_OUTSPEEDREGPIN7 0
#define MW_GPIOF_PUPDREGPIN7 0
#define MW_GPIOF_OUTTYPEREGPIN8 0
#define MW_GPIOF_OUTSPEEDREGPIN8 0
#define MW_GPIOF_PUPDREGPIN8 0
#define MW_GPIOF_OUTTYPEREGPIN9 0
#define MW_GPIOF_OUTSPEEDREGPIN9 0
#define MW_GPIOF_PUPDREGPIN9 0
#define MW_GPIOF_OUTTYPEREGPIN10 0
#define MW_GPIOF_OUTSPEEDREGPIN10 0
#define MW_GPIOF_PUPDREGPIN10 0
#define MW_GPIOF_OUTTYPEREGPIN11 0
#define MW_GPIOF_OUTSPEEDREGPIN11 0
#define MW_GPIOF_PUPDREGPIN11 0
#define MW_GPIOF_OUTTYPEREGPIN12 0
#define MW_GPIOF_OUTSPEEDREGPIN12 0
#define MW_GPIOF_PUPDREGPIN12 0
#define MW_GPIOF_OUTTYPEREGPIN13 0
#define MW_GPIOF_OUTSPEEDREGPIN13 0
#define MW_GPIOF_PUPDREGPIN13 0
#define MW_GPIOF_OUTTYPEREGPIN14 0
#define MW_GPIOF_OUTSPEEDREGPIN14 0
#define MW_GPIOF_PUPDREGPIN14 0
#define MW_GPIOF_OUTTYPEREGPIN15 0
#define MW_GPIOF_OUTSPEEDREGPIN15 0
#define MW_GPIOF_PUPDREGPIN15 0
#define MW_GPIOG_SHOWPINSETTING 0
#define MW_GPIOG_OUTTYPEREGPIN0 0
#define MW_GPIOG_OUTSPEEDREGPIN0 0
#define MW_GPIOG_PUPDREGPIN0 0
#define MW_GPIOG_OUTTYPEREGPIN1 0
#define MW_GPIOG_OUTSPEEDREGPIN1 0
#define MW_GPIOG_PUPDREGPIN1 0
#define MW_GPIOG_OUTTYPEREGPIN2 0
#define MW_GPIOG_OUTSPEEDREGPIN2 0
#define MW_GPIOG_PUPDREGPIN2 0
#define MW_GPIOG_OUTTYPEREGPIN3 0
#define MW_GPIOG_OUTSPEEDREGPIN3 0
#define MW_GPIOG_PUPDREGPIN3 0
#define MW_GPIOG_OUTTYPEREGPIN4 0
#define MW_GPIOG_OUTSPEEDREGPIN4 0
#define MW_GPIOG_PUPDREGPIN4 0
#define MW_GPIOG_OUTTYPEREGPIN5 0
#define MW_GPIOG_OUTSPEEDREGPIN5 0
#define MW_GPIOG_PUPDREGPIN5 0
#define MW_GPIOG_OUTTYPEREGPIN6 0
#define MW_GPIOG_OUTSPEEDREGPIN6 0
#define MW_GPIOG_PUPDREGPIN6 0
#define MW_GPIOG_OUTTYPEREGPIN7 0
#define MW_GPIOG_OUTSPEEDREGPIN7 0
#define MW_GPIOG_PUPDREGPIN7 0
#define MW_GPIOG_OUTTYPEREGPIN8 0
#define MW_GPIOG_OUTSPEEDREGPIN8 0
#define MW_GPIOG_PUPDREGPIN8 0
#define MW_GPIOG_OUTTYPEREGPIN9 0
#define MW_GPIOG_OUTSPEEDREGPIN9 0
#define MW_GPIOG_PUPDREGPIN9 0
#define MW_GPIOG_OUTTYPEREGPIN10 0
#define MW_GPIOG_OUTSPEEDREGPIN10 0
#define MW_GPIOG_PUPDREGPIN10 0
#define MW_GPIOG_OUTTYPEREGPIN11 0
#define MW_GPIOG_OUTSPEEDREGPIN11 0
#define MW_GPIOG_PUPDREGPIN11 0
#define MW_GPIOG_OUTTYPEREGPIN12 0
#define MW_GPIOG_OUTSPEEDREGPIN12 0
#define MW_GPIOG_PUPDREGPIN12 0
#define MW_GPIOG_OUTTYPEREGPIN13 0
#define MW_GPIOG_OUTSPEEDREGPIN13 0
#define MW_GPIOG_PUPDREGPIN13 0
#define MW_GPIOG_OUTTYPEREGPIN14 0
#define MW_GPIOG_OUTSPEEDREGPIN14 0
#define MW_GPIOG_PUPDREGPIN14 0
#define MW_GPIOG_OUTTYPEREGPIN15 0
#define MW_GPIOG_OUTSPEEDREGPIN15 0
#define MW_GPIOG_PUPDREGPIN15 0
#define MW_GPIOH_SHOWPINSETTING 0
#define MW_GPIOH_OUTTYPEREGPIN0 0
#define MW_GPIOH_OUTSPEEDREGPIN0 0
#define MW_GPIOH_PUPDREGPIN0 0
#define MW_GPIOH_OUTTYPEREGPIN1 0
#define MW_GPIOH_OUTSPEEDREGPIN1 0
#define MW_GPIOH_PUPDREGPIN1 0
#define MW_GPIOH_OUTTYPEREGPIN2 0
#define MW_GPIOH_OUTSPEEDREGPIN2 0
#define MW_GPIOH_PUPDREGPIN2 0
#define MW_GPIOH_OUTTYPEREGPIN3 0
#define MW_GPIOH_OUTSPEEDREGPIN3 0
#define MW_GPIOH_PUPDREGPIN3 0
#define MW_GPIOH_OUTTYPEREGPIN4 0
#define MW_GPIOH_OUTSPEEDREGPIN4 0
#define MW_GPIOH_PUPDREGPIN4 0
#define MW_GPIOH_OUTTYPEREGPIN5 0
#define MW_GPIOH_OUTSPEEDREGPIN5 0
#define MW_GPIOH_PUPDREGPIN5 0
#define MW_GPIOH_OUTTYPEREGPIN6 0
#define MW_GPIOH_OUTSPEEDREGPIN6 0
#define MW_GPIOH_PUPDREGPIN6 0
#define MW_GPIOH_OUTTYPEREGPIN7 0
#define MW_GPIOH_OUTSPEEDREGPIN7 0
#define MW_GPIOH_PUPDREGPIN7 0
#define MW_GPIOH_OUTTYPEREGPIN8 0
#define MW_GPIOH_OUTSPEEDREGPIN8 0
#define MW_GPIOH_PUPDREGPIN8 0
#define MW_GPIOH_OUTTYPEREGPIN9 0
#define MW_GPIOH_OUTSPEEDREGPIN9 0
#define MW_GPIOH_PUPDREGPIN9 0
#define MW_GPIOH_OUTTYPEREGPIN10 0
#define MW_GPIOH_OUTSPEEDREGPIN10 0
#define MW_GPIOH_PUPDREGPIN10 0
#define MW_GPIOH_OUTTYPEREGPIN11 0
#define MW_GPIOH_OUTSPEEDREGPIN11 0
#define MW_GPIOH_PUPDREGPIN11 0
#define MW_GPIOH_OUTTYPEREGPIN12 0
#define MW_GPIOH_OUTSPEEDREGPIN12 0
#define MW_GPIOH_PUPDREGPIN12 0
#define MW_GPIOH_OUTTYPEREGPIN13 0
#define MW_GPIOH_OUTSPEEDREGPIN13 0
#define MW_GPIOH_PUPDREGPIN13 0
#define MW_GPIOH_OUTTYPEREGPIN14 0
#define MW_GPIOH_OUTSPEEDREGPIN14 0
#define MW_GPIOH_PUPDREGPIN14 0
#define MW_GPIOH_OUTTYPEREGPIN15 0
#define MW_GPIOH_OUTSPEEDREGPIN15 0
#define MW_GPIOH_PUPDREGPIN15 0
#define MW_GPIOI_SHOWPINSETTING 0
#define MW_GPIOI_OUTTYPEREGPIN0 0
#define MW_GPIOI_OUTSPEEDREGPIN0 0
#define MW_GPIOI_PUPDREGPIN0 0
#define MW_GPIOI_OUTTYPEREGPIN1 0
#define MW_GPIOI_OUTSPEEDREGPIN1 0
#define MW_GPIOI_PUPDREGPIN1 0
#define MW_GPIOI_OUTTYPEREGPIN2 0
#define MW_GPIOI_OUTSPEEDREGPIN2 0
#define MW_GPIOI_PUPDREGPIN2 0
#define MW_GPIOI_OUTTYPEREGPIN3 0
#define MW_GPIOI_OUTSPEEDREGPIN3 0
#define MW_GPIOI_PUPDREGPIN3 0
#define MW_GPIOI_OUTTYPEREGPIN4 0
#define MW_GPIOI_OUTSPEEDREGPIN4 0
#define MW_GPIOI_PUPDREGPIN4 0
#define MW_GPIOI_OUTTYPEREGPIN5 0
#define MW_GPIOI_OUTSPEEDREGPIN5 0
#define MW_GPIOI_PUPDREGPIN5 0
#define MW_GPIOI_OUTTYPEREGPIN6 0
#define MW_GPIOI_OUTSPEEDREGPIN6 0
#define MW_GPIOI_PUPDREGPIN6 0
#define MW_GPIOI_OUTTYPEREGPIN7 0
#define MW_GPIOI_OUTSPEEDREGPIN7 0
#define MW_GPIOI_PUPDREGPIN7 0
#define MW_GPIOI_OUTTYPEREGPIN8 0
#define MW_GPIOI_OUTSPEEDREGPIN8 0
#define MW_GPIOI_PUPDREGPIN8 0
#define MW_GPIOI_OUTTYPEREGPIN9 0
#define MW_GPIOI_OUTSPEEDREGPIN9 0
#define MW_GPIOI_PUPDREGPIN9 0
#define MW_GPIOI_OUTTYPEREGPIN10 0
#define MW_GPIOI_OUTSPEEDREGPIN10 0
#define MW_GPIOI_PUPDREGPIN10 0
#define MW_GPIOI_OUTTYPEREGPIN11 0
#define MW_GPIOI_OUTSPEEDREGPIN11 0
#define MW_GPIOI_PUPDREGPIN11 0
#define MW_GPIOI_OUTTYPEREGPIN12 0
#define MW_GPIOI_OUTSPEEDREGPIN12 0
#define MW_GPIOI_PUPDREGPIN12 0
#define MW_GPIOI_OUTTYPEREGPIN13 0
#define MW_GPIOI_OUTSPEEDREGPIN13 0
#define MW_GPIOI_PUPDREGPIN13 0
#define MW_GPIOI_OUTTYPEREGPIN14 0
#define MW_GPIOI_OUTSPEEDREGPIN14 0
#define MW_GPIOI_PUPDREGPIN14 0
#define MW_GPIOI_OUTTYPEREGPIN15 0
#define MW_GPIOI_OUTSPEEDREGPIN15 0
#define MW_GPIOI_PUPDREGPIN15 0
#define MW_DATAVERSION 2016.02
#define MW_MULTI_TASKING_MODE 1

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
