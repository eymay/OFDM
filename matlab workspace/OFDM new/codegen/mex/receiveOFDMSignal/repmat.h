/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 */

#ifndef REPMAT_H
#define REPMAT_H

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
extern void b_repmat(const creal_T a[48], creal_T b[528]);
extern void repmat(const creal_T a[4], creal_T b[44]);

#endif

/* End of code generation (repmat.h) */
