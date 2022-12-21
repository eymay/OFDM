/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.h
 *
 * Code generation for function 'abs'
 *
 */

#ifndef ABS_H
#define ABS_H

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
extern void b_abs(const creal_T x[871], real_T b_y[871]);
extern void c_abs(const creal_T x[864], real_T b_y[864]);
extern void d_abs(const creal_T x[106], real_T b_y[106]);
extern void e_abs(const creal_T x[44], real_T b_y[44]);

#endif

/* End of code generation (abs.h) */
