% function [receiveTime,overrunCount] = USRP_OFDM_receiver()
clear
clc

Duration = 5;
MasterClockRate = 20e6;
DecimationFactor = 1;
SamplesPerFrame = 1840;

SampleRate = MasterClockRate/3;
FrameDuration = SamplesPerFrame/SampleRate;
Iterations = Duration/FrameDuration;

rx = comm.SDRuReceiver('Platform','B200','SerialNum','31FD9D5', ...
    'CenterFrequency', 1.2e9, ...
    'MasterClockRate',MasterClockRate, ...
    'DecimationFactor',DecimationFactor, ...
    'OutputDataType','double', ...
    'SamplesPerFrame', 1840, ...
    'Gain', 20);
count = 0;

disp('Started Reception...');
tic
for i = 1:2500
    [data,~,overrun] = rx();
    datax(:,i) =data;
    if overrun
        count = count+1;
    end
end

disp('Finished Reception...');
%        USRP_OFDM_demodulation

receiveTime = toc;
overrunCount = count;
release(rx);
% end

