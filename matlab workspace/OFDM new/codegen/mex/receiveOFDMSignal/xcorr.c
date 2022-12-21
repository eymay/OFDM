/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcorr.c
 *
 * Code generation for function 'xcorr'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "xcorr.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 163,/* lineNo */
  "xcorr",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\signal\\xcorr.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 282,/* lineNo */
  "xcorr",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\signal\\xcorr.m"/* pathName */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  16,                                  /* iLast */
  482,                                 /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "xcorr",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\signal\\xcorr.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  871,                                 /* iLast */
  474,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "xcorr",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\signal\\signal\\xcorr.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void b_crosscorr(const emlrtStack *sp, const real_T x[871], real_T c[1741]);
static void crosscorr(const emlrtStack *sp, const creal_T x[871], const creal_T
                      b_y[16], creal_T c[1741]);

/* Function Definitions */
static void b_crosscorr(const emlrtStack *sp, const real_T x[871], real_T c[1741])
{
  int32_T k;
  int32_T ihi;
  real_T s;
  int32_T i;
  int32_T i2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qb_emlrtRSI;
  memset(&c[0], 0, 1741U * sizeof(real_T));
  for (k = 0; k < 871; k++) {
    ihi = (int32_T)muDoubleScalarMin(871.0 - (real_T)k, 16.0);
    s = 0.0;
    for (i = 0; i < ihi; i++) {
      i2 = (k + i) + 1;
      if (!(i2 <= 871)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 871, &i_emlrtBCI, &st);
      }

      s += x[k + i];
    }

    c[k + 870] = s;
  }

  for (k = 0; k < 870; k++) {
    s = 0.0;
    for (i = 0; i <= 14 - k; i++) {
      i2 = (k + i) + 2;
      if (!(i2 <= 16)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 16, &h_emlrtBCI, &st);
      }

      s += x[i];
    }

    c[869 - k] = s;
  }
}

static void crosscorr(const emlrtStack *sp, const creal_T x[871], const creal_T
                      b_y[16], creal_T c[1741])
{
  int32_T i;
  int32_T k;
  int32_T ihi;
  real_T s_re;
  real_T s_im;
  int32_T i1;
  real_T a_re;
  real_T a_im;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qb_emlrtRSI;
  for (i = 0; i < 1741; i++) {
    c[i].re = 0.0;
    c[i].im = 0.0;
  }

  for (k = 0; k < 871; k++) {
    ihi = (int32_T)muDoubleScalarMin(871.0 - (real_T)k, 16.0);
    s_re = 0.0;
    s_im = 0.0;
    for (i = 0; i < ihi; i++) {
      i1 = (k + i) + 1;
      if (!(i1 <= 871)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 871, &i_emlrtBCI, &st);
      }

      a_re = x[i1 - 1].re;
      i1 = (k + i) + 1;
      if (!(i1 <= 871)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 871, &i_emlrtBCI, &st);
      }

      a_im = x[i1 - 1].im;
      s_re += b_y[i].re * a_re + b_y[i].im * a_im;
      s_im += b_y[i].re * a_im - b_y[i].im * a_re;
    }

    c[k + 870].re = s_re;
    c[k + 870].im = s_im;
  }

  for (k = 0; k < 870; k++) {
    s_re = 0.0;
    s_im = 0.0;
    for (i = 0; i <= 14 - k; i++) {
      i1 = (k + i) + 2;
      if (!(i1 <= 16)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 16, &h_emlrtBCI, &st);
      }

      a_re = b_y[i1 - 1].re;
      i1 = (k + i) + 2;
      if (!(i1 <= 16)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 16, &h_emlrtBCI, &st);
      }

      a_im = b_y[i1 - 1].im;
      s_re += a_re * x[i].re + a_im * x[i].im;
      s_im += a_re * x[i].im - a_im * x[i].re;
    }

    c[869 - k].re = s_re;
    c[869 - k].im = s_im;
  }
}

void b_xcorr(const emlrtStack *sp, const real_T x[871], real_T c[1741])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pb_emlrtRSI;
  b_crosscorr(&st, x, c);
}

void xcorr(const emlrtStack *sp, const creal_T x[871], creal_T c[1741])
{
  static const creal_T dcv0[16] = { { 0.0459987545121242,/* re */
      -0.0459987545121242              /* im */
    }, { -0.13244371685162329,         /* re */
      -0.0023395918849900038           /* im */
    }, { -0.013472723270465881,        /* re */
      0.078524785753782522             /* im */
    }, { 0.14275529282051713,          /* re */
      0.012651167853883804             /* im */
    }, { 0.0919975090242484,           /* re */
      -0.0                             /* im */
    }, { 0.14275529282051713,          /* re */
      0.012651167853883833             /* im */
    }, { -0.013472723270465881,        /* re */
      0.078524785753782522             /* im */
    }, { -0.13244371685162332,         /* re */
      -0.0023395918849899934           /* im */
    }, { 0.0459987545121242,           /* re */
      -0.0459987545121242              /* im */
    }, { 0.0023395918849899934,        /* re */
      0.13244371685162332              /* im */
    }, { -0.078524785753782522,        /* re */
      0.013472723270465881             /* im */
    }, { -0.012651167853883812,        /* re */
      -0.1427552928205171              /* im */
    }, { 0.0,                          /* re */
      -0.0919975090242484              /* im */
    }, { -0.012651167853883812,        /* re */
      -0.14275529282051713             /* im */
    }, { -0.078524785753782522,        /* re */
      0.013472723270465881             /* im */
    }, { 0.0023395918849900038,        /* re */
      0.13244371685162329              /* im */
    } };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pb_emlrtRSI;
  crosscorr(&st, x, dcv0, c);
}

/* End of code generation (xcorr.c) */
