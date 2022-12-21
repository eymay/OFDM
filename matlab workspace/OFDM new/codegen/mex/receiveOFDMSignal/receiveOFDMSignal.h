/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * receiveOFDMSignal.h
 *
 * Code generation for function 'receiveOFDMSignal'
 *
 */

#ifndef RECEIVEOFDMSIGNAL_H
#define RECEIVEOFDMSIGNAL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "receiveOFDMSignal_types.h"

/* Function Declarations */
extern void receiveOFDMSignal(receiveOFDMSignalStackData *SD, const emlrtStack
  *sp, const creal_T b_rxSig[130080], emxArray_real_T *decMsgInBits, real_T
  *numFramesDetected);
extern void receiveOFDMSignal_init(void);

#endif

/* End of code generation (receiveOFDMSignal.h) */
