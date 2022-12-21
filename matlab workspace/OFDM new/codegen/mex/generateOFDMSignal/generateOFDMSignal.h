/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generateOFDMSignal.h
 *
 * Code generation for function 'generateOFDMSignal'
 *
 */

#ifndef GENERATEOFDMSIGNAL_H
#define GENERATEOFDMSIGNAL_H

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
#include "generateOFDMSignal_types.h"

/* Function Declarations */
extern void generateOFDMSignal(const emlrtStack *sp, creal_T txSig[120000],
  real_T *frameLen);
extern void generateOFDMSignal_init(void);

#endif

/* End of code generation (generateOFDMSignal.h) */
