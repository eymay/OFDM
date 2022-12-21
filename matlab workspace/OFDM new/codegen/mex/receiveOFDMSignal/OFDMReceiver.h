/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * OFDMReceiver.h
 *
 * Code generation for function 'OFDMReceiver'
 *
 */

#ifndef OFDMRECEIVER_H
#define OFDMRECEIVER_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "receiveOFDMSignal_types.h"

/* Function Declarations */
extern void OFDMReceiver_frameEqualization(receiveOFDMSignalStackData *SD, const
  emlrtStack *sp, OFDMReceiver *obj, const creal_T x[1200], creal_T postEqData
  [528], creal_T demodData[528], creal_T eqGains[576]);
extern real_T OFDMReceiver_locatePreamble(const emlrtStack *sp, const creal_T x
  [1800]);

#ifdef __WATCOMC__

#pragma aux OFDMReceiver_locatePreamble value [8087];

#endif

extern void OFDMReceiver_setupImpl(const emlrtStack *sp, OFDMReceiver *obj);
extern void OFDMReceiver_validateInputsImpl(const emlrtStack *sp, const creal_T
  x[130080]);
extern void c_OFDMReceiver_coarseFreqCorrec(const emlrtStack *sp, OFDMReceiver
  *obj, const creal_T x[1200], creal_T b_y[1200], real_T *estFreqOffset);

#endif

/* End of code generation (OFDMReceiver.h) */
