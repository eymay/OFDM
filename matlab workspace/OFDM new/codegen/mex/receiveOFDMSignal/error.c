/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "error.h"

/* Variable Definitions */
static emlrtRTEInfo d_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "error",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\error.m"/* pName */
};

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &d_emlrtRTEI,
    "Coder:toolbox:eml_setop_unsortedA", 0);
}

void c_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &d_emlrtRTEI,
    "Coder:toolbox:eml_setop_unsortedB", 0);
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &d_emlrtRTEI, "MATLAB:nologicalnan", 0);
}

/* End of code generation (error.c) */
