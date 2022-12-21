/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_setop.c
 *
 * Code generation for function 'eml_setop'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "receiveOFDMSignal.h"
#include "eml_setop.h"
#include "error.h"

/* Variable Definitions */
static emlrtRSInfo xb_emlrtRSI = { 225,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 228,/* lineNo */
  "eml_setop",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = { 430,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 403,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 392,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

/* Function Definitions */
void do_vectors(const emlrtStack *sp, const real_T a_data[], const int32_T
                a_size[1], const real_T b[8], real_T c_data[], int32_T c_size[1],
                int32_T ia_data[], int32_T ia_size[1], int32_T ib_data[],
                int32_T ib_size[1])
{
  int32_T ncmax;
  boolean_T b_y;
  int32_T ialast;
  boolean_T exitg1;
  boolean_T p;
  int32_T nc;
  int32_T iafirst;
  int32_T ibfirst;
  int32_T iblast;
  int32_T b_ialast;
  real_T ak;
  real_T absxk;
  int32_T b_iblast;
  real_T bk;
  int32_T b_ia_data[8];
  int32_T exponent;
  int32_T b_exponent;
  int32_T c_exponent;
  real_T b_c_data[8];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  ncmax = muIntScalarMin_sint32(a_size[0], 8);
  c_size[0] = (int8_T)ncmax;
  ia_size[0] = ncmax;
  ib_size[0] = ncmax;
  b_y = true;
  if (a_size[0] != 0) {
    ialast = 1;
    exitg1 = false;
    while ((!exitg1) && (ialast <= a_size[0] - 1)) {
      if ((a_data[ialast - 1] <= a_data[ialast]) || muDoubleScalarIsNaN
          (a_data[ialast])) {
        p = true;
      } else {
        p = false;
      }

      if (!p) {
        b_y = false;
        exitg1 = true;
      } else {
        ialast++;
      }
    }
  }

  if (!b_y) {
    st.site = &xb_emlrtRSI;
    b_error(&st);
  }

  b_y = true;
  ialast = 1;
  exitg1 = false;
  while ((!exitg1) && (ialast < 8)) {
    if ((b[ialast - 1] <= b[ialast]) || muDoubleScalarIsNaN(b[ialast])) {
      p = true;
    } else {
      p = false;
    }

    if (!p) {
      b_y = false;
      exitg1 = true;
    } else {
      ialast++;
    }
  }

  if (!b_y) {
    st.site = &yb_emlrtRSI;
    c_error(&st);
  }

  nc = 0;
  iafirst = 1;
  ialast = 1;
  ibfirst = 1;
  iblast = 1;
  while ((ialast <= a_size[0]) && (iblast <= 8)) {
    b_ialast = ialast;
    ak = a_data[ialast - 1];
    exitg1 = false;
    while ((!exitg1) && (b_ialast < a_size[0])) {
      absxk = muDoubleScalarAbs(ak / 2.0);
      if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
        if (absxk <= 2.2250738585072014E-308) {
          absxk = 4.94065645841247E-324;
        } else {
          frexp(absxk, &exponent);
          absxk = ldexp(1.0, exponent - 53);
        }
      } else {
        absxk = rtNaN;
      }

      if (muDoubleScalarAbs(ak - a_data[b_ialast]) < absxk) {
        b_ialast++;
      } else {
        exitg1 = true;
      }
    }

    ialast = b_ialast;
    b_iblast = iblast;
    bk = b[iblast - 1];
    exitg1 = false;
    while ((!exitg1) && (b_iblast < 8)) {
      absxk = muDoubleScalarAbs(bk / 2.0);
      if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
        if (absxk <= 2.2250738585072014E-308) {
          absxk = 4.94065645841247E-324;
        } else {
          frexp(absxk, &b_exponent);
          absxk = ldexp(1.0, b_exponent - 53);
        }
      } else {
        absxk = rtNaN;
      }

      if (muDoubleScalarAbs(bk - b[b_iblast]) < absxk) {
        b_iblast++;
      } else {
        exitg1 = true;
      }
    }

    iblast = b_iblast;
    absxk = muDoubleScalarAbs(bk / 2.0);
    if ((!muDoubleScalarIsInf(absxk)) && (!muDoubleScalarIsNaN(absxk))) {
      if (absxk <= 2.2250738585072014E-308) {
        absxk = 4.94065645841247E-324;
      } else {
        frexp(absxk, &c_exponent);
        absxk = ldexp(1.0, c_exponent - 53);
      }
    } else {
      absxk = rtNaN;
    }

    if (muDoubleScalarAbs(bk - ak) < absxk) {
      nc++;
      c_data[nc - 1] = ak;
      ia_data[nc - 1] = iafirst;
      ib_data[nc - 1] = ibfirst;
      ialast = b_ialast + 1;
      iafirst = b_ialast + 1;
      iblast = b_iblast + 1;
      ibfirst = b_iblast + 1;
    } else {
      if ((ak < bk) || muDoubleScalarIsNaN(bk)) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        ialast = b_ialast + 1;
        iafirst = b_ialast + 1;
      } else {
        iblast = b_iblast + 1;
        ibfirst = b_iblast + 1;
      }
    }
  }

  if (ncmax > 0) {
    if (!(nc <= ncmax)) {
      emlrtErrorWithMessageIdR2012b(sp, &m_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > nc) {
      ialast = 0;
    } else {
      ialast = nc;
    }

    for (iafirst = 0; iafirst < ialast; iafirst++) {
      b_ia_data[iafirst] = ia_data[iafirst];
    }

    ia_size[0] = ialast;
    for (iafirst = 0; iafirst < ialast; iafirst++) {
      ia_data[iafirst] = b_ia_data[iafirst];
    }

    if (!(nc <= ncmax)) {
      emlrtErrorWithMessageIdR2012b(sp, &l_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > nc) {
      ialast = 0;
    } else {
      ialast = nc;
    }

    for (iafirst = 0; iafirst < ialast; iafirst++) {
      b_ia_data[iafirst] = ib_data[iafirst];
    }

    ib_size[0] = ialast;
    for (iafirst = 0; iafirst < ialast; iafirst++) {
      ib_data[iafirst] = b_ia_data[iafirst];
    }

    if (!(nc <= ncmax)) {
      emlrtErrorWithMessageIdR2012b(sp, &k_emlrtRTEI,
        "Coder:builtins:AssertionFailed", 0);
    }

    if (1 > nc) {
      ialast = 0;
    } else {
      ialast = nc;
    }

    for (iafirst = 0; iafirst < ialast; iafirst++) {
      b_c_data[iafirst] = c_data[iafirst];
    }

    c_size[0] = ialast;
    for (iafirst = 0; iafirst < ialast; iafirst++) {
      c_data[iafirst] = b_c_data[iafirst];
    }
  }
}

/* End of code generation (eml_setop.c) */
