/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generateOFDMSignal_mexutil.c
 *
 * Code generation for function 'generateOFDMSignal_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "generateOFDMSignal.h"
#include "generateOFDMSignal_mexutil.h"

/* Function Definitions */
const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m2);
  return y;
}

/* End of code generation (generateOFDMSignal_mexutil.c) */
