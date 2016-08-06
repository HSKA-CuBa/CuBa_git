#define S_FUNCTION_NAME CustomGain_SFunction
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include "matrix.h"

static void mdlInitializeSizes(SimStruct* S)
{
    //Anzahl der S-Function Parameter festlegen
    ssSetNumSFcnParams(S,1);         
    if(ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) return;
    
    //Anzahl der Eingaenge und deren Weite festlegen und ueberpruefen
    if(!ssSetNumInputPorts(S,1)) return;
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    
    //Anzahl der Ausgaenge und deren Weite festlegen
    if(!ssSetNumOutputPorts(S,1)) return;
    ssSetOutputPortWidth(S, 0, DYNAMICALLY_SIZED);
    
    //Anzahl der Abtastsraten festlegen
    ssSetNumSampleTimes(S, 1);
}

static void mdlInitializeSampleTimes(SimStruct* S)
{
    //Festelegen der Abtastrate und Abtastoffset auf INHERITED
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

static void mdlOutputs(SimStruct* S, int_T tid)
{   
    //Eingang-, Ausgangsignale und Parameter von dem SimStruct abfragen
    InputRealPtrsType inputPtrArr  = ssGetInputPortRealSignalPtrs(S, 0);
    real_T* outputPtr              = ssGetOutputPortRealSignal(S, 0);
    const mxArray* parameterPtr    = ssGetSFcnParam(S, 0);
    //Ausgangswert berechnen
    *outputPtr = (*(inputPtrArr[0])) * (*mxGetPr(parameterPtr));
}

static void mdlTerminate(SimStruct* S)
{
}

#ifdef MATLAB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif
    