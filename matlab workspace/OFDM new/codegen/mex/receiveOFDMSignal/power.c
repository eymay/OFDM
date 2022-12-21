/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "power.h"

/* Function Definitions */
void b_power(const real_T a[864], real_T b_y[864])
{
  int32_T k;
  for (k = 0; k < 864; k++) {
    b_y[k] = a[k] * a[k];
  }
}

void c_power(const real_T a[106], real_T b_y[106])
{
  int32_T k;
  for (k = 0; k < 106; k++) {
    b_y[k] = a[k] * a[k];
  }
}

void d_power(const real_T a[44], real_T b_y[44])
{
  int32_T k;
  for (k = 0; k < 44; k++) {
    b_y[k] = a[k] * a[k];
  }
}

void power(const real_T a[871], real_T b_y[871])
{
  int32_T k;
  for (k = 0; k < 871; k++) {
    b_y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
