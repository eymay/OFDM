/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fftshift.h
 *
 * Code generation for function 'fftshift'
 *
 */

#ifndef FFTSHIFT_H
#define FFTSHIFT_H

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
extern void b_fftshift(creal_T x[704]);
extern void fftshift(creal_T x[128]);

#endif

/* End of code generation (fftshift.h) */
