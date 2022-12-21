/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * OFDMReceiver.c
 *
 * Code generation for function 'OFDMReceiver'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "OFDMReceiver.h"
#include "power.h"
#include "resample.h"
#include "repmat.h"
#include "abs.h"
#include "SystemCore.h"
#include "mean.h"
#include "eml_setop.h"
#include "indexShapeCheck.h"
#include "xcorr.h"
#include "eml_int_forloop_overflow_check.h"
#include "receiveOFDMSignal_data.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 96,  /* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 125, /* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 128, /* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 135, /* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 1,   /* lineNo */
  "BPSKDemodulator",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\compiled\\+commcodegen\\BPSKDemodulator.p"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 212, /* lineNo */
  "OFDMDemodulator",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\OFDMDemodulator.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 225, /* lineNo */
  "OFDMDemodulator",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\OFDMDemodulator.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 85,  /* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 1,   /* lineNo */
  "Propagates",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+mixin\\+coder\\Propagates.p"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 1,   /* lineNo */
  "CustomIcon",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\matlab\\system\\+matlab\\+system\\+mixin\\CustomIcon.p"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 139, /* lineNo */
  "OFDMBase",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 44,  /* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 226, /* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 220, /* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 212,/* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 302,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 303,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 310,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 313,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 323,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 330,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 44, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 23, /* lineNo */
  "intersect",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\intersect.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 70, /* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 15, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 16, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 354,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 371,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 375,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 379,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 389,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 392,/* lineNo */
  "OFDMReceiver",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 139,/* lineNo */
  9,                                   /* colNo */
  "OFDMBase",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\comm\\+comm\\+internal\\OFDMBase.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 121,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 39,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  323,                                 /* lineNo */
  50,                                  /* colNo */
  "MLocations",                        /* aName */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  323,                                 /* lineNo */
  48,                                  /* colNo */
  "MLocations",                        /* aName */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  322,                                 /* lineNo */
  39,                                  /* colNo */
  "MLocations",                        /* aName */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  332,                                 /* lineNo */
  44,                                  /* colNo */
  "MLocations",                        /* aName */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  327,                                 /* lineNo */
  11,                                  /* colNo */
  "peaks",                             /* aName */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  323,                                 /* lineNo */
  15,                                  /* colNo */
  "peaks",                             /* aName */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 351, /* lineNo */
  30,                                  /* colNo */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  15,                                  /* iLast */
  351,                                 /* lineNo */
  30,                                  /* colNo */
  "obj.pFreqOffsetEstBuffer",          /* aName */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 354, /* lineNo */
  53,                                  /* colNo */
  "OFDMReceiver",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\comm\\commdemos\\OFDMReceiver.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo n_emlrtRTEI = { 17,/* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pName */
};

/* Function Definitions */
void OFDMReceiver_frameEqualization(receiveOFDMSignalStackData *SD, const
  emlrtStack *sp, OFDMReceiver *obj, const creal_T x[1200], creal_T postEqData
  [528], creal_T demodData[528], creal_T eqGains[576])
{
  creal_T decLongPreamble[106];
  int32_T i;
  real_T dv2[106];
  real_T dv3[106];
  static const int8_T iv10[106] = { 1, 1, -1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1,
    1, -1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 0, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1,
    -1, -1, -1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 1,
    -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 0, 1, -1,
    -1, 1, 1, -1, 1, -1, 1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1,
    1, 1 };

  real_T b_y[53];
  creal_T preambleEqGains[53];
  creal_T demodPilots[44];
  creal_T preambleEqGainsOnData[48];
  static const int8_T iv11[48] = { 0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30, 31, 32, 34, 35, 36,
    37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 48, 49, 50, 51, 52 };

  creal_T b_preambleEqGains[4];
  creal_T pilotNorm[44];
  real_T dv4[44];
  real_T postEqData_re;
  real_T c_y[44];
  real_T postEqData_im;
  static const int8_T iv12[44] = { -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1,
    -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, -1, 1,
    1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1 };

  creal_T pilotEqGainsOnData[528];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  Equalize the OFDM frame through the use of both the long preamble */
  /*  from the 802.11a standard and four pilot tones in the data frames. */
  /*  The gains from the pilots are interpolated across frequency and */
  /*  applied to all data subcarriers. */
  /*  Use long preamble frame to estimate channel in frequency domain */
  /*  Demodulate received long preamble */
  st.site = &ec_emlrtRSI;
  SystemCore_parenReference(&st, &obj->pPreambleOFDMDemod, *(creal_T (*)[128])&
    x[192], decLongPreamble);

  /*  Get preamble equalizer gains */
  for (i = 0; i < 106; i++) {
    if (decLongPreamble[i].im == 0.0) {
      decLongPreamble[i].re /= (real_T)iv10[i];
      decLongPreamble[i].im = 0.0;
    } else if (decLongPreamble[i].re == 0.0) {
      decLongPreamble[i].re = 0.0;
      decLongPreamble[i].im /= (real_T)iv10[i];
    } else {
      decLongPreamble[i].re /= (real_T)iv10[i];
      decLongPreamble[i].im /= (real_T)iv10[i];
    }
  }

  d_abs(decLongPreamble, dv2);
  st.site = &fc_emlrtRSI;
  c_power(dv2, dv3);
  b_mean(dv3, b_y);
  mean(decLongPreamble, preambleEqGains);
  for (i = 0; i < 53; i++) {
    if (-preambleEqGains[i].im == 0.0) {
      preambleEqGains[i].re /= b_y[i];
      preambleEqGains[i].im = 0.0;
    } else if (preambleEqGains[i].re == 0.0) {
      preambleEqGains[i].re = 0.0;
      preambleEqGains[i].im = -preambleEqGains[i].im / b_y[i];
    } else {
      preambleEqGains[i].re /= b_y[i];
      preambleEqGains[i].im = -preambleEqGains[i].im / b_y[i];
    }
  }

  /*  Separate data from preambles and demodulate them */
  st.site = &gc_emlrtRSI;
  b_SystemCore_parenReference(&st, &obj->pDataOFDMDemod, *(creal_T (*)[880])&x
    [320], demodData, demodPilots);

  /*  Apply preamble equalizer gains to data and pilots */
  for (i = 0; i < 48; i++) {
    preambleEqGainsOnData[i] = preambleEqGains[iv11[i]];
  }

  /*  Get pilot equalizer gains */
  for (i = 0; i < 4; i++) {
    b_preambleEqGains[i] = preambleEqGains[5 + 14 * i];
  }

  repmat(b_preambleEqGains, pilotNorm);
  for (i = 0; i < 44; i++) {
    postEqData_re = pilotNorm[i].re * demodPilots[i].re - pilotNorm[i].im *
      demodPilots[i].im;
    postEqData_im = pilotNorm[i].re * demodPilots[i].im + pilotNorm[i].im *
      demodPilots[i].re;
    if (postEqData_im == 0.0) {
      pilotNorm[i].re = postEqData_re / (real_T)iv12[i];
      pilotNorm[i].im = 0.0;
    } else if (postEqData_re == 0.0) {
      pilotNorm[i].re = 0.0;
      pilotNorm[i].im = postEqData_im / (real_T)iv12[i];
    } else {
      pilotNorm[i].re = postEqData_re / (real_T)iv12[i];
      pilotNorm[i].im = postEqData_im / (real_T)iv12[i];
    }
  }

  e_abs(pilotNorm, dv4);
  st.site = &hc_emlrtRSI;
  d_power(dv4, c_y);

  /*  Interpolate to data subcarrier size and apply pilot equalizer */
  for (i = 0; i < 44; i++) {
    if (-pilotNorm[i].im == 0.0) {
      demodPilots[i].re = pilotNorm[i].re / c_y[i];
      demodPilots[i].im = 0.0;
    } else if (pilotNorm[i].re == 0.0) {
      demodPilots[i].re = 0.0;
      demodPilots[i].im = -pilotNorm[i].im / c_y[i];
    } else {
      demodPilots[i].re = pilotNorm[i].re / c_y[i];
      demodPilots[i].im = -pilotNorm[i].im / c_y[i];
    }
  }

  st.site = &ic_emlrtRSI;
  resample(SD, &st, demodPilots, pilotEqGainsOnData);
  b_repmat(preambleEqGainsOnData, postEqData);
  for (i = 0; i < 528; i++) {
    postEqData_re = postEqData[i].re * demodData[i].re - postEqData[i].im *
      demodData[i].im;
    postEqData_im = postEqData[i].re * demodData[i].im + postEqData[i].im *
      demodData[i].re;
    postEqData[i].re = pilotEqGainsOnData[i].re * postEqData_re -
      pilotEqGainsOnData[i].im * postEqData_im;
    postEqData[i].im = pilotEqGainsOnData[i].re * postEqData_im +
      pilotEqGainsOnData[i].im * postEqData_re;
  }

  memcpy(&eqGains[0], &preambleEqGainsOnData[0], 48U * sizeof(creal_T));
  for (i = 0; i < 11; i++) {
    memcpy(&eqGains[i * 48 + 48], &pilotEqGainsOnData[i * 48], 48U * sizeof
           (creal_T));
  }
}

real_T OFDMReceiver_locatePreamble(const emlrtStack *sp, const creal_T x[1800])
{
  real_T preambleStartLocation;
  creal_T Phat[1741];
  real_T dv0[871];
  real_T dv1[871];
  real_T Rhat[1741];
  real_T b_y[864];
  real_T M[864];
  int32_T ix;
  int32_T ixstart;
  real_T mtmp;
  boolean_T exitg1;
  int32_T i;
  boolean_T b_x[864];
  int32_T ii;
  int32_T loop_ub;
  int16_T ii_data[864];
  int32_T iv9[2];
  int16_T MLocations_data[864];
  int8_T peaks_data[864];
  boolean_T b0;
  int32_T MLocations_size[1];
  real_T MLocations[8];
  real_T c_data[8];
  int32_T c_size[1];
  int32_T ia_data[8];
  int32_T ia_size[1];
  int32_T ib_data[8];
  int32_T ib_size[1];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;

  /*  OFDMReceiver Recover payload message from the time domain OFDM input */
  /*  signal based on the 802.11a standard. */
  /*  Copyright 2014-2016 The MathWorks, Inc. */
  /* SampleRate Sample rate */
  /* FrameLength Frame length */
  /* DisplayMessage Display decoded message */
  /* ShowScopes Show scopes */
  /*  Number of OFDM symbols per frame */
  /*  Number of bits converted to letters for display */
  /*  Pilot subcarrier indices in preamble symbols */
  /*  Data subcarrier indices in preamble symbols */
  /*  Preamble for each frame */
  /*  Pilots for each frame */
  /*  Moving buffer size at receiver */
  /*  Incremental distance window */
  /*  BPSK Demodulator System object */
  /*  OFDM Demodulator System object for preamble */
  /*  OFDM Demodulator System object for data */
  /*  OFDM Scopes System object */
  /*  Buffer for estimating frequency offset */
  /*  Number of detected frames */
  /*  OFDM Demodulator configuration */
  /*  Long Preamble */
  /*  A few adjustable algorithms parameters: */
  /*    1). Number of frequency estimates to be averaged over for frequency corrections */
  /*    2). Peak threshold after normalization for preamble detection  */
  /*    3). Mininum number of peaks for positive match in frame detection */
  /*  Validate data input */
  /*  Constant calculation */
  /*  Calculate locations of pilots without guardbands in preambles */
  /*  Calculate locations of data without guardbands in preambles */
  /*  Get preamble for each frame */
  /*  Get pilot for each frame */
  /*  BPSK demodulator */
  /*  OFDM demodulator for preamble */
  /*  OFDM demodulator for data */
  /*  Start index for the last moving buffer in this input */
  /*  Initialization */
  /*  Moving buffer for frame detection and message recovery         */
  /*  Current buffer */
  /*  Find preamble in buffer: Return -1 if finding nothing */
  /*  Check if this buffer holds a full frame */
  /*  Recover message from the detected frame */
  /*  Extract single frame from buffer */
  /*  Correct frequency offset */
  /*  Apply equalizers */
  /*  BPSK demodulation */
  /*  Save bits to output */
  /*  Convert bits to message and display it as specified */
  /*  Visualization */
  /*  Jump a frame, about 4 windows */
  /*  Window sliding */
  /*  Window sliding */
  /*  Locate the starting point of the preamble using cross correlation. */
  /*  Cross correlate */
  st.site = &jb_emlrtRSI;
  xcorr(&st, *(creal_T (*)[871])&x[0], Phat);
  b_abs(*(creal_T (*)[871])&x[0], dv0);
  st.site = &kb_emlrtRSI;
  power(dv0, dv1);
  st.site = &kb_emlrtRSI;
  b_xcorr(&st, dv1, Rhat);

  /*  Moving average */
  /*  Remove leading and tail zeros overlaps */
  /*  Calculate timing metric */
  c_abs(*(creal_T (*)[864])&Phat[870], b_y);
  st.site = &lb_emlrtRSI;
  b_power(b_y, M);
  st.site = &lb_emlrtRSI;
  b_power(*(real_T (*)[864])&Rhat[870], b_y);
  for (ix = 0; ix < 864; ix++) {
    M[ix] /= b_y[ix];
  }

  /*  Determine start of short preamble. First find peak locations */
  ixstart = 1;
  mtmp = M[0];
  if (muDoubleScalarIsNaN(M[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 865)) {
      ixstart = ix;
      if (!muDoubleScalarIsNaN(M[ix - 1])) {
        mtmp = M[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 864) {
    while (ixstart + 1 < 865) {
      if (M[ixstart] > mtmp) {
        mtmp = M[ixstart];
      }

      ixstart++;
    }
  }

  st.site = &mb_emlrtRSI;
  for (i = 0; i < 864; i++) {
    b_x[i] = (M[i] > mtmp * 0.6);
  }

  b_st.site = &sb_emlrtRSI;
  ixstart = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 865)) {
    if (b_x[ii - 1]) {
      ixstart++;
      ii_data[ixstart - 1] = (int16_T)ii;
      if (ixstart >= 864) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (1 > ixstart) {
    loop_ub = 0;
  } else {
    loop_ub = ixstart;
  }

  iv9[0] = 1;
  iv9[1] = loop_ub;
  c_st.site = &tb_emlrtRSI;
  indexShapeCheck(&c_st, 864, iv9);

  /*  Correct estimate to the start of preamble, not its center */
  for (ix = 0; ix < loop_ub; ix++) {
    MLocations_data[ix] = (int16_T)(ii_data[ix] - 9);
  }

  /*  Determine correct peaks */
  ixstart = (int16_T)loop_ub;
  for (ix = 0; ix < ixstart; ix++) {
    peaks_data[ix] = 0;
  }

  i = 0;
  while (i <= loop_ub - 1) {
    ix = i + 1;
    if (!((ix >= 1) && (ix <= loop_ub))) {
      emlrtDynamicBoundsCheckR2012b(ix, 1, loop_ub, &d_emlrtBCI, sp);
    }

    if (i + 1 > loop_ub) {
      ix = 0;
      ii = 0;
    } else {
      if (!((i + 1 >= 1) && (i + 1 <= loop_ub))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &c_emlrtBCI, sp);
      }

      ix = i;
      if (!(loop_ub >= 1)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, loop_ub, &b_emlrtBCI, sp);
      }

      ii = loop_ub;
    }

    iv9[0] = 1;
    iv9[1] = ii - ix;
    st.site = &nb_emlrtRSI;
    indexShapeCheck(&st, loop_ub, iv9);
    st.site = &nb_emlrtRSI;
    b_st.site = &ub_emlrtRSI;
    MLocations_size[0] = ii - ix;
    ixstart = ii - ix;
    for (ii = 0; ii < ixstart; ii++) {
      b_y[ii] = MLocations_data[ix + ii];
    }

    for (ix = 0; ix < 8; ix++) {
      MLocations[ix] = (MLocations_data[i] + 16 * ix) + 16;
    }

    c_st.site = &vb_emlrtRSI;
    do_vectors(&c_st, b_y, MLocations_size, MLocations, c_data, c_size, ia_data,
               ia_size, ib_data, ib_size);
    ix = (int16_T)loop_ub;
    if (!((i + 1 >= 1) && (i + 1 <= ix))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &g_emlrtBCI, sp);
    }

    peaks_data[i] = (int8_T)c_size[0];
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  Have at least obj.pNumRequiredPeaks peaks for positive match     */
  ixstart = (int16_T)loop_ub;
  for (i = 0; i < ixstart; i++) {
    if (peaks_data[i] < 5) {
      ix = (int16_T)loop_ub;
      if (!((i + 1 >= 1) && (i + 1 <= ix))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, ix, &f_emlrtBCI, sp);
      }

      peaks_data[i] = 0;
    }
  }

  /*  Pick earliest peak in time */
  st.site = &ob_emlrtRSI;
  b_st.site = &bc_emlrtRSI;
  c_st.site = &cc_emlrtRSI;
  if (((int16_T)loop_ub == 1) || ((int16_T)loop_ub != 1)) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(&c_st, &j_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (!((int16_T)loop_ub > 0)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &i_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  ixstart = peaks_data[0];
  ii = 1;
  if ((int16_T)loop_ub > 1) {
    for (ix = 2; ix <= (int16_T)loop_ub; ix++) {
      if (peaks_data[ix - 1] > ixstart) {
        ixstart = peaks_data[ix - 1];
        ii = ix;
      }
    }
  }

  if (ixstart > 0) {
    if (!(ii <= loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(ii, 1, loop_ub, &e_emlrtBCI, sp);
    }

    preambleStartLocation = MLocations_data[ii - 1];
  } else {
    /*  No desirable location found */
    preambleStartLocation = -1.0;
  }

  return preambleStartLocation;
}

void OFDMReceiver_setupImpl(const emlrtStack *sp, OFDMReceiver *obj)
{
  commcodegen_BPSKDemodulator *b_obj;
  comm_OFDMDemodulator *object;
  comm_OFDMDemodulator_1 *b_object;
  int32_T k;
  int32_T nb;
  int8_T tmp_data[4];
  int32_T x;
  int32_T exitg1;
  int32_T iv8[2];
  int32_T exponent;
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
  st.site = &k_emlrtRSI;
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
  b_obj = &obj->pBPSKDemod;
  b_st.site = &o_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  b_obj->isInitialized = 0;
  d_st.site = &g_emlrtRSI;
  d_st.site = &g_emlrtRSI;
  d_st.site = &g_emlrtRSI;
  b_st.site = &o_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  b_st.site = &o_emlrtRSI;

  /* System object Constructor function: comm.BPSKDemodulator */
  st.site = &l_emlrtRSI;
  object = &obj->pPreambleOFDMDemod;
  b_st.site = &q_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &e_emlrtRSI;
  e_st.site = &f_emlrtRSI;
  d_st.site = &e_emlrtRSI;
  object->isInitialized = 0;
  e_st.site = &g_emlrtRSI;
  e_st.site = &g_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &t_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &u_emlrtRSI;
  b_st.site = &r_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  e_st.site = &i_emlrtRSI;
  st.site = &m_emlrtRSI;
  b_object = &obj->pDataOFDMDemod;
  b_st.site = &q_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &e_emlrtRSI;
  e_st.site = &f_emlrtRSI;
  d_st.site = &e_emlrtRSI;
  b_object->isInitialized = 0;
  e_st.site = &g_emlrtRSI;
  e_st.site = &g_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &t_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &u_emlrtRSI;
  b_st.site = &r_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  e_st.site = &i_emlrtRSI;
  e_st.site = &i_emlrtRSI;
  f_st.site = &v_emlrtRSI;
  g_st.site = &w_emlrtRSI;
  for (k = 0; k < 4; k++) {
    tmp_data[k] = (int8_T)(12 + 14 * k);
  }

  nb = 0;
  k = 1;
  while (k <= 4) {
    x = tmp_data[k - 1];
    do {
      exitg1 = 0;
      k++;
      if (k > 4) {
        exitg1 = 1;
      } else {
        frexp((real_T)x / 2.0, &exponent);
        if (!(muDoubleScalarAbs(x - tmp_data[k - 1]) < ldexp(1.0, exponent - 53)))
        {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    nb++;
    tmp_data[nb - 1] = (int8_T)x;
  }

  h_st.site = &ab_emlrtRSI;
  if (1 > nb) {
    k = 0;
  } else {
    k = nb;
  }

  iv8[0] = 1;
  iv8[1] = k;
  h_st.site = &y_emlrtRSI;
  indexShapeCheck(&h_st, 4, iv8);
  h_st.site = &x_emlrtRSI;
  if ((!(1 > nb)) && (nb > 2147483646)) {
    i_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&i_st);
  }

  if (4 != k) {
    emlrtErrorWithMessageIdR2012b(&e_st, &f_emlrtRTEI,
      "comm:OFDM:IndexNotUniquePerSym", 0);
  }
}

void OFDMReceiver_validateInputsImpl(const emlrtStack *sp, const creal_T x
  [130080])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &j_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 130080)) {
    if ((!(muDoubleScalarIsInf(x[k].re) || muDoubleScalarIsInf(x[k].im))) &&
        (!(muDoubleScalarIsNaN(x[k].re) || muDoubleScalarIsNaN(x[k].im)))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrMsgIdAndExplicitTxt(&st, &e_emlrtRTEI,
      "MATLAB:OFDMReceiver.Input:expectedFinite", 39,
      "Expected the signal input to be finite.");
  }
}

void c_OFDMReceiver_coarseFreqCorrec(const emlrtStack *sp, OFDMReceiver *obj,
  const creal_T x[1200], creal_T b_y[1200], real_T *estFreqOffset)
{
  int32_T i;
  real_T y_re;
  creal_T b_x[32];
  real_T y_im;
  real_T c_x;
  real_T r;
  int32_T loop_ub;
  real_T x_data[15];
  boolean_T b1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  Frequency correction based on the Schmidl and Cox method, utilizing */
  /*  halves of the short preamble from the 802.11a standard. */
  /*  Cross-correlate preamble and determine phase angle */
  for (i = 0; i < 32; i++) {
    b_x[i].re = x[i].re * x[i + 32].re - -x[i].im * x[i + 32].im;
    b_x[i].im = x[i].re * x[i + 32].im + -x[i].im * x[i + 32].re;
  }

  y_re = b_x[0].re;
  y_im = b_x[0].im;
  for (i = 0; i < 31; i++) {
    y_re += b_x[i + 1].re;
    y_im += b_x[i + 1].im;
  }

  /*  Update frequency offset buffer */
  c_x = obj->pNumFrameDetected - 1.0;
  if ((!muDoubleScalarIsInf(c_x)) && (!muDoubleScalarIsNaN(c_x))) {
    if (c_x == 0.0) {
      r = 0.0;
    } else {
      r = muDoubleScalarRem(c_x, 15.0);
      if (r == 0.0) {
        r = 0.0;
      } else {
        if (c_x < 0.0) {
          r += 15.0;
        }
      }
    }
  } else {
    r = rtNaN;
  }

  if (r + 1.0 != (int32_T)muDoubleScalarFloor(r + 1.0)) {
    emlrtIntegerCheckR2012b(r + 1.0, &b_emlrtDCI, sp);
  }

  i = (int32_T)(r + 1.0);
  if (!((i >= 1) && (i <= 15))) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 15, &j_emlrtBCI, sp);
  }

  obj->pFreqOffsetEstBuffer[i - 1] = muDoubleScalarAtan2(y_im, y_re) /
    1.0053096491487338E-5;

  /*  Estimated frequency offset      */
  c_x = obj->pNumFrameDetected;
  c_x = muDoubleScalarMin(15.0, c_x);
  if (1.0 > c_x) {
    loop_ub = 0;
  } else {
    if (c_x != muDoubleScalarFloor(c_x)) {
      emlrtIntegerCheckR2012b(c_x, &c_emlrtDCI, sp);
    }

    loop_ub = (int32_T)c_x;
  }

  st.site = &dc_emlrtRSI;
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = obj->pFreqOffsetEstBuffer[i];
  }

  if ((loop_ub == 1) || (loop_ub != 1)) {
    b1 = true;
  } else {
    b1 = false;
  }

  if (!b1) {
    emlrtErrorWithMessageIdR2012b(&st, &n_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (loop_ub == 0) {
    c_x = 0.0;
  } else {
    c_x = x_data[0];
    for (i = 2; i <= loop_ub; i++) {
      c_x += x_data[i - 1];
    }
  }

  *estFreqOffset = c_x / (real_T)loop_ub;

  /*  Apply frequency correction */
  y_re = *estFreqOffset * 0.0;
  for (i = 0; i < 1200; i++) {
    b_y[i].re = 5.0E-8 * ((real_T)i * y_re);
    b_y[i].im = 5.0E-8 * ((real_T)i * *estFreqOffset);
  }

  for (i = 0; i < 1200; i++) {
    if (b_y[i].im == 0.0) {
      y_re = muDoubleScalarExp(b_y[i].re);
      y_im = 0.0;
    } else if (muDoubleScalarIsInf(b_y[i].im) && muDoubleScalarIsInf(b_y[i].re) &&
               (b_y[i].re < 0.0)) {
      y_re = 0.0;
      y_im = 0.0;
    } else {
      r = muDoubleScalarExp(b_y[i].re / 2.0);
      y_re = r * (r * muDoubleScalarCos(b_y[i].im));
      y_im = r * (r * muDoubleScalarSin(b_y[i].im));
    }

    b_y[i].re = y_re;
    b_y[i].im = y_im;
    y_re = b_y[i].re;
    b_y[i].re = b_y[i].re * x[i].re - b_y[i].im * x[i].im;
    b_y[i].im = y_re * x[i].im + b_y[i].im * x[i].re;
  }
}

/* End of code generation (OFDMReceiver.c) */
