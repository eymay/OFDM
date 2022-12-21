/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generateOFDMSignal_terminate.c
 *
 * Code generation for function 'generateOFDMSignal_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "generateOFDMSignal.h"
#include "generateOFDMSignal_terminate.h"
#include "_coder_generateOFDMSignal_mex.h"
#include "generateOFDMSignal_data.h"

/* Function Definitions */
void generateOFDMSignal_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtDestroyArray(&eml_mx);
  emlrtDestroyArray(&b_eml_mx);
}

void generateOFDMSignal_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (generateOFDMSignal_terminate.c) */
