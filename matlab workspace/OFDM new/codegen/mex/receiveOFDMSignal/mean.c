/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "mean.h"

/* Function Definitions */
void b_mean(const real_T x[106], real_T b_y[53])
{
  int32_T j;
  for (j = 0; j < 53; j++) {
    b_y[j] = (x[j] + x[j + 53]) / 2.0;
  }
}

void mean(const creal_T x[106], creal_T b_y[53])
{
  int32_T j;
  for (j = 0; j < 53; j++) {
    b_y[j].re = x[j].re + x[j + 53].re;
    b_y[j].im = x[j].im + x[j + 53].im;
    if (b_y[j].im == 0.0) {
      b_y[j].re /= 2.0;
      b_y[j].im = 0.0;
    } else if (b_y[j].re == 0.0) {
      b_y[j].re = 0.0;
      b_y[j].im /= 2.0;
    } else {
      b_y[j].re /= 2.0;
      b_y[j].im /= 2.0;
    }
  }
}

/* End of code generation (mean.c) */
