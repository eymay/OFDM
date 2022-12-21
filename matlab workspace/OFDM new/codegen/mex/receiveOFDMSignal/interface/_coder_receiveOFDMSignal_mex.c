/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_receiveOFDMSignal_mex.c
 *
 * Code generation for function '_coder_receiveOFDMSignal_mex'
 *
 */

/* Include files */
#include "receiveOFDMSignal.h"
#include "_coder_receiveOFDMSignal_mex.h"
#include "receiveOFDMSignal_terminate.h"
#include "_coder_receiveOFDMSignal_api.h"
#include "receiveOFDMSignal_initialize.h"
#include "receiveOFDMSignal_data.h"

/* Function Declarations */
static void receiveOFDMSignal_mexFunction(receiveOFDMSignalStackData *SD,
  int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
static void receiveOFDMSignal_mexFunction(receiveOFDMSignalStackData *SD,
  int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[4])
{
  int32_T n;
  const mxArray *inputs[4];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs < 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooFewInputsConstants", 9, 4, 17,
                        "receiveOFDMSignal", 4, 17, "receiveOFDMSignal", 4, 17,
                        "receiveOFDMSignal");
  }

  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        17, "receiveOFDMSignal");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "receiveOFDMSignal");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  receiveOFDMSignal_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  receiveOFDMSignal_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  receiveOFDMSignalStackData *c_receiveOFDMSignalStackDataGlo = NULL;
  c_receiveOFDMSignalStackDataGlo = (receiveOFDMSignalStackData *)mxCalloc(1, 1U
    * sizeof(receiveOFDMSignalStackData));
  mexAtExit(receiveOFDMSignal_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  receiveOFDMSignal_initialize();

  /* Dispatch the entry-point. */
  receiveOFDMSignal_mexFunction(c_receiveOFDMSignalStackDataGlo, nlhs, plhs,
    nrhs, prhs);
  mxFree(c_receiveOFDMSignalStackDataGlo);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_receiveOFDMSignal_mex.c) */
