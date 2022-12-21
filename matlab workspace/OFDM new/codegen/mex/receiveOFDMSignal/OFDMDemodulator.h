/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * OFDMDemodulator.h
 *
 * Code generation for function 'OFDMDemodulator'
 *
 */

#ifndef OFDMDEMODULATOR_H
#define OFDMDEMODULATOR_H

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
extern void OFDMDemodulator_stepImpl(const creal_T x[128], creal_T varargout_1
  [106]);
extern void b_OFDMDemodulator_stepImpl(const creal_T x[880], creal_T
  varargout_1[528], creal_T varargout_2[44]);

#endif

/* End of code generation (OFDMDemodulator.h) */
