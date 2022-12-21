@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=receiveOFDMSignal_mex
set MEX_NAME=receiveOFDMSignal_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2017a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for receiveOFDMSignal > receiveOFDMSignal_mex.mki
echo COMPILER=%COMPILER%>> receiveOFDMSignal_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> receiveOFDMSignal_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> receiveOFDMSignal_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> receiveOFDMSignal_mex.mki
echo LINKER=%LINKER%>> receiveOFDMSignal_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> receiveOFDMSignal_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> receiveOFDMSignal_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> receiveOFDMSignal_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> receiveOFDMSignal_mex.mki
echo BORLAND=%BORLAND%>> receiveOFDMSignal_mex.mki
echo OMPFLAGS= >> receiveOFDMSignal_mex.mki
echo OMPLINKFLAGS= >> receiveOFDMSignal_mex.mki
echo EMC_COMPILER=lcc64>> receiveOFDMSignal_mex.mki
echo EMC_CONFIG=optim>> receiveOFDMSignal_mex.mki
"C:\Program Files\MATLAB\R2017a\bin\win64\gmake" -B -f receiveOFDMSignal_mex.mk
