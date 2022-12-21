/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * receiveOFDMSignal_initialize.c
 *
 * Code generation for function 'receiveOFDMSignal_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "receiveOFDMSignal_initialize.h"
#include "_coder_receiveOFDMSignal_mex.h"
#include "receiveOFDMSignal_data.h"

/* Function Declarations */
static void receiveOFDMSignal_once(void);

/* Function Definitions */
static void receiveOFDMSignal_once(void)
{
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  static const int32_T iv1[2] = { 0, 0 };

  emlrtAssignP(&b_eml_mx, NULL);
  emlrtAssignP(&eml_mx, NULL);
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtAssignP(&b_eml_mx, m0);
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtAssignP(&eml_mx, m0);
  receiveOFDMSignal_init();
}

void receiveOFDMSignal_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Communication_Toolbox", 2);
  emlrtLicenseCheckR2012b(&st, "Signal_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    receiveOFDMSignal_once();
  }
}

/* End of code generation (receiveOFDMSignal_initialize.c) */
