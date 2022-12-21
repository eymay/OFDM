message = 'Live long and prosper, from the Communications Toolbox Team at MathWorks!';
numFrames = 1e2;

% Adjustable channel parameters
EbN0dB = 12; % Channel noise level (dB)
frequencyOffset = 1e4; % Frequency offset (Hz)
phaseOffset = 15; % Phase offset (Degrees)
delay = 80; % Initial sample offset for entire data stream (samples)

% Display recovered messages
displayRecoveredMsg = false;

% Enable scope visualizations
useScopes = true;

% Check for MATLAB Coder license
useCodegen = checkCodegenLicense;
if useCodegen
  fprintf(['--MATLAB Coder license found. ',...
    'Transmitter and receiver functions will be compiled for ',...
    'additional simulation acceleration.--\n']);
end

% By default the transmitter and receiver functions will be recompiled
% between every run, which is not always necessary. To disable receiver
% compilation, change "compileIt" to false.
compileIt = useCodegen;


% Compile transmitter with MATLAB Coder
if compileIt
    codegen generateOFDMSignal -args {coder.Constant(message), coder.Constant(numFrames)}
end

% Generate transmission signal
if useCodegen
    [txSig, frameLen] = generateOFDMSignal_mex(message, numFrames);
else
    [txSig, frameLen] = generateOFDMSignal(message, numFrames);
end

% Pass signal through channel
rxSig = applyOFDMChannel(txSig, EbN0dB, delay, frequencyOffset, phaseOffset);

% Compile receiver with MATLAB Coder
if compileIt
   codegen  receiveOFDMSignal -args {rxSig, coder.Constant(frameLen), coder.Constant(displayRecoveredMsg), coder.Constant(useScopes)}
end

% Recover signal
if useCodegen
    [decMsgInBits, numFramesDetected] = receiveOFDMSignal_mex(rxSig, frameLen, displayRecoveredMsg, useScopes);
else
    [decMsgInBits, numFramesDetected] = receiveOFDMSignal(rxSig, frameLen, displayRecoveredMsg, useScopes);
end

% Calculate average BER
[FER, BER] = calculateOFDMBER(message, decMsgInBits, numFramesDetected);
fprintf('\nAt EbNo = %5.2fdB, %d frames detected among the %d transmitted frames with FER = %f and BER = %f\n', ...
    EbN0dB, numFramesDetected, numFrames, FER, BER);