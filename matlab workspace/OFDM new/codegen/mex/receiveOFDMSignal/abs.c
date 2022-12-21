/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "abs.h"

/* Function Definitions */
void b_abs(const creal_T x[871], real_T b_y[871])
{
  int32_T k;
  for (k = 0; k < 871; k++) {
    b_y[k] = muDoubleScalarHypot(x[k].re, x[k].im);
  }
}

void c_abs(const creal_T x[864], real_T b_y[864])
{
  int32_T k;
  for (k = 0; k < 864; k++) {
    b_y[k] = muDoubleScalarHypot(x[k].re, x[k].im);
  }
}

void d_abs(const creal_T x[106], real_T b_y[106])
{
  int32_T k;
  for (k = 0; k < 106; k++) {
    b_y[k] = muDoubleScalarHypot(x[k].re, x[k].im);
  }
}

void e_abs(const creal_T x[44], real_T b_y[44])
{
  int32_T k;
  for (k = 0; k < 44; k++) {
    b_y[k] = muDoubleScalarHypot(x[k].re, x[k].im);
  }
}

/* End of code generation (abs.c) */
