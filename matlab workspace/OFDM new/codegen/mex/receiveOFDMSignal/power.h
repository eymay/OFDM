/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.h
 *
 * Code generation for function 'power'
 *
 */

#ifndef POWER_H
#define POWER_H

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
extern void b_power(const real_T a[864], real_T b_y[864]);
extern void c_power(const real_T a[106], real_T b_y[106]);
extern void d_power(const real_T a[44], real_T b_y[44]);
extern void power(const real_T a[871], real_T b_y[871]);

#endif

/* End of code generation (power.h) */
