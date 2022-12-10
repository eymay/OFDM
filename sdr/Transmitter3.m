function[transmitTime,underrunCount] = Transmitter3()
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
        syms t;
        % Amplitude of the carrier signal is taken as 1
       
%         dt = 1/SampleRate;
%         t = 0:dt:1-dt;
        
        Ac = 1;
        fc = 100e3;
        fm = fc/4;

        %message signal 
        mt = cos(2*pi*fm*t);
        Df = pi;
      

        %Frequency modulated signal       
       FreqMod_signal = Ac*cos(2*pi*fc*t + Df*int(mt,t,0,t));
      

       data = FreqMod_signal;
       tx = comm.SDRuTransmitter('Platform','B200','SerialNum','31FD9C0', ...
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

