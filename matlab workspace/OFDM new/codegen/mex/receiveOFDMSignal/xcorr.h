/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcorr.h
 *
 * Code generation for function 'xcorr'
 *
 */

#ifndef XCORR_H
#define XCORR_H

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
extern void b_xcorr(const emlrtStack *sp, const real_T x[871], real_T c[1741]);
extern void xcorr(const emlrtStack *sp, const creal_T x[871], creal_T c[1741]);

#endif

/* End of code generation (xcorr.h) */
