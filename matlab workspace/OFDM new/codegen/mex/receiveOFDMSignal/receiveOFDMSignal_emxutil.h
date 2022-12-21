/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * receiveOFDMSignal_emxutil.h
 *
 * Code generation for function 'receiveOFDMSignal_emxutil'
 *
 */

#ifndef RECEIVEOFDMSIGNAL_EMXUTIL_H
#define RECEIVEOFDMSIGNAL_EMXUTIL_H

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
extern void emxEnsureCapacity(const emlrtStack *sp, emxArray__common *emxArray,
  int32_T oldNumel, uint32_T elementSize, const emlrtRTEInfo *srcLocation);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T b_numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (receiveOFDMSignal_emxutil.h) */
