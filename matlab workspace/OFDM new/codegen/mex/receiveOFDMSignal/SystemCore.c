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
#include "receiveOFDMSignal.h"
#include "SystemCore.h"
#include "OFDMDemodulator.h"
#include "receiveOFDMSignal_mexutil.h"
#include "receiveOFDMSignal_data.h"

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 285,/* lineNo */
  "OFDMDemodulator",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\OFDMDemodulator.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 281,/* lineNo */
  "OFDMDemodulator",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\OFDMDemodulator.m"/* pathName */
};

static emlrtMCInfo c_emlrtMCI = { 202, /* lineNo */
  13,                                  /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtMCInfo d_emlrtMCI = { 202, /* lineNo */
  38,                                  /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtMCInfo e_emlrtMCI = { 203, /* lineNo */
  13,                                  /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtMCInfo f_emlrtMCI = { 203, /* lineNo */
  36,                                  /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtMCInfo g_emlrtMCI = { 194, /* lineNo */
  9,                                   /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtRSInfo uc_emlrtRSI = { 203,/* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 202,/* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 194,/* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

/* Function Declarations */
static void SystemCore_setupAndReset(const emlrtStack *sp,
  comm_OFDMDemodulator_1 *obj, const creal_T varargin_1[880]);
static void coder_internal_errorIf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, const
  mxArray *g, emlrtMCInfo *location);
static const mxArray *num2str(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);

/* Function Definitions */
static void SystemCore_setupAndReset(const emlrtStack *sp,
  comm_OFDMDemodulator_1 *obj, const creal_T varargin_1[880])
{
  comm_OFDMDemodulator_1 *b_obj;
  const mxArray *b_y;
  const mxArray *m2;
  const mxArray *c_y;
  static const int32_T iv14[2] = { 1, 27 };

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
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &d_st;
  f_st.tls = d_st.tls;
  g_st.prev = &d_st;
  g_st.tls = d_st.tls;
  b_obj = obj;
  if (b_obj->isInitialized != 0) {
    emlrtErrorWithMessageIdR2012b(&st, &c_emlrtRTEI,
      "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
  }

  b_obj->isInitialized = 1;
  b_st.site = &g_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  d_st.site = &kc_emlrtRSI;
  b_y = NULL;
  m2 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&b_y, m2);
  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv14);
  emlrtInitCharArrayR2013a(&d_st, 27, m2, &u[0]);
  emlrtAssign(&c_y, m2);
  e_st.site = &wc_emlrtRSI;
  f_st.site = &vc_emlrtRSI;
  g_st.site = &uc_emlrtRSI;
  coder_internal_errorIf(&e_st, b_y, c_y, num2str(&f_st, emlrt_marshallOut(7.0),
    &c_emlrtMCI), num2str(&f_st, emlrt_marshallOut(32.0), &d_emlrtMCI), num2str(
    &g_st, emlrt_marshallOut(34.0), &e_emlrtMCI), num2str(&g_st,
    emlrt_marshallOut(59.0), &f_emlrtMCI), &g_emlrtMCI);
  b_st.site = &g_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 880)) {
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
    emlrtErrMsgIdAndExplicitTxt(&c_st, &e_emlrtRTEI,
      "MATLAB:comm.OFDMDemodulator.Input:expectedFinite", 28,
      "Expected Input to be finite.");
  }
}

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
  const mxArray *m5;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 1, &pArray, "num2str", true, location);
}

void SystemCore_parenReference(const emlrtStack *sp, comm_OFDMDemodulator *obj,
  const creal_T varargin_1[128], creal_T varargout_1[106])
{
  comm_OFDMDemodulator *b_obj;
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_obj = obj;
  if (b_obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(&st, &c_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (b_obj->isInitialized != 1) {
    b_st.site = &g_emlrtRSI;
    c_st.site = &g_emlrtRSI;
    if (b_obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2012b(&c_st, &c_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    b_obj->isInitialized = 1;
    d_st.site = &g_emlrtRSI;
    e_st.site = &jc_emlrtRSI;
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 128)) {
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
      emlrtErrMsgIdAndExplicitTxt(&e_st, &e_emlrtRTEI,
        "MATLAB:comm.OFDMDemodulator.Input:expectedFinite", 28,
        "Expected Input to be finite.");
    }
  }

  OFDMDemodulator_stepImpl(varargin_1, varargout_1);
}

void SystemCore_reset(const emlrtStack *sp, dspcodegen_FIRRateConverter *obj)
{
  dspcodegen_FIRRateConverter *b_obj;
  int32_T i;
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(sp, &c_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 5, "reset");
  }

  if (obj->isInitialized == 1) {
    b_obj = obj;

    /* System object Initialization function: dsp.FIRRateConverter */
    b_obj->cSFunObject.W1_InBufIdx = 0;
    for (i = 0; i < 231; i++) {
      b_obj->cSFunObject.W0_InBuf[i].re = 0.0;
      b_obj->cSFunObject.W0_InBuf[i].im = 0.0;
    }
  }
}

void SystemCore_step(const emlrtStack *sp, dspcodegen_FIRRateConverter *obj,
                     const creal_T varargin_1[264], creal_T varargout_1[3168])
{
  dspcodegen_FIRRateConverter *b_obj;
  dsp_FIRRateConverter_1 *c_obj;
  int32_T outIdx;
  int32_T inIdx;
  int32_T m;
  int32_T i;
  int32_T inBufIdx;
  int32_T inputChannelOffset;
  int32_T n;
  int32_T outputStartIdx;
  int32_T outputStopIdx;
  real_T acc_re;
  real_T acc_im;
  int32_T coefPolyphaseOffset;
  real_T prod_re;
  real_T prod_im;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(sp, &c_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (obj->isInitialized != 1) {
    st.site = &g_emlrtRSI;
    b_obj = obj;
    b_st.site = &g_emlrtRSI;
    if (b_obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2012b(&b_st, &c_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    b_obj->isInitialized = 1;
    b_st.site = &g_emlrtRSI;

    /* System object Initialization function: dsp.FIRRateConverter */
    b_obj->cSFunObject.W1_InBufIdx = 0;
    for (i = 0; i < 231; i++) {
      b_obj->cSFunObject.W0_InBuf[i].re = 0.0;
      b_obj->cSFunObject.W0_InBuf[i].im = 0.0;
    }
  }

  st.site = &g_emlrtRSI;
  b_obj = obj;
  b_st.site = &p_emlrtRSI;
  c_obj = &b_obj->cSFunObject;

  /* System object Outputs function: dsp.FIRRateConverter */
  outIdx = 0;
  inIdx = 0;
  for (m = 0; m < 11; m++) {
    /* Update inBufIdx and inputChannelOffset for current channel */
    inBufIdx = c_obj->W1_InBufIdx;
    inputChannelOffset = m * 21;
    for (n = 0; n < 24; n++) {
      outputStartIdx = c_obj->P2_StartIdx;
      outputStopIdx = c_obj->P3_StopIdx;

      /* Read input into inBufArray */
      c_obj->W0_InBuf[inBufIdx + inputChannelOffset] = varargin_1[inIdx];
      inIdx++;

      /* Generate outputs (if any) for current input n */
      while (outputStartIdx < outputStopIdx) {
        acc_re = 0.0;
        acc_im = 0.0;
        coefPolyphaseOffset = c_obj->P1_PolyphaseSelector[outputStartIdx] * 21;
        for (i = inBufIdx; i < 21; i++) {
          prod_re = c_obj->P0_FILTER[(coefPolyphaseOffset + i) - inBufIdx] *
            c_obj->W0_InBuf[i + inputChannelOffset].re;
          prod_im = c_obj->P0_FILTER[(coefPolyphaseOffset + i) - inBufIdx] *
            c_obj->W0_InBuf[i + inputChannelOffset].im;
          acc_re += prod_re;
          acc_im += prod_im;
        }

        for (i = 0; i < inBufIdx; i++) {
          prod_re = c_obj->P0_FILTER[((coefPolyphaseOffset - inBufIdx) + i) + 21]
            * c_obj->W0_InBuf[i + inputChannelOffset].re;
          prod_im = c_obj->P0_FILTER[((coefPolyphaseOffset - inBufIdx) + i) + 21]
            * c_obj->W0_InBuf[i + inputChannelOffset].im;
          acc_re += prod_re;
          acc_im += prod_im;
        }

        varargout_1[outIdx].re = acc_re;
        varargout_1[outIdx].im = acc_im;
        outIdx++;
        outputStartIdx++;
      }

      /* Decrement inBufIdx, wrap if necessary */
      if (inBufIdx == 0) {
        inBufIdx = 20;
      } else {
        inBufIdx--;
      }
    }
  }

  /* Update inBufIdx */
  b_obj->cSFunObject.W1_InBufIdx = inBufIdx;
}

void b_SystemCore_parenReference(const emlrtStack *sp, comm_OFDMDemodulator_1
  *obj, const creal_T varargin_1[880], creal_T varargout_1[528], creal_T
  varargout_2[44])
{
  comm_OFDMDemodulator_1 *b_obj;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_obj = obj;
  if (b_obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(&st, &c_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (b_obj->isInitialized != 1) {
    b_st.site = &g_emlrtRSI;
    SystemCore_setupAndReset(&b_st, b_obj, varargin_1);
  }

  b_OFDMDemodulator_stepImpl(varargin_1, varargout_1, varargout_2);
}

void c_SystemCore_parenReference(const emlrtStack *sp,
  commcodegen_BPSKDemodulator *obj, const creal_T varargin_1[528], real_T
  varargout_1[528])
{
  commcodegen_BPSKDemodulator *b_obj;
  int32_T iIdx;
  int32_T b_varargin_1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  if (b_obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(&st, &c_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (b_obj->isInitialized != 1) {
    b_st.site = &g_emlrtRSI;
    c_st.site = &g_emlrtRSI;
    if (b_obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2012b(&c_st, &c_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    b_obj->isInitialized = 1;
  }

  /* System object Outputs function: comm.BPSKDemodulator */
  for (iIdx = 0; iIdx < 528; iIdx++) {
    if (varargin_1[iIdx].re > 0.0) {
      b_varargin_1 = 0;
    } else if (varargin_1[iIdx].re < 0.0) {
      b_varargin_1 = 1;
    } else {
      b_varargin_1 = !(varargin_1[iIdx].im == 0.0);
    }

    varargout_1[iIdx] = b_varargin_1 % 2;
  }
}

/* End of code generation (SystemCore.c) */
