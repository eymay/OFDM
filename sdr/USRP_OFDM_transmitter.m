
function[transmitTime,underrunCount] = USRP_OFDM_transmitter()

Duration = 10;
       SamplesPerFrame = 1e4;
       MasterClockRate = 20e6;
       InterpolationFactor = 1;
 
       SampleRate = MasterClockRate/3;
       FrameDuration = SamplesPerFrame/SampleRate;
       Iterations = Duration/FrameDuration;

%        sinGen = dsp.SineWave('Frequency',100e3,'SampleRate',SampleRate, ...
%                        'SamplesPerFrame',SamplesPerFrame, ...
%                        'ComplexOutput',true);
%        data = sinGen();

OFDM_transmitter

      
       tx = comm.SDRuTransmitter('Platform','B200','SerialNum','31FD9A2', ...
                          'CenterFrequency',2.45e9, ...
                          'MasterClockRate',MasterClockRate, ...
                          'InterpolationFactor',InterpolationFactor);
       tx(data);
       disp('Started Transmission...');
       underrunCount = 0;
       tic
       for i = 1:Iterations
           underrun = tx(data);
           if underrun
              underrunCount = underrunCount+1;
           end
       end
       transmitTime = toc;
       release(tx);
end
%codegen sdruTransmitData -o sdruTransmitMex;
%[transmitTime,underrunCount] = sdruTransmitMex()

