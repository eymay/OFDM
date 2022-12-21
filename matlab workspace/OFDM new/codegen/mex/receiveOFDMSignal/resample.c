/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * resample.c
 *
 * Code generation for function 'resample'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "resample.h"
#include "upfirdn.h"

/* Variable Definitions */
static emlrtRSInfo lc_emlrtRSI = { 93, /* lineNo */
  "resample",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\eml\\resample.m"/* pathName */
};

/* Function Definitions */
void resample(receiveOFDMSignalStackData *SD, const emlrtStack *sp, const
              creal_T x[44], creal_T yout[528])
{
  int32_T i5;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lc_emlrtRSI;
  upfirdn(&st, x, SD->f0.y);
  for (i5 = 0; i5 < 11; i5++) {
    memcpy(&yout[i5 * 48], &SD->f0.y[i5 * 278 + 121], 48U * sizeof(creal_T));
  }
}

/* End of code generation (resample.c) */
