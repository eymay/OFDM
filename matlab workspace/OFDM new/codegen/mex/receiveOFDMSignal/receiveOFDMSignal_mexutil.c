/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * receiveOFDMSignal_mexutil.c
 *
 * Code generation for function 'receiveOFDMSignal_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "receiveOFDMSignal_mexutil.h"

/* Function Definitions */
const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *b_y;
  const mxArray *m3;
  b_y = NULL;
  m3 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&b_y, m3);
  return b_y;
}

/* End of code generation (receiveOFDMSignal_mexutil.c) */
