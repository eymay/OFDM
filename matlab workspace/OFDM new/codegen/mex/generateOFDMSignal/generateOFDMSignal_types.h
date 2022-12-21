/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generateOFDMSignal_types.h
 *
 * Code generation for function 'generateOFDMSignal'
 *
 */

#ifndef GENERATEOFDMSIGNAL_TYPES_H
#define GENERATEOFDMSIGNAL_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_comm_OFDMModulator
#define typedef_comm_OFDMModulator

typedef struct {
  int32_T isInitialized;
} comm_OFDMModulator;

#endif                                 /*typedef_comm_OFDMModulator*/

#ifndef struct_comm_BPSKModulator_0
#define struct_comm_BPSKModulator_0

struct comm_BPSKModulator_0
{
  int32_T S0_isInitialized;
  real_T P0_modmap[4];
};

#endif                                 /*struct_comm_BPSKModulator_0*/

#ifndef typedef_comm_BPSKModulator_0
#define typedef_comm_BPSKModulator_0

typedef struct comm_BPSKModulator_0 comm_BPSKModulator_0;

#endif                                 /*typedef_comm_BPSKModulator_0*/

#ifndef typedef_commcodegen_BPSKModulator
#define typedef_commcodegen_BPSKModulator

typedef struct {
  int32_T isInitialized;
  comm_BPSKModulator_0 cSFunObject;
} commcodegen_BPSKModulator;

#endif                                 /*typedef_commcodegen_BPSKModulator*/

#ifndef typedef_OFDMTransmitter
#define typedef_OFDMTransmitter

typedef struct {
  int32_T isInitialized;
  commcodegen_BPSKModulator pBPSKMod;
  comm_OFDMModulator pDataOFDMMod;
} OFDMTransmitter;

#endif                                 /*typedef_OFDMTransmitter*/

#ifndef typedef_generateOFDMSignalStackData
#define typedef_generateOFDMSignalStackData

typedef struct {
  struct {
    creal_T txSig[120000];
  } f0;
} generateOFDMSignalStackData;

#endif                                 /*typedef_generateOFDMSignalStackData*/
#endif

/* End of code generation (generateOFDMSignal_types.h) */
