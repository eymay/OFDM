/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randi.c
 *
 * Code generation for function 'randi'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "generateOFDMSignal.h"
#include "randi.h"

/* Function Definitions */
void randi(real_T r[17])
{
  int32_T k;
  emlrtRandu(&r[0], 17);
  for (k = 0; k < 17; k++) {
    r[k] = muDoubleScalarFloor(r[k] * 2.0);
  }
}

/* End of code generation (randi.c) */
