/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * receiveOFDMSignal_types.h
 *
 * Code generation for function 'receiveOFDMSignal'
 *
 */

#ifndef RECEIVEOFDMSIGNAL_TYPES_H
#define RECEIVEOFDMSIGNAL_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3

typedef struct {
  uint32_T f1[8];
} cell_wrap_3;

#endif                                 /*typedef_cell_wrap_3*/

#ifndef typedef_comm_OFDMDemodulator
#define typedef_comm_OFDMDemodulator

typedef struct {
  int32_T isInitialized;
} comm_OFDMDemodulator;

#endif                                 /*typedef_comm_OFDMDemodulator*/

#ifndef typedef_comm_OFDMDemodulator_1
#define typedef_comm_OFDMDemodulator_1

typedef struct {
  int32_T isInitialized;
} comm_OFDMDemodulator_1;

#endif                                 /*typedef_comm_OFDMDemodulator_1*/

#ifndef struct_comm_BPSKDemodulator_0
#define struct_comm_BPSKDemodulator_0

struct comm_BPSKDemodulator_0
{
  int32_T S0_isInitialized;
};

#endif                                 /*struct_comm_BPSKDemodulator_0*/

#ifndef typedef_comm_BPSKDemodulator_0
#define typedef_comm_BPSKDemodulator_0

typedef struct comm_BPSKDemodulator_0 comm_BPSKDemodulator_0;

#endif                                 /*typedef_comm_BPSKDemodulator_0*/

#ifndef typedef_commcodegen_BPSKDemodulator
#define typedef_commcodegen_BPSKDemodulator

typedef struct {
  int32_T isInitialized;
  comm_BPSKDemodulator_0 cSFunObject;
} commcodegen_BPSKDemodulator;

#endif                                 /*typedef_commcodegen_BPSKDemodulator*/

#ifndef typedef_OFDMReceiver
#define typedef_OFDMReceiver

typedef struct {
  int32_T isInitialized;
  cell_wrap_3 inputVarSize[1];
  commcodegen_BPSKDemodulator pBPSKDemod;
  comm_OFDMDemodulator pPreambleOFDMDemod;
  comm_OFDMDemodulator_1 pDataOFDMDemod;
  real_T pFreqOffsetEstBuffer[15];
  real_T pNumFrameDetected;
} OFDMReceiver;

#endif                                 /*typedef_OFDMReceiver*/

#ifndef struct_dsp_FIRRateConverter_1
#define struct_dsp_FIRRateConverter_1

struct dsp_FIRRateConverter_1
{
  int32_T S0_isInitialized;
  creal_T W0_InBuf[231];
  int32_T W1_InBufIdx;
  real_T P0_FILTER[252];
  int32_T P1_PolyphaseSelector[12];
  int32_T P2_StartIdx;
  int32_T P3_StopIdx;
};

#endif                                 /*struct_dsp_FIRRateConverter_1*/

#ifndef typedef_dsp_FIRRateConverter_1
#define typedef_dsp_FIRRateConverter_1

typedef struct dsp_FIRRateConverter_1 dsp_FIRRateConverter_1;

#endif                                 /*typedef_dsp_FIRRateConverter_1*/

#ifndef typedef_dspcodegen_FIRRateConverter
#define typedef_dspcodegen_FIRRateConverter

typedef struct {
  int32_T isInitialized;
  dsp_FIRRateConverter_1 cSFunObject;
} dspcodegen_FIRRateConverter;

#endif                                 /*typedef_dspcodegen_FIRRateConverter*/

#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_receiveOFDMSignalStackData
#define typedef_receiveOFDMSignalStackData

typedef struct {
  struct {
    creal_T y[3058];
  } f0;

  struct {
    creal_T rxSig[130080];
  } f1;
} receiveOFDMSignalStackData;

#endif                                 /*typedef_receiveOFDMSignalStackData*/
#endif

/* End of code generation (receiveOFDMSignal_types.h) */
