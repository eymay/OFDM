@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=generateOFDMSignal_mex
set MEX_NAME=generateOFDMSignal_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2017a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for generateOFDMSignal > generateOFDMSignal_mex.mki
echo COMPILER=%COMPILER%>> generateOFDMSignal_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> generateOFDMSignal_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> generateOFDMSignal_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> generateOFDMSignal_mex.mki
echo LINKER=%LINKER%>> generateOFDMSignal_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> generateOFDMSignal_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> generateOFDMSignal_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> generateOFDMSignal_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> generateOFDMSignal_mex.mki
echo BORLAND=%BORLAND%>> generateOFDMSignal_mex.mki
echo OMPFLAGS= >> generateOFDMSignal_mex.mki
echo OMPLINKFLAGS= >> generateOFDMSignal_mex.mki
echo EMC_COMPILER=lcc64>> generateOFDMSignal_mex.mki
echo EMC_CONFIG=optim>> generateOFDMSignal_mex.mki
"C:\Program Files\MATLAB\R2017a\bin\win64\gmake" -B -f generateOFDMSignal_mex.mk
