
function[transmitTime,underrunCount] = USRP_OFDM_transmitter()

Duration = 10;
SamplesPerFrame = 1e6;
MasterClockRate = 20e6;
InterpolationFactor = 1;

SampleRate = MasterClockRate/3;
FrameDuration = SamplesPerFrame/SampleRate;
Iterations = Duration/FrameDuration;


OFDM_transmitter


tx = comm.SDRuTransmitter('Platform','B200','SerialNum','31FD9D5', ...
    'CenterFrequency',2.45e9, ...
    'MasterClockRate',MasterClockRate, ...
    'InterpolationFactor',InterpolationFactor, ...
    'CenterFrequency', 2.4500e+09, ...
    'LocalOscillatorOffset', 0, ...
                     'Gain', 8);

                 tx(data);
disp('Started Transmission...');
underrunCount = 0;
tic
for i = 1:Iterations
    underrun = tx(x_transmitted);
    if underrun
        underrunCount = underrunCount+1;
    end
end
transmitTime = toc;
release(tx);
end
%codegen sdruTransmitData -o sdruTransmitMex;
%[transmitTime,underrunCount] = sdruTransmitMex()

