/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_receiveOFDMSignal_api.c
 *
 * Code generation for function '_coder_receiveOFDMSignal_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "_coder_receiveOFDMSignal_api.h"
#include "receiveOFDMSignal_emxutil.h"
#include "SystemCore.h"
#include "receiveOFDMSignal_mexutil.h"
#include "receiveOFDMSignal_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_receiveOFDMSignal_api",      /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T b_y[130080]);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[130080]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_rxSig, const
  char_T *identifier, creal_T b_y[130080]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T b_y[130080])
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, b_y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *b_y;
  const mxArray *m4;
  static const int32_T iv17[2] = { 0, 0 };

  b_y = NULL;
  m4 = emlrtCreateNumericArray(2, iv17, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m4, u->size, 2);
  emlrtAssign(&b_y, m4);
  return b_y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[130080])
{
  static const int32_T dims[1] = { 130080 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", true, 1U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 8, true);
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_rxSig, const
  char_T *identifier, creal_T b_y[130080])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_rxSig), &thisId, b_y);
  emlrtDestroyArray(&b_rxSig);
}

void receiveOFDMSignal_api(receiveOFDMSignalStackData *SD, const mxArray * const
  prhs[4], const mxArray *plhs[2])
{
  emxArray_real_T *decMsgInBits;
  static const uint32_T b_frameLen[4] = { 38938987U, 1892087053U, 1430307529U,
    1410643333U };

  static const uint32_T showMsg[4] = { 1709037630U, 926886882U, 736726680U,
    2774870372U };

  static const uint32_T showScopes[4] = { 2771799987U, 1170139851U, 3519338680U,
    321885583U };

  real_T numFramesDetected;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &decMsgInBits, 2, &b_emlrtRTEI, true);

  /* Check constant function inputs */
  emlrtCheckArrayChecksumR2014a(&st, "frameLen", b_frameLen, prhs[1], false);
  emlrtCheckArrayChecksumR2014a(&st, "showMsg", showMsg, prhs[2], false);
  emlrtCheckArrayChecksumR2014a(&st, "showScopes", showScopes, prhs[3], false);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "rxSig", SD->f1.rxSig);

  /* Invoke the target function */
  receiveOFDMSignal(SD, &st, SD->f1.rxSig, decMsgInBits, &numFramesDetected);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(decMsgInBits);
  plhs[1] = emlrt_marshallOut(numFramesDetected);
  decMsgInBits->canFreeData = false;
  emxFree_real_T(&decMsgInBits);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_receiveOFDMSignal_api.c) */
