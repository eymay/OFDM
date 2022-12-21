/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * resample.h
 *
 * Code generation for function 'resample'
 *
 */

#ifndef RESAMPLE_H
#define RESAMPLE_H

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
extern void resample(receiveOFDMSignalStackData *SD, const emlrtStack *sp, const
                     creal_T x[44], creal_T yout[528]);

#endif

/* End of code generation (resample.h) */
