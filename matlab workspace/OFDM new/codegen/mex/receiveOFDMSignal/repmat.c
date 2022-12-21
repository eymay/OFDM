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
#include "receiveOFDMSignal.h"
#include "repmat.h"

/* Function Definitions */
void b_repmat(const creal_T a[48], creal_T b[528])
{
  int32_T jtilecol;
  int32_T ibtile;
  for (jtilecol = 0; jtilecol < 11; jtilecol++) {
    ibtile = jtilecol * 48;
    memcpy(&b[ibtile], &a[0], 48U * sizeof(creal_T));
  }
}

void repmat(const creal_T a[4], creal_T b[44])
{
  int32_T jtilecol;
  int32_T ibtile;
  for (jtilecol = 0; jtilecol < 11; jtilecol++) {
    ibtile = jtilecol << 2;
    memcpy(&b[ibtile], &a[0], sizeof(creal_T) << 2);
  }
}

/* End of code generation (repmat.c) */
