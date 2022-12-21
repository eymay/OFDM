/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.c
 *
 * Code generation for function 'SystemCore'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "generateOFDMSignal.h"
#include "SystemCore.h"
#include "OFDMModulator.h"
#include "generateOFDMSignal_mexutil.h"
#include "generateOFDMSignal_data.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 478,/* lineNo */
  "OFDMModulator",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\OFDMModulator.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 486,/* lineNo */
  "OFDMModulator",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\OFDMModulator.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 202,   /* lineNo */
  13,                                  /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 202, /* lineNo */
  38,                                  /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 203, /* lineNo */
  13,                                  /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtMCInfo d_emlrtMCI = { 203, /* lineNo */
  36,                                  /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtMCInfo e_emlrtMCI = { 194, /* lineNo */
  9,                                   /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 154,/* lineNo */
  28,                                  /* colNo */
  "validateattributes",                /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pName */
};

static emlrtRSInfo gb_emlrtRSI = { 203,/* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 202,/* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 194,/* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

/* Function Declarations */
static void coder_internal_errorIf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, const
  mxArray *g, emlrtMCInfo *location);
static const mxArray *num2str(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);

/* Function Definitions */
static void coder_internal_errorIf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, const
  mxArray *g, emlrtMCInfo *location)
{
  const mxArray *pArrays[6];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  pArrays[5] = g;
  emlrtCallMATLABR2012b(sp, 0, NULL, 6, pArrays, "coder.internal.errorIf", true,
                        location);
}

static const mxArray *num2str(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m4;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m4, 1, &pArray, "num2str", true, location);
}

void SystemCore_parenReference(const emlrtStack *sp, commcodegen_BPSKModulator
  *obj, const real_T varargin_1[528], creal_T varargout_1[528])
{
  commcodegen_BPSKModulator *b_obj;
  comm_BPSKModulator_0 *c_obj;
  int32_T inIdx;
  int32_T outIdx;
  int32_T i;
  real_T u;
  int32_T symbolIndex;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  if (b_obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(&st, &emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (b_obj->isInitialized != 1) {
    b_st.site = &f_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    if (b_obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2012b(&c_st, &emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    b_obj->isInitialized = 1;
  }

  c_obj = &b_obj->cSFunObject;

  /* System object Outputs function: comm.BPSKModulator */
  inIdx = 0;
  outIdx = 0;
  for (i = 0; i < 528; i++) {
    u = varargin_1[inIdx];
    inIdx++;
    symbolIndex = (int32_T)muDoubleScalarFloor(u);
    varargout_1[outIdx].re = c_obj->P0_modmap[symbolIndex << 1];
    varargout_1[outIdx].im = c_obj->P0_modmap[(symbolIndex << 1) + 1];
    outIdx++;
  }
}

void b_SystemCore_parenReference(const emlrtStack *sp, comm_OFDMModulator *obj,
  const creal_T varargin_1[528], creal_T varargout_1[880])
{
  comm_OFDMModulator *b_obj;
  static const real_T dv3[44] = { -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0,
    -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0, -1.0,
    -1.0, -1.0, 1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0,
    -1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, 1.0, -1.0 };

  const mxArray *y;
  const mxArray *m1;
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 27 };

  static const char_T u[27] = { 'c', 'o', 'm', 'm', ':', 'O', 'F', 'D', 'M', ':',
    'I', 'n', 'v', 'a', 'l', 'i', 'd', 'P', 'i', 'l', 'o', 't', 'I', 'n', 'd',
    'e', 'x' };

  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &f_st;
  h_st.tls = f_st.tls;
  i_st.prev = &f_st;
  i_st.tls = f_st.tls;
  b_obj = obj;
  if (b_obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(&st, &emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (b_obj->isInitialized != 1) {
    b_st.site = &f_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    if (b_obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2012b(&c_st, &emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    b_obj->isInitialized = 1;
    d_st.site = &f_emlrtRSI;
    e_st.site = &f_emlrtRSI;
    f_st.site = &eb_emlrtRSI;
    y = NULL;
    m1 = emlrtCreateLogicalScalar(false);
    emlrtAssign(&y, m1);
    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(&f_st, 27, m1, &u[0]);
    emlrtAssign(&b_y, m1);
    g_st.site = &ib_emlrtRSI;
    h_st.site = &hb_emlrtRSI;
    i_st.site = &gb_emlrtRSI;
    coder_internal_errorIf(&g_st, y, b_y, num2str(&h_st, emlrt_marshallOut(7.0),
      &emlrtMCI), num2str(&h_st, emlrt_marshallOut(32.0), &b_emlrtMCI), num2str(
      &i_st, emlrt_marshallOut(34.0), &c_emlrtMCI), num2str(&i_st,
      emlrt_marshallOut(59.0), &d_emlrtMCI), &e_emlrtMCI);
    d_st.site = &f_emlrtRSI;
    e_st.site = &fb_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 528)) {
      if ((!(muDoubleScalarIsInf(varargin_1[k].re) || muDoubleScalarIsInf
             (varargin_1[k].im))) && (!(muDoubleScalarIsNaN(varargin_1[k].re) ||
            muDoubleScalarIsNaN(varargin_1[k].im)))) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }

    if (!p) {
      emlrtErrMsgIdAndExplicitTxt(&e_st, &d_emlrtRTEI,
        "MATLAB:comm.OFDMModulator.Data input:expectedFinite", 33,
        "Expected Data input to be finite.");
    }
  }

  OFDMModulator_stepImpl(varargin_1, dv3, varargout_1);
}

/* End of code generation (SystemCore.c) */
