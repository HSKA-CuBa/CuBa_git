

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
#include <math.h>
#include <stddef.h>
#include <stdbool.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
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
void SensorenFilter_Block_Outputs_wrapper(const int16_T *x1__dd,
			const int16_T *y1__dd,
			const int16_T *phi1__d,
			const int16_T *x2__dd,
			const int16_T *y2__dd,
			const int16_T *phi2__d,
			real32_T *phi__raw,
			real32_T *phi__comp,
			real32_T *phi__kalman,
			real32_T *phi__d,
			const real_T *xD,
			const real32_T  *T_a, const int_T  p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE
    static bool initialRun = true;
    static float recentPhi = 0.0F;
    float x1__dd_f  = ((float)x1__dd[0]) * (-0.0006082F) + 0.4412F;
    float x2__dd_f  = ((float)x2__dd[0]) * (-0.000607F) + 0.2804F;
    float y1__dd_f  = ((float)y1__dd[0]) * (-0.0006064F) + 0.1248F;
    float y2__dd_f  = ((float)y2__dd[0]) * (-0.0006089F) + 0.09182F;
    float phi1__d_f = ((float)(phi1__d[0] + 89)) * (-0.0076F) * 0.0175F;
    float phi2__d_f = ((float)(phi2__d[0] + 889)) * (-0.0076F) * 0.0175;
    
    phi__d[0]       = (phi1__d_f + phi2__d_f) / 2.0F;
    //Winkelschaetzung
    phi__raw[0]     = -atan2(x1__dd_f - 2.2951F * x2__dd_f, y1__dd_f - 2.2951F * y2__dd_f);
    //Komplementaerfilter
    if(initialRun == true)
    {
        recentPhi = phi__raw[0];
    }
    float phi_inc   = T_a[0] * phi__d[0];
    phi__comp[0]    = (0.98F * (recentPhi + phi_inc)) + (0.02F * phi__raw[0]);
    recentPhi       = phi__comp[0];
    //Kalmanfilter
    static float sPhi__d[7]  = { 0.0F };
    static float sPhi[7]     = { 0.0F };
    static float sP          = 0.001F;
    static float sK          = 0.0F;
    static float sOldPhi     = 0.0F;
    static int index         = 0;
    if(initialRun == true)
    {
        initialRun = false;
        phi__kalman[0] = phi__raw[0];
        sOldPhi        = phi__raw[0];
        sPhi__d[0] = phi__d[0];
        sPhi__d[1] = phi__d[0];
        sPhi__d[2] = phi__d[0];
        sPhi__d[3] = phi__d[0];
        sPhi__d[4] = phi__d[0];
        sPhi__d[5] = phi__d[0];
        sPhi__d[6] = phi__d[0];
        sPhi[0]    = phi__raw[0];
        sPhi[1]    = phi__raw[0];
        sPhi[2]    = phi__raw[0];
        sPhi[3]    = phi__raw[0];
        sPhi[4]    = phi__raw[0];
        sPhi[5]    = phi__raw[0];
        sPhi[6]    = phi__raw[0];
    }
    sPhi[index]    = phi__raw[0];
    sPhi__d[index] = phi__d[0];
    index = index == 6 ? 0 : index + 1;
    float meanPhi_d = (sPhi__d[0] + sPhi__d[1] + sPhi__d[2] + sPhi__d[3] + 
                       sPhi__d[4] + sPhi__d[5] + sPhi__d[6]) / 7.0F;
    float varPhi_d  = ((sPhi__d[0]-meanPhi_d)*(sPhi__d[0]-meanPhi_d) + 
                       (sPhi__d[1]-meanPhi_d)*(sPhi__d[1]-meanPhi_d) + 
                       (sPhi__d[2]-meanPhi_d)*(sPhi__d[2]-meanPhi_d) + 
                       (sPhi__d[3]-meanPhi_d)*(sPhi__d[3]-meanPhi_d) +
                       (sPhi__d[4]-meanPhi_d)*(sPhi__d[4]-meanPhi_d) + 
                       (sPhi__d[5]-meanPhi_d)*(sPhi__d[5]-meanPhi_d) + 
                       (sPhi__d[6]-meanPhi_d)*(sPhi__d[6]-meanPhi_d)) * T_a[0] * T_a[0]/ 6.0F;
    float meanPhi  = (sPhi[0] + sPhi[1] + sPhi[2] + sPhi[3] + sPhi[4] +
                      sPhi[5] + sPhi[6]) / 7.0F;
    float varPhi   = ((sPhi[0]-meanPhi)*(sPhi[0]-meanPhi) + 
                      (sPhi[1]-meanPhi)*(sPhi[1]-meanPhi) +
                      (sPhi[2]-meanPhi)*(sPhi[2]-meanPhi) +
                      (sPhi[3]-meanPhi)*(sPhi[3]-meanPhi) +
                      (sPhi[4]-meanPhi)*(sPhi[4]-meanPhi) +
                      (sPhi[5]-meanPhi)*(sPhi[5]-meanPhi) +
                      (sPhi[6]-meanPhi)*(sPhi[6]-meanPhi)) / 6.0F;
    phi__kalman[0] = sOldPhi + phi__d[0]*T_a[0];
    sP             = sP + varPhi_d;
    sK             = sP / (sP + varPhi);
    phi__kalman[0] = phi__kalman[0] + sK * (phi__raw[0] - phi__kalman[0]);
    sP             = (1-sK)*sP;
    sOldPhi        = phi__kalman[0];
    #endif    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void SensorenFilter_Block_Update_wrapper(const int16_T *x1__dd,
			const int16_T *y1__dd,
			const int16_T *phi1__d,
			const int16_T *x2__dd,
			const int16_T *y2__dd,
			const int16_T *phi2__d,
			real32_T *phi__raw,
			real32_T *phi__comp,
			real32_T *phi__kalman,
			real32_T *phi__d,
			real_T *xD,
			const real32_T  *T_a,  const int_T  p_width0)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if(xD[0] != 1)
{
    xD[0] = 1;
    #ifndef MATLAB_MEX_FILE
    #endif
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
