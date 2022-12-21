/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * upfirdn.c
 *
 * Code generation for function 'upfirdn'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "upfirdn.h"
#include "FIRRateConverter.h"
#include "SystemCore.h"
#include "toLogicalCheck.h"

/* Variable Definitions */
static emlrtRSInfo mc_emlrtRSI = { 16, /* lineNo */
  "upfirdn",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\eml\\upfirdn.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 20, /* lineNo */
  "upfirdn",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\eml\\upfirdn.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 151,/* lineNo */
  "upfirdn",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\eml\\upfirdn.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 154,/* lineNo */
  "upfirdn",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\eml\\upfirdn.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 155,/* lineNo */
  "upfirdn",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\eml\\upfirdn.m"/* pathName */
};

/* Function Definitions */
void upfirdn(const emlrtStack *sp, const creal_T x_in[44], creal_T y_out[3058])
{
  dspcodegen_FIRRateConverter s;
  int32_T i6;
  creal_T b_x_in[264];
  creal_T b_y[3168];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mc_emlrtRSI;
  toLogicalCheck(&st, 1.0);
  st.site = &nc_emlrtRSI;
  toLogicalCheck(&st, 8.0);
  st.site = &oc_emlrtRSI;
  c_FIRRateConverter_FIRRateConve(&s);
  for (i6 = 0; i6 < 11; i6++) {
    memcpy(&b_x_in[i6 * 24], &x_in[i6 << 2], sizeof(creal_T) << 2);
    memset(&b_x_in[i6 * 24 + 4], 0, 20U * sizeof(creal_T));
  }

  st.site = &pc_emlrtRSI;
  SystemCore_step(&st, &s, b_x_in, b_y);
  st.site = &qc_emlrtRSI;
  SystemCore_reset(&st, &s);
  for (i6 = 0; i6 < 11; i6++) {
    memcpy(&y_out[i6 * 278], &b_y[i6 * 288], 278U * sizeof(creal_T));
  }

  /* System object Destructor function: dsp.FIRRateConverter */
}

/* End of code generation (upfirdn.c) */
