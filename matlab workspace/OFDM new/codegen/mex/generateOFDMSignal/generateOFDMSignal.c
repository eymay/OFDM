/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generateOFDMSignal.c
 *
 * Code generation for function 'generateOFDMSignal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "generateOFDMSignal.h"
#include "eml_int_forloop_overflow_check.h"
#include "OFDMTransmitter.h"
#include "generateOFDMSignal_data.h"

/* Variable Definitions */
static OFDMTransmitter OFDMTX;
static boolean_T OFDMTX_not_empty;
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "generateOFDMSignal",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\generateOFDMSignal.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 12,  /* lineNo */
  "generateOFDMSignal",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\generateOFDMSignal.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 42,  /* lineNo */
  "OFDMTransmitter",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMTransmitter.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 1,   /* lineNo */
  "System",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\System.p"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 1,   /* lineNo */
  "SystemProp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemProp.p"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 98,  /* lineNo */
  "OFDMTransmitter",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMTransmitter.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 101, /* lineNo */
  "OFDMTransmitter",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMTransmitter.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 1,   /* lineNo */
  "BPSKModulator",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\compiled\\+commcodegen\\BPSKModulator.p"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 1,   /* lineNo */
  "Nondirect",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+mixin\\+coder\\Nondirect.p"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 85,  /* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 1,   /* lineNo */
  "Propagates",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+mixin\\+coder\\Propagates.p"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 1,   /* lineNo */
  "CustomIcon",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\matlab\\system\\+matlab\\+system\\+mixin\\CustomIcon.p"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 272, /* lineNo */
  "OFDMModulator",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\OFDMModulator.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 286, /* lineNo */
  "OFDMModulator",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\OFDMModulator.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 1,   /* lineNo */
  "pvParse",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\matlab\\system\\+matlab\\+system\\pvParse.p"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 139, /* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 44,  /* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 226, /* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 220, /* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 212, /* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 112, /* lineNo */
  "OFDMTransmitter",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMTransmitter.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 113, /* lineNo */
  "OFDMTransmitter",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMTransmitter.m"/* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = { 139,/* lineNo */
  9,                                   /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

/* Function Definitions */
void generateOFDMSignal(const emlrtStack *sp, creal_T txSig[120000], real_T
  *frameLen)
{
  OFDMTransmitter *obj;
  commcodegen_BPSKModulator *b_obj;
  int32_T i;
  static const real_T dv0[4] = { 1.0, 0.0, -1.0, 1.2246467991473532E-16 };

  int32_T nb;
  int8_T tmp_data[4];
  int32_T x;
  int32_T exitg1;
  int32_T exponent;
  int32_T i0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack l_st;
  emlrtStack m_st;
  emlrtStack n_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  l_st.prev = &k_st;
  l_st.tls = k_st.tls;
  m_st.prev = &l_st;
  m_st.tls = l_st.tls;
  n_st.prev = &m_st;
  n_st.tls = m_st.tls;

  /* GENERATEOFDMSIGNAL: Generate OFDM signal based on the 802.11a standard. */
  /*  This function returns the time domain signal and the frame length. */
  /*  Copyright 2013-2016 The MathWorks, Inc. */
  if (!OFDMTX_not_empty) {
    st.site = &emlrtRSI;
    b_st.site = &c_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &e_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    OFDMTX.isInitialized = 0;
    d_st.site = &f_emlrtRSI;
    OFDMTX_not_empty = true;
  }

  st.site = &b_emlrtRSI;
  obj = &OFDMTX;
  b_st.site = &f_emlrtRSI;
  if (OFDMTX.isInitialized == 2) {
    emlrtErrorWithMessageIdR2012b(&b_st, &emlrtRTEI,
      "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }

  if (obj->isInitialized != 1) {
    c_st.site = &f_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    if (obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2012b(&d_st, &emlrtRTEI,
        "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5, "setup");
    }

    obj->isInitialized = 1;
    e_st.site = &f_emlrtRSI;

    /*  OFDMTransmitter Generate OFDM signal repeatedly for a payload message */
    /*  based on the 802.11a standard. */
    /*  Copyright 2014-2016 The MathWorks, Inc. */
    /* SampleRate Sample rate     */
    /* PayloadMessage Payload message */
    /* NumFrames Number of frames to transmit */
    /* FrameLength Frame length */
    /*  Number of bits from payload message */
    /*  Number of random bits padded in each frame */
    /*  Number of OFDM symbols per frame */
    /*  Preamble for each frame */
    /*  Pilots for each frame */
    /*  BPSK Modulator System object */
    /*  OFDM Modulator System object  */
    /*  OFDM Modulator configuration */
    /*  Convert message to bits */
    /*  Calculate number of OFDM symbols per frame */
    /*  Calculate number of bits padded in each frame */
    /*  Get preamble for each frame */
    /*  Get pilot for each frame */
    /*  BPSK modulator */
    f_st.site = &g_emlrtRSI;
    b_obj = &obj->pBPSKMod;
    g_st.site = &i_emlrtRSI;
    h_st.site = &d_emlrtRSI;
    i_st.site = &e_emlrtRSI;
    h_st.site = &d_emlrtRSI;
    obj->pBPSKMod.isInitialized = 0;
    i_st.site = &f_emlrtRSI;
    g_st.site = &i_emlrtRSI;
    h_st.site = &j_emlrtRSI;
    g_st.site = &i_emlrtRSI;

    /* System object Constructor function: comm.BPSKModulator */
    for (i = 0; i < 4; i++) {
      b_obj->cSFunObject.P0_modmap[i] = dv0[i];
    }

    /*  OFDM modulator */
    f_st.site = &h_emlrtRSI;
    g_st.site = &n_emlrtRSI;
    h_st.site = &k_emlrtRSI;
    i_st.site = &d_emlrtRSI;
    j_st.site = &e_emlrtRSI;
    i_st.site = &d_emlrtRSI;
    obj->pDataOFDMMod.isInitialized = 0;
    j_st.site = &f_emlrtRSI;
    h_st.site = &k_emlrtRSI;
    i_st.site = &l_emlrtRSI;
    h_st.site = &k_emlrtRSI;
    i_st.site = &m_emlrtRSI;
    g_st.site = &o_emlrtRSI;
    h_st.site = &e_emlrtRSI;
    i_st.site = &e_emlrtRSI;
    j_st.site = &p_emlrtRSI;
    k_st.site = &q_emlrtRSI;
    l_st.site = &r_emlrtRSI;
    for (i = 0; i < 4; i++) {
      tmp_data[i] = (int8_T)(12 + 14 * i);
    }

    nb = 0;
    i = 1;
    while (i <= 4) {
      x = tmp_data[i - 1];
      do {
        exitg1 = 0;
        i++;
        if (i > 4) {
          exitg1 = 1;
        } else {
          frexp((real_T)x / 2.0, &exponent);
          if (!(muDoubleScalarAbs(x - tmp_data[i - 1]) < ldexp(1.0, exponent -
                53))) {
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);

      nb++;
      tmp_data[nb - 1] = (int8_T)x;
    }

    m_st.site = &u_emlrtRSI;
    m_st.site = &t_emlrtRSI;
    m_st.site = &s_emlrtRSI;
    if ((!(1 > nb)) && (nb > 2147483646)) {
      n_st.site = &v_emlrtRSI;
      check_forloop_overflow_error(&n_st);
    }

    if (1 > nb) {
      i0 = 0;
    } else {
      i0 = nb;
    }

    if (4 != i0) {
      emlrtErrorWithMessageIdR2012b(&j_st, &b_emlrtRTEI,
        "comm:OFDM:IndexNotUniquePerSym", 0);
    }

    d_st.site = &f_emlrtRSI;
    e_st.site = &x_emlrtRSI;
    if (obj->pBPSKMod.isInitialized == 2) {
      emlrtErrorWithMessageIdR2012b(&e_st, &emlrtRTEI,
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 5, "reset");
    }

    e_st.site = &y_emlrtRSI;
    if (obj->pDataOFDMMod.isInitialized == 2) {
      emlrtErrorWithMessageIdR2012b(&e_st, &emlrtRTEI,
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 5, "reset");
    }
  }

  c_st.site = &f_emlrtRSI;
  OFDMTransmitter_stepImpl(&c_st, obj, txSig);

  /*  [EOF] */
  *frameLen = 1200.0;

  /*  [EOF] */
}

void generateOFDMSignal_init(void)
{
  OFDMTX_not_empty = false;
}

/* End of code generation (generateOFDMSignal.c) */
