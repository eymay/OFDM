clear

% function[transmitTime,underrunCount] = USRP_OFDM_transmitter()

Duration = 10;
SamplesPerFrame = 6640;
MasterClockRate = 20e6;
InterpolationFactor = 1;

SampleRate = MasterClockRate/3;
FrameDuration = SamplesPerFrame/SampleRate;
Iterations = Duration/FrameDuration;


OFDM_transmitter


tx = comm.SDRuTransmitter('Platform','B200','SerialNum','31FD9A2', ...
    'CenterFrequency',1.2e9, ...
    'MasterClockRate',MasterClockRate, ...
    'InterpolationFactor',InterpolationFactor, ... 
    'LocalOscillatorOffset', 0, ...
    'Gain', 40 );
     

disp('Started Transmission...'); 



underrunCount = 0;
tic
% for i = 1:Iterations
while 1
     underrun = tx(y);
%     if underrun
%         underrunCount = underrunCount+1;
%     end
end
disp('finished Transmission...');
transmitTime = toc;
release(tx);
% end
%codegen sdruTransmitData -o sdruTransmitMex;
%[transmitTime,underrunCount] = sdruTransmitMex()

