%% Frequency Offset Calibration Receiver with USRP(R) Hardware
%
% This example shows how to use the Universal Software Radio Peripheral(R)
% devices exploiting SDRu (Software Defined Radio USRP(R)) System objects to
% measure and calibrate for transmitter/receiver frequency offset at the
% receiver using MATLAB(R).
%
% Please refer to the Setup and Configuration section of <matlab:sdrudoc
% Documentation for USRP(R) Radio> for details on configuring your host
% computer to work with the SDRu Receiver System object.
%
% The USRP(R) Transmitter sends a sine wave at 100Hz with the MATLAB script,
% <matlab:edit('sdruFrequencyCalibrationTransmitter.m')
% sdruFrequencyCalibrationTransmitter.m>, to the USRP(R) receiver.  The
% USRP(R) Receiver monitors received signals, calculates the
% transmitter/receiver frequency offset and displays it in the MATLAB
% command window for calibration with the MATLAB script,
% <matlab:edit('sdruFrequencyCalibrationReceiver.m')
% sdruFrequencyCalibrationReceiver.m>.

%   Copyright 2013-2020 The MathWorks, Inc.

%% Introduction
% The example provides the following information about the USRP(R)
% transmitter/receiver link:
%
% * The quantitative value of the frequency offset
% * A graphical view of the spur-free dynamic range of the receiver
% * A graphical view of the qualitative SNR level of the received signal
% 
% To calibrate the frequency offset between two USRP(R) devices, run
% <matlab:edit('sdruFrequencyCalibrationTransmitter.m')
% sdruFrequencyCalibrationTransmitter.m> on one USRP(R) radio, and while
% simultaneously running <matlab:edit('sdruFrequencyCalibrationReceiver.m')
% sdruFrequencyCalibrationReceiver.m> on another USRP(R) radio. The
% CenterFrequency property of the SDRu transmitter and receiver System
% objects should have the same value.
%
% To compensate for a transmitter/receiver frequency offset, add the
% displayed frequency offset to the Center Frequency of the SDRu Receiver
% System object. Be sure to use the sign of the offset in your addition.
% Once you've done that, the spectrum displayed by the receiver's spectrum
% analyzer System object should have its maximum amplitude at roughly 0 Hz.
%
% Please refer to the Simulink(R) model <matlab:sdrufreqcalib_rx
% sdrufreqcalib_rx.mdl> for a block diagram view of the system.
% 
% 
%% Hardware Requirements
% To run this example, ensure that the center frequency of the SDRu
% Transmitter and Receiver System objects is within the acceptable range of
% your USRP(R) daughter board and the antennas you are using. 
%
%% Code Architecture 
% The Frequency Offset Calibration Receiver MATLAB script,
% sdruFrequencyCalibrationReceiver.m, uses three System objects:
% comm.SDRuReceiver, a coarse frequency offset object, and a
% dsp.SpectrumAnalyzer to show the power spectral density of the received
% signal.
%
%% Discover Radio
% Discover radio(s) connected to your computer. This example uses the first
% USRP(R) radio found using the |findsdru| function. Check if the radio is
% available and record the radio type. If no available radios are found,
% the example uses a default configuration for the system but does not run
% the main loop.

connectedRadios = findsdru;
if strncmp(connectedRadios(1).Status, 'Success', 7)
  radioFound = true;
  platform = connectedRadios(1).Platform;

  address = connectedRadios(1).SerialNum;
else
  radioFound = false;
  address = '192.168.10.2';
  platform = 'N200/N210/USRP2';
end

%% Initialization
% Baseband and RF configuration
rfRxFreq           = 1.2e9;  % Nominal RF receive center frequency
bbRxFreq           = 100;     % Received baseband sine wave frequency

prmFreqCalibRx = configureFreqCalibRx(platform, rfRxFreq, bbRxFreq);

% This example communicates with the USRP(R) board using the SDRu receiver
% System object. B200 and B210 series USRP(R) radios are addressed using a
% serial number while USRP2, N200, N210, X300 and X310 radios are addressed
% using an IP address. The parameter structure, prmFreqCalibRx, sets the
% CenterFrequency, Gain, InterpolationFactor, and SamplesPerFrame
% arguments.
switch platform
  case {'B200','B210'}
    radio = comm.SDRuReceiver(...
        'Platform',         platform, ...
        'SerialNum',        address, ...
        'MasterClockRate',  prmFreqCalibRx.MasterClockRate, ...
        'CenterFrequency',  prmFreqCalibRx.RxCenterFrequency,...
        'Gain',             prmFreqCalibRx.Gain, ...
        'DecimationFactor', prmFreqCalibRx.DecimationFactor,...
        'SamplesPerFrame',  prmFreqCalibRx.FrameLength,...
        'OutputDataType',   prmFreqCalibRx.OutputDataType)  
 
end

% Create a coarse frequency offset compensation System object to calculate 
% the offset. The System object performs an FFT on its input signal and 
% finds the frequency of maximum power. This quantity is the frequency 
% offset.
CFO = comm.CoarseFrequencyCompensator(...
    'FrequencyResolution',      25, ...
    'SampleRate',               prmFreqCalibRx.Fs);

spectrumAnalyzer = dsp.SpectrumAnalyzer(...
    'Name',                          'Actual Frequency Offset',...
    'Title',                         'Actual Frequency Offset', ...
    'SpectrumType',                  'Power density',...
    'FrequencySpan',                 'Full', ...
    'SampleRate',                     prmFreqCalibRx.Fs, ...
    'YLimits',                        [-130,-20],...
    'SpectralAverages',               50, ...
    'FrequencySpan',                  'Start and stop frequencies', ...
    'StartFrequency',                 -100e3, ...
    'StopFrequency',                  100e3,...
    'Position',                       figposition([50 30 30 40]));

%% Stream Processing                   
%  Loop until the example reaches the target number of frames.

% Check for the status of the USRP(R) radio
while radioFound
    for iFrame = 1 : prmFreqCalibRx.TotalFrames
        [rxSig, len ] = radio();
        if len > 0 
         % Display received frequency spectrum.
         spectrumAnalyzer(rxSig);
        
             dd=rxSig;
 
         % Compute the frequency offset.
         [~, offset] = CFO(rxSig);
         % Print the frequency offset compensation value in MATLAB command
         % window.
         offsetCompensationValue = -offset;
        end 
    end 
end 

% Release all System objects
release(radio); 
clear radio
release(CFO);

%% Conclusion
% In this example, you used Communications Toolbox(TM) System objects
% to build a receiver that calculates the relative frequency offset between
% a USRP(R) transmitter and a USRP(R) receiver.
%
%% Appendix
% The following scripts are used in this example.
%
% * <matlab:edit('configureFreqCalibRx.m') configureFreqCalibRx.m>
%
%% Copyright Notice
% Universal Software Radio Peripheral(R) and USRP(R) are trademarks of
% National Instruments Corp.
displayEndOfDemoMessage(mfilename)
