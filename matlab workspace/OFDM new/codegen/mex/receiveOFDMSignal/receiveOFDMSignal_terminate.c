/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * receiveOFDMSignal_terminate.c
 *
 * Code generation for function 'receiveOFDMSignal_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "receiveOFDMSignal_terminate.h"
#include "_coder_receiveOFDMSignal_mex.h"
#include "receiveOFDMSignal_data.h"

/* Function Definitions */
void receiveOFDMSignal_atexit(void)
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

void receiveOFDMSignal_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (receiveOFDMSignal_terminate.c) */
