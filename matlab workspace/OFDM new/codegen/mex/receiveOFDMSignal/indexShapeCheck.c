/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "indexShapeCheck.h"

/* Variable Definitions */
static emlrtRSInfo bb_emlrtRSI = { 18, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

/* Function Definitions */
void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
                     indexSize[2])
{
  boolean_T nonSingletonDimFound;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (!(matrixSize != 1)) {
    nonSingletonDimFound = false;
    if (indexSize[1] != 1) {
      nonSingletonDimFound = true;
    }

    if (nonSingletonDimFound) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
    }
  } else {
    nonSingletonDimFound = false;
  }

  st.site = &bb_emlrtRSI;
  if (nonSingletonDimFound) {
    emlrtErrorWithMessageIdR2012b(&st, &h_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.c) */
