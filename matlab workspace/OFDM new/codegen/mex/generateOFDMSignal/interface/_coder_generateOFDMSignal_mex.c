/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_generateOFDMSignal_mex.c
 *
 * Code generation for function '_coder_generateOFDMSignal_mex'
 *
 */

/* Include files */
#include "generateOFDMSignal.h"
#include "_coder_generateOFDMSignal_mex.h"
#include "generateOFDMSignal_terminate.h"
#include "_coder_generateOFDMSignal_api.h"
#include "generateOFDMSignal_initialize.h"
#include "generateOFDMSignal_data.h"

/* Function Declarations */
static void generateOFDMSignal_mexFunction(generateOFDMSignalStackData *SD,
  int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void generateOFDMSignal_mexFunction(generateOFDMSignalStackData *SD,
  int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs < 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooFewInputsConstants", 9, 4, 18,
                        "generateOFDMSignal", 4, 18, "generateOFDMSignal", 4, 18,
                        "generateOFDMSignal");
  }

  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        18, "generateOFDMSignal");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "generateOFDMSignal");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  generateOFDMSignal_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  generateOFDMSignal_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  generateOFDMSignalStackData *c_generateOFDMSignalStackDataGl = NULL;
  c_generateOFDMSignalStackDataGl = (generateOFDMSignalStackData *)mxCalloc(1,
    1U * sizeof(generateOFDMSignalStackData));
  mexAtExit(generateOFDMSignal_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  generateOFDMSignal_initialize();

  /* Dispatch the entry-point. */
  generateOFDMSignal_mexFunction(c_generateOFDMSignalStackDataGl, nlhs, plhs,
    nrhs, prhs);
  mxFree(c_generateOFDMSignalStackDataGl);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_generateOFDMSignal_mex.c) */
