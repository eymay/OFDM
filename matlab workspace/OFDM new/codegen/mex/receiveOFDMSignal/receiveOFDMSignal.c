/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * receiveOFDMSignal.c
 *
 * Code generation for function 'receiveOFDMSignal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "receiveOFDMSignal_emxutil.h"
#include "OFDMReceiver.h"
#include "SystemCore.h"
#include "receiveOFDMSignal_mexutil.h"
#include "receiveOFDMSignal_data.h"

/* Named Constants */
#define frameLen                       (1200.0)

/* Variable Definitions */
static OFDMReceiver ofdmrx;
static boolean_T ofdmrx_not_empty;
static emlrtRSInfo emlrtRSI = { 10,    /* lineNo */
  "receiveOFDMSignal",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\receiveOFDMSignal.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 16,  /* lineNo */
  "receiveOFDMSignal",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\receiveOFDMSignal.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 70,  /* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 71,  /* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 149,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 150,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 151,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 177,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 191,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 194,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 197,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 168,   /* lineNo */
  9,                                   /* colNo */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pName */
};

static emlrtMCInfo b_emlrtMCI = { 210, /* lineNo */
  17,                                  /* colNo */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  46,                                  /* colNo */
  "receiveOFDMSignal",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\receiveOFDMSignal.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  1800,                                /* iLast */
  188,                                 /* lineNo */
  40,                                  /* colNo */
  "buffer",                            /* aName */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 188,   /* lineNo */
  40,                                  /* colNo */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRSInfo sc_emlrtRSI = { 168,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 210,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

/* Function Declarations */
static void b_processOFDMScopes(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, const
  mxArray *g, const mxArray *h, const mxArray *i, const mxArray *j, emlrtMCInfo *
  location);
static void processOFDMScopes(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);

/* Function Definitions */
static void b_processOFDMScopes(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, const
  mxArray *g, const mxArray *h, const mxArray *i, const mxArray *j, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[9];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  pArrays[5] = g;
  pArrays[6] = h;
  pArrays[7] = i;
  pArrays[8] = j;
  emlrtCallMATLABR2012b(sp, 0, NULL, 9, pArrays, "processOFDMScopes", true,
                        location);
}

static void processOFDMScopes(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  emlrtCallMATLABR2012b(sp, 0, NULL, 3, pArrays, "processOFDMScopes", true,
                        location);
}

void receiveOFDMSignal(receiveOFDMSignalStackData *SD, const emlrtStack *sp,
  const creal_T b_rxSig[130080], emxArray_real_T *decMsgInBits, real_T
  *numFramesDetected)
{
  OFDMReceiver *obj;
  boolean_T anyInputSizeChanged;
  int32_T k;
  boolean_T exitg1;
  int32_T i0;
  static const uint32_T uv0[8] = { 130080U, 1U, 1U, 1U, 1U, 1U, 1U, 1U };

  cell_wrap_3 varSizes[1];
  static const uint32_T uv1[8] = { 130080U, 1U, 1U, 1U, 1U, 1U, 1U, 1U };

  real_T detFrmAtBeginning;
  static const uint32_T inSize[8] = { 130080U, 1U, 1U, 1U, 1U, 1U, 1U, 1U };

  int32_T bufferStartIdx;
  const mxArray *b_y;
  const mxArray *m1;
  static const int32_T iv2[2] = { 1, 5 };

  static const char_T u[5] = { 'r', 'e', 's', 'e', 't' };

  real_T varargout_2;
  creal_T buffer[1800];
  real_T preambleStartLocation;
  creal_T oneFrameToProcess[1200];
  creal_T b_oneFrameToProcess[1200];
  creal_T postEqData[528];
  creal_T preEqData[528];
  creal_T eqGains[576];
  real_T msgInBits[528];
  static const int32_T iv3[2] = { 1, 4 };

  static const char_T b_u[4] = { 's', 't', 'e', 'p' };

  const mxArray *c_y;
  static const int32_T iv4[1] = { 1200 };

  const mxArray *d_y;
  static const int32_T iv5[2] = { 48, 12 };

  const mxArray *e_y;
  static const int32_T iv6[2] = { 48, 11 };

  const mxArray *f_y;
  static const int32_T iv7[2] = { 48, 11 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;

  /*  RECEIVEOFDMSIGNAL: Recover OFDM symbols from the time domain input signal */
  /*  and return the number of detected frames and the decoded bits from these */
  /*  detected frames. */
  /*  Copyright 2014-2016 The MathWorks, Inc. */
  if (!ofdmrx_not_empty) {
    st.site = &emlrtRSI;
    b_st.site = &c_emlrtRSI;
    c_st.site = &e_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    c_st.site = &e_emlrtRSI;
    ofdmrx.isInitialized = 0;
    d_st.site = &g_emlrtRSI;
    d_st.site = &g_emlrtRSI;
    b_st.site = &d_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    e_st.site = &i_emlrtRSI;

    /*  [EOF] */
    ofdmrx_not_empty = true;
  }

  st.site = &b_emlrtRSI;
  obj = &ofdmrx;
  b_st.site = &g_emlrtRSI;
  if (ofdmrx.isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(&b_st, &c_emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (obj->isInitialized != 1) {
    c_st.site = &g_emlrtRSI;
    d_st.site = &g_emlrtRSI;
    if (obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2012b(&d_st, &c_emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    obj->isInitialized = 1;
    e_st.site = &g_emlrtRSI;
    for (i0 = 0; i0 < 8; i0++) {
      varSizes[0].f1[i0] = uv1[i0];
    }

    obj->inputVarSize[0] = varSizes[0];
    e_st.site = &g_emlrtRSI;
    OFDMReceiver_validateInputsImpl(&e_st, b_rxSig);
    e_st.site = &g_emlrtRSI;
    OFDMReceiver_setupImpl(&e_st, obj);
    d_st.site = &g_emlrtRSI;
    for (i0 = 0; i0 < 15; i0++) {
      obj->pFreqOffsetEstBuffer[i0] = 0.0;
    }

    obj->pNumFrameDetected = 0.0;
    e_st.site = &cb_emlrtRSI;
    if (obj->pBPSKDemod.isInitialized == 2) {
      emlrtErrorWithMessageIdR2012b(&e_st, &c_emlrtRTEI,
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 5, "reset");
    }

    e_st.site = &db_emlrtRSI;
    if (obj->pPreambleOFDMDemod.isInitialized == 2) {
      emlrtErrorWithMessageIdR2012b(&e_st, &c_emlrtRTEI,
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 5, "reset");
    }

    e_st.site = &eb_emlrtRSI;
    if (obj->pDataOFDMDemod.isInitialized == 2) {
      emlrtErrorWithMessageIdR2012b(&e_st, &c_emlrtRTEI,
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 5, "reset");
    }
  }

  c_st.site = &g_emlrtRSI;
  anyInputSizeChanged = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != uv0[k]) {
      anyInputSizeChanged = true;
      for (i0 = 0; i0 < 8; i0++) {
        obj->inputVarSize[0].f1[i0] = inSize[i0];
      }

      exitg1 = true;
    } else {
      k++;
    }
  }

  if (anyInputSizeChanged) {
    c_st.site = &g_emlrtRSI;
    OFDMReceiver_validateInputsImpl(&c_st, b_rxSig);
  }

  c_st.site = &g_emlrtRSI;
  detFrmAtBeginning = obj->pNumFrameDetected;
  i0 = decMsgInBits->size[0] * decMsgInBits->size[1];
  decMsgInBits->size[0] = 1;
  decMsgInBits->size[1] = 0;
  emxEnsureCapacity(&c_st, (emxArray__common *)decMsgInBits, i0, sizeof(real_T),
                    &emlrtRTEI);
  bufferStartIdx = 1;
  b_y = NULL;
  m1 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(&c_st, 5, m1, &u[0]);
  emlrtAssign(&b_y, m1);
  d_st.site = &sc_emlrtRSI;
  processOFDMScopes(&d_st, emlrt_marshallOut(2.0E+7), emlrt_marshallOut(frameLen),
                    b_y, &emlrtMCI);
  while (bufferStartIdx <= 128281) {
    memcpy(&buffer[0], &b_rxSig[bufferStartIdx + -1], 1800U * sizeof(creal_T));
    d_st.site = &fb_emlrtRSI;
    preambleStartLocation = OFDMReceiver_locatePreamble(&d_st, buffer);
    if ((preambleStartLocation != -1.0) && (preambleStartLocation + frameLen <=
         1800.0)) {
      anyInputSizeChanged = true;
    } else {
      anyInputSizeChanged = false;
    }

    if (anyInputSizeChanged) {
      obj->pNumFrameDetected++;
      for (i0 = 0; i0 < 1200; i0++) {
        varargout_2 = preambleStartLocation + (1.0 + (real_T)i0);
        if (varargout_2 != (int32_T)muDoubleScalarFloor(varargout_2)) {
          emlrtIntegerCheckR2012b(varargout_2, &emlrtDCI, &c_st);
        }

        k = (int32_T)varargout_2;
        if (!((k >= 1) && (k <= 1800))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, 1800, &emlrtBCI, &c_st);
        }

        oneFrameToProcess[i0].re = buffer[k - 1].re;
        varargout_2 = preambleStartLocation + (1.0 + (real_T)i0);
        if (varargout_2 != (int32_T)muDoubleScalarFloor(varargout_2)) {
          emlrtIntegerCheckR2012b(varargout_2, &emlrtDCI, &c_st);
        }

        k = (int32_T)varargout_2;
        if (!((k >= 1) && (k <= 1800))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, 1800, &emlrtBCI, &c_st);
        }

        oneFrameToProcess[i0].im = buffer[k - 1].im;
      }

      d_st.site = &gb_emlrtRSI;
      c_OFDMReceiver_coarseFreqCorrec(&d_st, obj, oneFrameToProcess,
        b_oneFrameToProcess, &varargout_2);
      d_st.site = &hb_emlrtRSI;
      OFDMReceiver_frameEqualization(SD, &d_st, obj, b_oneFrameToProcess,
        postEqData, preEqData, eqGains);
      d_st.site = &ib_emlrtRSI;
      c_SystemCore_parenReference(&d_st, &obj->pBPSKDemod, postEqData, msgInBits);
      k = decMsgInBits->size[1];
      i0 = decMsgInBits->size[0] * decMsgInBits->size[1];
      decMsgInBits->size[1] = k + 525;
      emxEnsureCapacity(&c_st, (emxArray__common *)decMsgInBits, i0, sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < 525; i0++) {
        decMsgInBits->data[k + i0] = msgInBits[i0];
      }

      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv3);
      emlrtInitCharArrayR2013a(&c_st, 4, m1, &b_u[0]);
      emlrtAssign(&b_y, m1);
      c_y = NULL;
      m1 = emlrtCreateNumericArray(1, iv4, mxDOUBLE_CLASS, mxCOMPLEX);
      emlrtExportNumericArrayR2013b(&c_st, m1, (void *)&b_oneFrameToProcess[0],
        8);
      emlrtAssign(&c_y, m1);
      d_y = NULL;
      m1 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxCOMPLEX);
      emlrtExportNumericArrayR2013b(&c_st, m1, (void *)&eqGains[0], 8);
      emlrtAssign(&d_y, m1);
      e_y = NULL;
      m1 = emlrtCreateNumericArray(2, iv6, mxDOUBLE_CLASS, mxCOMPLEX);
      emlrtExportNumericArrayR2013b(&c_st, m1, (void *)&preEqData[0], 8);
      emlrtAssign(&e_y, m1);
      f_y = NULL;
      m1 = emlrtCreateNumericArray(2, iv7, mxDOUBLE_CLASS, mxCOMPLEX);
      emlrtExportNumericArrayR2013b(&c_st, m1, (void *)&postEqData[0], 8);
      emlrtAssign(&f_y, m1);
      d_st.site = &tc_emlrtRSI;
      b_processOFDMScopes(&d_st, emlrt_marshallOut(2.0E+7), emlrt_marshallOut
                          (frameLen), b_y, emlrt_marshallOut((real_T)
        bufferStartIdx + preambleStartLocation), emlrt_marshallOut(varargout_2),
                          c_y, d_y, e_y, f_y, &b_emlrtMCI);
      if (bufferStartIdx < 128281) {
        bufferStartIdx = (int32_T)muDoubleScalarMin((real_T)bufferStartIdx +
          1200.0, 128281.0);
      } else {
        bufferStartIdx = 128581;
      }
    } else {
      bufferStartIdx += 300;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&c_st);
    }
  }

  varargout_2 = obj->pNumFrameDetected - detFrmAtBeginning;

  /*  [EOF] */
  *numFramesDetected = varargout_2;
}

void receiveOFDMSignal_init(void)
{
  ofdmrx_not_empty = false;
}

/* End of code generation (receiveOFDMSignal.c) */
