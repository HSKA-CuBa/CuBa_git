

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
void Sensoren_CustomBlock_Outputs_wrapper(int16_T *XAcceleration,
			int16_T *ZAngularVelocity,
			const real_T *xD,
			const uint32_T  *LPBW, const int_T  p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE
    XAcceleration[0] = readMPU6050_XAcceleration(false);
    ZAngularVelocity[0] = readMPU6050_ZGyroscope(true);
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void Sensoren_CustomBlock_Update_wrapper(int16_T *XAcceleration,
			int16_T *ZAngularVelocity,
			real_T *xD,
			const uint32_T  *LPBW,  const int_T  p_width0)
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
    initMPU6050(false, bandwidth);
    initMPU6050(true, bandwidth);
    #endif
    xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
