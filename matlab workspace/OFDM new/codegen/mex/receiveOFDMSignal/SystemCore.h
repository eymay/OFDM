/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.h
 *
 * Code generation for function 'SystemCore'
 *
 */

#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

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
extern void SystemCore_parenReference(const emlrtStack *sp, comm_OFDMDemodulator
  *obj, const creal_T varargin_1[128], creal_T varargout_1[106]);
extern void SystemCore_reset(const emlrtStack *sp, dspcodegen_FIRRateConverter
  *obj);
extern void SystemCore_step(const emlrtStack *sp, dspcodegen_FIRRateConverter
  *obj, const creal_T varargin_1[264], creal_T varargout_1[3168]);
extern void b_SystemCore_parenReference(const emlrtStack *sp,
  comm_OFDMDemodulator_1 *obj, const creal_T varargin_1[880], creal_T
  varargout_1[528], creal_T varargout_2[44]);
extern void c_SystemCore_parenReference(const emlrtStack *sp,
  commcodegen_BPSKDemodulator *obj, const creal_T varargin_1[528], real_T
  varargout_1[528]);

#endif

/* End of code generation (SystemCore.h) */
