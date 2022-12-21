/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "generateOFDMSignal.h"
#include "repmat.h"

/* Function Definitions */
void repmat(const creal_T a[1200], creal_T b[120000])
{
  int32_T itilerow;
  int32_T ibcol;
  for (itilerow = 0; itilerow < 100; itilerow++) {
    ibcol = itilerow * 1200;
    memcpy(&b[ibcol], &a[0], 1200U * sizeof(creal_T));
  }
}

/* End of code generation (repmat.c) */
