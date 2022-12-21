/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * upfirdn.h
 *
 * Code generation for function 'upfirdn'
 *
 */

#ifndef UPFIRDN_H
#define UPFIRDN_H

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
extern void upfirdn(const emlrtStack *sp, const creal_T x_in[44], creal_T y_out
                    [3058]);

#endif

/* End of code generation (upfirdn.h) */
