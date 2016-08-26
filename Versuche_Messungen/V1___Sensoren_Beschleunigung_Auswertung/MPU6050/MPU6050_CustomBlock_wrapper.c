

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#include "ELowPass.h"
#include "Global.h"
#include "MPU6050.h"
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void MPU6050_CustomBlock_Outputs_wrapper(int16_T *XAcceleration,
			int16_T *YAcceleration,
			int16_T *ZAcceleration,
			int16_T *XAngularVelocity,
			int16_T *YAngularVelocity,
			int16_T *ZAngularVelocity,
			const real_T *xD,
			const boolean_T  *AD0PinLevel, const int_T  p_width0,
			const uint32_T  *LPBW, const int_T  p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE
    XAcceleration[0] = readMPU6050_XAcceleration(AD0PinLevel[0]);
    YAcceleration[0] = readMPU6050_YAcceleration(AD0PinLevel[0]);
    ZAcceleration[0] = readMPU6050_ZAcceleration(AD0PinLevel[0]);
    XAngularVelocity[0] = readMPU6050_XGyroscope(AD0PinLevel[0]);
    YAngularVelocity[0] = readMPU6050_YGyroscope(AD0PinLevel[0]);
    ZAngularVelocity[0] = readMPU6050_ZGyroscope(AD0PinLevel[0]);
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void MPU6050_CustomBlock_Update_wrapper(int16_T *XAcceleration,
			int16_T *YAcceleration,
			int16_T *ZAcceleration,
			int16_T *XAngularVelocity,
			int16_T *YAngularVelocity,
			int16_T *ZAngularVelocity,
			real_T *xD,
			const boolean_T  *AD0PinLevel,  const int_T  p_width0,
			const uint32_T  *LPBW,  const int_T  p_width1)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] != 1)
{

    #ifndef MATLAB_MEX_FILE
    ELowPass bandwidth = BANDWIDTH_260;
    switch(LPBW[0])
    {
        case 260:
            bandwidth = BANDWIDTH_260;
            break;
        case 184:
            bandwidth = BANDWIDTH_184;
            break;
        case 94:
            bandwidth = BANDWIDTH_94;
            break;
        case 44:
            bandwidth = BANDWIDTH_44;
            break;
        case 21:
            bandwidth = BANDWIDTH_21;
            break;
        case 10:
            bandwidth = BANDWIDTH_10;
            break;
        case 5:
            bandwidth = BANDWIDTH_5;
            break;
    }
    initMPU6050(AD0PinLevel[0], bandwidth);
    #endif
    xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
