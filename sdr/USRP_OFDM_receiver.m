% function [receiveTime,overrunCount] = USRP_OFDM_receiver()

Duration = 10;
        MasterClockRate = 20e6;
        DecimationFactor = 1;
        SamplesPerFrame = 6640;

        SampleRate = MasterClockRate/3;
        FrameDuration = SamplesPerFrame/SampleRate;
        Iterations = Duration/FrameDuration;
        
        rx = comm.SDRuReceiver('Platform','B200','SerialNum','31FD9D5', ...
                       'CenterFrequency', 1.2e9, ...
                       'MasterClockRate',MasterClockRate, ...
                       'DecimationFactor',DecimationFactor, ...
                       'OutputDataType','double', ...
                       'SamplesPerFrame', 6640, ...
                       'Gain', 10);
        count = 0;

        disp('Started Reception...');
        tic
        for i = 1:Iterations
            [data,~,overrun] = rx();
            datax(:,i) =data;
            if overrun
              count = count+1;
            end  
        end     
       
        
%        USRP_OFDM_demodulation
       
       receiveTime = toc;
       overrunCount = count;
       release(rx);
% end

